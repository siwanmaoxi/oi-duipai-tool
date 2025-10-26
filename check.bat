@echo off
g++ correctCode.cpp -o correctCode.exe
g++ testCode.cpp -o testCode.exe
g++ makeExample.cpp -o makeExample.exe
set /a cnt=0
:loop
set /a cnt+=1
makeExample.exe %cnt% > in.txt
echo Test %cnt%:
type in.txt
testCode.exe < in.txt > out1.txt
correctCode.exe < in.txt > out2.txt
fc out1.txt out2.txt > nul
if not errorlevel 1 goto loop
echo Failed!
pause