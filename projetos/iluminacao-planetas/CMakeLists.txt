cmake_minimum_required(VERSION 3.17)
project(iluminacao_planetas)

set(CMAKE_CXX_STANDARD 14)

add_executable(iluminacao_planetas main.cpp)

target_link_libraries(iluminacao_planetas -lOpenGL32 -lglfw3dll -lfreeGLUT -lglu32)