#include <gtest/gtest.h>
#include "Visa.h"

TEST(VisaTest, Expiry) {
    Visa v("V1", Date(1,1,2020), Date(1,1,2030), "Tourist");
    EXPECT_TRUE(v.isValid(Date(1,1,2025)));
    EXPECT_FALSE(v.isValid(Date(1,1,2035)));
}