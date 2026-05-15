.xlist
include WINDEFS.INC
include CMACROS.INC
include NPDISP.INC
.list

sBegin	Code
assumes cs,Code
assumes ds,Data
assumes es,nothing

cProc	Pixel,<FAR,PUBLIC,WIN,PASCAL>

;	parmD	lpDestDev
;	parmW	X
;	parmW	Y
;	parmD	dwPhysColor
;	parmD	lpDrawMode

cBegin <nogen>
    push bp
    mov  bp,sp
    ;push si
	;push di
    ;EnterCrit
    mov bx, 9
    mov cx, 0504eh
    mov dx, 07e9h
    mov al, 'F'
    out dx, al
    ;LeaveCrit
    ;pop  di
    ;pop  si
    pop bp
    ret 16
cEnd <nogen>

sEnd	Code

end
