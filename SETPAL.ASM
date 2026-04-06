.xlist
include WINDEFS.INC
include CMACROS.INC
include NPDISP.INC
.list

sBegin	Code
assumes cs,Code
assumes ds,Data
assumes es,nothing

cProc	SetPalette,<FAR,PUBLIC,WIN,PASCAL>

;	parmW	nStartIndex
;	parmW	nNumEntries
;	parmD	lpPalette

cBegin <nogen>
    push bp
    mov  bp,sp
    push si
	push di
    EnterCrit
    mov bx, 22
    mov cx, 0504eh
    mov dx, 07e9h
    mov al, 'F'
    out dx, al
    LeaveCrit
    pop  di
    pop  si
    pop bp
    ret 8
cEnd <nogen>

sEnd Code

end
