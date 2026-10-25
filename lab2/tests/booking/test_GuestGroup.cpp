#include <gtest/gtest.h>
#include "GuestGroup.h"

TEST(GuestGroupTest, ManageGuests) {
    GuestGroup g("Family");
    g.addGuest(Id(1));
    g.addGuest(Id(2));
    EXPECT_EQ(g.getGuestIds().size(), 2);
    g.removeGuest(Id(1));
    EXPECT_EQ(g.getGuestIds().size(), 1);
}