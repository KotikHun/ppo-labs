#include <gtest/gtest.h>
#include "Cube.h"

TEST(CubeTest, DefaultConstructorCreatesSolvedCube) {
    Cube c;
    EXPECT_TRUE(c.isSolved());
}

TEST(CubeTest, UFourTimesReturnsToOriginal) {
    Cube c;
    Cube original = c;
    for (int i = 0; i < 4; ++i) {
        c.rotateFace(0, true);   // U по часовой
    }
    EXPECT_TRUE(c == original);
}

TEST(CubeTest, UClockwiseThenCounterReturnsToOriginal) {
    Cube c;
    Cube original = c;
    c.rotateFace(0, true);    // U по часовой
    c.rotateFace(0, false);   // U против часовой
    EXPECT_TRUE(c == original);
}

TEST(CubeTest, DFourTimesReturnsToOriginal) {
    Cube c;
    Cube original = c;
    for (int i = 0; i < 4; ++i) {
        c.rotateFace(1, true);   // D по часовой
    }
    EXPECT_TRUE(c == original);
}

TEST(CubeTest, LFourTimesReturnsToOriginal) {
    Cube c;
    Cube original = c;
    for (int i = 0; i < 4; ++i) {
        c.rotateFace(2, true);   // L по часовой
    }
    EXPECT_TRUE(c == original);
}

TEST(CubeTest, RFourTimesReturnsToOriginal) {
    Cube c;
    Cube original = c;
    for (int i = 0; i < 4; ++i) {
        c.rotateFace(3, true);   // R по часовой
    }
    EXPECT_TRUE(c == original);
}

TEST(CubeTest, FFourTimesReturnsToOriginal) {
    Cube c;
    Cube original = c;
    for (int i = 0; i < 4; ++i) {
        c.rotateFace(4, true);   // F по часовой
    }
    EXPECT_TRUE(c == original);
}

TEST(CubeTest, BFourTimesReturnsToOriginal) {
    Cube c;
    Cube original = c;
    for (int i = 0; i < 4; ++i) {
        c.rotateFace(5, true);   // B по часовой
    }
    EXPECT_TRUE(c == original);
}

TEST(CubeTest, RotateUChangesSolvedState) {
    Cube c;
    c.rotateFace(0, true);   // U по часовой
    EXPECT_FALSE(c.isSolved());
}

TEST(CubeTest, RandomizeMakesUnsolved) {
    Cube c;
    c.randomize();
    EXPECT_FALSE(c.isSolved());
}

TEST(CubeTest, CopyConstructor) {
    Cube c;
    c.rotateFace(0, true);   // перемешали
    Cube copy = c;
    EXPECT_TRUE(copy == c);
}

TEST(CubeTest, CopyIsIndependent) {
    Cube c;
    Cube copy = c;
    copy.rotateFace(0, true);
    EXPECT_TRUE(c.isSolved());
    EXPECT_FALSE(copy.isSolved());
}

TEST(CubeTest, EqualityOperatorForEqual) {
    Cube a;
    Cube b;
    EXPECT_TRUE(a == b);
}

TEST(CubeTest, EqualityOperatorForNotEqual) {
    Cube a;
    Cube b;
    b.rotateFace(0, true);
    EXPECT_FALSE(a == b);
}