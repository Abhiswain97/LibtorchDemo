# LibtorchDemo

Trying out C++ frontend for PyTorch

## Requirements

1. C++
2. CMake

## Use with docker

Check out my other repo [libtorch-cpu-docker](https://github.com/Abhiswain97/libtorch-cpu-docker) to see how to use with docker

## How to use (Windows)

1. Download libtorch from: [here](https://download.pytorch.org/libtorch/cpu/libtorch-win-shared-with-deps-debug-1.8.1%2Bcpu.zip)
2. Unzip it. Inside it is the libtorch folder. This is your path to libtorch
3. Clone this repo:

   ```
   git clone https://github.com/Abhiswain97/LibtorchDemo.git
   cd LibtorchDemo
   ```
4. For Windows your CMakeLists.txt should contain (by default this repo is made to run on Windows):

   ```
   cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
   project(LibtorchDemo)

   set(Torch_DIR "D:\\libtorch-Windows\\libtorch-win-shared-with-deps-debug-1.8.1+cu111\\libtorch\\share\\cmake\\Torch")
   find_package(Torch REQUIRED)
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")

   add_executable(LibtorchDemo LibtorchDemo.cpp)
   target_link_libraries(LibtorchDemo "${TORCH_LIBRARIES}")
   set_property(TARGET LibtorchDemo PROPERTY CXX_STANDARD 14)

   # The following code block is suggested to be used on Windows.
   # According to https://github.com/pytorch/pytorch/issues/25457,
   # the DLLs need to be copied to avoid memory errors.
   if (MSVC)
     file(GLOB TORCH_DLLS "${TORCH_INSTALL_PREFIX}/lib/*.dll")
     add_custom_command(TARGET LibtorchDemo
                        POST_BUILD
                        COMMAND ${CMAKE_COMMAND} -E copy_if_different
                        ${TORCH_DLLS}
                        $<TARGET_FILE_DIR:LibtorchDemo>)
   endif (MSVC)
   ```
5. You need to set the `Torch_DIR` in CMakeLists.txt to absolute path to `Torch`. In step 2, indside the libtorch folder, `Torch` is inside `libtorch\\share\\cmake\\Torch`. Mostly the standard CMakeLists.txt doesn't throw up any error even if you don't set the `Torch_DIR`. Incase it does, you set the `Torch_DIR` 
 
6. Do `run.bat <absolute path to libtorch>`

7. If everything goes well, then below is what you should see:
   ```
   C:\Users\abhi0\Desktop\LibtorchDemo>run.bat "D:\libtorch-Windows\libtorch-win-shared-with-deps-debug-1.8.1+cu111"
   path to libtorch is: "D:\libtorch-Windows\libtorch-win-shared-with-deps-debug-1.8.1+cu111"
   -- Building for: Visual Studio 16 2019
   -- The C compiler identification is MSVC 19.28.29915.0
   -- The CXX compiler identification is MSVC 19.28.29915.0
   -- Detecting C compiler ABI info
   -- Detecting C compiler ABI info - done
   -- Check for working C compiler: C:/Program Files (x86)/Microsoft Visual Studio/2019/Community/VC/Tools/MSVC/14.28.29910/bin/Hostx64/x64/cl.exe - skipped
   -- Detecting C compile features
   -- Detecting C compile features - done
   -- Detecting CXX compiler ABI info
   -- Detecting CXX compiler ABI info - done
   -- Check for working CXX compiler: C:/Program Files (x86)/Microsoft Visual Studio/2019/Community/VC/Tools/MSVC/14.28.29910/bin/Hostx64/x64/cl.exe - skipped
   -- Detecting CXX compile features
   -- Detecting CXX compile features - done
   -- Looking for pthread.h
   -- Looking for pthread.h - not found
   -- Found Threads: TRUE
   -- Found CUDA: C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v11.2 (found version "11.2")
   -- Caffe2: CUDA detected: 11.2
   -- Caffe2: CUDA nvcc is: C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v11.2/bin/nvcc.exe
   -- Caffe2: CUDA toolkit directory: C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v11.2
   -- Caffe2: Header version is: 11.2
   -- Found CUDNN: C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v11.2/lib/x64/cudnn.lib
   -- Found cuDNN: v8.1.0  (include: C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v11.2/include, library: C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v11.2/lib/x64/cudnn.lib)
   -- C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v11.2/lib/x64/nvrtc.lib shorthash is aa1d5a72
   -- Autodetected CUDA architecture(s):  6.1
   -- Added CUDA NVCC flags for: -gencode;arch=compute_61,code=sm_61
   -- Found Torch: D:/libtorch-Windows/libtorch-win-shared-with-deps-debug-1.8.1+cu111/libtorch/lib/torch.lib
   -- Configuring done
   -- Generating done
   -- Build files have been written to: C:/Users/abhi0/Desktop/LibtorchDemo/build

   Build finished. Executable created. Running it!

   Checking for cuda avalability:
   cuda is available!
    0.8093 -1.1354 -0.2401 -0.0059  0.7970
    1.0390  1.2386 -0.4145  1.4510  0.6607
   -0.9958  0.6723 -0.5838 -0.0190 -0.4640
   -0.0024 -0.1334 -1.2071 -0.3401 -0.9488
    0.4475  0.1180 -0.0469 -0.1800 -0.4797
   [ CUDAFloatType{5,5} ]
    0.8093 -1.1354 -0.2401 -0.0059  0.7970
    1.0390  1.2386 -0.4145  1.4510  0.6607
   -0.9958  0.6723 -0.5838 -0.0190 -0.4640
   -0.0024 -0.1334 -1.2071 -0.3401 -0.9488
    0.4475  0.1180 -0.0469 -0.1800 -0.4797
   [ CPUFloatType{5,5} ]
   libtorch-gpu & libtorch-cpu is setup properly!
   ```
  
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

> Note 1: The `Torch_DIR` has to be set respectively. It mostly lies inside `<absolute path to libtorch>/libtorch/share/cmake/Torch`  
> Note 2: In our case only the `CPUFloatType{5, 5}` tensor will print, as we have installed the cpu-olny version of libtorch. However, I have the CUDA version also that's why you see two tensors print
