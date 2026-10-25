#include "VipGuest.h"
#include <sstream>

using namespace std;

VipGuest::VipGuest()
    : Guest(), discountPercent(0) {
}

VipGuest::VipGuest(const string& firstName,
                   const string& lastName,
                   const Date& birthDate,
                   const ContactInfo& contacts,
                   Gender gender,
                   const string& passportNumber,
                   int discountPercent)
    : Guest(firstName, lastName, birthDate, contacts, gender, passportNumber),
      discountPercent(discountPercent) {
}

VipGuest::VipGuest(const VipGuest& other)
    : Guest(other),
      discountPercent(other.discountPercent) {
}

VipGuest& VipGuest::operator=(const VipGuest& other) {
    if (this == &other) {
        return *this;
    }
    Guest::operator=(other);
    discountPercent = other.discountPercent;
    return *this;
}

VipGuest::~VipGuest() {
}

int VipGuest::getDiscountPercent() const {
    return discountPercent;
}

void VipGuest::setDiscountPercent(int discountPercent) {
    this->discountPercent = discountPercent;
}

string VipGuest::toString() const {
    stringstream ss;
    ss << "VipGuest{" << Guest::toString()
       << ", discount=" << discountPercent << "%}";
    return ss.str();
}

bool VipGuest::operator==(const VipGuest& other) const {
    return getId() == other.getId();
}

bool VipGuest::operator!=(const VipGuest& other) const {
    return !(*this == other);
}

ostream& operator<<(ostream& os, const VipGuest& vg) {
    os << vg.toString();
    return os;
}

istream& operator>>(istream& is, VipGuest& vg) {
    is >> static_cast<Guest&>(vg);
    is >> vg.discountPercent;
    return is;
}