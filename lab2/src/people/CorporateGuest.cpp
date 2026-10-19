#include "CorporateGuest.h"
#include <sstream>

using namespace std;

CorporateGuest::CorporateGuest()
    : Guest(), companyName("") {
}

CorporateGuest::CorporateGuest(const string& firstName,
                               const string& lastName,
                               const Date& birthDate,
                               const ContactInfo& contacts,
                               Gender gender,
                               const string& passportNumber,
                               const string& companyName)
    : Guest(firstName, lastName, birthDate, contacts, gender, passportNumber),
      companyName(companyName) {
}

CorporateGuest::CorporateGuest(const CorporateGuest& other)
    : Guest(other),
      companyName(other.companyName) {
}

CorporateGuest& CorporateGuest::operator=(const CorporateGuest& other) {
    if (this == &other) {
        return *this;
    }
    Guest::operator=(other);
    companyName = other.companyName;
    return *this;
}

CorporateGuest::~CorporateGuest() {
}

string CorporateGuest::getCompanyName() const {
    return companyName;
}

void CorporateGuest::setCompanyName(const string& companyName) {
    this->companyName = companyName;
}

string CorporateGuest::toString() const {
    stringstream ss;
    ss << "CorporateGuest{" << Guest::toString()
       << ", company=" << companyName << "}";
    return ss.str();
}

bool CorporateGuest::operator==(const CorporateGuest& other) const {
    return getId() == other.getId();
}

bool CorporateGuest::operator!=(const CorporateGuest& other) const {
    return !(*this == other);
}

ostream& operator<<(ostream& os, const CorporateGuest& cg) {
    os << cg.toString();
    return os;
}

istream& operator>>(istream& is, CorporateGuest& cg) {
    is >> static_cast<Guest&>(cg);
    is >> cg.companyName;
    return is;
}