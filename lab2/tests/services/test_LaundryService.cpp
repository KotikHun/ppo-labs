#include <gtest/gtest.h>
#include "LaundryService.h"

TEST(LaundryServiceTest, CostCalculation) {
    LaundryService ls("Laundry", Money(100, Currency::RUB), 12); // 12 вещей (скидка)
    EXPECT_DOUBLE_EQ(ls.calculateCost().getAmount(), 1080.0);
}