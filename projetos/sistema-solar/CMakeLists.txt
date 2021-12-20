cmake_minimum_required(VERSION 3.17)
project(sistema_solar)

set(CMAKE_CXX_STANDARD 14)

add_executable(sistema_solar main.cpp)

target_link_libraries(sistema_solar -lOpenGL32 -lglfw3dll -lfreeGLUT -lglu32)