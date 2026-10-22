#include "Tariff.h"
#include <sstream>
using namespace std;

Tariff::Tariff() : name(""), season(Season::Summer), multiplier(1.0) {}
Tariff::Tariff(const string& name, Season season, double multiplier)
    : name(name), season(season), multiplier(multiplier) {}
Tariff::Tariff(const Tariff& other)
    : name(other.name), season(other.season), multiplier(other.multiplier) {}

Tariff& Tariff::operator=(const Tariff& other) {
    if (this == &other) return *this;
    name = other.name;
    season = other.season;
    multiplier = other.multiplier;
    return *this;
}
Tariff::~Tariff() {}

string Tariff::getName() const { return name; }
Season Tariff::getSeason() const { return season; }
double Tariff::getMultiplier() const { return multiplier; }

Money Tariff::apply(const Money& basePrice) const {
    return basePrice.multiply(multiplier);
}

string Tariff::toString() const {
    stringstream ss;
    ss << "Tariff{" << name << ", mult=" << multiplier << "}";
    return ss.str();
}
ostream& operator<<(ostream& os, const Tariff& t) { os << t.toString(); return os; }