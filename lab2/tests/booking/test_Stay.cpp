#include <gtest/gtest.h>
#include "Stay.h"

TEST(StayTest, Basics) {
    Stay s(Id(1), Id(2), Date(1,1,2023), Date(5,1,2023));
    EXPECT_EQ(s.getCheckInDate(), Date(1,1,2023));
}