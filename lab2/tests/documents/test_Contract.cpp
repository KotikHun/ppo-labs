#include <gtest/gtest.h>
#include "Contract.h"

TEST(ContractTest, Expiry) {
    Contract c("C1", Date(1,1,2020), Date(1,1,2030), Id(1));
    EXPECT_TRUE(c.isValid(Date(1,1,2025)));
    EXPECT_FALSE(c.isValid(Date(1,1,2035)));
}