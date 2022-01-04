@echo off

WHERE cl
IF %ERRORLEVEL% NEQ 0 (
rem Getting access to the compiler
rem Trying a bunch of locations that I've had on my machines before, it is what it is :)
IF EXIST "C:\Program Files (x86)\Microsoft Visual Studio\2017\Enterprise\VC\Auxiliary\Build\vcvarsall.bat" (
  call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Enterprise\VC\Auxiliary\Build\vcvarsall.bat" x64 >nul
) ELSE IF EXIST "C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\vcvarsall.bat" (
  call "C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\vcvarsall.bat" x64 >nul
) ELSE IF EXIST "C:\Program Files (x86)\Microsoft Visual Studio\2017\BuildTools\VC\Auxiliary\Build\vcvarsall.bat" (
  call "C:\Program Files (x86)\Microsoft Visual Studio\2017\BuildTools\VC\Auxiliary\Build\vcvarsall.bat" x64 >nul
) ELSE IF EXIST "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvarsall.bat" (
  call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvarsall.bat" x64 >nul
)
)

rem Setting the language as C
rem set LANGUAGE_FLAGS=/TC

rem Setting the language as C++
set LANGUAGE_FLAGS=/TP

rem Macro defines
set DEFINES_FLAGS=/D "WIN32" /D "DEBUG" /D "_CONSOLE" /D "_CRT_SECURE_NO_WARNINGS"

rem Warnings
set WARNINGS_FLAGS=/W3 /WX

rem Debugging informmation
set DEBUG_FLAGS=/Zi /analyze- /MD

rem Compiler Extension behaviour
set EXTENSION_FLAGS=/Zc:forScope /Zc:inline

rem Performance
set PERF_FLAGS=/GS- /fp:fast /Oy- /Od /Oi /GL /Gy

rem Executable output path
set EXECUTABLE_PATH=/Fe"build/practice.exe"

rem Intermediate path
set INTERMEDIATE_FILES=/Fo"build/practice.obj" /Fd"build/vc140.pdb"

rem All compiler & linker setup flags combined
set COMPILER_FLAGS=%LANGUAGE_FLAGS% %DEFINES_FLAGS% %WARNINGS_FLAGS% %DEBUG_FLAGS% %EXTENSION_FLAGS% %PERF_FLAGS%

cl %COMPILER_FLAGS% %INTERMEDIATE_FILES% %EXECUTABLE_PATH% src/winmain.c