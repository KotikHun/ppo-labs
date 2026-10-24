#include <gtest/gtest.h>
#include "CardPayment.h"

TEST(CardPaymentTest, Process) {
    CardPayment valid(Money(100, Currency::RUB), Date(), "1234-5678");
    EXPECT_TRUE(valid.processPayment());
    EXPECT_EQ(valid.getStatus(), PaymentStatus::Success);

    CardPayment invalid(Money(100, Currency::RUB), Date(), ""); // Пустая карта
    EXPECT_FALSE(invalid.processPayment());
    EXPECT_EQ(invalid.getStatus(), PaymentStatus::Failed);
}