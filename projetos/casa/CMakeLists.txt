cmake_minimum_required(VERSION 3.17)
project(casa)

set(CMAKE_CXX_STANDARD 14)

add_executable(casa main.cpp)

target_link_libraries(casa -lOpenGL32 -lglfw3dll -lfreeGLUT -lglu32)