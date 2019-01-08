;----------------------------------------------------------------------------------------
; Public Masm32 Library
;
; Copyright 2007 Veria Kalantary
; veria.kalantary@gmail.com
; https://github.com/veriak
;
;----------------------------------------------------------------------------------------

method0Proto		typedef proto :DWORD
method1Proto    	typedef proto :DWORD
method2Proto    	typedef proto :DWORD, :DWORD
method3Proto    	typedef proto :DWORD, :DWORD, :DWORD
method4Proto    	typedef proto :DWORD, :DWORD, :DWORD, :DWORD
method5Proto    	typedef proto :DWORD, :DWORD, :DWORD, :DWORD, :DWORD
method6Proto    	typedef proto :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD
method7Proto    	typedef proto :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD
method8Proto    	typedef proto :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD
method9Proto    	typedef proto :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD
method10Proto   	typedef proto :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD
method11Proto   	typedef proto :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD,    :DWORD
method12Proto   	typedef proto :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD,    :DWORD, :DWORD
method13Proto   	typedef proto :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD,    :DWORD, :DWORD, :DWORD
method14Proto   	typedef proto :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD,    :DWORD, :DWORD, :DWORD, :DWORD
method15Proto   	typedef proto :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD,    :DWORD, :DWORD, :DWORD, :DWORD, :DWORD
method16Proto   	typedef proto :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD,    :DWORD, :DWORD, :DWORD, :DWORD, :DWORD,    :DWORD
method17Proto   	typedef proto :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD,    :DWORD, :DWORD, :DWORD, :DWORD, :DWORD,    :DWORD, :DWORD
method18Proto   	typedef proto :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD,    :DWORD, :DWORD, :DWORD, :DWORD, :DWORD,    :DWORD, :DWORD, :DWORD
method19Proto   	typedef proto :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD,    :DWORD, :DWORD, :DWORD, :DWORD, :DWORD,    :DWORD, :DWORD, :DWORD, :DWORD
method20Proto   	typedef proto :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD,    :DWORD, :DWORD, :DWORD, :DWORD, :DWORD,    :DWORD, :DWORD, :DWORD, :DWORD

method0         	typedef ptr method0Proto
method1         	typedef ptr method1Proto
method2         	typedef ptr method2Proto
method3         	typedef ptr method3Proto
method4         	typedef ptr method4Proto
method5         	typedef ptr method5Proto
method6         	typedef ptr method6Proto
method7         	typedef ptr method7Proto
method8         	typedef ptr method8Proto
method9         	typedef ptr method9Proto
method10        	typedef ptr method10Proto
method11        	typedef ptr method11Proto
method12        	typedef ptr method12Proto
method13        	typedef ptr method13Proto
method14        	typedef ptr method14Proto
method15        	typedef ptr method15Proto
method16        	typedef ptr method16Proto
method17        	typedef ptr method17Proto
method18        	typedef ptr method18Proto
method19        	typedef ptr method19Proto
method20        	typedef ptr method20Proto

LPPCSTR				typedef ptr LPCSTR
PVARIANT			typedef ptr VARIANT
HRESULT				typedef	DWORD

memcpy 				PROTO	:DWORD, :DWORD, :DWORD
memset 				PROTO	:DWORD, :BYTE, :DWORD
memcmp				PROTO	:DWORD, :DWORD, :DWORD 
stol 				PROTO 	:DWORD, :DWORD, :BYTE
Swap16				PROTO	:WORD
Swap32				PROTO	:DWORD
lstrAllocAndCpy 	PROTO 	:LPPCSTR, :LPCSTR
lstrcpyCRLF 		PROTO 	:LPCSTR, :LPCSTR
lstrcatCRLF 		PROTO 	:LPCSTR, :LPCSTR
ShowMessage 		PROTO	:LPCSTR
ShowErrorMessage 	PROTO	:HANDLE
CompareStructVar 	PROTO	:DWORD, :DWORD, :DWORD
StrToBstr 			PROTO	:LPCSTR
BstrToStr 			PROTO	:BSTR
FreeBstr 			PROTO	:DWORD 
BstrStrCmp 			PROTO	:BSTR, :LPCSTR
SetLength 			PROTO	:DWORD, :DWORD, :DWORD
StrCmp 				PROTO 	:LPCSTR, :LPCSTR, :DWORD
StrPos 				PROTO	:LPCSTR, :LPCSTR
DeleteStr 			PROTO	:LPCSTR, :DWORD, :DWORD
CopyStr 			PROTO	:LPCSTR, :LPCSTR, :DWORD, :DWORD
ByteToStr			PROTO	:DWORD, :DWORD, :LPCSTR
HexStr 				PROTO	:DWORD, :DWORD
Swap 				PROTO	:DWORD, :DWORD
ReversHexStr 		PROTO	:DWORD, :DWORD
Hex2WideStr 		PROTO	:DWORD, :DWORD
NumToStr 			PROTO	:DWORD, :DWORD
memshift 			PROTO	:DWORD, :DWORD, :DWORD, :DWORD
MinMaxElementSearch PROTO	:DWORD, :DWORD, :DWORD, :DWORD
WriteFileCRLF 		PROTO	:HANDLE, :DWORD
Rand 				PROTO	:DWORD, :DWORD
LogErrorMessage 	PROTO	:LPCSTR, :LPCSTR

HandlesList	struct
	dwHandlesCount			dd	?
	pHandles				dd	?
HandlesList ends

.const
	szCR	              	db	13, 0
	szLF	              	db	10, 0
	szCRLF              	db	13, 10, 0
	szDot					db	".", 0
	szVirgol				db	",", 0
	
.data?    
    seh      				dd 	6 dup (?)

.code

memcpy proc uses ecx esi edi ptrSrc:DWORD, ptrDest:DWORD, dwSize:DWORD     
	mov ecx, dwSize 
    mov esi, ptrSrc       
    mov edi, ptrDest
    cld
    rep movsb
    ret
memcpy endp

memset proc uses ecx edi pMem:DWORD, dwVal:BYTE, dwSize:DWORD
    mov edi, pMem
    mov al, dwVal
    mov ecx, dwSize
    cld
    rep stosb 
    ret
memset endp

memcmp proc uses esi edi ecx p1:DWORD, p2:DWORD, dwSize:DWORD
	mov esi, p1
	mov edi, p2
	mov ecx, dwSize
	repz cmpsb
	jz @F	
	mov eax, 1
	ret 
@@:	
	mov eax, 0
	ret
memcmp endp

stol proc uses ebx ecx edi lpMem:DWORD, dwSize:DWORD, chr:BYTE
    mov edi, lpMem
    mov ebx, edi
    mov al, 0
    mov ecx, dwSize
    repne scasb
    std
    mov al, chr
    mov ecx, edi
    sub ecx, ebx
    repne scasb
    inc edi
    cld
    mov eax, edi
    ret
stol endp 

Swap16 proc uses ebx s:WORD
	xor eax, eax
	mov ax, s
	and ax, 00FFh
	shl eax, 8
	xor ebx, ebx
	mov bx, s
	shr bx, 8
	and bx, 00FFh
	or ax, bx          
    ret
Swap16 endp

Swap32 proc uses ebx s:DWORD
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
    ret
Swap32 endp

lstrcpyCRLF proc lpString1:LPCSTR, lpString2:LPCSTR
	invoke lstrcpy, lpString1, lpString2
	invoke lstrcat, lpString1, addr szCRLF	
	ret
lstrcpyCRLF endp

lstrcatCRLF proc lpString1:LPCSTR, lpString2:LPCSTR
	invoke lstrcat, lpString1, lpString2
	invoke lstrcat, lpString1, addr szCRLF	
	ret
lstrcatCRLF endp

lstrAllocAndCpy proc lppszDest:LPPCSTR, lpszSrc:LPCSTR
	invoke lstrlen, lpszSrc
    invoke GlobalAlloc, GPTR, eax
    mov ebx, lppszDest    
    mov [ebx], eax        
    invoke lstrcpy, dword ptr [ebx], lpszSrc 	
	ret
lstrAllocAndCpy endp

ShowMessage proc lpMessage:LPSTR
	pushad	
	invoke MessageBox, 0, lpMessage, StrM("Information"), MB_OK or MB_ICONINFORMATION
	popad
	ret
ShowMessage endp

ShowErrorMessage proc uses ebx ecx edx hDlg:DWORD
	LOCAL pErrorMessage: DWORD
    invoke GetLastError	
	mov ebx, eax
	invoke FormatMessage, FORMAT_MESSAGE_ALLOCATE_BUFFER or FORMAT_MESSAGE_FROM_SYSTEM, NULL, ebx,\
					0, addr pErrorMessage, 0, 0
	invoke MessageBox, hDlg, pErrorMessage, NULL, MB_OK
	invoke LocalFree, pErrorMessage 
	ret
ShowErrorMessage endp

CompareStructVar proc uses esi edi ecx pStructVarA: DWORD, pStructVarB: DWORD, dwSize: DWORD			
	mov esi, pStructVarA
	mov edi, pStructVarB
	mov ecx, dwSize
@@:
	mov eax, dword ptr [esi]
	add esi, 4
	sub eax, dword ptr [edi]
	jnz @F
	add edi, 4
	sub ecx, 4	
	cmp ecx, 0
	jne @B	
	xor eax, eax	
@@:
	ret
CompareStructVar endp

StrToBstr proc uses ecx edx lpStrBuff:LPCSTR
	LOCAL bstr: DWORD
	LOCAL dwBuffSize: DWORD
		
	invoke lstrlen, lpStrBuff
	.if eax
		shl eax, 1
		mov dwBuffSize, eax
		inc eax			
		invoke SysAllocStringByteLen, 0, eax
		mov bstr, eax
		invoke MultiByteToWideChar, CP_ACP, 0, lpStrBuff, -1, bstr, dwBuffSize
		mov eax, bstr		
	.endif					
	ret
StrToBstr endp

BstrToStr proc uses ecx edx bs:BSTR  
	LOCAL pszBuff: DWORD
	LOCAL lenBuff: DWORD		
	invoke WideCharToMultiByte, CP_ACP, 0, bs, -1, pszBuff, 0, NULL, NULL
	.if eax > 0
		mov lenBuff, eax
		invoke GlobalAlloc, GPTR, eax				
		mov pszBuff, eax
		invoke WideCharToMultiByte, CP_ACP, 0, bs, -1, pszBuff, lenBuff, NULL, NULL
		mov eax, pszBuff
	.endif
	ret			
BstrToStr endp

FreeBstr proc uses ecx edx pBstr:DWORD
	mov eax, pBstr
	mov eax, [eax]
	invoke SysFreeString, eax
	mov eax, pBstr		  
	m2m [eax], NULL
	ret
FreeBstr endp

BstrStrCmp proc uses ebx pbstr1:BSTR, lpstr:LPCSTR
	LOCAL bstr2: BSTR
	invoke StrToBstr, lpstr
    mov bstr2, eax   
    mov ebx, pbstr1
    invoke lstrcmpW, dword ptr [ebx], bstr2	
    push eax
    invoke FreeBstr, pbstr1
    invoke FreeBstr, addr bstr2
    pop eax	
	ret
BstrStrCmp endp 

SetLength proc uses ebx ecx edx ppBuff:DWORD, dwElementSize:DWORD, dwCount:DWORD
	LOCAL hHeap: DWORD
	LOCAL dwSize: DWORD
	LOCAL pBuff: DWORD		
	invoke GetProcessHeap
	mov hHeap, eax
	mov ebx, ppBuff
	m2m pBuff, dword ptr [ebx]	
	.if dwCount == 0 
		invoke HeapFree, hHeap, NULL, pBuff
		mov dword ptr [ebx], NULL 		
	.else
		mov eax, dwCount
		mul dwElementSize
		mov dwSize, eax	
		.if pBuff == NULL
			invoke HeapAlloc, hHeap, HEAP_ZERO_MEMORY, dwSize
		.else
			invoke HeapReAlloc, hHeap, HEAP_ZERO_MEMORY, pBuff, dwSize	
		.endif					
		mov [ebx], eax				 
	.endif 	
	ret
SetLength endp 

StrCmp proc uses ecx esi edi pString1:LPCSTR, pString2:LPCSTR, dwCmpLen:DWORD	
	mov esi, pString1
	mov edi, pString2
	mov ecx, dwCmpLen
	repz cmpsb
	jz @F	
	mov eax, 1
	ret 
@@:	
	mov eax, 0
	ret
StrCmp endp

PosStr proc uses ebx ecx edx esi edi _pStr:LPCSTR, _pSubStr:LPCSTR
	LOCAL pStr: LPVOID
	LOCAL pSubStr: LPVOID	
	LOCAL dwStrLen: DWORD
	LOCAL dwSubStrLen: DWORD
		
	invoke lstrlen, _pStr
	mov dwStrLen, eax
	inc eax
	invoke GlobalAlloc, GPTR, eax
	mov pStr, eax
	
	invoke lstrlen, _pSubStr
	mov dwSubStrLen, eax	
	inc eax
	invoke GlobalAlloc, GPTR, eax
	mov pSubStr, eax
	
	mov esi, _pStr
	mov edi, pStr
	xor ecx, ecx
	.while ecx < dwStrLen
		mov al, byte ptr [esi]		
		.if al >= 'A'
        	.if al <= 'Z'
            	add al, 32
          	.endif
        .endif
        mov byte ptr [edi], al
        inc ecx
        inc esi
        inc edi
    .endw    
    
	mov esi, _pSubStr
	mov edi, pSubStr
	xor ecx, ecx
	.while ecx < dwSubStrLen
		mov al, byte ptr [esi]		
		.if al >= 'A'
        	.if al <= 'Z'
            	add al, 32
          	.endif
        .endif
        mov byte ptr [edi], al
        inc ecx
        inc esi
        inc edi
    .endw    
	 
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
					mov ebx, ecx
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
		xor ebx, ebx	
	.endif	
@@Exit:
	invoke GlobalFree, pStr
	invoke GlobalFree, pSubStr
	mov eax, ebx	
	ret
PosStr endp

DeleteStr proc uses ebx esi edi pStr:LPCSTR, dwIndex:DWORD, dwCount:DWORD
	LOCAL dwStrLen: DWORD		
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
	ret
DeleteStr endp

CopyStr proc uses ebx esi edi pDestStr:LPCSTR, pSrcStr:LPCSTR, dwIndex:DWORD, dwCount:DWORD
	LOCAL dwSrcStrLen: DWORD		
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
	ret
CopyStr endp 

ByteToStr proc uses ecx esi edi Len:DWORD, pArray:DWORD, pStr:LPCSTR
	mov	ecx, Len
	mov esi, pArray
	mov edi, pStr	
@@:
	mov al, byte ptr [esi]
	and al, 0F0h
	shr al, 4
	.if al <= 9	
		add al, "0"
		mov	byte ptr [edi], al
	.else
		sub	al, 10
		add al, "A"
		mov	byte ptr [edi], al
	.endif
	inc	edi
	mov	al, byte ptr [esi]
	and	al, 0Fh
	.if al <= 9	
		add al,"0"
		mov	byte ptr [edi], al
	.else
		sub	al, 10
		add al, "A"
		mov	byte ptr [edi], al
	.endif
	inc	edi
	inc	esi	
	dec	ecx
	cmp ecx, 0
	jnz @B	
	mov	byte ptr [edi], 0			
	xor	eax, eax
	ret	
ByteToStr endp

HexStr proc uses esi edi ecx edx pstr:DWORD, pstrlen:DWORD
    mov eax, pstrlen
    mov ecx, 2
    mul ecx
    inc eax
    invoke GlobalAlloc, GPTR, eax
    mov edi, eax
    mov esi, pstr    
    push edi            
WriteHex:
    xor eax, eax
    lodsb
    invoke wsprintf, edi, StrM('%02X'), eax    
    add edi, 2
    dec pstrlen
    jnz WriteHex
    pop eax
    ret    
HexStr endp

ReversHexStr proc uses esi edi ebx ecx edx pstr:DWORD, pstrlen:DWORD
	LOCAL temp[2]:BYTE
	LOCAL flag:DWORD
	
	mov eax, pstrlen
    mov cl, 2
    div cl
    inc eax
    invoke GlobalAlloc, GPTR, eax
    mov edi, eax
    mov esi, pstr
    
    push edi
    mov flag, 0
    
WriteStr:
    xor eax, eax
    lodsb
    mov temp[0], al
    mov temp[1], 0
    cmp al, 'A'
    jne BB
    mov al, 0Ah
    jmp @F
BB:	
	cmp al, 'B'
    jne CC
    mov al, 0Bh
    jmp @F
CC: 
	cmp al, 'C'
    jne @DD
    mov al, 0Ch
    jmp @F
@DD:	
	cmp al, 'D'
    jne EE
    mov al, 0Dh
    jmp @F
EE: 
	cmp al, 'E'
    jne FF
    mov al, 0Eh
    jmp @F
FF:	
	cmp al, 'F'
    jne @NO

    mov al, 0Fh
    jmp @F       
@NO:
	invoke atodw, addr temp
@@: 
	cmp flag, 1
	je @F
	inc flag
	mov bl, al 
	jmp WriteStr   
@@: 
	mov flag, 0
	shl bl, 4
    or al, bl 
    mov byte ptr [edi], al  
    inc edi
    dec pstrlen
    dec pstrlen
    jnz WriteStr
    pop eax
    
	ret
ReversHexStr endp

Hex2WideStr proc uses esi edi ebx ecx pstr:DWORD, pdestlen:DWORD
	LOCAL temp[2]:BYTE
	LOCAL flag:DWORD
	LOCAL pstrlen:DWORD	
	invoke lstrlen, pstr
	mov pstrlen, eax
    mov cl, 2
    div cl
    inc eax
    invoke GlobalAlloc, GPTR, eax
    mov edi, eax
    mov esi, pstr    
    push edi
    mov flag, 0
    xor ebx, ebx    
WriteStr:
    xor eax, eax
    lodsb
    mov temp[0], al
    mov temp[1], 0
    cmp al, 'A'
    jne BB
    mov al, 0Ah
    jmp @F
BB:	
	cmp al, 'B'
    jne CC
    mov al, 0Bh
    jmp @F
CC: 
	cmp al, 'C'
    jne @DD
    mov al, 0Ch
    jmp @F
@DD:	
	cmp al, 'D'
    jne EE
    mov al, 0Dh
    jmp @F
EE: 
	cmp al, 'E'
    jne FF
    mov al, 0Eh
    jmp @F
FF:	
	cmp al, 'F'
    jne @NO
    mov al, 0Fh
    jmp @F       
@NO:
	invoke atodw, addr temp
@@: 			    
	shl bx, 4
    or bx, ax 
	inc flag
    cmp flag, 4
	je @F     
	jmp WriteStr   
@@: 	
    mov word ptr [edi], bx
  	xor ebx, ebx
	mov flag, 0  
    add edi, 2
    sub pstrlen, 4   
    jnz WriteStr        
    pop eax
    mov esi, eax
    sub edi, esi    
    push pdestlen
    pop ebx
    mov dword ptr [ebx], edi
	ret
Hex2WideStr endp

Swap proc uses esi ecx edx ebx lpBuff:DWORD, dwLen:DWORD		
	mov ecx, dwLen
	mov edx, eax
	xor edx, edx
	mov esi, lpBuff 
@@:
	mov bl, byte ptr [esi]	
	inc esi 
	mov bh, byte ptr [esi]
	dec esi	
	mov byte ptr [esi], bh
	inc esi
	mov byte ptr [esi], bl
	add edx, 2
	.if edx < ecx 
		inc esi
		jmp @B
	.endif	
	ret
Swap ENDP

NumToStr proc dwNum:DWORD, lpBuff:DWORD
	local tmpNum[32]:BYTE
	local nf:NUMBERFMT
	invoke wsprintf, addr tmpNum, StrM("%u"), dwNum
	and nf.NumDigits, 0
	and nf.LeadingZero, FALSE
	mov nf.Grouping, 3
	mov nf.lpDecimalSep, offset szDot
	mov nf.lpThousandSep, offset szVirgol
	and nf.NegativeOrder, 0
	invoke GetNumberFormat, LOCALE_USER_DEFAULT, 0, addr tmpNum, addr nf, lpBuff, 32
	ret
NumToStr endp

memshift proc uses esi edi ebx ecx edx lpBuff:DWORD, dwBuffSize:DWORD, dwElementsSize:DWORD, dwShiftDir:DWORD
	LOCAL lpTempBuff: DWORD
	LOCAL dwi: DWORD
		
	invoke GlobalAlloc, GPTR, dwBuffSize
	mov lpTempBuff, eax
	invoke memcpy, lpBuff, lpTempBuff, dwBuffSize	
	mov esi, lpTempBuff 
	mov edi, lpBuff		
	mov ebx, edi		
	.if !dwShiftDir					
		add edi, dwElementsSize					
	.else		
		add ebx, dwBuffSize
		sub ebx, dwElementsSize 					
		add esi, dwElementsSize		
	.endif	
	.if dwElementsSize == 1	
		mov BYTE ptr [ebx], 0
	.elseif dwElementsSize == 2
		mov WORD ptr [ebx], 0
	.elseif dwElementsSize == 4
		mov DWORD ptr [ebx], 0
	.endif			
	mov eax, dwBuffSize
	xor edx, edx
	mov ebx, dwElementsSize
	div ebx
	dec eax
	mov dwi, eax	
	.while dwi > 0				
		.if dwElementsSize == 1
			mov al, BYTE ptr [esi]
			mov BYTE ptr [edi], al			
		.elseif dwElementsSize == 2
			mov ax, WORD ptr [esi]			
			mov WORD ptr [edi], ax			
		.elseif dwElementsSize == 4
			mov eax, DWORD ptr [esi]			
			mov DWORD ptr [edi], eax			
		.endif								
		add esi, dwElementsSize
		add edi, dwElementsSize
		dec dwi		
	.endw			
	invoke GlobalFree, lpTempBuff
	ret
memshift endp

MinMaxElementSearch proc uses esi ebx edx lpBuff:DWORD, dwBuffSize:DWORD, dwElementsSize:DWORD, dwFlag:DWORD
	LOCAL dwi: DWORD			
	xor edx, edx		
	mov eax, dwBuffSize
	mov ebx, dwElementsSize
	div ebx
	mov dwi, eax
	dec dwi
	xor eax, eax
	mov esi, lpBuff
	.if dwElementsSize == 1
		mov al, byte ptr [esi]
	.elseif dwElementsSize == 2
		mov ax, word ptr [esi]
	.elseif dwElementsSize == 4
		mov eax, dword ptr [esi]
	.endif 	  	
	xor ebx, ebx	
	.while dwi > 0		
		add esi, dwElementsSize		
		.if dwElementsSize == 1
			mov bl, byte ptr [esi]
		.elseif dwElementsSize == 2
			mov bx, word ptr [esi]
		.elseif dwElementsSize == 4
			mov ebx, dword ptr [esi]
		.endif 	  		
		.if dwFlag
			.if ebx > eax
				mov eax, ebx
			.endif
		.else
			.if ebx < eax
				mov eax, ebx
			.endif
		.endif					
		dec dwi				
	.endw		
	ret
MinMaxElementSearch endp 

WriteFileCRLF proc hFile:HANDLE, lpBuff:DWORD
	LOCAL dwByteCount: DWORD
	invoke lstrlen, lpBuff
	mov ebx, eax
	invoke WriteFile, hFile, lpBuff, ebx, addr dwByteCount, 0
    invoke WriteFile, hFile, addr szCRLF, 2, addr dwByteCount, 0
	ret
WriteFileCRLF endp

Rand proc uses ecx edx first:DWORD, second:DWORD
    invoke GetTickCount 
    mov ecx, 23         
    mul ecx             
    add eax, 7          
    mov ecx, second     
    sub ecx, first      
    inc ecx             
    xor edx, edx        
    div ecx             
    add edx, first      
    mov eax, edx        
    ret
Rand endp

LogErrorMessage proc uses ebx ecx edx esi edi lpszAppName:LPCSTR, lpszMessage:LPCSTR
	LOCAL tempbuff[512]: BYTE 
	LOCAL pErrorMessage: DWORD
	LOCAL Strings[2]: DWORD
	LOCAL hEventSrc: HANDLE

	invoke GetLastError
	mov ebx, eax	
	invoke wsprintf, addr tempbuff, StrM("%s error: %d"), lpszAppName, ebx		
	invoke FormatMessage, FORMAT_MESSAGE_ALLOCATE_BUFFER or FORMAT_MESSAGE_FROM_SYSTEM, NULL, ebx,\
					0, addr pErrorMessage, 0, 0
	invoke lstrcat, addr tempbuff, pErrorMessage
	invoke LocalFree, pErrorMessage	
	invoke RegisterEventSource, NULL, lpszAppName 
	.if eax	
		mov hEventSrc, eax
		lea ebx, Strings  
		lea eax, tempbuff
		mov (dword ptr [ebx]), eax
		add ebx, sizeof DWORD
		m2m (dword ptr [ebx]), lpszMessage
		invoke ReportEvent, hEventSrc, EVENTLOG_ERROR_TYPE, 0, 0, NULL, 2, 0, addr Strings, NULL
		invoke DeregisterEventSource, hEventSrc 
	.endif	  	
	ret
LogErrorMessage endp