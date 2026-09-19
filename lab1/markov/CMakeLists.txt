cmake_minimum_required(VERSION 3.20)
project(markov LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDART_REQUIRED ON)

add_executable(markov
        src/main.cpp
        src/Alphabet.cpp
        src/Rule.cpp
        src/MarkovAlgorithm.cpp
        src/ConsolMenu.cpp
)

target_include_directories(markov PRIVATE include)


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
        src/Alphabet.cpp
        src/Rule.cpp
        src/MarkovAlgorithm.cpp
        tests/test_rule.cpp
        tests/test_markov_algorithm.cpp
)

target_include_directories(markov_tests PRIVATE include)

target_link_libraries(markov_tests
        PRIVATE
        gtest
        gtest_main
)

# ========== Покрытие ==========
option(ENABLE_COVERAGE "Enable coverage" OFF)

if(ENABLE_COVERAGE)
    target_compile_options(markov_tests PRIVATE --coverage -O0 -g)
    target_link_options(markov_tests PRIVATE --coverage)
endif()