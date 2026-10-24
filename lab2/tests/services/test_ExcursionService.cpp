#include <gtest/gtest.h>
#include "ExcursionService.h"

TEST(ExcursionServiceTest, CostCalculation) {
    ExcursionService es("Excursion", Money(100, Currency::RUB), 3); // 3 человека
    EXPECT_DOUBLE_EQ(es.calculateCost().getAmount(), 300.0);
}