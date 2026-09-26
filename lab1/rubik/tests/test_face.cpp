#include <gtest/gtest.h>
#include <sstream>
#include "Face.h"

TEST(FaceTest, DefaultConstructorCreatesWhiteFace) {
    Face f;
    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 3; ++c) {
            EXPECT_EQ(f.getCell(r, c), Color::White);
        }
    }
}

TEST(FaceTest, ColorConstructorCreatesColoredFace) {
    Face f(Color::Green);
    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 3; ++c) {
            EXPECT_EQ(f.getCell(r, c), Color::Green);
        }
    }
}

TEST(FaceTest, SetAndGetCell) {
    Face f;
    f.setCell(1, 2, Color::Red);
    EXPECT_EQ(f.getCell(1, 2), Color::Red);
    EXPECT_EQ(f.getCell(0, 0), Color::White);
}

TEST(FaceTest, CopyConstructor) {
    Face original(Color::Blue);
    Face copy = original;
    EXPECT_EQ(copy.getCell(0, 0), Color::Blue);
    EXPECT_EQ(copy.getCell(2, 2), Color::Blue);
}

TEST(FaceTest, CopyIsIndependent) {
    Face original(Color::Blue);
    Face copy = original;
    copy.setCell(0, 0, Color::Red);
    EXPECT_EQ(original.getCell(0, 0), Color::Blue);
    EXPECT_EQ(copy.getCell(0, 0), Color::Red);
}

TEST(FaceTest, AssignmentOperator) {
    Face a(Color::Blue);
    Face b;
    b = a;
    EXPECT_EQ(b.getCell(0, 0), Color::Blue);
}

TEST(FaceTest, SelfAssignment) {
    Face f(Color::Orange);
    f = f;
    EXPECT_EQ(f.getCell(0, 0), Color::Orange);
}

TEST(FaceTest, EqualityOperatorForEqual) {
    Face a(Color::White);
    Face b(Color::White);
    EXPECT_TRUE(a == b);
}

TEST(FaceTest, EqualityOperatorForNotEqual) {
    Face a(Color::White);
    Face b(Color::Yellow);
    EXPECT_FALSE(a == b);
}

TEST(FaceTest, InequalityOperator) {
    Face a(Color::White);
    Face b(Color::Yellow);
    EXPECT_TRUE(a != b);
}

TEST(FaceTest, RotateClockwise) {
    Face f;
    f.setCell(0, 0, Color::Red);
    f.setCell(0, 2, Color::Blue);
    f.setCell(2, 2, Color::Green);
    f.setCell(2, 0, Color::Yellow);

    f.rotateClockwise();

    EXPECT_EQ(f.getCell(0, 0), Color::Yellow);
    EXPECT_EQ(f.getCell(0, 2), Color::Red);
    EXPECT_EQ(f.getCell(2, 2), Color::Blue);
    EXPECT_EQ(f.getCell(2, 0), Color::Green);
}

TEST(FaceTest, RotateCounterClockwise) {
    Face f;
    f.setCell(0, 0, Color::Red);
    f.setCell(0, 2, Color::Blue);
    f.setCell(2, 2, Color::Green);
    f.setCell(2, 0, Color::Yellow);

    f.rotateCounterClockwise();

    EXPECT_EQ(f.getCell(0, 0), Color::Blue);
    EXPECT_EQ(f.getCell(0, 2), Color::Green);
    EXPECT_EQ(f.getCell(2, 2), Color::Yellow);
    EXPECT_EQ(f.getCell(2, 0), Color::Red);
}

TEST(FaceTest, FourClockwiseRotationsReturnToOriginal) {
    Face f;
    f.setCell(0, 0, Color::Red);
    f.setCell(0, 1, Color::Blue);
    f.setCell(0, 2, Color::Green);
    f.setCell(1, 0, Color::Yellow);
    f.setCell(1, 1, Color::Orange);

    Face original = f;

    for (int i = 0; i < 4; ++i) {
        f.rotateClockwise();
    }

    EXPECT_TRUE(f == original);
}

TEST(FaceTest, ClockwiseThenCounterReturnsToOriginal) {
    Face f(Color::Green);
    f.setCell(0, 0, Color::Red);
    Face original = f;

    f.rotateClockwise();
    f.rotateCounterClockwise();

    EXPECT_TRUE(f == original);
}

TEST(FaceTest, OutputOperator) {
    Face f;
    std::ostringstream os;
    os << f;
    std::string result = os.str();

    EXPECT_NE(result.find("0"), std::string::npos);
}

TEST(FaceTest, InputOperator) {
    std::istringstream is("1 1 1 2 2 2 3 3 3");
    Face f;
    is >> f;

    EXPECT_EQ(f.getCell(0, 0), Color::Yellow);
    EXPECT_EQ(f.getCell(1, 1), Color::Orange);
    EXPECT_EQ(f.getCell(2, 2), Color::Red);
}