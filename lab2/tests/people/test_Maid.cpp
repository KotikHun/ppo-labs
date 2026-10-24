#include <gtest/gtest.h>
#include "Maid.h"

TEST(MaidTest, CleanRoom) {
    Maid m("A", "B", Date(), ContactInfo(), Gender::Female, "Maid", 30000, 0);
    m.cleanRoom();
    EXPECT_EQ(m.getCleanedRoomsCount(), 1);
}