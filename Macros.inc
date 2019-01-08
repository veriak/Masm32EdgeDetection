;----------------------------------------------------------------------------------------
; Macros Masm32 Library
;
; Copyright 2007 Veria Kalantary
; veria.kalantary@gmail.com
; https://github.com/veriak
;
;----------------------------------------------------------------------------------------

MAKELANGID macro p, s
  xor eax, eax
  mov eax, s
  shl eax, 10
  xor ebx, ebx
  mov ebx, p
  or eax, ebx
endm

abs macro X
  local if, then, endif
  if: cmp &X, 0 
      jl  then
      jmp endif
  then:
      neg &X
  endif:
endm

m2m macro dest, src
	push src
    pop dest
endm

StrM macro data:VARARG                    
    LOCAL Buff
.data
    Buff db data, 0h
.code
    exitm <addr Buff>
endm

MAKELONG macro a, b
	xor eax, eax
	mov eax, b
	shl eax, 16
	or eax, a
	exitm <eax> 
endm

LOBYTE macro a
	mov ax, a
	and ax, 0FFh
	exitm <al>	
endm

HIBYTE macro a
	mov ax, a
	and ax, 0FF00h
	shr ax, 8
	exitm <al>	
endm

LOWORD macro a
	mov eax, a
	and eax, 0FFFFh
	exitm <ax>	
endm

HIWORD macro a
	mov eax, a
	and eax, 0FFFF0000h
	shr eax, 16
	exitm <ax>	
endm

RGB macro red, green, blue
	xor eax, eax
	mov al, blue
	shl eax, 8
	mov al, green
	shl eax, 8
	mov al, red
	exitm <eax>
endm
      
enum MACRO enumname, initCount, parmlist:VARARG
 LOCAL count
 count = initCount
 enumname typedef byte
 FOR parm, <parmlist>
  parm = count
  count = count + 1
 ENDM
ENDM

L MACRO sText:REQ 
LOCAL str, chr, flag 
str TEXTEQU < > 
flag TEXTEQU <.> 
FORC chr, <&sText>  
   IFDIF flag, <\> 
      IFDIF str, < > 
         str CATSTR str, <,> 
      ENDIF 
   ENDIF 
   IFDIF flag, <\> 
      IFIDN <&chr>, <\> 
         flag CATSTR <\> 
      ELSE 
         str CATSTR str, <">, <&chr>, <"> 
      ENDIF 
   ELSE 
      flag CATSTR <X>         
      IFIDN <&chr>, <|> 
         str CATSTR str, <"!!"> 
         flag CATSTR < > 
      ENDIF        
      IFIDN <&chr>, <n> 
         str CATSTR str, <13,10> 
         flag CATSTR < > 
      ENDIF 
      IFIDN <&chr>, <0> 
         str CATSTR str, <0> 
         flag CATSTR < > 
      ENDIF        
      IFIDN <&flag>, <X>  
         str CATSTR str, <">, <&chr>, <"> 
      ENDIF 
      flag CATSTR < > 
   ENDIF 
ENDM 
EXITM str 
ENDM

Swap16$ macro s
	push ebx
	xor eax, eax
	mov ax, s
	and ax, 00FFh
	shl eax, 8
	xor ebx, ebx
	mov bx, s
	shr bx, 8
	and bx, 00FFh
	or ax, bx      
    pop ebx
    exitm <ax>
endm

Swap32$ macro s
	push ebx
	xor eax, eax
	mov eax, s
	and eax, 0FF000000h
	shr eax, 24
	xor ebx, ebx
	mov ebx, s
	and ebx, 00FF0000h
	shr ebx, 8	
	or eax, ebx
	mov ebx, s
	and ebx, 0000FF00h
	shl ebx, 8
	or eax, ebx
	mov ebx, s
	and ebx, 000000FFh
	shl ebx, 24
	or eax, ebx	      
    pop ebx
    exitm <eax>
endm

StrToBstr$ MACRO lpStrBuff
	LOCAL bstr
	LOCAL dwBuffSize
	
	.data
		bstr BSTR 0
		dwBuffSize DWORD 0		
	.code	
	invoke lstrlen, lpStrBuff
	.if eax != 0
		shl eax, 1
		mov dwBuffSize, eax
		inc eax			
		invoke SysAllocStringByteLen, 0, eax
		mov bstr, eax
		Invoke MultiByteToWideChar, CP_ACP, 0, lpStrBuff, -1, bstr, dwBuffSize
		mov eax, bstr		
	.endif					
	EXITM <eax>
ENDM

BstrToStr$ MACRO bstr  
	LOCAL pszBuff
	LOCAL lenBuff
	
	.data
		pszBuff	DWORD 0
		lenBuff DWORD 0
	.code
	invoke WideCharToMultiByte, CP_ACP, 0, bstr, -1, pszBuff, 0, NULL, NULL
	.if eax > 0
		mov lenBuff, eax
		invoke GlobalAlloc, GPTR, eax				
		mov pszBuff, eax
		invoke WideCharToMultiByte, CP_ACP, 0, bstr, -1, pszBuff, lenBuff, NULL, NULL
		mov eax, pszBuff
	.endif
	EXITM <eax>			
ENDM

FreeBstr$ MACRO bstr
	invoke SysFreeString, bstr   		
	mov bstr, NULL
ENDM

PosStr$ MACRO pStr, pSubStr
	LOCAL dwStrLen
	LOCAL dwSubStrLen
	
	.data
		dwStrLen DWORD 0
		dwSubStrLen DWORD 0
	.code
	push ebx
	push ecx
	push edx
	push esi
	push edi	
	invoke lstrlen, pStr
	mov dwStrLen, eax
	invoke lstrlen, pSubStr
	mov dwSubStrLen, eax
	xor ecx, ecx	
	mov esi, pStr
	dec esi	
	dec esi
@@Next:	
	inc esi
	inc ecx	
	.if ecx <= dwStrLen
		xor edx, edx
		mov edi, pSubStr
		dec edi		
	@@Scan:		
		inc edx
		.if edx <= dwSubStrLen			
			mov al, [esi + edx]			
			mov bl, [edi + edx] 			 
			.if al == bl
				.if edx == dwSubStrLen
					mov eax, ecx
					jmp @@Exit
				.else
					jmp @@Scan
				.endif				
			.else
				jmp @@Next		
			.endif
		.else 
			jmp @@Next			
		.endif		
	.else
		xor eax, eax	
	.endif	
@@Exit:	
	pop edi
	pop esi
	pop edx
	pop ecx
	pop ebx				
	EXITM <eax>
ENDM

DeleteStr$ MACRO pStr, dwIndex, dwCount
	LOCAL dwStrLen		
	
	.data
		dwStrLen DWORD 0
	.code
	push ebx	
	push esi
	push edi	
	invoke lstrlen, pStr
	mov dwStrLen, eax	
	mov ebx, dwIndex
	add ebx, dwCount
	dec ebx
	.if (dwIndex <= eax) && (dwIndex > 0) && (ebx <= eax)
		mov esi, pStr		
		add esi, dwIndex
		dec esi
		mov edi, esi
		add edi, dwCount
		sub dwStrLen, ebx
	@@:	
		.if dwStrLen > 0
			mov al, [edi]
			mov [esi], al
			inc esi
			inc edi
			dec dwStrLen
			jmp @B	
		.endif 	
		mov byte ptr [esi], 0
		mov eax, pStr
	.else
		mov eax, 0	
	.endif
	pop edi
	pop esi	
	pop ebx		
	EXITM <eax>
ENDM 

CopyStr$ MACRO pDestStr, pSrcStr, dwIndex, dwCount
	.code
	push ebx	
	push esi
	push edi	
	invoke lstrlen, pSrcStr		
	mov ebx, dwIndex
	add ebx, dwCount
	dec ebx
	.if (dwIndex <= eax) && (dwIndex > 0) && (ebx <= eax)
		mov esi, pSrcStr		
		add esi, dwIndex
		dec esi
		mov edi, pDestStr		
		mov ebx, dwCount
	@@:	
		.if ebx > 0
			mov al, [esi]
			mov [edi], al
			inc esi
			inc edi
			dec ebx
			jmp @B	
		.endif 	
		mov byte ptr [edi], 0
		mov eax, pDestStr
	.else
		mov eax, 0	
	.endif
	pop edi
	pop esi	
	pop ebx	
	EXITM <eax>
ENDM