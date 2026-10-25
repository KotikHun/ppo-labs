#include <gtest/gtest.h>
#include "Employee.h"

TEST(EmployeeTest, Position) {
    Employee e("A", "B", Date(), ContactInfo(), Gender::Male, "Manager", 50000);
    EXPECT_EQ(e.getPosition(), "Manager");
    EXPECT_DOUBLE_EQ(e.getSalary(), 50000);
}