@echo off

:: Add your custom path (e.g., the MinGW bin directory)
:: I have MinGW installed in C:\Programs\mingw\winlibs-x86_64-posix-seh-gcc-13.2.0-mingw-w64ucrt-11.0.1-r4\mingw64
::SET MINGW_BIN_PATH=%MINGW64_V8%\bin
::SET PATH=%MINGW_BIN_PATH%;%PATH%

SET build_dir=build

:: Check if the build directory exists
IF EXIST "%build_dir%" (
    echo Removing existing build directory...
    rmdir /s /q "%build_dir%"
)

echo Creating new build directory...
mkdir "%build_dir%"
cd "%build_dir%"

::cmake -G "MinGW Makefiles" ..
cmake -G "Visual Studio 17" ..
cmake --build .

echo Build completed.
cd ..
pause
