#include "ContactInfo.h"
#include <sstream>
#include <cctype>

using namespace std;

ContactInfo::ContactInfo() : phone(""), email("") {
}

ContactInfo::ContactInfo(const string& phone, const string& email)
    : phone(phone), email(email) {
}

ContactInfo::ContactInfo(const ContactInfo& other)
    : phone(other.phone), email(other.email) {
}

ContactInfo& ContactInfo::operator=(const ContactInfo& other) {
    if (this == &other) {
        return *this;
    }
    phone = other.phone;
    email = other.email;
    return *this;
}

ContactInfo::~ContactInfo() {
}

string ContactInfo::getPhone() const {
    return phone;
}

string ContactInfo::getEmail() const {
    return email;
}

void ContactInfo::setPhone(const string& phone) {
    this->phone = phone;
}

void ContactInfo::setEmail(const string& email) {
    this->email = email;
}

bool ContactInfo::isValid() const {
    if (phone.empty()) {
        return false;
    }
    if (!isdigit(phone[0]) && phone[0] != '+') {
        return false;
    }

    size_t at = email.find('@');
    if (at == string::npos) {
        return false;
    }
    if (at == 0) {
        return false;
    }

    size_t dot = email.find('.', at + 1);
    if (dot == string::npos) {
        return false;
    }
    if (dot == at + 1) {
        return false;
    }
    if (dot + 2 >= email.size()) {
        return false;
    }

    return true;
}

string ContactInfo::toString() const {
    stringstream ss;
    ss << phone << " | " << email;
    return ss.str();
}

bool ContactInfo::operator==(const ContactInfo& other) const {
    return phone == other.phone && email == other.email;
}

bool ContactInfo::operator!=(const ContactInfo& other) const {
    return !(*this == other);
}

bool ContactInfo::operator<(const ContactInfo& other) const {
    if (phone != other.phone) {
        return phone < other.phone;
    }
    return email < other.email;
}

bool ContactInfo::operator>(const ContactInfo& other) const {
    return other < *this;
}

ostream& operator<<(ostream& os, const ContactInfo& c) {
    os << c.toString();
    return os;
}

istream& operator>>(istream& is, ContactInfo& c) {
    string phone, email;
    is >> phone >> email;
    c = ContactInfo(phone, email);
    return is;
}

