#include <gtest/gtest.h>
#include "Review.h"

TEST(ReviewTest, Basics) {
    Review r(Id(1), Rating(5), Comment("Great", "Ivan"), Date());
    EXPECT_EQ(r.getGuestId().getValue(), 1);
    EXPECT_EQ(r.getRating().getScore(), 5);
}