cmake_minimum_required(VERSION 3.20)
project(lab2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

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
        src/people/VipGuest.cpp
        src/people/RegularGuest.cpp
        src/people/CorporateGuest.cpp
        src/people/Employee.cpp
        src/people/Manager.cpp
        src/people/Administrator.cpp
        src/people/Maid.cpp
        src/people/Chef.cpp
        src/people/SecurityGuard.cpp
        src/people/ContactPerson.cpp
        src/rooms/Room.cpp
        src/rooms/StandardRoom.cpp
        src/rooms/LuxRoom.cpp
        src/rooms/Apartment.cpp
        src/rooms/SuiteRoom.cpp
        src/rooms/Building.cpp
        src/rooms/Floor.cpp
        src/booking/Reservation.cpp
        src/booking/Company.cpp
        src/booking/GuestGroup.cpp
        src/booking/Stay.cpp
        src/booking/CheckIn.cpp
        src/booking/CheckOut.cpp
        src/services/Service.cpp
        src/services/CleaningService.cpp
        src/services/FoodService.cpp
        src/services/TransferService.cpp
        src/services/ExcursionService.cpp
        src/services/SpaService.cpp
        src/services/LaundryService.cpp
        src/services/ServiceOrder.cpp
        src/payments/Payment.cpp
        src/payments/CashPayment.cpp
        src/payments/CardPayment.cpp
        src/payments/OnlinePayment.cpp
        src/payments/Invoice.cpp
        src/payments/Tariff.cpp
        src/payments/Discount.cpp
        src/documents/Document.cpp
        src/documents/Passport.cpp
        src/documents/Visa.cpp
        src/documents/Contract.cpp
        src/documents/Receipt.cpp
        src/reviews/Rating.cpp
        src/reviews/Comment.cpp
        src/reviews/Review.cpp
        src/reviews/Feedback.cpp
        src/reviews/Complaint.cpp
        src/managers/GuestManager.cpp
        src/managers/RoomManager.cpp
        src/managers/BookingManager.cpp
        src/managers/ServiceManager.cpp
        src/managers/PaymentManager.cpp
        src/managers/StaffManager.cpp
        src/managers/ReportManager.cpp
        src/Hotel.cpp
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

add_executable(lab2_app main.cpp)
target_link_libraries(lab2_app PRIVATE lab2_lib)

# ==========================================
# Tests (GoogleTest)
# ==========================================
include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Собираем все файлы .cpp из папки tests (включая подпапки)
file(GLOB_RECURSE TEST_SOURCES "tests/*.cpp")

add_executable(lab2_tests ${TEST_SOURCES})

target_link_libraries(lab2_tests PRIVATE lab2_lib GTest::gtest_main)

# Добавляем пути, чтобы в тестах работали #include "Date.h" и т.д.
target_include_directories(lab2_tests PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/include/core
        ${CMAKE_CURRENT_SOURCE_DIR}/include/people
        ${CMAKE_CURRENT_SOURCE_DIR}/include/rooms
        ${CMAKE_CURRENT_SOURCE_DIR}/include/booking
        ${CMAKE_CURRENT_SOURCE_DIR}/include/services
        ${CMAKE_CURRENT_SOURCE_DIR}/include/payments
        ${CMAKE_CURRENT_SOURCE_DIR}/include/documents
        ${CMAKE_CURRENT_SOURCE_DIR}/include/reviews
        ${CMAKE_CURRENT_SOURCE_DIR}/include/managers
        ${CMAKE_CURRENT_SOURCE_DIR}/include/exceptions
)

target_link_libraries(lab2_tests PRIVATE lab2_lib GTest::gtest_main)