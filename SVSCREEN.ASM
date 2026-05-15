.xlist
include WINDEFS.INC
include CMACROS.INC
include NPDISP.INC
.list

;sBegin	Data
;
;; for SaveScreenBitmap
;NPDISP_REQUEST struc
;npdr_version        	dw	?
;npdr_funcOrder      	dw	?
;npdr_returnCode     	dw	?
;npdr_reserved       	dw	?
;npdr_lpRetValueAddr		dd	?
;npdr_lpRect				dd	?
;npdr_wCommand			dw	?
;NPDISP_REQUEST ends
;
;EXTRN npdisp_request:BYTE
;EXTRN npdisp_retValue:DWORD
;
;EXTRN g_isStdMode:BYTE
;
;sEnd	Data

sBegin	Code
assumes cs,Code
assumes ds,Data

cProc	SaveScreenBitmap,<FAR,PUBLIC,WIN,PASCAL> ;,<si,di>

;	parmD	lpRect
;	parmW	wCommand

cBegin <nogen>
    push bp
    mov  bp,sp
    ;push si
	;push di
    ;EnterCrit
    mov bx, 92
    mov cx, 0504eh
    mov dx, 07e9h
    mov al, 'F'
    out dx, al
    ;LeaveCrit
    ;pop  di
    ;pop  si
    pop bp
    ret 6
cEnd <nogen>

sEnd	Code
end
