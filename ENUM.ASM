.xlist
include WINDEFS.INC
include CMACROS.INC
include NPDISP.INC
.list

sBegin	Data

; for EnumObj
NPDISP_REQUEST_EnumObj struc
npdr_eo_version        		dw	?
npdr_eo_funcOrder      		dw	?
npdr_eo_returnCode     		dw	?
npdr_eo_reserved       		dw	?
npdr_eo_lpRetValueAddr		dd	?
npdr_eo_lpDestDevAddr		dd	?
npdr_eo_wStyle				dw	?
npdr_eo_enumIdx				dw	?
npdr_eo_lpLogObjAddr		dd	?
NPDISP_REQUEST_EnumObj ends

; 別領域に確保
npdisp_request_e	db	32	DUP(?)
npdisp_retValue_e	dd	?

sEnd	Data

sBegin	Code
assumes cs,Code
assumes ds,Data
assumes es,nothing

cProc	EnumDFonts,<FAR,PUBLIC,WIN,PASCAL>,<si,di>

	parmD	lp_device
	parmD	lp_face_name
	parmD	lp_callback_func
	parmD	lp_client_data

cBegin
	mov	ax,1
cEnd

assumes ds,Data
assumes es,nothing

cProc	EnumObj,<FAR,PUBLIC,WIN,PASCAL>,<si,di>

	parmD	lpDestDev
	parmW	wStyle
	parmD	lpCallbackFunc
	parmD	lpClientData
	
	localV	logObj, 12

cBegin
;NPDISP_REQUEST_EnumObj struc
;npdr_eo_version        		dw	?
;npdr_eo_funcOrder      		dw	?
;npdr_eo_returnCode     		dw	?
;npdr_eo_reserved       		dw	?
;npdr_eo_lpRetValueAddr		dd	?
;npdr_eo_lpDestDevAddr		dd	?
;npdr_eo_wStyle				dw	?
;npdr_eo_enumIdx				dw	?
;npdr_eo_lpLogObjAddr		dd	?
;NPDISP_REQUEST_EnumObj ends
    	push dx
    	
    	xor si, si
    	mov npdisp_request_e.npdr_eo_version, NPDISP_VERSION
    	mov npdisp_request_e.npdr_eo_funcOrder, 7
    	mov npdisp_request_e.npdr_eo_returnCode, 0
    	mov WORD PTR npdisp_request_e.npdr_eo_lpRetValueAddr, OFFSET npdisp_retValue_e
    	mov WORD PTR npdisp_request_e.npdr_eo_lpRetValueAddr+2, SEG npdisp_retValue_e
		mov ax, WORD PTR lpDestDev
		mov dx, WORD PTR lpDestDev+2
		mov WORD PTR npdisp_request_e.npdr_eo_lpDestDevAddr, ax
		mov WORD PTR npdisp_request_e.npdr_eo_lpDestDevAddr+2, dx
		mov ax, WORD PTR wStyle
		mov WORD PTR npdisp_request_e.npdr_eo_wStyle, ax
		lea ax, logObj
		mov dx, ss
		mov WORD PTR npdisp_request_e.npdr_eo_lpLogObjAddr, ax
		mov WORD PTR npdisp_request_e.npdr_eo_lpLogObjAddr+2, dx
		
		mov ax, 1 ; デフォルト戻り値=1 
.continueEnum:
    	push ax
    	EnterCrit
		mov ax, si
		mov WORD PTR npdisp_request_e.npdr_eo_enumIdx, ax
    	mov WORD PTR npdisp_retValue_e, 0
    	mov WORD PTR npdisp_retValue_e+2, 0
        mov dx, 07e8h
    	mov ax, OFFSET npdisp_request_e
    	out dx, al
    	mov al, ah
    	out dx, al
    	mov ax, SEG npdisp_request_e
    	out dx, al
    	mov al, ah
    	out dx, al
        mov dx, 07e9h
        mov al, 'N'
        out dx, al
        mov al, 'P'
        out dx, al
        mov al, '2'
        out dx, al
        mov al, '1'
        out dx, al
        LeaveCrit
        pop ax
        
		cmp WORD PTR npdisp_request_e.npdr_eo_returnCode, 1
        jne .endenum
        
		cmp WORD PTR npdisp_retValue_e, 0
        je .endenum
        
		lea	ax,logObj
		farPtr ptr1,ss,ax
		cCall lpCallbackFunc,<ptr1,lpClientData>
		and	ax,ax
		jz .endenum
		
		inc si
		jmp .continueEnum
        
.endenum:
    	pop dx
cEnd

sEnd	Code
end
