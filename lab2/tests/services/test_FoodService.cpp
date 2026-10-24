#include <gtest/gtest.h>
#include "FoodService.h"

TEST(FoodServiceTest, CostCalculation) {
    FoodService fs("Food", Money(100, Currency::RUB), true); // В номер (наценка)
    EXPECT_DOUBLE_EQ(fs.calculateCost().getAmount(), 120.0);

    FoodService fs2("Food", Money(100, Currency::RUB), false); // Не в номер
    EXPECT_DOUBLE_EQ(fs2.calculateCost().getAmount(), 100.0);
}