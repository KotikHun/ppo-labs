#include <gtest/gtest.h>
#include "LuxRoom.h"

TEST(LuxRoomTest, Pricing) {
    LuxRoom room(102, 2, RoomStatus::Available, Money(1000, Currency::RUB), true);
    EXPECT_DOUBLE_EQ(room.calculatePrice().getAmount(), 1500.0); // Наценка 1.5
}