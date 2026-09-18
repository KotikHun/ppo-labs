#include "MarkovAlgorithm.h"

using namespace std;

MarkovAlgorithm::MarkovAlgorithm() {
}

MarkovAlgorithm::MarkovAlgorithm(const MarkovAlgorithm& other)
    : alphabet(other.alphabet), rules(other.rules), tape(other.tape) {
}

MarkovAlgorithm::~MarkovAlgorithm() {
}

MarkovAlgorithm& MarkovAlgorithm::operator=(const MarkovAlgorithm& other) {
    if (this == &other) {
        return *this;
    }
    alphabet = other.alphabet;
    rules = other.rules;
    tape = other.tape;
    return *this;
}

void MarkovAlgorithm::setAlphabet(const Alphabet& newAlphabet) {
    alphabet = newAlphabet;
}

Alphabet MarkovAlgorithm::getAlphabet() const {
    return alphabet;
}

void MarkovAlgorithm::addRule(const Rule& newRule) {
    rules.push_back(newRule);
}

void MarkovAlgorithm::removeRule(size_t index) {
    rules.erase(rules.begin() + index);
}

vector<Rule> MarkovAlgorithm::getRules() const {
    return rules;
}

size_t MarkovAlgorithm::ruleCount() const {
    return rules.size();
}

void MarkovAlgorithm::setTape(const string& newTape) {
    tape = newTape;
}

string MarkovAlgorithm::getTape() const {
    return tape;
}

bool MarkovAlgorithm::step() {
    for (Rule& rule : rules) {
        if (rule.isApplicable(tape)) {
            bool isFinal = rule.apply(tape);
            return !isFinal;
        }
    }
    return false;
}

void MarkovAlgorithm::run() {
    while (step()) {
    }
}

void MarkovAlgorithm::loadFromStream(istream& is) {
    string alphabetLine;
    is >> alphabetLine;

    alphabet = Alphabet();
    for (char c : alphabetLine) {
        alphabet.add(c);
    }

    is >> tape;

    rules.clear();
    Rule currentRule;
    while (is >> currentRule) {
        rules.push_back(currentRule);
    }
}

void MarkovAlgorithm::saveToStream(ostream& os) const {
    for (char c : alphabet.getAll()) {
        os << c;
    }
    os << endl;

    os << tape << endl;

    for (const Rule& rule : rules) {
        os << rule << endl;
    }
}

bool MarkovAlgorithm::operator==(const MarkovAlgorithm& other) const {
    return alphabet == other.alphabet
        && rules == other.rules
        && tape == other.tape;
}

bool MarkovAlgorithm::operator!=(const MarkovAlgorithm& other) const {
    return !(*this == other);
}

ostream& operator<<(ostream& os, const MarkovAlgorithm& m) {
    for (char c : m.alphabet.getAll()) {
        os << c;
    }
    os << endl;

    os << m.tape << endl;

    for (const Rule& rule : m.rules) {
        os << rule << endl;
    }

    return os;
}

istream& operator>>(istream& is, MarkovAlgorithm& m) {
    string alphabetLine;
    is >> alphabetLine;

    m.alphabet = Alphabet();
    for (char c : alphabetLine) {
        m.alphabet.add(c);
    }

    is >> m.tape;

    m.rules.clear();
    Rule currentRule;
    while (is >> currentRule) {
        m.rules.push_back(currentRule);
    }

    return is;
}