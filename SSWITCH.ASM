.xlist
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
assumes es,nothing

cProc	UserRepaintDisable,<FAR,PASCAL,PUBLIC>

	parmB	RepaintDisable		;TRUE = to Disable, FALSE = to enable

cBegin
	xor ax, ax
cEnd

sEnd	Code
end
