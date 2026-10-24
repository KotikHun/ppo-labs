#include <gtest/gtest.h>
#include "CashPayment.h"

TEST(CashPaymentTest, Process) {
    CashPayment p(Money(100, Currency::RUB), Date(), Money(0, Currency::RUB));
    EXPECT_TRUE(p.processPayment());
    EXPECT_EQ(p.getStatus(), PaymentStatus::Success);
}