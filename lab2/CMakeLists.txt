cmake_minimum_required(VERSION 3.20)
project(lab2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ========== Покрытие ==========
option(ENABLE_COVERAGE "Enable coverage" OFF)
if(ENABLE_COVERAGE)
    add_compile_options(--coverage -O0 -g)
    add_link_options(--coverage)
endif()

# ========== Библиотека с классами ==========
add_library(lab2_lib
        src/core/Date.cpp
        src/core/Money.cpp
        src/core/Id.cpp
        src/core/Address.cpp
        src/core/ContactInfo.cpp
        src/people/Person.cpp
        src/people/Guest.cpp
)
target_include_directories(lab2_lib PUBLIC
        include
        include/core
        include/people
        include/rooms
        include/booking
        include/services
        include/payments
        include/documents
        include/reviews
        include/exceptions
        include/managers
)