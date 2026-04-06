.286c

.xlist
include CMACROS.INC
include WINDEFS.INC
include NPDISP.INC
.list

sBegin	Code
assumes cs,Code
assumes ds,Data

cProc	SetCursor, <PUBLIC, FAR>
;	parmD   lpCursorShape

cBegin <nogen>
    push bp
    mov  bp,sp
    push si
	push di
    EnterCrit
    mov bx, 102
    mov cx, 0504eh
    mov dx, 07e9h
    mov al, 'F'
    out dx, al
    LeaveCrit
    pop  di
    pop  si
    pop bp
    ret 4
cEnd <nogen>

cProc	CheckCursor, <FAR,PUBLIC>
cBegin <nogen>
    push bp
    mov  bp,sp
    push si
	push di
    EnterCrit
    mov bx, 104
    mov cx, 0504eh
    mov dx, 07e9h
    mov al, 'F'
    out dx, al
    LeaveCrit
    pop  di
    pop  si
    pop bp
    ret 0
cEnd <nogen>

cProc	MoveCursor, <PUBLIC, FAR>
;        parmW   absX
;        parmW   absY
cBegin <nogen>
    push bp
    mov  bp,sp
    push si
	push di
    EnterCrit
    mov bx, 103
    mov cx, 0504eh
    mov dx, 07e9h
    mov al, 'F'
    out dx, al
    LeaveCrit
    pop  di
    pop  si
    pop bp
    ret 4
cEnd <nogen>

cProc	Inquire,<PUBLIC,FAR,WIN,PASCAL>,<si,di>
	parmD	lp_cursor_info
cBegin
    les di, lp_cursor_info
    mov word ptr es:[di], 1
    mov word ptr es:[di+2], 2
	mov ax, 4
cEnd

sEnd	Code
end
