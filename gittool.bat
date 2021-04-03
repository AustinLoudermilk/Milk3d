@ECHO OFF

:MENU
CLS
ECHO.
ECHO GIT
ECHO ---
ECHO.
ECHO 1 - status
ECHO 2 - add all
ECHO 3 - reset
ECHO 4 - commit
echo.
ECHO 5 - exit
ECHO.
SET /P M= ~ 
IF %M%==1 GOTO STATUS
IF %M%==2 GOTO ADD
IF %M%==3 GOTO RESET
IF %M%==4 GOTO COMMIT
IF %M%==5 GOTO EOF

:STATUS
CLS
ECHO.
ECHO --GIT STATUS--
ECHO.
git status
ECHO.
ECHO -- -- -- -- --
pause >nul
GOTO MENU

:ADD
CLS
ECHO.
ECHO --GIT ADD--
ECHO.
git add *
ECHO.
ECHO -- -- -- -- --
pause >nul
GOTO MENU

:RESET
CLS
ECHO.
ECHO --GIT RESET--
ECHO.
git reset
ECHO.
ECHO -- -- -- -- --
pause >nul
GOTO MENU

:COMMIT
CLS
ECHO.
ECHO --GIT COMMIT--
ECHO.
SET /p A= -m: 
git commit -m %A%
ECHO.
SET /P PUSH=Push? (y/n):
IF /I "%PUSH%" NEQ "Y" (GOTO MENU) ELSE (git push origin main)
ECHO.
ECHO -- -- -- -- --
pause >nul
GOTO MENU