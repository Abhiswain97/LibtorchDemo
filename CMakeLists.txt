# CMakeList.txt : CMake project for LibtorchDemo, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

find_package(Torch REQUIRED)

# Add source to this project's executable.
add_executable (LibtorchDemo "LibtorchDemo.cpp" "LibtorchDemo.h")

target_link_libraries(LibtorchDemo "${TORCH_LIBRARIES}")

if (MSVC)
  file(GLOB TORCH_DLLS "${TORCH_INSTALL_PREFIX}/lib/*.dll")
  add_custom_command(TARGET LibtorchDemo
                     POST_BUILD
                     COMMAND ${CMAKE_COMMAND} -E copy_if_different
                     ${TORCH_DLLS}
                     $<TARGET_FILE_DIR:LibtorchDemo>)
endif (MSVC)
# TODO: Add tests and install targets if needed.
