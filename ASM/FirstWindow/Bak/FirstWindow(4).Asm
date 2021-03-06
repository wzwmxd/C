.386
.model flat,stdcall
option casemap:none

include windows.inc
include gdi32.inc
includelib gdi32.lib
include user32.inc
includelib user32.lib
include kernel32.inc
includelib kernel32.lib
.data?
hInstance dd ?
hWinMain dd ?
.const
szClassName db 'MyClass',0
szCaption db 'My first Window!',0
szText db 'Win32 ASM!',0

.code
_ProcWinMain proc uses ebx edi esi,hWnd,uMsg,wParam,lParam
	LOCAL @stPs:PAINTSTRUCT
	LOCAL @stRect:RECT
	LOCAL @hDc
	
	mov eax,uMsg
	.if eax==WM_PAINT
		invoke BeginPaint,hWnd,addr @stPs
		mov @hDc,eax
		
		invoke GetClientRect,hWnd,addr @stRect
		invoke DrawText,@hDc,addr szText,-1,\
		addr @stRect,\
		DT_SINGLELINE or DT_CENTER or DT_VCENTER
		invoke EndPaint,hWnd,addr @stPs
	.elseif eax==WM_CLOSE
		invoke DestroyWindow,hWinMain
		invoke PostQuitMessage,NULL
	.else
		invoke DefWindowProc,hWnd,uMsg,wParam,lParam
		ret
	.endif
	xor eax,eax
	ret
_ProcWinMain endp

_WinMain proc
	
	LOCAL @stWndClass:WNDCLASSEX
	LOCAL @srMsg:MSG
	invoke GetModuleHandle,NULL
	mov hInstance,eax
	invoke RtlZeroMemory,addr @stWndClass,sizeof @stWndClass
	
	invoke LoadCursor,0,IDC_ARROW
	mov @stWndClass.hCursor,eax
	push hInstance
	pop @stWndClass.hInstance
	mov @stWndClass.cbSize,sizeof WNDCLASSEX
	mov @stWndClass.style,CS_HREDRAW or CS_VREDRAW
	mov @stWndClass.lpfnWndProc,offset _ProcWinMain
	mov @stWndClass.hbrBackground,COLOR_WINDOW+1
	mov @stWndClass.lpszClassName,offset szClassName
	invoke RegisterClassEx,addr @stWndClass
	
	invoke CreateWindowEx,WS_EX_CLIENTEDGE,\
		offset szClassName,offset szCaption,\
		WS_OVERLAPPEDWINDOW,\
		100,100,600,400,\
		NULL,NULL,hInstance,NULL
	mov hWinMain,eax
	invoke ShowWindow,hWinMain,SW_SHOWNORMAL
	invoke UpdateWindow,hWinMain
	
	.while TRUE
		invoke GetMessage,addr @stMsg,NULL,0,0
		.break .if eax==0
			invoke TranslateMessage,addr @stMsg
			invoke DispatchMessage,addr @stMsg
			
		.endif
	.endw
	ret

_WinMain endp

start:
	call _WinMain
	invoke ExitProcess,NULL
	end start