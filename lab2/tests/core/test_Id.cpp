#include <gtest/gtest.h>
#include "Id.h"

TEST(IdTest, Generation) {
    Id id1;
    Id id2;
    EXPECT_NE(id1.getValue(), id2.getValue()); // ID должны быть разными
}

TEST(IdTest, ManualSet) {
    Id id(42);
    EXPECT_EQ(id.getValue(), 42);
    id.setValue(100);
    EXPECT_EQ(id.getValue(), 100);
}

TEST(IdTest, Operators) {
    Id id1(1), id2(2);
    EXPECT_TRUE(id1 < id2);
    EXPECT_TRUE(id1 != id2);
}