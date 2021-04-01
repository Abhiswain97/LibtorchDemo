# LibtorchDemo
Trying out C++ frontend for PyTorch

## Requirements

1. C++
2. CMake

## How to use

1. Go to [this](https://download.pytorch.org/libtorch/cu102/libtorch-win-shared-with-deps-debug-1.8.1.zip) link, download the zip file. 
2. Unzip it
3. Now we make a `build` directory
    ```
    mkdir build
    cd build
    ```
4. use CMake to build the project  
    ```
    cmake -DCMAKE_PREFIX_PATH=/absolute/path/to/libtorch ..
    cmake --build . --config Release
    ```
    
*Now run it using:* <br>

on Windows: `.\Release\LibtorchDemo.exe`<br>
on Lnux & Mac: `./Libtorch`

> Note: this is the CPU-only version of PyTorch C++
