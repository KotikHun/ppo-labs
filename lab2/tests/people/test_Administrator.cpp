#include <gtest/gtest.h>
#include "Administrator.h"

TEST(AdministratorTest, DeskNumber) {
    Administrator a("A", "B", Date(), ContactInfo(), Gender::Male, "Admin", 40000, 5);
    EXPECT_EQ(a.getDeskNumber(), 5);
}