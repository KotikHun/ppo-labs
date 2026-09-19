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
