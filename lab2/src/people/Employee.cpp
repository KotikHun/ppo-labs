#include "Employee.h"
#include <sstream>

using namespace std;

Employee::Employee()
    : Person(), position(""), salary(0.0) {
}

Employee::Employee(const string& firstName,
                   const string& lastName,
                   const Date& birthDate,
                   const ContactInfo& contacts,
                   Gender gender,
                   const string& position,
                   double salary)
    : Person(firstName, lastName, birthDate, contacts, gender),
      position(position), salary(salary) {
}

Employee::Employee(const Employee& other)
    : Person(other),
      position(other.position), salary(other.salary) {
}

Employee& Employee::operator=(const Employee& other) {
    if (this == &other) {
        return *this;
    }
    Person::operator=(other);
    position = other.position;
    salary = other.salary;
    return *this;
}

Employee::~Employee() {
}

string Employee::getPosition() const {
    return position;
}

double Employee::getSalary() const {
    return salary;
}

void Employee::setPosition(const string& position) {
    this->position = position;
}

void Employee::setSalary(double salary) {
    this->salary = salary;
}

string Employee::toString() const {
    stringstream ss;
    ss << "Employee{" << Person::toString()
       << ", position=" << position
       << ", salary=" << salary << "}";
    return ss.str();
}

bool Employee::operator==(const Employee& other) const {
    return getId() == other.getId();
}

bool Employee::operator!=(const Employee& other) const {
    return !(*this == other);
}

ostream& operator<<(ostream& os, const Employee& e) {
    os << e.toString();
    return os;
}

istream& operator>>(istream& is, Employee& e) {
    is >> static_cast<Person&>(e);
    is >> e.position >> e.salary;
    return is;
}