#include <gtest/gtest.h>
#include "Guest.h"

TEST(GuestTest, Loyalty) {
    Guest g("A", "B", Date(), ContactInfo(), Gender::Male, "1234");
    EXPECT_EQ(g.getLoyaltyPoints(), 0);
    g.addLoyaltyPoints(50);
    EXPECT_EQ(g.getLoyaltyPoints(), 50);
}