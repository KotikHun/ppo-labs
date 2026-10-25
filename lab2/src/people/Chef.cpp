#include "Chef.h"
#include <sstream>
using namespace std;

Chef::Chef() : Employee(), specialty("") {}
Chef::Chef(const string& fName, const string& lName, const Date& bDate, const ContactInfo& contacts, Gender gender, const string& position, double salary, const string& specialty)
    : Employee(fName, lName, bDate, contacts, gender, position, salary), specialty(specialty) {}
Chef::Chef(const Chef& other) : Employee(other), specialty(other.specialty) {}
Chef& Chef::operator=(const Chef& other) {
    if (this == &other) return *this;
    Employee::operator=(other);
    specialty = other.specialty;
    return *this;
}
Chef::~Chef() {}
string Chef::getSpecialty() const { return specialty; }
void Chef::setSpecialty(const string& specialty) { this->specialty = specialty; }
string Chef::toString() const {
    stringstream ss;
    ss << "Chef{" << Employee::toString() << ", specialty=" << specialty << "}";
    return ss.str();
}
ostream& operator<<(ostream& os, const Chef& c) { os << c.toString(); return os; }
istream& operator>>(istream& is, Chef& c) {
    is >> static_cast<Employee&>(c) >> c.specialty; return is;
}