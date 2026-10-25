#include "Discount.h"
#include <sstream>
using namespace std;

namespace {
constexpr double PERCENT_MAX = 100.0;
}

Discount::Discount() : description(""), percent(0) {}
Discount::Discount(const string& description, int percent)
    : description(description), percent(percent) {}
Discount::Discount(const Discount& other)
    : description(other.description), percent(other.percent) {}

Discount& Discount::operator=(const Discount& other) {
    if (this == &other) return *this;
    description = other.description;
    percent = other.percent;
    return *this;
}
Discount::~Discount() {}

string Discount::getDescription() const { return description; }
int Discount::getPercent() const { return percent; }

Money Discount::apply(const Money& amount) const {
    double factor = 1.0 - (percent / PERCENT_MAX);
    return amount.multiply(factor);
}

string Discount::toString() const {
    stringstream ss;
    ss << "Discount{" << description << ", " << percent << "%}";
    return ss.str();
}
ostream& operator<<(ostream& os, const Discount& d) { os << d.toString(); return os; }
