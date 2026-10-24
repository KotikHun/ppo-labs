#include <gtest/gtest.h>
#include "Company.h"

TEST(CompanyTest, Basics) {
    Company c("Google", "123456", Address());
    EXPECT_EQ(c.getName(), "Google");
}