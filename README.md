# LibtorchDemo

Trying out C++ frontend for PyTorch

## Requirements

<<<<<<< HEAD
Just install docker!

## Use with docker

1. Pull the image: `docker pull abhiswain97/libtorchdemo`

2. Run it: `docker run -ti abhiswain97/libtorchdemo /bin/bash -c "./LibtorchDemo"`

3. If everything goes well you should see:

   ```
   C:\Users\abhi0\Desktop\LibtorchDemo>docker run -ti abhiswain97/libtorchdemo /bin/bash -c "./LibtorchDemo" 
   Checking for cuda avalability: 
   cuda is not available
   -0.1336 -0.6198 -0.2604 -0.8663  1.2848
   0.0099 -1.0338 -3.0041 -1.4328 -0.2585
   -1.8973 -0.3134 -0.6984  0.6462  1.2177
   0.6520 -0.5877 -1.0204  0.8315 -1.5695
   -0.0769  1.3863 -0.9401 -1.3562  0.5110
   [ CPUFloatType{5,5} ]
   Only libtorch-cpu is setup properly!
   ```
=======
1. C++
2. CMake
  
## How to use (Linux)
>>>>>>> linux

> Note: This is only cpu version of libtorch


<<<<<<< HEAD
=======
## Use with docker





> Note 1: The `Torch_DIR` has to be set respectively. It mostly lies inside `<absolute path to libtorch>/libtorch/share/cmake/Torch`  
> Note 2: In our case only the `CPUFloatType{5, 5}` tensor will print, as we have installed the cpu-olny version of libtorch. However, I have the CUDA version also that's why you see two tensors print


>>>>>>> linux
