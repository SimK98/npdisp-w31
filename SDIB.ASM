.xlist
include WINDEFS.INC
include CMACROS.INC
include NPDISP.INC
.list

sBegin	Data

EXTRN npdisp_request:BYTE
EXTRN npdisp_retValue:DWORD

sEnd	Data


sBegin	Code
assumes cs,Code
assumes ds,Data

cProc	StretchDIBits,<FAR,PUBLIC,WIN,PASCAL> ;,<si,di>

;	parmD	lpPDevice, 
;	parmW	fGet, 
;	parmW	DestX, 
;	parmW	DestY, 
;	parmW	DestXE, 
;	parmW	DestYE, 
;	parmW	SrcX, 
;	parmW	SrcY, 
;	parmW	SrcXE, 
;	parmW	SrcYE, 
;	parmD	lpBits, 
;	parmD	lpBitmapInfo,
;	parmD	lpTranslate, 
;	parmD	dwROP, 
;	parmD	lpPBrush,
;	parmD	lpDrawMode, 
;	parmD	lpClipRect


cBegin <nogen>
    push bp
    mov  bp,sp
    push si
	push di
    EnterCrit
    mov bx, 28
    mov cx, 0504eh
    mov dx, 07e9h
    mov al, 'F'
    out dx, al
    LeaveCrit
    pop  di
    pop  si
    pop bp
    ret 50
cEnd <nogen>

sEnd	Code
end
