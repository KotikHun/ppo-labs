#include "Manager.h"
#include <sstream>

using namespace std;

Manager::Manager()
    : Person(), Employee(), Guest(), department("") {
}

Manager::Manager(const string& firstName,
                 const string& lastName,
                 const Date& birthDate,
                 const ContactInfo& contacts,
                 Gender gender,
                 const string& position,
                 double salary,
                 const string& passportNumber,
                 const string& department)
    : Person(firstName, lastName, birthDate, contacts, gender),
      Employee(firstName, lastName, birthDate, contacts, gender, position, salary),
      Guest(firstName, lastName, birthDate, contacts, gender, passportNumber),
      department(department) {
}

Manager::Manager(const Manager& other)
    : Person(other),
      Employee(other),
      Guest(other),
      department(other.department) {
}

Manager& Manager::operator=(const Manager& other) {
    if (this == &other) {
        return *this;
    }
    Person::operator=(other);
    Employee::operator=(other);
    Guest::operator=(other);
    department = other.department;
    return *this;
}

Manager::~Manager() {
}

string Manager::getDepartment() const {
    return department;
}

void Manager::setDepartment(const string& department) {
    this->department = department;
}

string Manager::toString() const {
    stringstream ss;
    ss << "Manager{"
       << "EmployeePart=" << Employee::toString()
       << ", GuestPart=" << Guest::toString()
       << ", department=" << department << "}";
    return ss.str();
}

ostream& operator<<(ostream& os, const Manager& m) {
    os << m.toString();
    return os;
}

istream& operator>>(istream& is, Manager& m) {
    // Читаем общую часть (Person) - можно через static_cast к Person
    is >> static_cast<Person&>(m);
    // Читаем специфичные части
    is >> m.position >> m.salary;
    is >> m.passportNumber;
    is >> m.department;
    return is;
}

