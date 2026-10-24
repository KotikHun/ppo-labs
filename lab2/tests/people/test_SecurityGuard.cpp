#include <gtest/gtest.h>
#include "SecurityGuard.h"

TEST(SecurityGuardTest, Shift) {
    SecurityGuard sg("A", "B", Date(), ContactInfo(), Gender::Male, "Guard", 35000, "Night");
    EXPECT_EQ(sg.getShift(), "Night");
}