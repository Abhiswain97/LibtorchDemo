cmake_minimum_required (VERSION 3.8)

project(LibtorchDemo)

set(Torch_DIR "libtorch-cxx11-abi-shared-with-deps-1.8.1+cpu/libtorch/share/cmake/Torch")
set(PYTHON_EXECUTABLE "/usr/bin/python3")

find_package(Torch REQUIRED)

set(CXXFLAGS "-W -Wall -Wextra -Werror -std=c++14")

# Add source to this project's executable.
add_executable(LibtorchDemo "LibtorchDemo.cpp")

target_link_libraries(LibtorchDemo "${TORCH_LIBRARIES}")
