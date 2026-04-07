.xlist
include CMACROS.INC
include WINDEFS.INC
include NPDISP.INC
.list

externFP AllocCSToDSAlias
externFP FreeSelector

sBegin	Data

hooked_int_2Fh	db	0
prev_int_2Fh	dd	0

; for INT2Fh
NPDISP_REQUEST struc
npdr_version        	dw	?
npdr_funcOrder      	dw	?
npdr_returnCode     	dw	?
npdr_reserved       	dw	?
npdr_ax					dw	?
NPDISP_REQUEST ends

EXTRN npdisp_request:BYTE
EXTRN npdisp_retValue:DWORD

sEnd	Data

sBegin	Code
assumes cs,Code
assumes ds,Data
assumes es,nothing

; データセグメント保持用
_cstods 		dw	0

public	hook_int_2Fh
hook_int_2Fh proc far
	cmp hooked_int_2Fh, 0
	jz .hook_int_2Fh_main
	retf

.hook_int_2Fh_main:
    push ds
    mov ax, 352Fh
    int 21h
    mov word ptr prev_int_2Fh, bx
    mov word ptr prev_int_2Fh+2, es
    
    ; csに直接書くことは出来ない 
    ; なので、AllocCSToDSAliasで書き込み用エイリアスを取得 
    push es
    mov     ax, seg _TEXT
	cCall   AllocCSToDSAlias, <cs>
	mov es, ax
	mov ax, ds
    mov word ptr es:[_cstods], ax
	mov ax, es
	cCall   FreeSelector, <ax>
	pop es
	
    mov dx, OFFSET screen_switch_hook
    mov ax, SEG screen_switch_hook
    mov ds, ax
    mov ax, 252Fh
    int 21h
    pop ds
    
    mov hooked_int_2Fh, 1
    
    retf
hook_int_2Fh endp

public	unhook_int_2Fh
unhook_int_2Fh proc far
    push ds
    lds dx, prev_int_2Fh
    mov ax, 252Fh
    int 21h
    pop ds
    
    mov hooked_int_2Fh, 0
    retf
unhook_int_2Fh endp

screen_switch_hook proc far
    push    ds
    mov     ds, cs:[_cstods] ; Data セグメントへ
    
    cmp ax, 4001h
    je  .sendnp2

    cmp ax, 4002h
    je  .sendnp2
    
    jmp  .chain

.sendnp2:
	push si
	push ax
	push bx
	push cx
	push dx
	mov si, ax
    mov bx, 0ff2fh
    mov cx, 0504eh
    mov dx, 07e9h
    mov al, 'F'
    out dx, al
	pop dx
	pop cx
	pop bx
	pop ax
	pop si
	
.chain:
    push    word ptr [prev_int_2Fh+2]  ; segment
    push    word ptr [prev_int_2Fh+0]  ; offset
    push    bp
    mov     bp, sp
    mov     ds, [bp+6]                 ; 元の DS を復元
    pop     bp
    retf    2                          ; push ds 分を捨てて旧ハンドラへ

screen_switch_hook endp

sEnd	Code
end
