#include <gtest/gtest.h>
#include "TransferService.h"

TEST(TransferServiceTest, CostCalculation) {
    TransferService ts("Transfer", Money(100, Currency::RUB), 1.5); // 1.5 км
    EXPECT_DOUBLE_EQ(ts.calculateCost().getAmount(), 150.0);
}