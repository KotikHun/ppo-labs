#include <gtest/gtest.h>
#include "CleaningService.h"

TEST(CleaningServiceTest, CostCalculation) {
    CleaningService cs("Clean", Money(100, Currency::RUB), 3);
    EXPECT_DOUBLE_EQ(cs.calculateCost().getAmount(), 300.0);
    EXPECT_EQ(cs.getRoomsCount(), 3);
}