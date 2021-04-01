# LibtorchDemo
Trying out C++ frontend for PyTorch

## How to use

Follow the steps below
```
mkdir build
cd build
cmake -DCMAKE_PREFIX_PATH=/absolute/path/to/libtorch ..
cmake --build . --config Release
```

*Now run it using:* <br>

on Windows: `.\Release\LibtorchDemo.exe`<br>
on Lnux & Mac: `./Libtorch`
