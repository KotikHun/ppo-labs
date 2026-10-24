#include <gtest/gtest.h>
#include "Feedback.h"

TEST(FeedbackTest, Basics) {
    Feedback f(Comment("Ok", "Anon"), Date(), "Website");
    EXPECT_EQ(f.getChannel(), "Website");
}