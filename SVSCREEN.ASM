.xlist
include WINDEFS.INC
include CMACROS.INC
include NPDISP.INC
.list

sBegin	Data

; for SaveScreenBitmap
NPDISP_REQUEST struc
npdr_version        	dw	?
npdr_funcOrder      	dw	?
npdr_returnCode     	dw	?
npdr_reserved       	dw	?
npdr_lpRetValueAddr		dd	?
npdr_lpRect				dd	?
npdr_wCommand			dw	?
NPDISP_REQUEST ends

EXTRN npdisp_request:BYTE
EXTRN npdisp_retValue:DWORD

sEnd	Data

sBegin	Code
assumes cs,Code
assumes ds,Data

cProc	SaveScreenBitmap,<FAR,PUBLIC,WIN,PASCAL>,<si,di>

	parmD	lpRect
	parmW	wCommand

cBegin

    	push ax
    	push dx
    	EnterCrit
    	mov npdisp_request.npdr_version, NPDISP_VERSION
    	mov npdisp_request.npdr_funcOrder, 92
    	mov npdisp_request.npdr_returnCode, 0
    	mov WORD PTR npdisp_retValue, 0
    	mov WORD PTR npdisp_retValue+2, 0
    	mov WORD PTR npdisp_request.npdr_lpRetValueAddr, OFFSET npdisp_retValue
    	mov WORD PTR npdisp_request.npdr_lpRetValueAddr+2, SEG npdisp_retValue
		mov ax, WORD PTR lpRect
		mov dx, WORD PTR lpRect+2
		mov WORD PTR npdisp_request.npdr_lpRect, ax
		mov WORD PTR npdisp_request.npdr_lpRect+2, dx
		mov ax, WORD PTR wCommand
		mov WORD PTR npdisp_request.npdr_wCommand, ax
        mov dx, 07e8h
    	mov ax, OFFSET npdisp_request
    	out dx, al
    	mov al, ah
    	out dx, al
    	mov ax, SEG npdisp_request
    	out dx, al
    	mov al, ah
    	out dx, al
        mov dx, 07e9h
        mov al, 'N'
        out dx, al
        mov al, 'P'
        out dx, al
        mov al, '2'
        out dx, al
        mov al, '1'
        out dx, al
    	pop dx
    	pop ax
    	LeaveCrit
    	
		mov ax, WORD PTR npdisp_retValue
cEnd

sEnd	Code
end
