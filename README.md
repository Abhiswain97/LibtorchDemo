# LibtorchDemo
Trying out C++ frontend for PyTorch

## Requirements

1. C++
2. CMake

## How to use

### According to documentation

1. Go to [this](https://download.pytorch.org/libtorch/cu102/libtorch-win-shared-with-deps-debug-1.8.1.zip) link, download the libtorch zip file. 
2. Unzip it: This unzipped folder contains libtorch. 
4. Now we make a `build` directory
    ```
    mkdir build
    cd build
    ```
4. use CMake to build the project  
    ```
    cmake -DCMAKE_PREFIX_PATH=/absolute/path/to/libtorch ..
    cmake --build . --config Release
    ```
    > The -DCMAKE_PREFIX_PATH = the absolute path of libtorch (eg. C:\Users\.......\libtorch-win-shared-with-deps-debug-1.8.1+cpu\libtorch)
    
5. Now run it using: <br>

    on Windows: `.\Release\LibtorchDemo.exe`<br>
    on Lnux & Mac: `./Libtorch`

### Alternative ways

You can also use Visual Studio. That is much simpler to do. If you're interested then follow this tutorial -> [Pytorch C++ Setup on Visual Studio 2019 - Windows](https://www.youtube.com/watch?v=6eTVqYGIWx0) 

> Note: this is the CPU-only version of PyTorch C++
