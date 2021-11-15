cmake_minimum_required(VERSION 3.17)
project(ola)

set(CMAKE_CXX_STANDARD 14)

add_executable(ola main.cpp)

target_link_libraries(ola -lOpenGL32 -lglfw3dll -lfreeGLUT -lglu32)