#include <gtest/gtest.h>
#include "Person.h"

TEST(PersonTest, Basics) {
    Person p("Ivan", "Ivanov", Date(1,1,1990), ContactInfo(), Gender::Male);
    EXPECT_EQ(p.getFirstName(), "Ivan");
    p.setFirstName("Petr");
    EXPECT_EQ(p.getFirstName(), "Petr");
}