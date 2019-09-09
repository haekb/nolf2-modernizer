
echo off
setlocal


rem Parameters:
rem    "/r" - Rebuild

set Rebuild=

if "%3" == "/R" set Rebuild=/REBUILD
if "%3" == "/r" set Rebuild=/REBUILD


echo - Building
msdev game\to2.dsw /MAKE "Game - Win32 Debug" %Rebuild% >> BuildDebug.log
if errorlevel 1 echo -    Found errors


endlocal