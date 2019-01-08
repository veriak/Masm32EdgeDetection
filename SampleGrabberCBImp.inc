;----------------------------------------------------------------------------------------
;
; Copyright 2007 Veria Kalantary
; veria.kalantary@gmail.com
; https://github.com/veriak
;
;----------------------------------------------------------------------------------------

QueryInterface_SGCB			PROTO :DWORD, :DWORD, :DWORD
AddRef_SGCB               	PROTO :DWORD
Release_SGCB              	PROTO :DWORD
BufferCB					PROTO :DWORD, :REAL8, :DWORD, :DWORD
SampleCB					PROTO :DWORD, :REAL8, :PIMediaSample

FilterColor					PROTO :REAL8, :PIMediaSample

SampleGrabberCBObject struct
	lpVTable	DWORD	0
SampleGrabberCBObject ends

TRGB struct
	bBlue		BYTE	0
	bGreen		BYTE	0
	bRed		BYTE	0	
TRGB ends

.data?
	pBuffer							DWORD					?
	Vih								VIDEOINFOHEADER			<>
	hWnd							DWORD					?
	dwWidth							DWORD					?
	dwHeight						DWORD					?
	dwLeft							DWORD					?
	dwTop							DWORD					?	
	dwPixelsNum						DWORD					?
	
	
.data
	vtSGCB			ISampleGrabberCB		<QueryInterface_SGCB,\
											AddRef_SGCB,\
											Release_SGCB,\
											SampleCB,\
											BufferCB>
	SGCB			SampleGrabberCBObject	<OFFSET vtSGCB> 	

.code
		
QueryInterface_SGCB proc this_:DWORD, pRIID:DWORD,  ppv:DWORD
	LOCAL Match     :DWORD
    LOCAL ppvt      :DWORD
    
    invoke IsEqualGUID, pRIID, addr IID_IUnknown
    mov Match, eax
    invoke IsEqualGUID, pRIID, addr IID_ISampleGrabberCB
    or eax, Match
    .if (eax == TRUE)                     
        mov eax, this_          
        mov edx, ppv
        mov [edx], eax
        mov ppvt, eax
        invoke AddRef_SGCB, ppvt     
        mov eax, S_OK         
        jmp Exit
    .endif        
NoInterface:
    xor eax, eax
    mov edx, ppv 
    mov [edx], eax
    mov eax, E_NOINTERFACE
Exit: 
	ret
QueryInterface_SGCB endp

AddRef_SGCB proc this_:DWORD
	mov eax, 1
	ret
AddRef_SGCB endp

Release_SGCB proc this_:DWORD
	mov eax, 2
	ret
Release_SGCB endp

BufferCB proc this_:DWORD, SampleTime:REAL8, pBuff:DWORD, BufferLen:DWORD
	mov eax, S_OK
	ret
BufferCB endp

SampleCB proc this_:DWORD, SampleTime:REAL8, pMediaSample:PIMediaSample 
	invoke FilterColor, SampleTime, pMediaSample
	mov eax, S_OK
	ret
SampleCB endp

FilterColor proc SampleTime:REAL8, pMediaSample: PIMediaSample
	LOCAL hdc: HDC
	LOCAL Gx: DWORD
	LOCAL Gy: DWORD
	LOCAL pTempBuffer: DWORD	
	LOCAL WidthDetect: DWORD 
	
	pushad
	coinvoke pMediaSample, IMediaSample, GetPointer, addr pBuffer
	
	mov edx, pBuffer
	assume edx: ptr TRGB
	mov ecx, dwPixelsNum
	xor eax, eax
	
@@:	
;RedFilter:	
;	mov [edx].bGreen, al
;	mov [edx].bBlue, al
;
;BlueFilter:
;	mov [edx].bRed, al
;	mov [edx].bGreen, al
;
;GreenFilter:
;	mov [edx].bRed, al
;	mov [edx].bBlue, al

GrayFilter:
	xor eax, eax
	xor ebx, ebx
	mov al, [edx].bRed
	mov bl, [edx].bGreen
	add ax, bx
	mov bl, [edx].bGreen
	add ax, bx
	mov ebx, 3
	div bl
	mov [edx].bRed, al
	mov [edx].bGreen, al
	mov [edx].bBlue, al  	
	add edx, 3
	dec ecx
	jnz @B	

;EdgeFilter:
;	mov eax, dwPixelsNum
;	mov ebx, 3
;	mul ebx
;	mov ebx, eax 
;	invoke GlobalAlloc, GPTR, ebx
;	mov pTempBuffer, eax
;	mov ebx, pTempBuffer
;	assume ebx: ptr TRGB
;	mov edx, pBuffer
;	mov ecx, dwPixelsNum
;	sub ecx, dwWidth
;	sub ecx, dwWidth
;	sub ecx, 3
;	mov WidthDetect, 0
;@@:
;	mov eax, dwWidth
;	sub eax, 2
;	.if WidthDetect==eax
;		add ebx, 6
;		add edx, 6
;		sub ecx, 2
;		mov WidthDetect, 0
;		jmp @B
;	.endif	
;	
;	inc WidthDetect
;	mov Gx, 0
;	mov Gy, 0
;	xor eax, eax
;	mov al, [edx].bRed
;	add Gx, eax
;	sub Gy, eax	 
;	mov al, [edx + 3].bRed
;	add Gx, eax
;	add Gx, eax	
;	mov al, [edx + 6].bRed
;	add Gx, eax
;	add Gy, eax	
;	push edx
;	add edx, dwWidth
;	add edx, dwWidth
;	add edx, dwWidth	
;	mov al, [edx].bRed
;	sub Gy, eax
;	sub Gy, eax
;	mov al, [edx + 6].bRed
;	add Gy, eax
;	add Gy, eax
;	add edx, dwWidth
;	add edx, dwWidth
;	add edx, dwWidth
;	mov al, [edx].bRed
;	sub Gx, eax
;	sub Gy, eax
;	mov al, [edx + 3].bRed
;	sub Gx, eax
;	sub Gx, eax
;	mov al, [edx + 6].bRed
;	sub Gx, eax
;	add Gy, eax	
;	pop edx
;
;	abs Gx
;	abs Gy
;	
;	mov eax, Gx
;	add eax, Gy
;
;	mov esi, dwWidth
;	add esi, dwWidth
;	add esi, dwWidth
;	mov [ebx + esi + 3].bRed, al
;	mov [ebx + esi + 3].bGreen, al
;	mov [ebx + esi + 3].bBlue, al
;	
;	add ebx, 3
;	add edx, 3
;	dec ecx
;	jnz @B
	
EdgeFilter2:
	mov eax, dwPixelsNum
	mov ebx, 3
	mul ebx
	mov ebx, eax 
	invoke GlobalAlloc, GPTR, ebx
	mov pTempBuffer, eax
	mov ebx, pTempBuffer
	assume ebx: ptr TRGB
	mov edx, pBuffer
	mov ecx, dwPixelsNum
	sub ecx, dwWidth
	sub ecx, dwWidth
	sub ecx, 3
	mov WidthDetect, 0
@@:
	mov eax, dwWidth
	sub eax, 2
	.if WidthDetect==eax
		add ebx, 6
		add edx, 6
		sub ecx, 2
		mov WidthDetect, 0
		jmp @B
	.endif	
	
	inc WidthDetect

	mov Gx, 0
	xor eax, eax
	mov al, [edx + 3].bRed
	sub Gx, eax
	push edx
	add edx, dwWidth
	add edx, dwWidth
	add edx, dwWidth	
	mov al, [edx].bRed
	sub Gx, eax
	mov al, [edx + 3].bRed
	add Gx, eax
	add Gx, eax
	add Gx, eax
	add Gx, eax
	mov al, [edx + 6].bRed
	sub Gx, eax
	add edx, dwWidth
	add edx, dwWidth
	add edx, dwWidth
	mov al, [edx + 3].bRed
	sub Gx, eax
	pop edx

	xor eax, eax
	mov esi, Gx
	cmp esi, 0
	jg l1
	mov al, 0
	jmp l2 
l1:
	mov al, 255
l2:		
	
	mov esi, dwWidth
	add esi, dwWidth
	add esi, dwWidth
	mov [ebx + esi + 3].bRed, al
	mov [ebx + esi + 3].bGreen, al
	mov [ebx + esi + 3].bBlue, al
	
	add ebx, 3
	add edx, 3
	dec ecx
	jnz @B

	mov eax, dwPixelsNum
	mov ebx, 3
	mul ebx
	mov ebx, eax 
	mov edx, pTempBuffer
	mov ecx, dwPixelsNum
	sub ecx, dwWidth
	sub ecx, dwWidth
	sub ecx, 3
	mov WidthDetect, 0

@@:
	mov eax, dwWidth
	sub eax, 2
	.if WidthDetect==eax		
		add edx, 6
		sub ecx, 2
		mov WidthDetect, 0
		jmp @B
	.endif	
	
	inc WidthDetect
	mov Gx, 0

	mov eax, 0
	push edx
	add edx, dwWidth
	add edx, dwWidth
	add edx, dwWidth	
	mov al, [edx + 3].bRed
	mov Gx, eax
	pop edx

	.if Gx != 0
		mov Gx, 0
		xor eax, eax		
		mov al, [edx].bRed
		add Gx, eax
		mov al, [edx + 3].bRed
		add Gx, eax
		mov al, [edx + 6].bRed
		add Gx, eax		
		push edx
		add edx, dwWidth
		add edx, dwWidth
		add edx, dwWidth	
		mov al, [edx].bRed
		add Gx, eax
		mov al, [edx + 6].bRed
		add Gx, eax
		add edx, dwWidth
		add edx, dwWidth
		add edx, dwWidth
		mov al, [edx].bRed
		add Gx, eax
		mov al, [edx + 3].bRed
		add Gx, eax
		mov al, [edx + 6].bRed
		add Gx, eax
		.if Gx == 2040
			mov Gx, 255
		.else
			mov Gx, 0	
		.endif
		pop edx
	.else
		mov Gx, 255
	.endif	
	
	mov eax, Gx
	
	mov esi, dwWidth
	add esi, dwWidth
	add esi, dwWidth
	mov [edx + esi + 3].bRed, al
	mov [edx + esi + 3].bGreen, al
	mov [edx + esi + 3].bBlue, al
	
	add edx, 3
	dec ecx
	jnz @B
	
	assume edx: NOTHING
	
	invoke GetDC, hWnd
	mov hdc, eax				
	lea ecx, Vih.bmiHeader
	invoke SetDIBitsToDevice, hdc, dwLeft, dwTop,  dwWidth, dwHeight,
			    0, 0, 0, dwHeight, pTempBuffer, ecx, DIB_RGB_COLORS
	invoke GlobalFree, pTempBuffer		    			    
	popad		    	
	ret
FilterColor endp
