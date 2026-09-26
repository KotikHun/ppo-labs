cmake_minimum_required(VERSION 3.20)
project(rubik LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ========== Покрытие ==========
option(ENABLE_COVERAGE "Enable coverage" OFF)

if(ENABLE_COVERAGE)
    add_compile_options(--coverage -O0 -g)
    add_link_options(--coverage)
endif()

# ========== Библиотека с классами ==========
add_library(rubik_lib
        src/Face.cpp
        src/Cube.cpp
        src/ConsoleMenu.cpp
)

target_include_directories(rubik_lib PUBLIC include)

# ========== GoogleTest ==========
include(FetchContent)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
        DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# ========== Тесты ==========
enable_testing()

add_executable(rubik_tests
        tests/test_face.cpp
        tests/test_cube.cpp
        tests/test_cube.cpp
)

target_include_directories(rubik_tests PRIVATE include)

target_link_libraries(rubik_tests
        PRIVATE
        rubik_lib
        gtest
        gtest_main
)