#include <gtest/gtest.h>
#include "Date.h"

TEST(DateTest, BasicInstantiation) {
    Date d(15, 6, 2023);
    EXPECT_TRUE(d.isValid());
    EXPECT_EQ(d.getDay(), 15);
    EXPECT_EQ(d.getMonth(), 6);
    EXPECT_EQ(d.getYear(), 2023);
}

TEST(DateTest, Validation) {
    EXPECT_FALSE(Date(31, 2, 2023).isValid());
    EXPECT_FALSE(Date(1, 13, 2023).isValid());
}

TEST(DateTest, Arithmetic) {
    Date d(31, 1, 2023);
    Date next = d.addDays(1);
    EXPECT_EQ(next.getDay(), 1);
    EXPECT_EQ(next.getMonth(), 2);

    EXPECT_EQ(Date(1,1,2023).daysBetween(Date(3,1,2023)), 2);
}

TEST(DateTest, Operators) {
    Date d1(1, 1, 2023), d2(2, 1, 2023);
    EXPECT_TRUE(d1 < d2);
    EXPECT_TRUE(d2 > d1);
    EXPECT_TRUE(d1 != d2);
    EXPECT_TRUE(d1 <= d2);
    EXPECT_TRUE(d2 >= d1);
    EXPECT_TRUE(d1 == Date(1,1,2023));
}