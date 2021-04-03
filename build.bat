@ECHO OFF
CLS

:BUILD
CLS
ECHO BUILDING FILES
ECHO --------------
ECHO.
call vendor\bin\premake\premake5.exe vs2019
ECHO.
ECHO.
SET /P PUSH=Rebuild? (y/n):
IF /I "%PUSH%" NEQ "Y" (GOTO EOF) ELSE (GOTO BUILD)