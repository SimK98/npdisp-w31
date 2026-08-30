@echo off
rem Build from a Visual C++ 6.0 command prompt.
del npdispdd.obj
del npdispdd.dll
nmake /f MAKEFILE
