#include "RegularGuest.h"
#include <sstream>

using namespace std;

RegularGuest::RegularGuest()
    : Guest(), visitCount(0) {
}

RegularGuest::RegularGuest(const string& firstName,
                           const string& lastName,
                           const Date& birthDate,
                           const ContactInfo& contacts,
                           Gender gender,
                           const string& passportNumber)
    : Guest(firstName, lastName, birthDate, contacts, gender, passportNumber),
      visitCount(0) {
}

RegularGuest::RegularGuest(const RegularGuest& other)
    : Guest(other),
      visitCount(other.visitCount) {
}

RegularGuest& RegularGuest::operator=(const RegularGuest& other) {
    if (this == &other) {
        return *this;
    }
    Guest::operator=(other);
    visitCount = other.visitCount;
    return *this;
}

RegularGuest::~RegularGuest() {
}

int RegularGuest::getVisitCount() const {
    return visitCount;
}

void RegularGuest::setVisitCount(int visitCount) {
    this->visitCount = visitCount;
}

void RegularGuest::incrementVisitCount() {
    visitCount++;
}

string RegularGuest::toString() const {
    stringstream ss;
    ss << "RegularGuest{" << Guest::toString()
       << ", visits=" << visitCount << "}";
    return ss.str();
}

bool RegularGuest::operator==(const RegularGuest& other) const {
    return getId() == other.getId();
}

bool RegularGuest::operator!=(const RegularGuest& other) const {
    return !(*this == other);
}

ostream& operator<<(ostream& os, const RegularGuest& rg) {
    os << rg.toString();
    return os;
}

istream& operator>>(istream& is, RegularGuest& rg) {
    is >> static_cast<Guest&>(rg);
    is >> rg.visitCount;
    return is;
}

