#include <gtest/gtest.h>
#include "Face.h"

TEST(FaceTest, DefaultConstructorCreatesWhiteFace) {
    Face f;
    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 3; ++c) {
            EXPECT_EQ(f.getCell(r, c), Color::White);
        }
    }
}