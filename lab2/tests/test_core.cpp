#include <gtest/gtest.h>
#include "Date.h"
#include "Money.h"

// --- Тесты для Date ---
TEST(DateTest, ValidDate) {
    Date d(15, 6, 2023);
    EXPECT_TRUE(d.isValid());
    EXPECT_EQ(d.getDay(), 15);
    EXPECT_EQ(d.getMonth(), 6);
    EXPECT_EQ(d.getYear(), 2023);
}

TEST(DateTest, InvalidDate) {
    Date d(31, 2, 2023); // 31 февраля не бывает
    EXPECT_FALSE(d.isValid());
}

TEST(DateTest, AddDays) {
    Date d(31, 1, 2023);
    Date next = d.addDays(1);
    EXPECT_EQ(next.getDay(), 1);
    EXPECT_EQ(next.getMonth(), 2);
}

TEST(DateTest, Comparison) {
    Date d1(1, 1, 2023);
    Date d2(2, 1, 2023);
    EXPECT_TRUE(d1 < d2);
    EXPECT_TRUE(d1 != d2);
}

// --- Тесты для Money ---
TEST(MoneyTest, AddMoney) {
    Money m1(100.0, Currency::RUB);
    Money m2(50.0, Currency::RUB);
    Money result = m1.add(m2);
    EXPECT_DOUBLE_EQ(result.getAmount(), 150.0);
}

TEST(MoneyTest, SubtractMoney) {
    Money m1(100.0, Currency::RUB);
    Money m2(30.0, Currency::RUB);
    Money result = m1.subtract(m2);
    EXPECT_DOUBLE_EQ(result.getAmount(), 70.0);
}