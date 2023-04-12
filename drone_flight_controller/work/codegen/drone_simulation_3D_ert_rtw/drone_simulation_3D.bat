
set skipSetupArg=%2
if "%skipSetupArg%" NEQ "skip_setup_msvc" (
call "setup_msvc.bat"
)

cd .

if "%1"=="" (nmake  -f drone_simulation_3D.mk all) else (nmake  -f drone_simulation_3D.mk %1)
@if errorlevel 1 goto error_exit

exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
exit /B 1