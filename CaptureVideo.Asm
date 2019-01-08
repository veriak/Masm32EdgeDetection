;----------------------------------------------------------------------------------------
;
; Copyright 2007 Veria Kalantary
; veria.kalantary@gmail.com
; https://github.com/veriak
;
;----------------------------------------------------------------------------------------

.386
.model flat, stdcall  
option casemap :none  

include \masm32\include\windows.inc
include \masm32\include\masm32.inc
INCLUDE \masm32\include\kernel32.inc
INCLUDE \masm32\include\user32.inc
include \masm32\include\gdi32.inc
include \masm32\include\comdlg32.inc
include \masm32\include\comctl32.inc
include \masm32\include\oaidl.inc
include \masm32\include\ole32.inc
include \masm32\include\oleaut32.inc
include \masm32\include\advapi32.inc

includelib \masm32\lib\masm32.lib
includelib \masm32\lib\kernel32.lib
includelib \masm32\lib\user32.lib
includelib \masm32\lib\gdi32.lib
includelib \masm32\lib\comdlg32.lib
includelib \masm32\lib\comctl32.lib
includelib \masm32\lib\ole32.lib
includelib \masm32\lib\oleaut32.lib
includelib \masm32\lib\advapi32.lib

include CaptureVideo.inc
include SampleGrabberCBImp.inc

WinMain 				proto 	:HINSTANCE, :HINSTANCE, :LPSTR, :DWORD
MediaStartUp 			proto
MediaCleanUp 			proto
PlayMediaFile 			proto	:DWORD
GetMediaFilePath 		proto 	:DWORD
HandleMediaEvent		proto
PreviewVideo			proto
CaptureVideo			proto
ConnectFilters			proto	:PIGraphBuilder, :PIBaseFilter, :PIBaseFilter
GetUnconnectedPin		proto	:PIBaseFilter, :PPIPin, :BYTE
FreeMediaType 			proto 	:PAM_MEDIA_TYPE
GrabAFrame				proto
SaveFrame				proto
	
.const
	WM_GRAPHNOTIFY  	EQU	WM_APP + 1
	IDM_EXIT			EQU	1001
	IDM_PREVIEW			EQU	1010
	IDM_CAPTURE			EQU	1011	
	IDM_GRABAFRAME		EQU	1012
	IDM_SAVEFRAME		EQU	1013
	IDM_FRAMEPROCESSING	EQU	1014			
					

.data
	szMainMenu						db	"MainMenu", 0
	szIoEJaamEJamMediaPlayerClass	db	"IoEJaamEJamMediaPlayerClass", 0
	FilterString            		db  "*.*",0,"*.*",0,0	
	szwSourceFilter					WORD L(<Source>)
	szwGrabberFilter				WORD L(<Grabber>)
	szwNullRenderer					WORD L(<NullRenderer>)	
	
	
.data?
	hInstance						DWORD	?		
	hIcon 							DWORD 	?
	hMainMenu						DWORD	?
    szfilepath						db	MAX_PATH dup (?)
    dwRW							DWORD	?
    dwRH							DWORD	?
    ofn								OPENFILENAME	<?>
      	    	
	pGraphBuilder					PIGraphBuilder			? 
 	pMediaControl					PIMediaControl 			?
 	pVideoWindow					PIVideoWindow			?
 	pBasicVideo						PIBasicVideo			?
 	pMediaEvent						PIMediaEventEx			?
 	pCaptureGraphBuilder			PICaptureGraphBuilder2	?
 	pSource							PIBaseFilter			?	
    pCapture						PIBaseFilter			?     
    pGrabberFilter					PIBaseFilter			?
    pGrabber						PISampleGrabber			?   
    pNullRenderer					PIBaseFilter			?	 									 		
	
	szfiltername					db	MAX_PATH		dup (?)
	szwfiltername					db	MAX_PATH * 2	dup (?)
	
	m_MediaType						AM_MEDIA_TYPE			<>
	
	cbBuffer						DWORD					?
	bfh								BITMAPFILEHEADER		<>
	bih								BITMAPINFOHEADER		<>
		
	pGrabberOutPin					PIPin					?
	ThisPinDir						BYTE		    		?	
	
	crect							RECT					<> 					
	
.code

start:
	invoke GetModuleHandle, NULL
	mov	hInstance, eax
	INVOKE LoadMenu, hInstance, addr szMainMenu
    mov hMainMenu, eax
    invoke InitCommonControls	    
	invoke WinMain, hInstance, NULL, NULL, SW_SHOWNORMAL			 
	invoke ExitProcess, 0
		    
WindowProc proc hwnd:HWND, uMsg:UINT, wParam:WPARAM, lParam:LPARAM
	LOCAL hdc: HDC
	LOCAL ps: PAINTSTRUCT	
	
	mov eax, uMsg
	.if eax == WM_CREATE
		push hwnd
		pop hWnd		
		invoke MediaStartUp			
		
    .elseif eax == WM_DESTROY
        invoke MediaCleanUp
        invoke PostQuitMessage, NULL        
        
    .elseif eax == WM_GRAPHNOTIFY
        invoke HandleMediaEvent
	
	.elseif uMsg == WM_COMMAND
		mov eax, wParam
        and eax, 0ffffh		

        .if eax == IDM_EXIT
			invoke SendMessage, hWnd, WM_DESTROY, 0, 0
		
		.elseif eax == IDM_PREVIEW	
			invoke PreviewVideo 
			coinvoke pMediaControl, IMediaControl, Run
			ret
			
		.elseif eax == IDM_CAPTURE			
			invoke CaptureVideo
			coinvoke pMediaControl, IMediaControl, Run
		
		.elseif eax == IDM_GRABAFRAME
			invoke GrabAFrame
		
		.elseif eax == IDM_SAVEFRAME
			invoke SaveFrame
		
		.elseif eax == IDM_FRAMEPROCESSING
			coinvoke pMediaControl, IMediaControl, Run
				
		.endif		
		
	.elseif eax == WM_PAINT
		invoke BeginPaint, hwnd, addr ps
		mov hdc, eax			
		lea ebx, Vih.bmiHeader
		invoke SetDIBitsToDevice, hdc, dwLeft, dwTop, dwWidth, dwHeight,
				    0, 0, 0, dwHeight, pBuffer, ebx, DIB_RGB_COLORS
		invoke EndPaint, hwnd, addr ps   
	.else
        invoke DefWindowProc, hwnd, uMsg, wParam, lParam
        ret
    .endif
    xor eax,eax
    ret 
WindowProc endp

WinMain proc hInst:HINSTANCE, hPrevInst:HINSTANCE, CmdLine:LPSTR, CmdShow:DWORD	
	LOCAL wc:WNDCLASSEX
    LOCAL msg:MSG        
    LOCAL hwnd:HWND  
    LOCAL tempBuffer:DWORD          
        
    mov wc.cbSize, SIZEOF WNDCLASSEX
    mov wc.style, CS_HREDRAW OR CS_VREDRAW
    mov wc.lpfnWndProc, offset WindowProc
    mov wc.cbClsExtra, NULL
    mov wc.cbWndExtra, NULL
    push hInstance
    pop wc.hInstance
    invoke GetStockObject, BLACK_BRUSH
    mov wc.hbrBackground, eax       
    mov wc.lpszMenuName, offset szMainMenu 
    mov wc.lpszClassName, offset szIoEJaamEJamMediaPlayerClass 
    ;invoke LoadIcon, hInstance, StrM("IDI_ICON")
    mov eax, NULL
    mov hIcon, eax
    mov wc.hIcon, eax    
    mov wc.hIconSm, eax
    invoke LoadCursor, NULL, IDC_ARROW
    mov wc.hCursor, eax
    invoke RegisterClassEx, addr wc   
    invoke GetSystemMetrics, SM_CXFULLSCREEN
    sub eax, 20
    mov dwRW, eax
    invoke GetSystemMetrics, SM_CYFULLSCREEN
    sub eax, 20           
    mov dwRH, eax     
    add eax, 20 
    invoke CreateWindowEx, NULL,\
                    addr szIoEJaamEJamMediaPlayerClass,\
                    StrM("IoE Jaam E Jam Media Player"),\
                    WS_SYSMENU or WS_MINIMIZEBOX,\
                    10,\
                    10,\
                    dwRW,\
                    eax,\
                    NULL,\
                    NULL,\
                    hInstance,\
                    NULL
    
    mov hwnd, eax            
    invoke ShowWindow, hwnd, SW_SHOWNORMAL
    invoke UpdateWindow, hwnd       
                                            
    .while TRUE
        invoke GetMessage, addr msg, NULL, 0, 0
        .break .if (!eax)         
	    invoke TranslateMessage, addr msg
    	invoke DispatchMessage, addr msg    	   	     	
    .endw
    mov eax, msg.wParam	
    ret 
WinMain ENDP

MediaStartUp proc	
	LOCAL pCreateDevEnum: PICreateDevEnum
 	LOCAL pEnumMoniker:	PIEnumMoniker
 	LOCAL pMoniker:	PIMoniker
	
	invoke CoInitialize, NULL           	   	   	
   	invoke CoCreateInstance, addr CLSID_CaptureGraphBuilder2, NULL, CLSCTX_INPROC_SERVER, 
       	                addr IID_ICaptureGraphBuilder2, addr pCaptureGraphBuilder
	invoke CoCreateInstance, addr CLSID_FilterGraph, NULL, CLSCTX_INPROC_SERVER, 
       	                addr IID_IGraphBuilder, addr pGraphBuilder       	                
    coinvoke pCaptureGraphBuilder, ICaptureGraphBuilder2, SetFiltergraph, pGraphBuilder
        
	invoke CoCreateInstance, addr CLSID_SystemDeviceEnum, NULL, CLSCTX_INPROC_SERVER, 
       	                addr IID_ICreateDevEnum, addr pCreateDevEnum
	coinvoke pCreateDevEnum, ICreateDevEnum, CreateClassEnumerator, addr CLSID_VideoInputDeviceCategory, addr pEnumMoniker, 0		
	coinvoke pEnumMoniker, IEnumMoniker, Next, 1, addr pMoniker, NULL			
	coinvoke pMoniker, IMoniker, BindToObject, 0, 0, addr IID_IBaseFilter, addr pSource			

	coinvoke pGraphBuilder, IGraphBuilder, AddFilter, pSource, addr szwSourceFilter		
			
	invoke CoCreateInstance, addr CLSID_SampleGrabber, NULL, CLSCTX_INPROC_SERVER, 
						addr IID_ISampleGrabber, addr pGrabber
	coinvoke pGrabber, ISampleGrabber, QueryInterface, addr IID_IBaseFilter, addr pGrabberFilter
	coinvoke pGraphBuilder, IGraphBuilder, AddFilter, pGrabberFilter, addr szwGrabberFilter	    	

	coinvoke pGraphBuilder, IGraphBuilder, QueryInterface, addr IID_IMediaControl, addr pMediaControl
   	coinvoke pGraphBuilder, IGraphBuilder, QueryInterface, addr IID_IVideoWindow, addr pVideoWindow
   	coinvoke pGraphBuilder, IGraphBuilder, QueryInterface, addr IID_IBasicVideo, addr pBasicVideo
   	coinvoke pGraphBuilder, IGraphBuilder, QueryInterface, addr IID_IMediaEventEx, addr pMediaEvent
	
;	invoke ConnectFilters, pGraphBuilder, pSource, pGrabberFilter					
;	coinvoke pGrabber, ISampleGrabber, SetOneShot, TRUE
;	coinvoke pGrabber, ISampleGrabber, SetBufferSamples, TRUE
;	coinvoke pVideoWindow, IVideoWindow, put_AutoShow, FALSE	
		
	coinvoke pGrabber, ISampleGrabber, SetOneShot, FALSE
	coinvoke pGrabber, ISampleGrabber, SetBufferSamples, FALSE
	coinvoke pGrabber, ISampleGrabber, SetCallback, offset SGCB, 0 
	
	invoke CoCreateInstance, addr CLSID_NullRenderer, NULL, CLSCTX_INPROC_SERVER, 
						addr IID_IBaseFilter, addr pNullRenderer
	coinvoke pGraphBuilder, IGraphBuilder, AddFilter, pNullRenderer, addr szwNullRenderer						
	
	invoke memset, addr m_MediaType, 0, SizeOf GUID	
	invoke memcpy, addr MEDIATYPE_Video, addr m_MediaType.majortype, SizeOf GUID
	invoke memcpy, addr MEDIASUBTYPE_RGB24, addr m_MediaType.subtype, SizeOf GUID	
	coinvoke pGrabber, ISampleGrabber, SetMediaType, addr m_MediaType
	
	coinvoke pCaptureGraphBuilder, ICaptureGraphBuilder2, RenderStream, addr PIN_CATEGORY_PREVIEW,\ 
						addr MEDIATYPE_Video, pSource, pGrabberFilter, pNullRenderer
							   
	coinvoke pGrabber, ISampleGrabber, GetConnectedMediaType, addr m_MediaType	
	lea ebx, m_MediaType.formattype			
	invoke CompareStructVar, ebx, addr FORMAT_VideoInfo, SizeOf GUID
	.if (eax == 0) && (m_MediaType.cbFormat >= sizeof(VIDEOINFOHEADER)) && (m_MediaType.pbFormat != NULL)				
    	invoke memcpy, m_MediaType.pbFormat, addr Vih, Sizeof VIDEOINFOHEADER 
	.else	
		mov eax, VFW_E_INVALIDMEDIATYPE
		ret 
	.endif	
	
;	coinvoke pMediaControl, IMediaControl, Run

	push Vih.bmiHeader.biWidth
	pop dwWidth
	push Vih.bmiHeader.biHeight
	pop dwHeight
	mov eax, dwWidth
	mul dwHeight
	mov dwPixelsNum, eax
	invoke GetClientRect, hWnd, addr crect     
    mov edx, crect.right
    sub edx, dwWidth
    shr edx, 1
    mov ecx, crect.bottom
    sub ecx, dwHeight
    shr ecx, 1        		
	mov dwLeft, edx
	mov dwTop, ecx			
	ret
MediaStartUp endp

ConnectFilters proc pGraph: PIGraphBuilder, pSrcFilter: PIBaseFilter, pDestFilter: PIBaseFilter
	LOCAL pIn: PIPin
	LOCAL pOut:	PIPin
		
	.if (pGraph == NULL) || (pSrcFilter == NULL) || (pDestFilter == NULL)
		mov eax, E_POINTER
		ret
	.endif	
	invoke GetUnconnectedPin, pSrcFilter, addr pOut, PINDIR_OUTPUT		
	.if eax != S_OK
		mov eax, E_FAIL
		ret
	.endif		
	invoke GetUnconnectedPin, pDestFilter, addr pIn, PINDIR_INPUT	
	.if eax != S_OK
		mov eax, E_FAIL
		ret
	.endif	
	coinvoke pGraph, IGraphBuilder, Connect, pOut, pIn	
	coinvoke pIn, IPin, Release
	coinvoke pOut, IPin, Release
	ret 
ConnectFilters endp

GetUnconnectedPin proc pFilter: PIBaseFilter, ppPin: PPIPin, PinDir: BYTE 	
	LOCAL pEnum: PIEnumPins
	LOCAL pPin: PIPin	
	LOCAL pTmp:	PIPin
						
	coinvoke pFilter, IBaseFilter, EnumPins, addr pEnum
	.if eax != S_OK    	
    	ret
    .endif      
    .while TRUE     	    	
    	coinvoke pEnum, IEnumPins, Next, 1, addr pPin, NULL     	   	    	    	    	    	
    	.if eax == S_OK
    		coinvoke pPin, IPin, QueryDirection, addr ThisPinDir    		
    		xor ebx, ebx
    		mov bl, ThisPinDir           	     	
        	.if bl == ThisPinDir     				            		   		              				    		
 				coinvoke pPin, IPin, ConnectedTo, addr pTmp		 				 				
            	.if eax == S_OK              			   
            		coinvoke pTmp, IPin, Release             		          		           		
            	.else                 	                    	            			            		
					coinvoke pEnum, IEnumPins, Release               		          			
            		mov ebx, ppPin
                	mov ecx, pPin 
                	mov PIPin ptr [ebx], ecx                		
                	mov eax, S_OK                 	               	
					ret
				.endif				
			.endif															  			
			coinvoke pPin, IPin, Release			
		.else			
			.break	  
		.endif	                                               
	.endw    
    coinvoke pEnum, IEnumPins, Release                 
    mov eax, E_FAIL       	 
    ret      
GetUnconnectedPin endp

MediaCleanUp proc
	LOCAL evCode: DWORD	
	coinvoke pVideoWindow, IVideoWindow, put_Visible, FALSE
	coinvoke pVideoWindow, IVideoWindow, put_Owner,	NULL
	coinvoke pMediaControl, IMediaControl, Stop
    coinvoke pMediaEvent, IMediaEventEx, WaitForCompletion, INFINITE, addr evCode
    coinvoke pGraphBuilder, IGraphBuilder, RemoveFilter, pSource
    coinvoke pGraphBuilder, IGraphBuilder, RemoveFilter, pGrabberFilter
    coinvoke pGraphBuilder, IGraphBuilder, RemoveFilter, pNullRenderer    
    coinvoke pSource, IBaseFilter, Release
    coinvoke pGrabberFilter, IBaseFilter, Release
    coinvoke pNullRenderer, IBaseFilter, Release
	coinvoke pMediaEvent, IMediaEventEx, Release
	coinvoke pBasicVideo, IBasicVideo, Release
	coinvoke pVideoWindow, IVideoWindow, Release
	coinvoke pMediaControl, IMediaControl, Release	
	.if pCapture
		coinvoke pCapture, IBaseFilter, Release
	.endif		
    coinvoke pGraphBuilder, IGraphBuilder, Release
    invoke CoUninitialize	
	ret
MediaCleanUp endp

GetMediaFilePath proc lpszFilePath:DWORD		
	mov ofn.lStructSize, SIZEOF ofn
    push hWnd
    pop ofn.hWndOwner
    push hInstance
    pop ofn.hInstance
    mov ofn.lpstrFilter, OFFSET FilterString
    push lpszFilePath
    pop ofn.lpstrFile 
    mov ofn.nMaxFile, MAX_PATH
    invoke GetOpenFileName, ADDR ofn    
	ret
GetMediaFilePath endp

PlayMediaFile proc lpszFilePath:DWORD	
	LOCAL szwfilename[MAX_PATH * 2]: BYTE
	
    invoke lstrlen, lpszFilePath 
    invoke MultiByteToWideChar, CP_ACP, 0, lpszFilePath, -1, addr szwfilename, eax    
    coinvoke pGraphBuilder, IGraphBuilder, RenderFile, addr szwfilename, NULL            
    coinvoke pVideoWindow, IVideoWindow, put_Owner, hWnd   
    coinvoke pVideoWindow, IVideoWindow, put_WindowStyle, WS_CHILD or WS_CLIPSIBLINGS
    invoke GetClientRect, hWnd, addr crect
    coinvoke pBasicVideo, IBasicVideo, GetVideoSize, addr dwWidth, addr dwHeight 
    mov ebx, crect.right
    sub ebx, dwWidth
    shr ebx, 1
    mov ecx, crect.bottom
    sub ecx, dwHeight
    shr ecx, 1  
    coinvoke pVideoWindow, IVideoWindow, SetWindowPosition, ebx, ecx, dwWidth, dwHeight
    coinvoke pMediaEvent, IMediaEventEx, SetNotifyWindow, hWnd, WM_GRAPHNOTIFY, 0
    coinvoke pMediaControl, IMediaControl, Run		
	ret
PlayMediaFile endp

HandleMediaEvent proc
	LOCAL evCode, param1, param2: DWORD
    
    .while TRUE
    	coinvoke pMediaEvent, IMediaEventEx, GetEvent, addr evCode, addr param1, addr param2, 0
    	.if eax == 0     
        	coinvoke pMediaEvent, IMediaEventEx, FreeEventParams, evCode, param1, param2
        	mov ebx, evCode
        	.if (ebx == EC_COMPLETE) || (ebx == EC_USERABORT)        	 
            	invoke MediaCleanUp            	            	
            	.break
        	.endif
        .else
        	.break
        .endif 
    .endw	
	ret
HandleMediaEvent endp

PreviewVideo proc        
    coinvoke pCaptureGraphBuilder, ICaptureGraphBuilder2, RenderStream, addr PIN_CATEGORY_PREVIEW, addr MEDIATYPE_Video, pSource, NULL, NULL
	coinvoke pVideoWindow, IVideoWindow, put_Owner, hWnd   
  	coinvoke pVideoWindow, IVideoWindow, put_WindowStyle, WS_CHILD or WS_CLIPSIBLINGS
   	invoke GetClientRect, hWnd, addr crect
   	coinvoke pBasicVideo, IBasicVideo, GetVideoSize, addr dwWidth, addr dwHeight 
   	mov ebx, crect.right
   	sub ebx, dwWidth
   	shr ebx, 1
   	mov ecx, crect.bottom
   	sub ecx, dwHeight
   	shr ecx, 1  
   	coinvoke pVideoWindow, IVideoWindow, SetWindowPosition, ebx, ecx, dwWidth, dwHeight    	    	    								        	                       	                  
	coinvoke pMediaEvent, IMediaEventEx, SetNotifyWindow, hWnd, WM_GRAPHNOTIFY, 0    		
	ret
PreviewVideo endp

CaptureVideo proc
	invoke PreviewVideo 	
    invoke memset, addr szwfiltername, 0, sizeof szwfiltername
    invoke lstrcpy, addr szfiltername, StrM("C:\test.avi")
    invoke lstrlen, addr szfiltername       
    invoke MultiByteToWideChar, CP_ACP, 0, addr szfiltername, -1, addr szwfiltername, eax       
    coinvoke pCaptureGraphBuilder, ICaptureGraphBuilder2, SetOutputFileName, addr MEDIASUBTYPE_Avi, addr szwfiltername, addr pCapture, 0
    coinvoke pCaptureGraphBuilder, ICaptureGraphBuilder2, RenderStream, addr PIN_CATEGORY_CAPTURE, addr MEDIATYPE_Video, pSource, NULL, pCapture    		
	ret
CaptureVideo endp

FreeMediaType proc pmt: PAM_MEDIA_TYPE
	mov ebx, pmt 
	mov ecx, (AM_MEDIA_TYPE ptr [ebx]).cbFormat
    .if ecx != 0
        invoke CoTaskMemFree, (AM_MEDIA_TYPE ptr [ebx]).pbFormat
        mov (AM_MEDIA_TYPE ptr [ebx]).cbFormat, 0
        mov (AM_MEDIA_TYPE ptr [ebx]).pbFormat, NULL
    .endif
    mov ecx, (AM_MEDIA_TYPE ptr [ebx]).pUnk
    .if ecx != NULL        
        coinvoke (AM_MEDIA_TYPE ptr [ebx]).pUnk, IUnknown, Release
        mov (AM_MEDIA_TYPE ptr [ebx]).pUnk, NULL
    .endif
FreeMediaType endp

GrabAFrame proc	
	LOCAL hdc: HDC
	LOCAL evCode: DWORD
	
	coinvoke pGrabber, ISampleGrabber, SetOneShot, TRUE
	
	coinvoke pMediaEvent, IMediaEventEx, WaitForCompletion, INFINITE, addr evCode
	mov cbBuffer, 0
	coinvoke pGrabber, ISampleGrabber, GetCurrentBuffer, addr cbBuffer, NULL
	mov ebx, cbBuffer
	invoke GlobalAlloc, GPTR, cbBuffer
	mov pBuffer, eax
	coinvoke pGrabber, ISampleGrabber, GetCurrentBuffer, addr cbBuffer, pBuffer						
      	 
	invoke memset, addr m_MediaType, 0, SizeOf GUID	 		
	coinvoke pGrabber, ISampleGrabber, GetConnectedMediaType, addr m_MediaType
	lea ebx, m_MediaType.formattype			
	invoke CompareStructVar, ebx, addr FORMAT_VideoInfo, SizeOf GUID
	.if (eax == 0) && (m_MediaType.cbFormat >= sizeof(VIDEOINFOHEADER)) && (m_MediaType.pbFormat != NULL)				
    	invoke memcpy, m_MediaType.pbFormat, addr Vih, Sizeof VIDEOINFOHEADER 
	.else	
		mov eax, VFW_E_INVALIDMEDIATYPE
		ret 
	.endif	
							 					
	invoke GetDC, hWnd
	mov hdc, eax
			
	push Vih.bmiHeader.biWidth
	pop dwWidth
	push Vih.bmiHeader.biHeight
	pop dwHeight
	invoke GetClientRect, hWnd, addr crect     
    mov edx, crect.right
    sub edx, dwWidth
    shr edx, 1
    mov ecx, crect.bottom
    sub ecx, dwHeight
    shr ecx, 1        		
	mov dwLeft, edx
	mov dwTop, ecx
	lea ecx, Vih.bmiHeader
	invoke SetDIBitsToDevice, hdc, dwLeft, dwTop, dwWidth, dwHeight,
			    0, 0, 0, dwHeight, pBuffer, ecx, DIB_RGB_COLORS	
	ret
GrabAFrame endp

SaveFrame proc
	LOCAL dwWritten: DWORD
	LOCAL hFile: DWORD	
		
	invoke memset, addr bih, 0, sizeof bih
	mov bih.biSize, sizeof bih
	push Vih.bmiHeader.biWidth
    pop bih.biWidth
    push Vih.bmiHeader.biHeight
    pop bih.biHeight
    mov bih.biPlanes, 1
    mov bih.biBitCount, 24
    
	invoke CreateFile, StrM("test.bmp"), GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, NULL, NULL
	mov hFile, eax            
    invoke memset, addr bfh, 0, sizeof BITMAPFILEHEADER
    mov bfh.bfType, 'MB'
    mov ebx, cbBuffer
    add ebx, sizeof BITMAPFILEHEADER
    add ebx, sizeof BITMAPINFOHEADER
    mov bfh.bfSize, ebx
    mov ebx, sizeof BITMAPINFOHEADER
    add ebx, sizeof BITMAPFILEHEADER
    mov bfh.bfOffBits, ebx

    mov dwWritten, 0
    invoke WriteFile, hFile, addr bfh, sizeof bfh, addr dwWritten, NULL
   	mov dwWritten, 0
    invoke WriteFile, hFile, addr bih, sizeof bih, addr dwWritten, NULL
	mov dwWritten, 0	        
    invoke WriteFile, hFile, pBuffer, cbBuffer, addr dwWritten, NULL
    invoke CloseHandle, hFile						    								    			 									
	ret
SaveFrame endp

end start