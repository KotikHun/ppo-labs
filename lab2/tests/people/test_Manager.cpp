#include <gtest/gtest.h>
#include "Manager.h"

TEST(ManagerTest, MultipleInheritance) {
    Manager m("A", "B", Date(), ContactInfo(), Gender::Male, "Director", 100000, "1234", "HR");
    EXPECT_EQ(m.getDepartment(), "HR");
    EXPECT_EQ(m.getPosition(), "Director"); // Из Employee
    EXPECT_EQ(m.getLoyaltyPoints(), 0);     // Из Guest
}