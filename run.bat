@echo off
set p=%1
echo "path to libtorch is: %p%"
if exist build\ ( 
    cd build && cmake . && cmake --build . --config Release && Release\LibtorchDemo.exe
    ) else (
        mkdir build && cd build && cmake -DCMAKE_PREFIX_PATH=%p% .. -Wno-dev && cmake --build . --config Release && Release\LibtorchDemo.exe
        )