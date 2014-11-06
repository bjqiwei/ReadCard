@echo off
::echo current directory:
echo %~dp0
regsvr32 "%~dp0\ReadCard.dll"
