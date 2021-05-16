@echo off
set p=%1
echo path to libtorch is: %p%
if exist build\ ( 
    cd build 
    cmake . 
    cmake --build . --config Release > NUL 
    echo.
    echo Rebuiliding project after changes....
    echo Build finished. Executable created. Running it! 
    echo.
    Release\LibtorchDemo.exe
    cd ..
    ) else (
        mkdir build 
        cd build 
        cmake -DCMAKE_PREFIX_PATH=%p% .. -Wno-dev 
        cmake --build . --config Release > NUL 
        echo.
        echo Build finished. Executable created. Running it!
        echo.
        Release\LibtorchDemo.exe
        cd ..
    )