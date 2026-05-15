.xlist
include WINDEFS.INC
include CMACROS.INC
include NPDISP.INC
.list

;sBegin	Data
;
;; for UpdateColors
;NPDISP_REQUEST struc
;npdr_version        	dw	?
;npdr_funcOrder      	dw	?
;npdr_returnCode     	dw	?
;npdr_reserved       	dw	?
;npdr_wStartX			dw	?
;npdr_wStartY			dw	?
;npdr_wExtX				dw	?
;npdr_wExtY				dw	?
;npdr_lpTranslate		dd	?
;NPDISP_REQUEST ends
;
;EXTRN npdisp_request:BYTE
;EXTRN npdisp_retValue:DWORD
;
;sEnd	Data

sBegin	Code
assumes cs,Code
assumes ds,Data
assumes es,nothing

cProc	UpdateColors,<FAR,PUBLIC,WIN,PASCAL> ;,<si,di>

;	parmW	wStartX
;	parmW	wStartY
;	parmW	wExtX
;	parmW	wExtY
;	parmD	lpTranslate
    
cBegin <nogen>
    push bp
    mov  bp,sp
    ;push si
	;push di
    ;EnterCrit
    mov bx, 26
    mov cx, 0504eh
    mov dx, 07e9h
    mov al, 'F'
    out dx, al
    ;LeaveCrit
    ;pop  di
    ;pop  si
    pop bp
    ret 12
cEnd <nogen>

sEnd Code

end
