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

TEST(CubeTest, SaveAndLoadAreSymmetric) {
    Cube original;
    original.rotateFace(0, true);
    original.rotateFace(2, false);
    original.rotateFace(5, true);

    std::ostringstream os;
    original.saveToStream(os);

    std::istringstream is(os.str());
    Cube loaded;
    loaded.loadFromStream(is);

    EXPECT_TRUE(original == loaded);
}

TEST(CubeTest, OutputOperatorWorks) {
    Cube c;
    std::ostringstream os;
    os << c;
    EXPECT_FALSE(os.str().empty());
}

TEST(CubeTest, InputOperatorWorks) {
    Cube original;
    original.rotateFace(0, true);

    std::ostringstream os;
    os << original;

    std::istringstream is(os.str());
    Cube loaded;
    is >> loaded;

    EXPECT_TRUE(original == loaded);
}

TEST(CubeTest, UCounterClockwiseFourTimesReturnsToOriginal) {
    Cube c;
    Cube original = c;
    for (int i = 0; i < 4; ++i) {
        c.rotateFace(0, false);
    }
    EXPECT_TRUE(c == original);
}

TEST(CubeTest, DCounterClockwiseFourTimesReturnsToOriginal) {
    Cube c;
    Cube original = c;
    for (int i = 0; i < 4; ++i) {
        c.rotateFace(1, false);
    }
    EXPECT_TRUE(c == original);
}

TEST(CubeTest, LCounterClockwiseFourTimesReturnsToOriginal) {
    Cube c;
    Cube original = c;
    for (int i = 0; i < 4; ++i) {
        c.rotateFace(2, false);
    }
    EXPECT_TRUE(c == original);
}

TEST(CubeTest, RCounterClockwiseFourTimesReturnsToOriginal) {
    Cube c;
    Cube original = c;
    for (int i = 0; i < 4; ++i) {
        c.rotateFace(3, false);
    }
    EXPECT_TRUE(c == original);
}

TEST(CubeTest, FCounterClockwiseFourTimesReturnsToOriginal) {
    Cube c;
    Cube original = c;
    for (int i = 0; i < 4; ++i) {
        c.rotateFace(4, false);
    }
    EXPECT_TRUE(c == original);
}

TEST(CubeTest, BCounterClockwiseFourTimesReturnsToOriginal) {
    Cube c;
    Cube original = c;
    for (int i = 0; i < 4; ++i) {
        c.rotateFace(5, false);
    }
    EXPECT_TRUE(c == original);
}

TEST(CubeTest, GetAndSetFace) {
    Cube c;
    Face newFace(Color::Red);
    c.setFace(0, newFace);

    Face retrieved = c.getFace(0);
    EXPECT_EQ(retrieved.getCell(0, 0), Color::Red);
    EXPECT_EQ(retrieved.getCell(2, 2), Color::Red);
}

TEST(CubeTest, AssignmentOperator) {
    Cube a;
    a.rotateFace(0, true);

    Cube b;
    b = a;

    EXPECT_TRUE(a == b);
}

TEST(CubeTest, SelfAssignment) {
    Cube c;
    c.rotateFace(0, true);
    Cube original = c;

    c = c;

    EXPECT_TRUE(c == original);
}