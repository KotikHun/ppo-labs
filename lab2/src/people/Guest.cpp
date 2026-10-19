#include "Guest.h"
#include <sstream>

using namespace std;

Guest::Guest()
    : Person(), passportNumber(""), loyaltyPoints(0) {
}

Guest::Guest(const string& firstName,
             const string& lastName,
             const Date& birthDate,
             const ContactInfo& contacts,
             Gender gender,
             const string& passportNumber)
    : Person(firstName, lastName, birthDate, contacts, gender),
      passportNumber(passportNumber),
      loyaltyPoints(0) {
}

Guest::Guest(const Guest& other)
    : Person(other),
      passportNumber(other.passportNumber),
      loyaltyPoints(other.loyaltyPoints) {
}

Guest& Guest::operator=(const Guest& other) {
    if (this == &other) {
        return *this;
    }
    Person::operator=(other);
    passportNumber = other.passportNumber;
    loyaltyPoints = other.loyaltyPoints;
    return *this;
}

Guest::~Guest() {
}

string Guest::getPassportNumber() const {
    return passportNumber;
}

int Guest::getLoyaltyPoints() const {
    return loyaltyPoints;
}

void Guest::setPassportNumber(const string& passportNumber) {
    this->passportNumber = passportNumber;
}

void Guest::setLoyaltyPoints(int loyaltyPoints) {
    this->loyaltyPoints = loyaltyPoints;
}

void Guest::addLoyaltyPoints(int points) {
    loyaltyPoints += points;
}

string Guest::toString() const {
    stringstream ss;
    ss << "Guest{" << Person::toString()
       << ", passport=" << passportNumber
       << ", points=" << loyaltyPoints << "}";
    return ss.str();
}

bool Guest::operator==(const Guest& other) const {
    return getId() == other.getId();
}

bool Guest::operator!=(const Guest& other) const {
    return !(*this == other);
}

bool Guest::operator<(const Guest& other) const {
    return getId() < other.getId();
}

bool Guest::operator>(const Guest& other) const {
    return other < *this;
}

ostream& operator<<(ostream& os, const Guest& g) {
    os << g.toString();
    return os;
}

istream& operator>>(istream& is, Guest& g) {
    is >> static_cast<Person&>(g);
    is >> g.passportNumber;
    return is;
}