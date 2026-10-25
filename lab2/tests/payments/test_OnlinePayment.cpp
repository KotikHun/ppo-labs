#include <gtest/gtest.h>
#include "OnlinePayment.h"

TEST(OnlinePaymentTest, Process) {
    OnlinePayment valid(Money(100, Currency::RUB), Date(), "test@mail.com");
    EXPECT_TRUE(valid.processPayment());
    EXPECT_EQ(valid.getStatus(), PaymentStatus::Success);

    OnlinePayment invalid(Money(100, Currency::RUB), Date(), "invalid-email");
    EXPECT_FALSE(invalid.processPayment());
}