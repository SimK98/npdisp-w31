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
assumes es,nothing

cProc	DeviceMode,<FAR,PUBLIC,WIN,PASCAL>,<si,di>

	parmW	h_wnd
	parmW	h_inst
	parmD	lp_device_type
	parmD	lp_output_file


cBegin
	mov	ax,-1
cEnd

sEnd	Code
end
