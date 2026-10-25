#include <gtest/gtest.h>
#include "Passport.h"

TEST(PassportTest, Expiry) {
    Passport p("123", Date(1,1,2020), Date(1,1,2030), "Russia");
    EXPECT_TRUE(p.isValid(Date(1,1,2025)));
    EXPECT_FALSE(p.isValid(Date(1,1,2035)));
    EXPECT_EQ(p.getCountry(), "Russia");
}