#include "Guest.h"
#include <sstream>

using namespace std;

Guest::Guest()
    : Person(), passportNumber(""), loyaltyPoints(0),
      preferredLanguage("en"), notes("") {
}

Guest::Guest(const string& firstName,
             const string& lastName,
             const Date& birthDate,
             const ContactInfo& contacts,
             Gender gender,
             const string& passportNumber)
    : Person(firstName, lastName, birthDate, contacts, gender),
      passportNumber(passportNumber),
      loyaltyPoints(0), preferredLanguage("en"), notes("") {
}

Guest::Guest(const Guest& other)
    : Person(other),
      passportNumber(other.passportNumber),
      loyaltyPoints(other.loyaltyPoints),
      preferredLanguage(other.preferredLanguage),
      notes(other.notes) {
}

Guest& Guest::operator=(const Guest& other) {
    if (this == &other) {
        return *this;
    }
    Person::operator=(other);
    passportNumber = other.passportNumber;
    loyaltyPoints = other.loyaltyPoints;
    preferredLanguage = other.preferredLanguage;
    notes = other.notes;
    return *this;
}

Guest::~Guest() {}

string Guest::getPassportNumber() const { return passportNumber; }
int Guest::getLoyaltyPoints() const { return loyaltyPoints; }
string Guest::getPreferredLanguage() const { return preferredLanguage; }
string Guest::getNotes() const { return notes; }

void Guest::setPassportNumber(const string& passportNumber) {
    this->passportNumber = passportNumber;
}

void Guest::setLoyaltyPoints(int loyaltyPoints) {
    this->loyaltyPoints = loyaltyPoints;
}

void Guest::setPreferredLanguage(const string& lang) {
    this->preferredLanguage = lang;
}

void Guest::setNotes(const string& n) {
    this->notes = n;
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

bool Guest::operator==(const Guest& other) const { return Person::operator==(other); }
bool Guest::operator!=(const Guest& other) const { return !(*this == other); }
bool Guest::operator<(const Guest& other) const { return loyaltyPoints < other.loyaltyPoints; }
bool Guest::operator>(const Guest& other) const { return loyaltyPoints > other.loyaltyPoints; }

ostream& operator<<(ostream& os, const Guest& g) {
    os << g.toString();
    return os;
}

istream& operator>>(istream& is, Guest& g) {
    string fn, ln, pass;
    is >> fn >> ln >> pass;
    g.setFirstName(fn);
    g.setLastName(ln);
    g.setPassportNumber(pass);
    return is;
}
