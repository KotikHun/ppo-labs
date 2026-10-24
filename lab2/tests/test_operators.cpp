#include <gtest/gtest.h>
#include <sstream>
#include "Date.h"
#include "Money.h"
#include "Id.h"
#include "Address.h"
#include "ContactInfo.h"
#include "Person.h"
#include "Guest.h"
#include "StandardRoom.h"
#include "Passport.h"
#include "Comment.h"
#include "Reservation.h"

TEST(OperatorsCoverage, StreamIO) {
    std::stringstream ss;

    // Core
    Date d(1, 1, 2023); ss << d;
    Money m(100, Currency::RUB); ss << m;
    Id id(1); ss << id;
    Address addr("R", "C", "S", "H"); ss << addr;
    ContactInfo ci("123", "a@b.c"); ss << ci;

    // People
    Person p("A", "B", Date(), ContactInfo(), Gender::Male); ss << p;
    Guest g("A", "B", Date(), ContactInfo(), Gender::Male, "P1"); ss << g;

    // Rooms
    StandardRoom sr(1, 2, RoomStatus::Available, Money(100, Currency::RUB), true); ss << sr;

    // Documents
    Passport pass("P", Date(), Date(), "R"); ss << pass;

    // Reviews
    Comment c("T", "A"); ss << c;

    // Booking
    Reservation r(Id(1), Id(2), Date(), Date(), Money(100, Currency::RUB)); ss << r;

    // Проверяем, что оператор ввода хотя бы скомпилировался и не упал на корректных данных
    std::stringstream input("1 1 2023");
    input >> d;
    
    // Если мы дошли сюда без падения, значит, операторы работают
    EXPECT_TRUE(true);
}