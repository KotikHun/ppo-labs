#include <gtest/gtest.h>
#include "ServiceOrder.h"

TEST(ServiceOrderTest, Basics) {
    ServiceOrder so(Id(1), Id(2), 1, Money(100, Currency::RUB));
    so.setStatus(ServiceStatus::Completed);
    EXPECT_EQ(so.getStatus(), ServiceStatus::Completed);
    EXPECT_EQ(so.getQuantity(), 1);
}