cmake_minimum_required(VERSION 3.17)
project(flor_de_abril)

set(CMAKE_CXX_STANDARD 14)

add_executable(flor_de_abril main.cpp)

target_link_libraries(flor_de_abril -lOpenGL32 -lglfw3dll -lfreeGLUT -lglu32)