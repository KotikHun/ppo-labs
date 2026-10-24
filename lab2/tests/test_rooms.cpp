#include <gtest/gtest.h>
#include "StandardRoom.h"
#include "LuxRoom.h"

TEST(RoomTest, StandardRoomPrice) {
    StandardRoom room(101, 2, RoomStatus::Available, Money(1000, Currency::RUB), true);
    Money price = room.calculatePrice();
    EXPECT_DOUBLE_EQ(price.getAmount(), 1000.0); // Коэффициент 1.0
}

TEST(RoomTest, LuxRoomPrice) {
    LuxRoom room(102, 2, RoomStatus::Available, Money(1000, Currency::RUB), true);
    Money price = room.calculatePrice();
    EXPECT_DOUBLE_EQ(price.getAmount(), 1500.0); // Коэффициент 1.5
}