@echo off
::echo current directory:
echo %~dp0
regsvr32 /u "%~dp0\ReadCard.dll"
