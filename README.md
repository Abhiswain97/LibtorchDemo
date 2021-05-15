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
4. For Linux your CMakeLists.txt should contain:

```
cmake_minimum_required (VERSION 3.8)

project(LibtorchDemo)

set(Torch_DIR "/home/abhishek/libtorch/share/cmake/Torch")
set(PYTHON_EXECUTABLE "/home/abhishek/miniconda3/bin/python")

find_package(Torch REQUIRED)

set(CXXFLAGS "-W -Wall -Wextra -Werror -std=c++14")

# Add source to this project's executable.
add_executable(LibtorchDemo "LibtorchDemo.cpp")

target_link_libraries(LibtorchDemo "${TORCH_LIBRARIES}")
```

5. Do `sh run.sh <absolute path to libtorch>`

6. If everything goes well, then below is what you should see:

```
(base) ➜  LibtorchDemo git:(main) ✗ sh run.sh ~/libtorch
Creating build folder and building the project
-- The C compiler identification is GNU 9.3.0
-- The CXX compiler identification is GNU 9.3.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Looking for pthread.h
-- Looking for pthread.h - found
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD - Failed
-- Looking for pthread_create in pthreads
-- Looking for pthread_create in pthreads - not found
-- Looking for pthread_create in pthread
-- Looking for pthread_create in pthread - found
-- Found Threads: TRUE
-- Found CUDA: /usr/local/cuda (found version "11.2")
-- Caffe2: CUDA detected: 11.2
-- Caffe2: CUDA nvcc is: /usr/local/cuda/bin/nvcc
-- Caffe2: CUDA toolkit directory: /usr/local/cuda
-- Caffe2: Header version is: 11.2
-- Found CUDNN: /usr/lib/x86_64-linux-gnu/libcudnn.so
-- Found cuDNN: v8.1.1  (include: /usr/include, library: /usr/lib/x86_64-linux-gnu/libcudnn.so)
-- /usr/local/cuda/lib64/libnvrtc.so shorthash is 369df368
-- Autodetected CUDA architecture(s):  6.1
-- Added CUDA NVCC flags for: -gencode;arch=compute_61,code=sm_61
-- Found Torch: /home/abhishek/libtorch/lib/libtorch.so
-- Configuring done
-- Generating done
-- Build files have been written to: /home/abhishek/Desktop/LibtorchDemo/build
[ 50%] Building CXX object CMakeFiles/LibtorchDemo.dir/LibtorchDemo.cpp.o
[100%] Linking CXX executable LibtorchDemo
[100%] Built target LibtorchDemo
Checking for cuda avalability:
cuda is available!
 1.0814  0.8394  0.0384 -0.2273  1.0203
 0.2249 -0.4426 -0.5200  1.2232 -1.4246
 0.8897  0.2271 -2.1782  1.2484  0.5803
-1.4917  0.8680 -0.4567 -0.8395 -1.2555
-1.3380 -1.3143  0.8531  0.6529  0.2630
[ CUDAFloatType{5,5} ]
 1.0814  0.8394  0.0384 -0.2273  1.0203
 0.2249 -0.4426 -0.5200  1.2232 -1.4246
 0.8897  0.2271 -2.1782  1.2484  0.5803
-1.4917  0.8680 -0.4567 -0.8395 -1.2555
-1.3380 -1.3143  0.8531  0.6529  0.2630
[ CPUFloatType{5,5} ]
libtorch-gpu & libtorch-cpu is setup properly!
```

<br>

> Note: In our case only the `CPUFloatType{5, 5}` tensor will print, as we have installed the cpu-olny version of libtorch. However, I have the CUDA version also that's why you see two tensors print
