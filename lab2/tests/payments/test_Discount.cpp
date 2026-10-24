#include <gtest/gtest.h>
#include "Discount.h"

TEST(DiscountTest, Apply) {
    Discount d("New Year", 20); // 20% скидка
    EXPECT_DOUBLE_EQ(d.apply(Money(100, Currency::RUB)).getAmount(), 80.0);
}