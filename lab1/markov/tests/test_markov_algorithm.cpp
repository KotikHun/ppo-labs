#include <gtest/gtest.h>
#include <sstream>
#include "MarkovAlgorithm.h"

TEST(MarkovAlgorithmTest, DefaultConstructor) {
    MarkovAlgorithm m;
    EXPECT_EQ(m.ruleCount(), 0);
    EXPECT_EQ(m.getTape(), "");
}

TEST(MarkovAlgorithmTest, SetAndGetAlphabet) {
    MarkovAlgorithm m;
    Alphabet a;
    a.add('x');
    a.add('y');
    m.setAlphabet(a);

    Alphabet result = m.getAlphabet();
    EXPECT_EQ(result.size(), 2);
    EXPECT_TRUE(result.contains('x'));
    EXPECT_TRUE(result.contains('y'));
}

TEST(MarkovAlgorithmTest, AddRuleIncreasesCount) {
    MarkovAlgorithm m;
    EXPECT_EQ(m.ruleCount(), 0);
    m.addRule(Rule("aa", "b", false));
    EXPECT_EQ(m.ruleCount(), 1);
    m.addRule(Rule("b", "a", true));
    EXPECT_EQ(m.ruleCount(), 2);
}

TEST(MarkovAlgorithmTest, RemoveRuleDecreasesCount) {
    MarkovAlgorithm m;
    m.addRule(Rule("aa", "b", false));
    m.addRule(Rule("b", "a", true));
    m.removeRule(0);
    EXPECT_EQ(m.ruleCount(), 1);
    EXPECT_EQ(m.getRules()[0].getLeft(), "b");
}

TEST(MarkovAlgorithmTest, GetRulesReturnsCopy) {
    MarkovAlgorithm m;
    m.addRule(Rule("aa", "b", false));
    std::vector<Rule> rules = m.getRules();
    EXPECT_EQ(rules.size(), 1);
}

TEST(MarkovAlgorithmTest, SetAndGetTape) {
    MarkovAlgorithm m;
    m.setTape("aab");
    EXPECT_EQ(m.getTape(), "aab");
}

TEST(MarkovAlgorithmTest, StepAppliesFirstApplicableRule) {
    MarkovAlgorithm m;
    m.setTape("aab");
    m.addRule(Rule("aa", "b", false));

    bool result = m.step();
    EXPECT_TRUE(result);
    EXPECT_EQ(m.getTape(), "bb");
}

TEST(MarkovAlgorithmTest, StepReturnsFalseWhenNoRuleApplies) {
    MarkovAlgorithm m;
    m.setTape("abc");
    m.addRule(Rule("xx", "y", false));

    bool result = m.step();
    EXPECT_FALSE(result);
    EXPECT_EQ(m.getTape(), "abc");
}

TEST(MarkovAlgorithmTest, StepStopsOnFinalRule) {
    MarkovAlgorithm m;
    m.setTape("aab");
    m.addRule(Rule("aa", "b", true));

    bool result = m.step();
    EXPECT_FALSE(result);
    EXPECT_EQ(m.getTape(), "bb");
}

TEST(MarkovAlgorithmTest, RunExecutesUntilFinal) {
    MarkovAlgorithm m;
    m.setTape("aab");
    m.addRule(Rule("aa", "b", false));
    m.addRule(Rule("b", "a", true));

    m.run();
    EXPECT_EQ(m.getTape(), "ab");
}

TEST(MarkovAlgorithmTest, RunStopsWhenNoRuleApplies) {
    MarkovAlgorithm m;
    m.setTape("xyz");
    m.addRule(Rule("aa", "b", false));

    m.run();
    EXPECT_EQ(m.getTape(), "xyz");
}

TEST(MarkovAlgorithmTest, EqualityOperatorForEqual) {
    MarkovAlgorithm a, b;
    a.setTape("aab");
    a.addRule(Rule("aa", "b", false));
    b.setTape("aab");
    b.addRule(Rule("aa", "b", false));

    EXPECT_TRUE(a == b);
}

TEST(MarkovAlgorithmTest, EqualityOperatorForDifferentTape) {
    MarkovAlgorithm a, b;
    a.setTape("aab");
    b.setTape("abc");
    EXPECT_FALSE(a == b);
}

TEST(MarkovAlgorithmTest, EqualityOperatorForDifferentRules) {
    MarkovAlgorithm a, b;
    a.addRule(Rule("aa", "b", false));
    b.addRule(Rule("aa", "c", false));
    EXPECT_FALSE(a == b);
}

TEST(MarkovAlgorithmTest, InequalityOperator) {
    MarkovAlgorithm a, b;
    a.setTape("aab");
    b.setTape("abc");
    EXPECT_TRUE(a != b);
}

TEST(MarkovAlgorithmTest, CopyConstructor) {
    MarkovAlgorithm a;
    a.setTape("aab");
    a.addRule(Rule("aa", "b", false));

    MarkovAlgorithm b = a;
    EXPECT_EQ(b.getTape(), "aab");
    EXPECT_EQ(b.ruleCount(), 1);
}

TEST(MarkovAlgorithmTest, CopyIsIndependent) {
    MarkovAlgorithm a;
    a.setTape("aab");

    MarkovAlgorithm b = a;
    b.setTape("xyz");

    EXPECT_EQ(a.getTape(), "aab");
    EXPECT_EQ(b.getTape(), "xyz");
}

TEST(MarkovAlgorithmTest, AssignmentOperator) {
    MarkovAlgorithm a, b;
    a.setTape("aab");
    a.addRule(Rule("aa", "b", false));

    b = a;
    EXPECT_EQ(b.getTape(), "aab");
    EXPECT_EQ(b.ruleCount(), 1);
}

TEST(MarkovAlgorithmTest, SelfAssignment) {
    MarkovAlgorithm a;
    a.setTape("aab");
    a.addRule(Rule("aa", "b", false));

    a = a;
    EXPECT_EQ(a.getTape(), "aab");
    EXPECT_EQ(a.ruleCount(), 1);
}

TEST(MarkovAlgorithmTest, OutputOperator) {
    MarkovAlgorithm m;
    Alphabet a;
    a.add('a');
    a.add('b');
    m.setAlphabet(a);
    m.setTape("aab");
    m.addRule(Rule("aa", "b", false));

    std::ostringstream os;
    os << m;
    std::string result = os.str();

    EXPECT_NE(result.find("ab"), std::string::npos);
    EXPECT_NE(result.find("aab"), std::string::npos);
    EXPECT_NE(result.find("aa -> b"), std::string::npos);
}

TEST(MarkovAlgorithmTest, InputOperator) {
    std::istringstream is("ab\naab\naa -> b\nb ->. a\n");
    MarkovAlgorithm m;
    is >> m;

    EXPECT_EQ(m.getTape(), "aab");
    EXPECT_EQ(m.ruleCount(), 2);
    EXPECT_EQ(m.getAlphabet().size(), 2);
}

TEST(MarkovAlgorithmTest, LoadAndSaveAreSymmetric) {
    MarkovAlgorithm original;
    Alphabet a;
    a.add('a');
    a.add('b');
    original.setAlphabet(a);
    original.setTape("aab");
    original.addRule(Rule("aa", "b", false));
    original.addRule(Rule("b", "a", true));

    std::ostringstream os;
    original.saveToStream(os);

    std::istringstream is(os.str());
    MarkovAlgorithm loaded;
    loaded.loadFromStream(is);

    EXPECT_TRUE(original == loaded);
}