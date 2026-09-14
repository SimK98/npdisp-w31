# NPDISP graphics API compatibility driver.
# Target toolchain: Microsoft Visual C++ 6.0 / LINK 6.x.

CC=cl
LD=link
RC=rc
CFLAGS=/nologo /O1 /W3 /MT
LDFLAGS=/nologo /DLL /BASE:0xA2000000 /FIXED:NO /SUBSYSTEM:WINDOWS,4.0 /DEF:npogl32.def

all: npogl32.dll

npogl32.obj: npogl32.c
	$(CC) $(CFLAGS) /c npogl32.c

npogl32.res: NPOGL32.RCV
	$(RC) /r /fo npogl32.res NPOGL32.RCV

npogl32.dll: npogl32.obj npogl32.res npogl32.def
	$(LD) $(LDFLAGS) /OUT:npogl32.dll npogl32.obj npogl32.res kernel32.lib user32.lib gdi32.lib

clean:
	-del npogl32.obj
	-del npogl32.dll
	-del npogl32.exp
	-del npogl32.lib
	-del npogl32.res
