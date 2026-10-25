#include <gtest/gtest.h>
#include "Comment.h"

TEST(CommentTest, Basics) {
    Comment c("Good", "Ivan");
    EXPECT_EQ(c.getText(), "Good");
    EXPECT_EQ(c.getAuthor(), "Ivan");
}