@echo off
setlocal

set VS_COM_CMD_PATH="C:\Program Files (x86)\Microsoft Visual Studio\2019\preview\Common7\Tools\VsDevCmd.bat"

if not defined VS_CMD_PATH (
    if exist %VS_COM_CMD_PATH% (
        set VS_CMD_PATH=%VS_COM_CMD_PATH%
    ) else (
        echo No VS developer command prompt detected!
        goto :EOF
    )
)

echo.
echo   Building

if not exist bin\ (
    mkdir bin
)

pushd bin

cmake -G "Visual Studio 17 2022" ..\ -DCMAKE_BUILD_TYPE=Debug

echo Calling VS Developer Command Prompt to build
call %VS_CMD_PATH%

msbuild -v:m CorProfiler.sln

popd

echo.
echo.
echo.
echo Done building

echo Copying binaries to main directory
copy /y  eventpipe\bin\Debug\EventPipeProfiler.dll .
copy /y  eventpipe\bin\Debug\SampleProfiler.dll .
