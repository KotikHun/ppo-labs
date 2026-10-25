#include <gtest/gtest.h>
#include "Rating.h"

TEST(RatingTest, Validation) {
    Rating r;
    r.setScore(4);
    EXPECT_EQ(r.getScore(), 4);
    r.setScore(10); // Недопустимо, должно остаться 4
    EXPECT_EQ(r.getScore(), 4);
}