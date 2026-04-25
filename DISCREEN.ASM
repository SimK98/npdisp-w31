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
	assumes	cs,Code
	assumes	ds,Data
	assumes	es,nothing

cProc	DIBScreenBlt,<FAR,PUBLIC,WIN,PASCAL> ; ,<si,di> ; = SetDIBitsToDevice

;	parmD	lp_pdevice
;	parmW	ScrXorg
;	parmW	ScrYorg
;	parmW	StartScan
;	parmW	NumScan
;	parmD	lpClipRect
;	parmD	lpDrawMode
;	parmD	lp_bits
;    parmD   lp_bi
;    parmD   dwColorInfo

cBegin <nogen>
    push bp
    mov  bp,sp
    push si
	push di
    EnterCrit
    mov bx, 21
    mov cx, 0504eh
    mov dx, 07e9h
    mov al, 'F'
    out dx, al
    LeaveCrit
    pop  di
    pop  si
    pop bp
    ret 32
cEnd <nogen>

sEnd	Code
end
