# LibtorchDemo

Trying out C++ frontend for PyTorch

## Requirements

1. C++
2. CMake

## How to use (Linux)

1. `wget https://download.pytorch.org/libtorch/cpu/libtorch-cxx11-abi-shared-with-deps-1.8.1%2Bcpu.zip`
2. `unzip libtorch-cxx11-abi-shared-with-deps-1.8.1+cpu.zip`
3. Clone this repo:

   ```
   git clone https://github.com/Abhiswain97/LibtorchDemo.git
   cd LibtorchDemo
   ```

4. Do `sh run.sh <absolute path to libtorch>`

5. If everything goes well, then below is what you should see:

<img src="libtorchdemo.png">

<br>

> Note: In our case only the `CPUFloatType{5, 5}` tensor prints, as we have installed the cpu-olny version of libtorch.
