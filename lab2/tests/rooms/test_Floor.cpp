#include <gtest/gtest.h>
#include "Floor.h"

TEST(FloorTest, Basics) {
    Floor f(1, 10, "Standard");
    EXPECT_EQ(f.getRoomsCount(), 10);
}