#include <gtest/gtest.h>
#include "Address.h"

TEST(AddressTest, Basics) {
    Address addr("Russia", "Moscow", "Tverskaya", "12A");
    EXPECT_EQ(addr.getCountry(), "Russia");
    EXPECT_EQ(addr.getCity(), "Moscow");

    addr.setCity("SPb");
    EXPECT_EQ(addr.getCity(), "SPb");
    EXPECT_EQ(addr.toString(), "Russia, SPb, Tverskaya, 12A");
}