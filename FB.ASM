.xlist
include WINDEFS.INC
include CMACROS.INC
include NPDISP.INC
.list

sBegin	Data

; for FastBorder
NPDISP_REQUEST struc
npdr_version        	dw	?
npdr_funcOrder      	dw	?
npdr_returnCode     	dw	?
npdr_reserved       	dw	?
npdr_lpRetValueAddr		dd	?
npdr_lpRectAddr			dd	?
npdr_wHorizBorderThick	dw	?
npdr_wVertBorderThick	dw	?
npdr_dwRasterOp			dd	?
npdr_lpDestDevAddr		dd	?
npdr_lpPBrushAddr		dd	?
npdr_lpDrawModeAddr		dd	?
npdr_lpClipRectAddr		dd	?
NPDISP_REQUEST ends

EXTRN npdisp_request:BYTE
EXTRN npdisp_retValue:DWORD

sEnd	Data

sBegin	Code
assumes cs,Code
assumes ds,Data
assumes es,nothing

cProc	FastBorder,<FAR,PUBLIC,WIN,PASCAL> ;,<si,di>

;	parmD	lpRect
;	parmW	wHorizBorderThick
;	parmW	wVertBorderThick
;	parmD	dwRasterOp
;	parmD	lpDestDev
;	parmD	lpPBrush
;	parmD	lpDrawMode
;	parmD	lpClipRect
	
cBegin <nogen>
    push bp
    mov  bp,sp
    ;push si
	;push di
    ;EnterCrit
    mov bx, 17
    mov cx, 0504eh
    mov dx, 07e9h
    mov al, 'F'
    out dx, al
    ;LeaveCrit
    ;pop  di
    ;pop  si
    pop bp
    ret 28
cEnd <nogen>

sEnd	Code
end
