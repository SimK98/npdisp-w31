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

cProc	StretchBlt,<FAR,PUBLIC,WIN,PASCAL> ;,<si,di>

;	parmD	lpDestDev;
;	parmW	wDestX;
;	parmW	wDestY;
;	parmW	wDestXext;
;	parmW	wDestYext;
;	parmD	lpSrcDev;
;	parmW	wSrcX;
;	parmW	wSrcY;
;	parmW	wSrcXext;
;	parmW	wSrcYext;
;	parmD	Rop3;
;	parmD	lpPBrush;
;	parmD	lpDrawMode;
;	parmD	lpClip;

cBegin <nogen>
    push bp
    mov  bp,sp
    push si
	push di
    EnterCrit
    mov bx, 27
    mov cx, 0504eh
    mov dx, 07e9h
    mov al, 'F'
    out dx, al
    LeaveCrit
    pop  di
    pop  si
    pop bp
    ret 40
cEnd <nogen>

sEnd	Code
end
