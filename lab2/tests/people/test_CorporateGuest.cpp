#include <gtest/gtest.h>
#include "CorporateGuest.h"

TEST(CorporateGuestTest, Company) {
    CorporateGuest c("A", "B", Date(), ContactInfo(), Gender::Male, "1234", "Google");
    EXPECT_EQ(c.getCompanyName(), "Google");
}