#include "Employee.h"
#include <sstream>

using namespace std;

Employee::Employee()
    : Person(), position(""), salary(0.0), department("General"), hireDate() {
}

Employee::Employee(const string& firstName,
                   const string& lastName,
                   const Date& birthDate,
                   const ContactInfo& contacts,
                   Gender gender,
                   const string& position,
                   double salary)
    : Person(firstName, lastName, birthDate, contacts, gender),
      position(position), salary(salary), department("General"), hireDate() {
}

Employee::Employee(const Employee& other)
    : Person(other),
      position(other.position), salary(other.salary),
      department(other.department), hireDate(other.hireDate) {
}

Employee& Employee::operator=(const Employee& other) {
    if (this == &other) {
        return *this;
    }
    Person::operator=(other);
    position = other.position;
    salary = other.salary;
    department = other.department;
    hireDate = other.hireDate;
    return *this;
}

Employee::~Employee() {}

string Employee::getPosition() const { return position; }
double Employee::getSalary() const { return salary; }
string Employee::getDepartment() const { return department; }
Date Employee::getHireDate() const { return hireDate; }
Id Employee::getId() const { return Person::getId(); }

void Employee::setPosition(const string& position) { this->position = position; }
void Employee::setSalary(double salary) { this->salary = salary; }
void Employee::setDepartment(const string& dept) { this->department = dept; }
void Employee::setHireDate(const Date& date) { this->hireDate = date; }

string Employee::toString() const {
    stringstream ss;
    ss << "Employee{" << Person::toString()
       << ", position=" << position
       << ", salary=" << salary << "}";
    return ss.str();
}

bool Employee::operator==(const Employee& other) const { return Person::operator==(other); }
bool Employee::operator!=(const Employee& other) const { return !(*this == other); }

ostream& operator<<(ostream& os, const Employee& e) {
    os << e.toString();
    return os;
}

istream& operator>>(istream& is, Employee& e) {
    string pos;
    double sal;
    is >> pos >> sal;
    e.setPosition(pos);
    e.setSalary(sal);
    return is;
}
