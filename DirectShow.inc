;----------------------------------------------------------------------------------------
; Direct Show Masm32 Library
;
; Copyright 2007 Veria Kalantary
; veria.kalantary@gmail.com
; https://github.com/veriak
;
;----------------------------------------------------------------------------------------

include Com.inc

_vtIFilterGraph MACRO CastName:REQ    
    _vtIUnknown CastName        
    &CastName&_AddFilter     			comethod3   ?
    &CastName&_RemoveFilter 			comethod2   ?
    &CastName&_EnumFilters 				comethod2   ?
    &CastName&_FindFilterByName 		comethod3   ?
    &CastName&_ConnectDirect 			comethod4   ?
    &CastName&_Reconnect 				comethod2   ?
    &CastName&_Disconnect 				comethod2   ?
    &CastName&_SetDefaultSyncSource 	comethod1   ?
ENDM

IFilterGraph STRUCT
    _vtIFilterGraph IFilterGraph
IFilterGraph ENDS

_vtIGraphBuilder MACRO CastName:REQ        
    _vtIFilterGraph CastName    
    &CastName&_Connect 					comethod3   ?
    &CastName&_Render 					comethod2   ?
    &CastName&_RenderFile 				comethod3   ?
    &CastName&_AddSourceFilter 			comethod4   ?
    &CastName&_SetLogFile 				comethod2   ?
    &CastName&_Abort 					comethod1   ?
    &CastName&_ShouldOperationContinue 	comethod1   ?
ENDM

IGraphBuilder STRUCT
    _vtIGraphBuilder IGraphBuilder
IGraphBuilder ENDS

_vtIMediaControl MACRO CastName:REQ
	_vtIDispatch CastName    
    &CastName&_Run 						comethod1   ?
    &CastName&_Pause 					comethod1   ?
    &CastName&_Stop 					comethod1   ?
    &CastName&_StopWhenReady 			comethod1   ?
    &CastName&_GetState 				comethod3   ?
    &CastName&_RenderFile 				comethod2   ?
    &CastName&_AddSourceFilter 			comethod3   ?
    &CastName&_get_FilterCollection 	comethod2   ?
    &CastName&_get_RegFilterCollection 	comethod2   ?
ENDM

IMediaControl STRUCT
    _vtIMediaControl IMediaControl
IMediaControl ENDS

_vtIMediaEvent MACRO CastName:REQ
    _vtIDispatch CastName
    &CastName&_GetEventHandle 			comethod2   ?
    &CastName&_GetEvent 				comethod5   ?
    &CastName&_WaitForCompletion 		comethod3   ?
    &CastName&_CancelDefaultHandling 	comethod2   ?
    &CastName&_RestoreDefaultHandling 	comethod2   ?
    &CastName&_FreeEventParams 			comethod4   ?
ENDM

IMediaEvent STRUCT
    _vtIMediaEvent IMediaEvent
IMediaEvent ENDS

_vtIMediaEventEx MACRO CastName:REQ
    _vtIMediaEvent CastName
    &CastName&_SetNotifyWindow 			comethod4   ?
    &CastName&_SetNotifyFlags 			comethod2   ?
    &CastName&_GetNotifyFlags 			comethod2   ?
ENDM

IMediaEventEx STRUCT
    _vtIMediaEventEx IMediaEventEx
IMediaEventEx ENDS

_vtIMediaPosition MACRO CastName:REQ
    _vtIDispatch CastName    
    &CastName&_get_Duration 			comethod2   ?
    &CastName&_put_CurrentPosition 		comethod2   ?
    &CastName&_get_CurrentPosition 		comethod2   ?
    &CastName&_get_StopTime 			comethod2   ?
    &CastName&_put_StopTime 			comethod2   ?
    &CastName&_get_PrerollTime 			comethod2   ?
    &CastName&_put_PrerollTime 			comethod2   ?
    &CastName&_put_Rate 				comethod2   ?
    &CastName&_get_Rate 				comethod2   ?
    &CastName&_CanSeekForward 			comethod2   ?
    &CastName&_CanSeekBackward 			comethod2   ?
ENDM

IMediaPosition STRUCT
    _vtIMediaPosition IMediaPosition
IMediaPosition ENDS

_vtIVideoWindow MACRO CastName:REQ
    _vtIDispatch CastName    
    &CastName&_put_Caption 				comethod2   ?
    &CastName&_get_Caption 				comethod2   ?
    &CastName&_put_WindowStyle 			comethod2   ?
    &CastName&_get_WindowStyle 			comethod2   ?
    &CastName&_put_WindowStyleEx 		comethod2   ?
    &CastName&_get_WindowStyleEx 		comethod2   ?
    &CastName&_put_AutoShow 			comethod2   ?
    &CastName&_get_AutoShow 			comethod2   ?
    &CastName&_put_WindowState 			comethod2   ?
    &CastName&_get_WindowState 			comethod2   ?
    &CastName&_put_BackgroundPalette 	comethod2   ?
    &CastName&_get_BackgroundPalette 	comethod2   ?
    &CastName&_put_Visible 				comethod2   ?
    &CastName&_get_Visible 				comethod2   ?
    &CastName&_put_Left 				comethod2   ?
    &CastName&_get_Left 				comethod2   ?
    &CastName&_put_Width 				comethod2   ?
    &CastName&_get_Width 				comethod2   ?
    &CastName&_put_Top 					comethod2   ?
    &CastName&_get_Top 					comethod2   ?
    &CastName&_put_Height 				comethod2   ?
    &CastName&_get_Height 				comethod2   ?
    &CastName&_put_Owner 				comethod2   ?
    &CastName&_get_Owner 				comethod2   ?
    &CastName&_put_MessageDrain 		comethod2   ?
    &CastName&_get_MessageDrain 		comethod2   ?
    &CastName&_get_BorderColor 			comethod2   ?
    &CastName&_put_BorderColor 			comethod2   ?
    &CastName&_get_FullScreenMode 		comethod2   ?
    &CastName&_put_FullScreenMode 		comethod2   ?
    &CastName&_SetWindowForeground 		comethod2   ?
    &CastName&_NotifyOwnerMessage 		comethod5   ?
    &CastName&_SetWindowPosition 		comethod5   ?
    &CastName&_GetWindowPosition 		comethod5   ?
    &CastName&_GetMinIdealImageSize 	comethod3   ?
    &CastName&_GetMaxIdealImageSize 	comethod3   ?
    &CastName&_GetRestorePosition 		comethod5   ?
    &CastName&_HideCursor 				comethod2   ?
    &CastName&_IsCursorHidden 			comethod2   ?
ENDM

IVideoWindow STRUCT
    _vtIVideoWindow	IVideoWindow
IVideoWindow ENDS

_vtIBasicAudio MACRO CastName:REQ
    _vtIDispatch CastName    
    &CastName&_put_Volume 				comethod2   ?
    &CastName&_get_Volume 				comethod2   ?
    &CastName&_put_Balance 				comethod2   ?
    &CastName&_get_Balance 				comethod2   ?
ENDM

IBasicAudio STRUCT
    _vtIBasicAudio IBasicAudio
IBasicAudio ENDS

_vtIBasicVideo MACRO CastName:REQ
    _vtIDispatch CastName    
	&CastName&_get_AvgTimePerFrame  	comethod2   ?
	&CastName&_get_BitRate  			comethod2   ?
	&CastName&_get_BitErrorRate  		comethod2   ?
	&CastName&_get_VideoWidth  			comethod2   ?
	&CastName&_get_VideoHeight  		comethod2   ?
	&CastName&_put_SourceLeft  			comethod2   ?	
	&CastName&_get_SourceLeft  			comethod2   ?
	&CastName&_put_SourceWidth  		comethod2   ?
	&CastName&_get_SourceWidth  		comethod2   ?
	&CastName&_put_SourceTop  			comethod2   ?
	&CastName&_get_SourceTop  			comethod2   ?
	&CastName&_put_SourceHeight  		comethod2   ?
	&CastName&_get_SourceHeight  		comethod2   ?
	&CastName&_put_DestinationLeft  	comethod2   ?
	&CastName&_get_DestinationLeft  	comethod2   ?
	&CastName&_put_DestinationWidth  	comethod2   ?
	&CastName&_get_DestinationWidth  	comethod2   ?
	&CastName&_put_DestinationTop  		comethod2   ?
	&CastName&_get_DestinationTop  		comethod2   ?
	&CastName&_put_DestinationHeight  	comethod2   ?
	&CastName&_get_DestinationHeight  	comethod2   ?
	&CastName&_SetSourcePosition  		comethod5   ?
	&CastName&_GetSourcePosition  		comethod5   ?
	&CastName&_SetDefaultSourcePosition comethod1   ? 
	&CastName&_SetDestinationPosition  	comethod1   ?
	&CastName&_GetDestinationPosition  	comethod5   ?
	&CastName&_SetDefaultDestinationPosition	comethod1   ?  
	&CastName&_GetVideoSize  			comethod3   ?
	&CastName&_GetVideoPaletteEntries   comethod5   ?
	&CastName&_GetCurrentImage  		comethod3   ?
	&CastName&_IsUsingDefaultSource  	comethod1   ?
	&CastName&_IsUsingDefaultDestination		comethod1   ? 
ENDM

IBasicVideo STRUCT
    _vtIBasicVideo	IBasicVideo
IBasicVideo	ENDS

_vtICaptureGraphBuilder MACRO CastName:REQ    
    _vtIUnknown CastName
    &CastName&_SetFiltergraph			comethod2   ?
    &CastName&_GetFiltergraph			comethod2   ?
    &CastName&_SetOutputFileName		comethod5   ?
    &CastName&_FindInterface			comethod6   ?
    &CastName&_RenderStream				comethod6   ?
    &CastName&_ControlStream			comethod8   ?
    &CastName&_AllocCapFile				comethod3   ?
    &CastName&_CopyCaptureFile			comethod5   ?
ENDM

ICaptureGraphBuilder struct
	_vtICaptureGraphBuilder	ICaptureGraphBuilder 
ICaptureGraphBuilder ends

_vtICaptureGraphBuilder2 MACRO CastName:REQ    
    _vtICaptureGraphBuilder	CastName
    &CastName&_FindPin					comethod8   ?
ENDM

ICaptureGraphBuilder2 struct
	_vtICaptureGraphBuilder2	ICaptureGraphBuilder2 
ICaptureGraphBuilder2 ends

_vtICreateDevEnum MACRO CastName:REQ    
    _vtIUnknown CastName
    &CastName&_CreateClassEnumerator	comethod4   ?
ENDM

ICreateDevEnum struct
	_vtICreateDevEnum ICreateDevEnum 
ICreateDevEnum ends

_vtIMediaFilter MACRO CastName:REQ    
    _vtIPersist CastName            
    &CastName&_Stop 					comethod1   ? 
	&CastName&_Pause 					comethod1   ?  
	&CastName&_Run						comethod2   ?  
	&CastName&_GetState					comethod3   ?  
	&CastName&_SetSyncSource			comethod2   ?  
	&CastName&_GetSyncSource 			comethod2   ?
ENDM

IMediaFilter STRUCT
    _vtIMediaFilter IMediaFilter
IMediaFilter ENDS

_vtIBaseFilter MACRO CastName:REQ    
    _vtIMediaFilter CastName                
    &CastName&_EnumPins					comethod2   ?   
	&CastName&_FindPin  				comethod3   ?
	&CastName&_QueryFilterInfo  		comethod2   ?
	&CastName&_JoinFilterGraph  		comethod3   ?
	&CastName&_QueryVendorInfo 			comethod2   ?
ENDM

IBaseFilter STRUCT
    _vtIBaseFilter IBaseFilter
IBaseFilter ENDS

_vtISampleGrabber MACRO CastName:REQ    
    _vtIUnknown CastName            
    &CastName&_SetOneShot 				comethod2   ?
	&CastName&_SetMediaType 			comethod2   ?	
	&CastName&_GetConnectedMediaType 	comethod2   ?
	&CastName&_SetBufferSamples 		comethod2   ?
	&CastName&_GetCurrentBuffer 		comethod3   ?
	&CastName&_GetCurrentSample 		comethod2   ?
	&CastName&_SetCallback 				comethod3   ?
ENDM

ISampleGrabber STRUCT
    _vtISampleGrabber ISampleGrabber 
ISampleGrabber ENDS

_vtISampleGrabberCB MACRO CastName:REQ    
    _vtIUnknown CastName            
	&CastName&_SampleCB		 			comethod3   ?    
    &CastName&_BufferCB 				comethod4   ?		
ENDM

ISampleGrabberCB STRUCT
    _vtISampleGrabberCB ISampleGrabberCB 
ISampleGrabberCB ENDS

_vtIPin MACRO CastName:REQ    
    _vtIUnknown CastName            
    &CastName&_Connect 					comethod3   ?
	&CastName&_ReceiveConnection 		comethod3   ?
	&CastName&_Disconnect 				comethod1   ?
	&CastName&_ConnectedTo 				comethod2   ?
	&CastName&_ConnectionMediaType 		comethod2   ?
	&CastName&_QueryPinInfo 			comethod2   ?
	&CastName&_QueryDirection 			comethod2   ?	
	&CastName&_QueryId 					comethod2   ?
	&CastName&_QueryAccept 				comethod2   ?
	&CastName&_EnumMediaTypes 			comethod2   ?
	&CastName&_QueryInternalConnections comethod3   ?
	&CastName&_EndOfStream 				comethod1   ?
	&CastName&_BeginFlush 				comethod1   ?
	&CastName&_EndFlush 				comethod1   ?
	&CastName&_NewSegment 				comethod4   ?		
ENDM	

IPin STRUCT
    _vtIPin IPin 
IPin ENDS

_vtIEnumPins MACRO CastName:REQ    
    _vtIUnknown CastName            
    &CastName&_Next						comethod4   ?  
	&CastName&_Skip  					comethod2   ?
	&CastName&_Reset  					comethod1   ?
	&CastName&_Clone  					comethod2   ?
ENDM	

IEnumPins STRUCT
    _vtIEnumPins IEnumPins 
IEnumPins ENDS

_vtIMediaSample MACRO CastName:REQ    
    _vtIUnknown CastName
    &CastName&_GetPointer 				comethod2   ? 
	&CastName&_GetSize 					comethod1   ? 
	&CastName&_GetTime 					comethod3   ?	
	&CastName&_SetTime 					comethod3   ?
	&CastName&_IsSyncPoint 				comethod1   ? 
	&CastName&_SetSyncPoint 			comethod2   ?
	&CastName&_IsPreroll 				comethod1   ? 
	&CastName&_SetPreroll 				comethod2   ?
    &CastName&_GetActualDataLength 		comethod1   ?
	&CastName&_SetActualDataLength 		comethod2   ?    
	&CastName&_GetMediaType 			comethod2   ? 
	&CastName&_SetMediaType 			comethod2   ?
	&CastName&_IsDiscontinuity 			comethod1   ? 			 
	&CastName&_SetDiscontinuity 		comethod2   ? 	 		 	 	
	&CastName&_GetMediaTime 			comethod3   ? 
	&CastName&_SetMediaTime 			comethod3   ?	
ENDM	

IMediaSample  STRUCT
    _vtIMediaSample IMediaSample  
IMediaSample  ENDS 

PIFilterGraph			typedef	ptr		IFilterGraph
PIGraphBuilder			typedef	ptr		IGraphBuilder		
PIMediaControl			typedef	ptr		IMediaControl
PIMediaEvent			typedef	ptr		IMediaEvent
PIMediaEventEx			typedef	ptr		IMediaEventEx
PIMediaPosition			typedef	ptr		IMediaPosition
PIVideoWindow			typedef	ptr		IVideoWindow
PIBasicAudio			typedef	ptr		IBasicAudio
PIBasicVideo			typedef	ptr		IBasicVideo
PICaptureGraphBuilder	typedef	ptr		ICaptureGraphBuilder
PICaptureGraphBuilder2	typedef	ptr		ICaptureGraphBuilder2
PICreateDevEnum			typedef	ptr		ICreateDevEnum
PIMediaFilter			typedef	ptr		IMediaFilter
PIBaseFilter			typedef	ptr		IBaseFilter
PISampleGrabber			typedef	ptr		ISampleGrabber
PISampleGrabberCB		typedef	ptr		ISampleGrabberCB
PIPin					typedef	ptr		IPin
PIEnumPins				typedef	ptr		IEnumPins
PIMediaSample			typedef ptr		IMediaSample

PPIPin					typedef	ptr		PIPin

.const
	CLSID_FilterGraph 			GUID <0e436ebb3h, 524fh, 11ceh, <9fh, 53h, 0h, 20h, 0afh, 0bh, 0a7h, 70h>>
	CLSID_CaptureGraphBuilder	GUID <0BF87B6E0h, 8C27h, 11d0h, <0B3h, 0F0h, 00h, 0AAh, 00h, 37h, 61h, 0C5h>>
	CLSID_CaptureGraphBuilder2	GUID <0BF87B6E1h, 8C27h, 11d0h, <0B3h, 0F0h, 00h, 0AAh, 00h, 37h, 61h, 0C5h>>
	CLSID_SystemDeviceEnum		GUID <62BE5D10h, 60EBh, 11d0h, <0BDh, 3Bh, 00h, 0A0h, 0C9h, 11h, 0CEh, 86h>>
	CLSID_VideoInputDeviceCategory	GUID <860BB310h, 5D01h, 11d0h, <0BDh, 3Bh, 00h, 0A0h, 0C9h, 11h, 0CEh, 86h>>
	CLSID_SampleGrabber			GUID <0c1f400a0h, 3f08h, 11d3h, <9fh, 0bh, 00h, 60h, 08h, 03h, 9eh, 37h>>																		
	CLSID_NullRenderer			GUID <0c1f400a4h, 3f08h, 11d3h, <9fh, 0bh, 00h, 60h, 08h, 03h, 9eh, 37h>>
	
	IID_IGraphBuilder 			GUID <56A868A9h, 0AD4h, 11ceh, <0B0h, 3Ah, 00h, 20h, 0AFh, 0Bh, 0A7h, 70h>>
	IID_IMediaControl 			GUID <56A868B1h, 0AD4h, 11CEh, <0B0h, 3Ah, 00h, 20h, 0AFh, 0Bh, 0A7h, 70h>>
	IID_IMediaEvent 			GUID <56A868B6h, 0AD4h, 11CEh, <0B0h, 3Ah, 00h, 20h, 0AFh, 0Bh, 0A7h, 70h>>
	IID_IMediaEventEx			GUID <56A868C0h, 0AD4h, 11CEh, <0B0h, 3Ah, 00h, 20h, 0AFh, 0Bh, 0A7h, 70h>>
	IID_IMediaPosition 			GUID <56A868B2h, 0AD4h, 11CEh, <0B0h, 3Ah, 00h, 20h, 0AFh, 0Bh, 0A7h, 70h>>
	IID_IVideoWindow 			GUID <56a868b4h, 0ad4h, 11ceh, <0b0h, 3ah, 00h, 20h, 0afh, 0bh, 0a7h, 70h>>
	IID_IBasicAudio 			GUID <56a868b3h, 0ad4h, 11ceh, <0b0h, 3ah, 00h, 20h, 0afh, 0bh, 0a7h, 70h>>
	IID_IBasicVideo 			GUID <56a868b5h, 0ad4h, 11ceh, <0b0h, 3ah, 00h, 20h, 0afh, 0bh, 0a7h, 70h>>
	IID_ICaptureGraphBuilder	GUID <0BF87B6E0h, 8C27h, 11D0h, <0B3h, 0F0h, 00h, 0AAh, 00h, 37h, 61h, 0C5h>>
	IID_ICaptureGraphBuilder2	GUID <93E5A4E0h, 2D50h, 11d2h, <0ABh, 0FAh, 00h, 0A0h, 0C9h, 0C6h, 0E3h, 8Dh>>
	IID_ICreateDevEnum			GUID <29840822h, 5B84h, 11D0h, <0BDh, 3Bh, 00h, 0A0h, 0C9h, 11h, 0CEh, 86h>>	
	IID_IMediaFilter			GUID <56a86899h, 0ad4h, 11ceh, <0b0h, 3ah, 00h, 20h, 0afh, 0bh, 0a7h, 70h>>	
	IID_IBaseFilter				GUID <56a86895h, 0ad4h, 11ceh, <0b0h, 3ah, 00h, 20h, 0afh, 0bh, 0a7h, 70h>>
	IID_ISampleGrabber			GUID <6b652fffh, 11feh, 4fceh, <92h, 0adh, 02h, 66h, 0b5h, 0d7h, 0c7h, 8fh>>
	IID_ISampleGrabberCB		GUID <0579154ah, 2b53h, 4994h, <0b0h, 0d0h, 0e7h, 73h, 14h, 8eh, 0ffh, 85h>>
	IID_IPin					GUID <56a86891h, 0ad4h, 11ceh, <0b0h, 3ah, 00h, 20h, 0afh, 0bh, 0a7h, 70h>>								        	 
	IID_IEnumPins				GUID <56a86892h, 0ad4h, 11ceh, <0b0h, 3ah, 00h, 20h, 0afh, 0bh, 0a7h, 70h>>
	IID_IMediaSample			GUID <56A8689Ah, 0AD4h, 11CEh, <0B0h, 3Ah, 00h, 20h, 0AFh, 0Bh, 0A7h, 70h>>
	;IID_IAMStreamConfig			GUID <0c6e13340h, 30ach, 11d0h, <0a1, 8c,0x00,0xa0,0xc9,0x11,0x89,0x56);
																					
	PIN_CATEGORY_CAPTURE		GUID <0fb6c4281h, 0353h, 11d1h, <90h, 5fh, 00h, 00h, 0c0h, 0cch, 16h, 0bah>>
	PIN_CATEGORY_PREVIEW		GUID <0fb6c4282h, 0353h, 11d1h, <90h, 5fh, 00h, 00h, 0c0h, 0cch, 16h, 0bah>>
	
	MEDIATYPE_Video				GUID <73646976h, 0000h, 0010h, <80h, 00h, 00h, 0AAh, 00h, 38h, 9Bh, 71h>>
	MEDIATYPE_Audio				GUID <73647561h, 0000h, 0010h, <80h, 00h, 00h, 0AAh, 00h, 38h, 9Bh, 71h>>
	MEDIATYPE_Text				GUID <73747874h, 0000h, 0010h, <80h, 00h, 00h, 0AAh, 00h, 38h, 9Bh, 71h>>
	MEDIATYPE_Midi				GUID <7364696Dh, 0000h, 0010h, <80h, 00h, 00h, 0AAh, 00h, 38h, 9Bh, 71h>>
	
	MEDIASUBTYPE_Avi			GUID <0e436eb88h, 524fh, 11ceh, <9fh, 53h, 00h, 20h, 0afh, 0bh, 0a7h, 70h>>
	MEDIASUBTYPE_RGB24			GUID <0e436eb7dh, 524fh, 11ceh, <9fh, 53h, 00h, 20h, 0afh, 0bh, 0a7h, 70h>>
	
	FORMAT_None					GUID <0F6417D6h, 0c318h, 11d0h, <0a4h, 3fh, 00h, 0a0h, 0c9h, 22h, 31h, 96h>>
	FORMAT_VideoInfo			GUID <05589f80h, 0c356h, 11ceh, <0bfh, 01h, 00h, 0aah, 00h, 55h, 59h, 5ah>>
	FORMAT_VideoInfo2			GUID <0f72a76A0h, 0eb0ah, 11d0h, <0ach, 0e4h, 00h, 00h, 0c0h, 0cch, 16h, 0bah>>
	FORMAT_WaveFormatEx			GUID <05589f81h, 0c356h, 11ceh, <0bfh, 01h, 00h, 0aah, 00h, 55h, 59h, 5ah>>
	FORMAT_MPEGVideo			GUID <05589f82h, 0c356h, 11ceh, <0bfh, 01h, 00h, 0aah, 00h, 55h, 59h, 5ah>>
	FORMAT_MPEGStreams			GUID <05589f83h, 0c356h, 11ceh, <0bfh, 01h, 00h, 0aah, 00h, 55h, 59h, 5ah>>
	FORMAT_DvInfo				GUID <05589f84h, 0c356h, 11ceh, <0bfh, 01h, 00h, 0aah, 00h, 55h, 59h, 5ah>>

  	EC_SYSTEMBASE                       EQU 0h
  	EC_USER                             EQU 8000h
  	EC_COMPLETE                         EQU 01h
  	EC_USERABORT                        EQU 02h
  	EC_ERRORABORT                       EQU 03h
  	EC_TIME                             EQU 04h
  	EC_REPAINT                          EQU 05h
  	EC_STREAM_ERROR_STOPPED             EQU 06h
  	EC_STREAM_ERROR_STILLPLAYING        EQU 07h
  	EC_ERROR_STILLPLAYING               EQU 08h
  	EC_PALETTE_CHANGED                  EQU 09h
  	EC_VIDEO_SIZE_CHANGED               EQU 0Ah
  	EC_QUALITY_CHANGE                   EQU 0Bh
  	EC_SHUTTING_DOWN                    EQU 0Ch
  	EC_CLOCK_CHANGED                    EQU 0Dh
  	EC_OPENING_FILE                     EQU 10h
  	EC_BUFFERING_DATA                   EQU 11h
  	EC_FULLSCREEN_LOST                  EQU 12h
  	EC_ACTIVATE                         EQU	13h
  	EC_NEED_RESTART                     EQU 14h
  	EC_WINDOW_DESTROYED                 EQU 15h
  	EC_DISPLAY_CHANGED                  EQU 16h
  	EC_STARVATION                  		EQU 17h
  	EC_OLE_EVENT						EQU 18h
  	EC_NOTIFY_WINDOW                    EQU 19h
  	EC_STREAM_CONTROL_STOPPED          	EQU 1Ah
  	EC_STREAM_CONTROL_STARTED          	EQU 1Bh
  	EC_END_OF_SEGMENT                   EQU 1Ch
  	EC_SEGMENT_STARTED                  EQU 1Dh
  	EC_LENGTH_CHANGED                   EQU 1Eh
  	
  	VFW_E_INVALIDMEDIATYPE 				EQU 80040200h
  	 
  	
REFERENCE_TIME							typedef	QWORD		

VIDEOINFOHEADER STRUCT
    rcSource							RECT			<>
    rcTarget							RECT			<>
    dwBitRate							DWORD			?
    dwBitErrorRate						DWORD			?
    AvgTimePerFrame						REFERENCE_TIME	?
    bmiHeader							BITMAPINFOHEADER	<>
VIDEOINFOHEADER ENDS

MPEG1VIDEOINFO STRUCT
    hdr									VIDEOINFOHEADER	<>
    dwStartTimeCode						DWORD			?
    cbSequenceHeader					DWORD			?
    bSequenceHeader						BYTE			?
MPEG1VIDEOINFO ENDS
  	
AM_MEDIA_TYPE STRUCT
    majortype							GUID	<>
    subtype								GUID	<>
    bFixedSizeSamples					DWORD	?
    bTemporalCompression				DWORD	?
    lSampleSize							DWORD	?
    formattype							GUID	<>
    pUnk								PIUnknown	?
    cbFormat							DWORD	?
    pbFormat							DWORD	?
AM_MEDIA_TYPE ENDS    
PAM_MEDIA_TYPE	typedef	ptr	AM_MEDIA_TYPE
	