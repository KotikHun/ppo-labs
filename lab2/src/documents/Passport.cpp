#include "Passport.h"
#include <sstream>
using namespace std;

Passport::Passport() : Document(), country("") {}
Passport::Passport(const string& documentNumber, const Date& issueDate, const Date& expiryDate, const string& country)
    : Document(documentNumber, issueDate, expiryDate), country(country) {}
Passport::Passport(const Passport& other) : Document(other), country(other.country) {}
Passport& Passport::operator=(const Passport& other) {
    if (this == &other) return *this;
    Document::operator=(other);
    country = other.country;
    return *this;
}
Passport::~Passport() {}

string Passport::getCountry() const { return country; }
void Passport::setCountry(const string& country) { this->country = country; }

bool Passport::isValid(const Date& currentDate) const {
    // Документ действителен, если текущая дата не позже даты истечения
    return currentDate < expiryDate || currentDate == expiryDate;
}

string Passport::toString() const {
    stringstream ss;
    ss << "Passport{" << Document::toString() << ", country=" << country << "}";
    return ss.str();
}
ostream& operator<<(ostream& os, const Passport& p) { os << p.toString(); return os; }