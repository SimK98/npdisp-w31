.xlist
include WINDEFS.INC
include CMACROS.INC
include NPDISP.INC
.list

sBegin	Code
assumes cs,Code
assumes ds,Data

cProc	BITBLT,<FAR,PUBLIC,WIN,PASCAL>

;	parmD	lpDestDev
;	parmW	DestxOrg
;	parmW	DestyOrg
;	parmD	lpSrcDev
;	parmW	SrcxOrg
;	parmW	SrcyOrg
;	parmW	xExt
;	parmW	yExt
;	parmD	Rop
;	parmD	lpPBrush
;	parmD	lpDrawMode

cBegin <nogen>
    push bp
    mov  bp,sp
    push si
	push di
    EnterCrit
    mov bx, 1
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
