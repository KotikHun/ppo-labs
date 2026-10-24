#include <gtest/gtest.h>
#include "Building.h"

TEST(BuildingTest, Basics) {
    Building b(1, "Main", Address(), 5);
    EXPECT_EQ(b.getFloorsCount(), 5);
    EXPECT_EQ(b.getName(), "Main");
}