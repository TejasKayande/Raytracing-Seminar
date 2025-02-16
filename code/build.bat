
@echo off
setlocal

cd /D "%~dp0"

if not exist "bin" ( mkdir bin )

pushd bin

set FLAGS=/EHsc /Zi /MP
set SYSTEM_LIBS=User32.lib

set SOURCE_FILES=..\source\fourth.cpp ^
                 ..\source\util\color.cpp ^
                 ..\source\util\image.cpp ^
                 ..\source\util\vector.cpp ^
                 ..\source\util\objects.cpp

set OUTPUT_EXE=fourth.exe

call cl %FLAGS% ^
        %SOURCE_FILES% ^
        %SYSTEM_LIBS% ^
        /link /OUT:%OUTPUT_EXE% ^

popd
endlocal
