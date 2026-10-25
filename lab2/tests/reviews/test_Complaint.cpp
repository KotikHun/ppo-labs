#include <gtest/gtest.h>
#include "Complaint.h"

TEST(ComplaintTest, Resolve) {
    Complaint c(Id(1), Comment("Bad", "Guest"), 2);
    EXPECT_FALSE(c.getIsResolved());
    c.resolve();
    EXPECT_TRUE(c.getIsResolved());
}