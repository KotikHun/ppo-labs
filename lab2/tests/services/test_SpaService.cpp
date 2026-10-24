#include <gtest/gtest.h>
#include "SpaService.h"

TEST(SpaServiceTest, CostCalculation) {
    SpaService ss("Spa", Money(100, Currency::RUB), 2); // 2 часа
    EXPECT_DOUBLE_EQ(ss.calculateCost().getAmount(), 300.0); // 100 * 2 * 1.5
}