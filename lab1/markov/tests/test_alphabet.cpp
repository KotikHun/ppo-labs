#include <gtest/gtest.h>
#include "Alphabet.h"

TEST(AlphabetTest, DefaultConstructorCreatesEmptyAlphabet) {
    Alphabet a;
    EXPECT_EQ(a.size(), 0);
}

TEST(AlphabetTest, AddIncreasesSize) {
    Alphabet a;
    a.add('x');
    EXPECT_EQ(a.size(), 1);
    a.add('y');
    EXPECT_EQ(a.size(), 2);
}

TEST(AlphabetTest, AddDuplicateDoesNotIncreaseSize) {
    Alphabet a;
    a.add('x');
    a.add('x');
    EXPECT_EQ(a.size(), 1);
}

TEST(AlphabetTest, ContainsReturnsTrueForExisting) {
    Alphabet a;
    a.add('x');
    EXPECT_TRUE(a.contains('x'));
}

TEST(AlphabetTest, ContainsReturnsFalseForMissing) {
    Alphabet a;
    a.add('x');
    EXPECT_FALSE(a.contains('y'));
}

TEST(AlphabetTest, ContainsReturnsFalseForEmpty) {
    Alphabet a;
    EXPECT_FALSE(a.contains('x'));
}

TEST(AlphabetTest, GetAllReturnsCopy) {
    Alphabet a;
    a.add('x');
    a.add('y');

    std::set<char> all = a.getAll();
    EXPECT_EQ(all.size(), 2);
    EXPECT_TRUE(all.count('x') == 1);
    EXPECT_TRUE(all.count('y') == 1);
}

TEST(AlphabetTest, EqualityOperatorForEqual) {
    Alphabet a, b;
    a.add('x');
    a.add('y');
    b.add('x');
    b.add('y');
    EXPECT_TRUE(a == b);
}

TEST(AlphabetTest, EqualityOperatorForNotEqual) {
    Alphabet a, b;
    a.add('x');
    b.add('y');
    EXPECT_FALSE(a == b);
}

TEST(AlphabetTest, InequalityOperator) {
    Alphabet a, b;
    a.add('x');
    b.add('y');
    EXPECT_TRUE(a != b);
}

TEST(AlphabetTest, CopyConstructor) {
    Alphabet a;
    a.add('x');
    a.add('y');

    Alphabet b = a;
    EXPECT_EQ(b.size(), 2);
    EXPECT_TRUE(b.contains('x'));
    EXPECT_TRUE(b.contains('y'));
}

TEST(AlphabetTest, CopyIsIndependent) {
    Alphabet a;
    a.add('x');

    Alphabet b = a;
    b.add('y');

    EXPECT_EQ(a.size(), 1);
    EXPECT_EQ(b.size(), 2);
}

TEST(AlphabetTest, AssignmentOperator) {
    Alphabet a, b;
    a.add('x');
    a.add('y');

    b = a;
    EXPECT_EQ(b.size(), 2);
    EXPECT_TRUE(b.contains('x'));
    EXPECT_TRUE(b.contains('y'));
}

TEST(AlphabetTest, SelfAssignment) {
    Alphabet a;
    a.add('x');

    a = a;
    EXPECT_EQ(a.size(), 1);
    EXPECT_TRUE(a.contains('x'));
}

TEST(AlphabetTest, OutputOperator) {
    Alphabet a;
    a.add('a');
    a.add('b');
    a.add('c');

    std::ostringstream os;
    os << a;
    EXPECT_EQ(os.str(), "abc");
}

TEST(AlphabetTest, InputOperator) {
    std::istringstream is("abc");
    Alphabet a;
    is >> a;

    EXPECT_EQ(a.size(), 3);
    EXPECT_TRUE(a.contains('a'));
    EXPECT_TRUE(a.contains('b'));
    EXPECT_TRUE(a.contains('c'));
}