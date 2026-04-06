.xlist
include WINDEFS.INC
include CMACROS.INC
include NPDISP.INC
.list

sBegin	Data

; for UpdateColors
NPDISP_REQUEST struc
npdr_version        	dw	?
npdr_funcOrder      	dw	?
npdr_returnCode     	dw	?
npdr_reserved       	dw	?
npdr_wStartX			dw	?
npdr_wStartY			dw	?
npdr_wExtX				dw	?
npdr_wExtY				dw	?
npdr_lpTranslate		dd	?
NPDISP_REQUEST ends

EXTRN npdisp_request:BYTE
EXTRN npdisp_retValue:DWORD

sEnd	Data

sBegin	Code
assumes cs,Code
assumes ds,Data
assumes es,nothing

cProc	UpdateColors,<FAR,PUBLIC,WIN,PASCAL>,<si,di>

	parmW	wStartX
	parmW	wStartY
	parmW	wExtX
	parmW	wExtY
	parmD	lpTranslate

cBegin
    	push ax
    	push dx
    	EnterCrit
    	mov npdisp_request.npdr_version, NPDISP_VERSION
    	mov npdisp_request.npdr_funcOrder, 26
    	mov npdisp_request.npdr_returnCode, 0
		mov ax, WORD PTR wStartX
		mov WORD PTR npdisp_request.npdr_wStartX, ax
		mov ax, WORD PTR wStartY
		mov WORD PTR npdisp_request.npdr_wStartY, ax
		mov ax, WORD PTR wExtX
		mov WORD PTR npdisp_request.npdr_wExtX, ax
		mov ax, WORD PTR wExtY
		mov WORD PTR npdisp_request.npdr_wExtY, ax
		mov ax, WORD PTR lpTranslate
		mov dx, WORD PTR lpTranslate+2
		mov WORD PTR npdisp_request.npdr_lpTranslate, ax
		mov WORD PTR npdisp_request.npdr_lpTranslate+2, dx
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
        LeaveCrit
    	pop dx
    	pop ax
    	
		mov ax, WORD PTR npdisp_retValue
cEnd

sEnd Code

end
