#include <gtest/gtest.h>
#include "CheckOut.h"

TEST(CheckOutTest, Basics) {
    CheckOut co(Id(1), Date(5,1,2023), true);
    EXPECT_TRUE(co.getRoomCleaned());
}