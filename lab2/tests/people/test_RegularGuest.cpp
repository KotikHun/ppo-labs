#include <gtest/gtest.h>
#include "RegularGuest.h"

TEST(RegularGuestTest, Visits) {
    RegularGuest r("A", "B", Date(), ContactInfo(), Gender::Male, "1234");
    r.incrementVisitCount();
    EXPECT_EQ(r.getVisitCount(), 1);
}