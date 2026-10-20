#include "ContactPerson.h"
#include <sstream>

using namespace std;

ContactPerson::ContactPerson() : person(), companyName("") {
}

ContactPerson::ContactPerson(const Person& person, const string& companyName)
    : person(person), companyName(companyName) {
}

ContactPerson::ContactPerson(const ContactPerson& other)
    : person(other.person), companyName(other.companyName) {
}

ContactPerson& ContactPerson::operator=(const ContactPerson& other) {
    if (this == &other) {
        return *this;
    }
    person = other.person;
    companyName = other.companyName;
    return *this;
}

ContactPerson::~ContactPerson() {
}

Person ContactPerson::getPerson() const {
    return person;
}

string ContactPerson::getCompanyName() const {
    return companyName;
}

void ContactPerson::setPerson(const Person& person) {
    this->person = person;
}

void ContactPerson::setCompanyName(const string& companyName) {
    this->companyName = companyName;
}

string ContactPerson::toString() const {
    stringstream ss;
    ss << "ContactPerson{" << person.toString()
       << ", company=" << companyName << "}";
    return ss.str();
}

bool ContactPerson::operator==(const ContactPerson& other) const {
    return person == other.person; // У Person уже есть operator==
}

bool ContactPerson::operator!=(const ContactPerson& other) const {
    return !(*this == other);
}

ostream& operator<<(ostream& os, const ContactPerson& cp) {
    os << cp.toString();
    return os;
}

istream& operator>>(istream& is, ContactPerson& cp) {
    is >> cp.person >> cp.companyName;
    return is;
}