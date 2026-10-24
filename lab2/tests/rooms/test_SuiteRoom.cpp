#include <gtest/gtest.h>
#include "SuiteRoom.h"

TEST(SuiteRoomTest, Pricing) {
    SuiteRoom room(301, 4, RoomStatus::Available, Money(1000, Currency::RUB), true);
    EXPECT_DOUBLE_EQ(room.calculatePrice().getAmount(), 3000.0); // Наценка 3.0
}