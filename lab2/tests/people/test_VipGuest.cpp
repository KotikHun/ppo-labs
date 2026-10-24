#include <gtest/gtest.h>
#include "VipGuest.h"

TEST(VipGuestTest, Discount) {
    VipGuest v("A", "B", Date(), ContactInfo(), Gender::Male, "1234", 15);
    EXPECT_EQ(v.getDiscountPercent(), 15);
}