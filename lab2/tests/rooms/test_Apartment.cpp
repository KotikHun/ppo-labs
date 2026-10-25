#include <gtest/gtest.h>
#include "Apartment.h"

TEST(ApartmentTest, Pricing) {
    Apartment room(201, 4, RoomStatus::Available, Money(1000, Currency::RUB), 3);
    EXPECT_DOUBLE_EQ(room.calculatePrice().getAmount(), 2000.0); // Наценка 2.0
}