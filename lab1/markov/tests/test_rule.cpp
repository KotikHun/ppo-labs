#include <gtest/gtest.h>
#include <sstream>
#include "Rule.h"

TEST(RuleTest, DefaultConstructorCreatesEmptyRule) {
    Rule r;
    EXPECT_EQ(r.getLeft(), "");
    EXPECT_EQ(r.getRight(), "");
    EXPECT_FALSE(r.getIsFinal());
}

TEST(RuleTest, ParameterizedConstructor) {
    Rule r("aa", "b", false);
    EXPECT_EQ(r.getLeft(), "aa");
    EXPECT_EQ(r.getRight(), "b");
    EXPECT_FALSE(r.getIsFinal());
}

TEST(RuleTest, ParameterizedConstructorFinal) {
    Rule r("b", "a", true);
    EXPECT_EQ(r.getLeft(), "b");
    EXPECT_EQ(r.getRight(), "a");
    EXPECT_TRUE(r.getIsFinal());
}

TEST(RuleTest, IsApplicableReturnsTrue) {
    Rule r("aa", "b", false);
    EXPECT_TRUE(r.isApplicable("aab"));
}

TEST(RuleTest, IsApplicableReturnsFalse) {
    Rule r("aa", "b", false);
    EXPECT_FALSE(r.isApplicable("abc"));
}

TEST(RuleTest, ApplyReplacesFirstOccurrence) {
    Rule r("aa", "b", false);
    std::string tape = "aab";
    bool result = r.apply(tape);
    EXPECT_EQ(tape, "bb");
    EXPECT_FALSE(result);
}

TEST(RuleTest, ApplyReturnsTrueForFinal) {
    Rule r("aa", "b", true);
    std::string tape = "aab";
    bool result = r.apply(tape);
    EXPECT_EQ(tape, "bb");
    EXPECT_TRUE(result);
}

TEST(RuleTest, ApplyReturnsFalseIfNotApplicable) {
    Rule r("aa", "b", false);
    std::string tape = "abc";
    bool result = r.apply(tape);
    EXPECT_EQ(tape, "abc");
    EXPECT_FALSE(result);
}

TEST(RuleTest, ApplyReplacesOnlyFirstOccurrence) {
    Rule r("a", "b", false);
    std::string tape = "aaa";
    r.apply(tape);
    EXPECT_EQ(tape, "baa");
}

TEST(RuleTest, EqualityOperatorForEqual) {
    Rule a("aa", "b", false);
    Rule b("aa", "b", false);
    EXPECT_TRUE(a == b);
}

TEST(RuleTest, EqualityOperatorForNotEqual) {
    Rule a("aa", "b", false);
    Rule b("aa", "c", false);
    EXPECT_FALSE(a == b);
}

TEST(RuleTest, EqualityOperatorForDifferentFinal) {
    Rule a("aa", "b", false);
    Rule b("aa", "b", true);
    EXPECT_FALSE(a == b);
}

TEST(RuleTest, InequalityOperator) {
    Rule a("aa", "b", false);
    Rule b("aa", "c", false);
    EXPECT_TRUE(a != b);
}

TEST(RuleTest, CopyConstructor) {
    Rule a("aa", "b", true);
    Rule b = a;
    EXPECT_EQ(b.getLeft(), "aa");
    EXPECT_EQ(b.getRight(), "b");
    EXPECT_TRUE(b.getIsFinal());
}

TEST(RuleTest, AssignmentOperator) {
    Rule a("aa", "b", true);
    Rule b;
    b = a;
    EXPECT_EQ(b.getLeft(), "aa");
    EXPECT_EQ(b.getRight(), "b");
    EXPECT_TRUE(b.getIsFinal());
}

TEST(RuleTest, SelfAssignment) {
    Rule a("aa", "b", true);
    a = a;
    EXPECT_EQ(a.getLeft(), "aa");
    EXPECT_EQ(a.getRight(), "b");
    EXPECT_TRUE(a.getIsFinal());
}

TEST(RuleTest, OutputOperatorNonFinal) {
    Rule r("aa", "b", false);
    std::ostringstream os;
    os << r;
    EXPECT_EQ(os.str(), "aa -> b");
}

TEST(RuleTest, OutputOperatorFinal) {
    Rule r("aa", "b", true);
    std::ostringstream os;
    os << r;
    EXPECT_EQ(os.str(), "aa ->. b");
}

TEST(RuleTest, InputOperatorNonFinal) {
    std::istringstream is("aa -> b");
    Rule r;
    is >> r;
    EXPECT_EQ(r.getLeft(), "aa");
    EXPECT_EQ(r.getRight(), "b");
    EXPECT_FALSE(r.getIsFinal());
}

TEST(RuleTest, InputOperatorFinal) {
    std::istringstream is("b ->. a");
    Rule r;
    is >> r;
    EXPECT_EQ(r.getLeft(), "b");
    EXPECT_EQ(r.getRight(), "a");
    EXPECT_TRUE(r.getIsFinal());
}