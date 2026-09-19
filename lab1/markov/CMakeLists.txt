cmake_minimum_required(VERSION 3.20)
project(markov LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ========== Покрытие ==========
option(ENABLE_COVERAGE "Enable coverage" OFF)

if(ENABLE_COVERAGE)
    add_compile_options(--coverage -O0 -g)
    add_link_options(--coverage)
endif()

# ========== Библиотека с классами ==========
add_library(markov_lib
        src/Alphabet.cpp
        src/Rule.cpp
        src/MarkovAlgorithm.cpp
        src/ConsoleMenu.cpp
)

target_include_directories(markov_lib PUBLIC include)

# ========== Основная программа ==========
add_executable(markov
        src/main.cpp
)

target_link_libraries(markov PRIVATE markov_lib)

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

add_executable(markov_tests
        tests/test_alphabet.cpp
        tests/test_rule.cpp
        tests/test_markov_algorithm.cpp
)

target_include_directories(markov_tests PRIVATE include)

target_link_libraries(markov_tests
        PRIVATE
        markov_lib
        gtest
        gtest_main
)