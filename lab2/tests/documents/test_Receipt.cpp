#include <gtest/gtest.h>
#include "Receipt.h"

TEST(ReceiptTest, Expiry) {
    Receipt r("R1", Date(1,1,2020), Date(1,1,2030), Money(100, Currency::RUB));
    EXPECT_TRUE(r.isValid(Date(1,1,2025)));
    EXPECT_FALSE(r.isValid(Date(1,1,2035)));
}