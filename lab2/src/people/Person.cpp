#include "Person.h"
#include <sstream>

using namespace std;

Person::Person()
    : firstName(""), lastName(""), birthDate(),
      contacts(), gender(Gender::Other) {
}

Person::Person(const string& firstName,
               const string& lastName,
               const Date& birthDate,
               const ContactInfo& contacts,
               Gender gender)
    : firstName(firstName), lastName(lastName),
      birthDate(birthDate), contacts(contacts), gender(gender) {
}

Person::Person(const Person& other)
    : firstName(other.firstName), lastName(other.lastName),
      birthDate(other.birthDate), contacts(other.contacts),
      gender(other.gender), id(other.id) {
}

Person& Person::operator=(const Person& other) {
    if (this == &other) {
        return *this;
    }
    firstName = other.firstName;
    lastName = other.lastName;
    birthDate = other.birthDate;
    contacts = other.contacts;
    gender = other.gender;
    id = other.id;
    return *this;
}

Person::~Person() {
}

string Person::getFirstName() const {
    return firstName;
}

string Person::getLastName() const {
    return lastName;
}

Date Person::getBirthDate() const {
    return birthDate;
}

ContactInfo Person::getContacts() const {
    return contacts;
}

Gender Person::getGender() const {
    return gender;
}

Id Person::getId() const {
    return id;
}

void Person::setFirstName(const string& firstName) {
    this->firstName = firstName;
}

void Person::setLastName(const string& lastName) {
    this->lastName = lastName;
}

void Person::setBirthDate(const Date& birthDate) {
    this->birthDate = birthDate;
}

void Person::setContacts(const ContactInfo& contacts) {
    this->contacts = contacts;
}

void Person::setGender(Gender gender) {
    this->gender = gender;
}

string Person::toString() const {
    stringstream ss;
    ss << "Person[id=" << id.toString()
       << ", name=" << firstName << " " << lastName
       << ", birth=" << birthDate.toString()
       << ", gender=";
    switch (gender) {
    case Gender::Male:   ss << "Male";   break;
    case Gender::Female: ss << "Female"; break;
    case Gender::Other:  ss << "Other";  break;
    }
    ss << "]";
    return ss.str();
}

bool Person::operator==(const Person& other) const {
    return id == other.id;
}

bool Person::operator!=(const Person& other) const {
    return !(*this == other);
}

bool Person::operator<(const Person& other) const {
    return id < other.id;
}

bool Person::operator>(const Person& other) const {
    return other < *this;
}

ostream& operator<<(ostream& os, const Person& p) {
    os << p.toString();
    return os;
}

istream& operator>>(istream& is, Person& p) {
    is >> p.firstName
       >> p.lastName
       >> p.birthDate
       >> p.contacts;
    return is;
}