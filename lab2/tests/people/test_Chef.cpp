#include <gtest/gtest.h>
#include "Chef.h"

TEST(ChefTest, Specialty) {
    Chef c("A", "B", Date(), ContactInfo(), Gender::Male, "Chef", 60000, "Pastry");
    EXPECT_EQ(c.getSpecialty(), "Pastry");
}