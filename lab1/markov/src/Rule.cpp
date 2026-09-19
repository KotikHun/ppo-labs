#include "Rule.h"

using namespace std;

Rule::Rule() : left(""), right(""), isFinal(false) {
}

Rule::Rule(const string& left, const string& right, bool isFinal)
    : left(left), right(right), isFinal(isFinal) {
}

Rule::Rule(const Rule& other)
    : left(other.left), right(other.right), isFinal(other.isFinal) {
}

Rule::~Rule() {
}

Rule& Rule::operator=(const Rule& other) {
    if (this == &other) {
        return *this;
    }
    left = other.left;
    right = other.right;
    isFinal = other.isFinal;
    return *this;
}

string Rule::getLeft() const {
    return left;
}

string Rule::getRight() const {
    return right;
}

bool Rule::getIsFinal() const {
    return isFinal;
}

bool Rule::isApplicable(const string& tape) const {
    return tape.find(left) != string::npos;
}

bool Rule::apply(string& tape) const {
    size_t position = tape.find(left);
    if (position == string::npos) {
        return false;
    }
    tape.replace(position, left.length(), right);
    return isFinal;
}

bool Rule::operator==(const Rule& other) const {
    return left == other.left
        && right == other.right
        && isFinal == other.isFinal;
}

bool Rule::operator!=(const Rule& other) const {
    return !(*this == other);
}

ostream& operator<<(ostream& os, const Rule& r) {
    os << r.left << " ->";
    if (r.isFinal) {
        os << ".";
    }
    os << " " << r.right;
    return os;
}

istream& operator>>(istream& is, Rule& r) {
    string left;
    string arrow;
    string right;
    is >> left >> arrow >> right;

    bool finalRule = false;
    if (!arrow.empty() && arrow.back() == '.') {
        finalRule = true;
    }

    r = Rule(left, right, finalRule);
    return is;
}