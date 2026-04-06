.xlist
include WINDEFS.INC
include CMACROS.INC
include NPDISP.INC
.list

sBegin	Data

PUBLIC npdisp_request
npdisp_request	db	100	DUP(?)
PUBLIC npdisp_retValue
npdisp_retValue	dd	?

sEnd	Data

end
