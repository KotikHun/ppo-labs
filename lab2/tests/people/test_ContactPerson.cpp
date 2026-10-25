#include <gtest/gtest.h>
#include "ContactPerson.h"

TEST(ContactPersonTest, Company) {
    Person p("A", "B", Date(), ContactInfo(), Gender::Male);
    ContactPerson cp(p, "Partner LLC");
    EXPECT_EQ(cp.getCompanyName(), "Partner LLC");
}