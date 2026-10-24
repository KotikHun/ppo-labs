#include <gtest/gtest.h>
#include "Money.h"

TEST(MoneyTest, Arithmetic) {
    Money m1(100.0, Currency::RUB);
    Money m2(50.0, Currency::RUB);

    EXPECT_DOUBLE_EQ(m1.add(m2).getAmount(), 150.0);
    EXPECT_DOUBLE_EQ(m1.subtract(m2).getAmount(), 50.0);
    EXPECT_DOUBLE_EQ(m1.multiply(2.0).getAmount(), 200.0);
}

TEST(MoneyTest, Operators) {
    Money m1(100.0, Currency::RUB);
    Money m2(50.0, Currency::RUB);
    Money m3(100.0, Currency::RUB);

    EXPECT_TRUE(m1 > m2);
    EXPECT_TRUE(m2 < m1);
    EXPECT_TRUE(m1 >= m3);
    EXPECT_TRUE(m1 <= m3);
    EXPECT_TRUE(m1 == m3);
}

TEST(MoneyTest, ToString) {
    Money m(100.5, Currency::USD);
    EXPECT_EQ(m.toString(), "100.50 USD");
}