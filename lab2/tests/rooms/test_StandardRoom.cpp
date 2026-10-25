#include <gtest/gtest.h>
#include "StandardRoom.h"

TEST(StandardRoomTest, Pricing) {
    StandardRoom room(101, 2, RoomStatus::Available, Money(1000, Currency::RUB), true);
    EXPECT_DOUBLE_EQ(room.calculatePrice().getAmount(), 1000.0);
    EXPECT_TRUE(room.getHasBalcony());
}