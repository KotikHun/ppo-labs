#include <gtest/gtest.h>
#include "CheckIn.h"

TEST(CheckInTest, Basics) {
    CheckIn ci(Id(1), Date(1,1,2023), "Admin");
    EXPECT_EQ(ci.getEmployeeName(), "Admin");
}