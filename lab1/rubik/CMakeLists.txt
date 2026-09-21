cmake_minimum_required(VERSION 3.20)
project(rubik LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ========== Библиотека ==========
add_library(rubik_lib
        src/Face.cpp
        tests/test_face.cpp
)

target_include_directories(rubik_lib PUBLIC include)