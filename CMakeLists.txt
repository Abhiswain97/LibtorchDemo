cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(LibtorchDemo)

set(Torch_DIR "D:\\libtorch-Windows\\libtorch-win-shared-with-deps-debug-1.8.1+cu111\\libtorch\\share\\cmake\\Torch")
set(PYTHON_EXECUTABLE "C:\\Users\\abhi0\\anaconda3\\python")
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