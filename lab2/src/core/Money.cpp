#include "Money.h"
#include <sstream>
#include <iomanip>

using namespace std;

Money::Money() : amount(0.0), currency(Currency::RUB) {
}

Money::Money(double amount, Currency currency)
    : amount(amount), currency(currency) {
}

Money::Money(const Money& other)
    : amount(other.amount), currency(other.currency) {
}

Money& Money::operator=(const Money& other) {
    if (this == &other) {
        return *this;
    }
    amount = other.amount;
    currency = other.currency;
    return *this;
}

Money::~Money() {
}

double Money::getAmount() const {
    return amount;
}

Currency Money::getCurrency() const {
    return currency;
}

Money Money::add(const Money& other) const {
    return Money(amount + other.amount, currency);
}

Money Money::subtract(const Money& other) const {
    return Money(amount - other.amount, currency);
}

Money Money::multiply(double factor) const {
    return Money(amount * factor, currency);
}

string Money::toString() const {
    stringstream ss;
    ss << fixed << setprecision(2) << amount << " ";
    switch (currency) {
    case Currency::RUB: ss << "RUB"; break;
    case Currency::USD: ss << "USD"; break;
    case Currency::EUR: ss << "EUR"; break;
    }
    return ss.str();
}

bool Money::operator==(const Money& other) const {
    return amount == other.amount && currency == other.currency;
}

bool Money::operator!=(const Money& other) const {
    return !(*this == other);
}

bool Money::operator<(const Money& other) const {
    if (currency != other.currency) {
        return static_cast<int>(currency) < static_cast<int>(other.currency);
    }
    return amount < other.amount;
}

bool Money::operator>(const Money& other) const {
    return other < *this;
}

ostream& operator<<(ostream& os, const Money& m) {
    os << m.toString();
    return os;
}

istream& operator>>(istream& is, Money& m) {
    double amount;
    string cur;
    is >> amount >> cur;

    Currency c = m.currency;
    if (cur == "RUB") {
        c = Currency::RUB;
    } else if (cur == "USD") {
        c = Currency::USD;
    } else if (cur == "EUR") {
        c = Currency::EUR;
    }

    m = Money(amount, c);
    return is;
}