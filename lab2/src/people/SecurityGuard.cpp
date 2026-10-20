#include "SecurityGuard.h"
#include <sstream>
using namespace std;

SecurityGuard::SecurityGuard() : Employee(), shift("") {}
SecurityGuard::SecurityGuard(const string& fName, const string& lName, const Date& bDate, const ContactInfo& contacts, Gender gender, const string& position, double salary, const string& shift)
    : Employee(fName, lName, bDate, contacts, gender, position, salary), shift(shift) {}
SecurityGuard::SecurityGuard(const SecurityGuard& other) : Employee(other), shift(other.shift) {}
SecurityGuard& SecurityGuard::operator=(const SecurityGuard& other) {
    if (this == &other) return *this;
    Employee::operator=(other);
    shift = other.shift;
    return *this;
}
SecurityGuard::~SecurityGuard() {}
string SecurityGuard::getShift() const { return shift; }
void SecurityGuard::setShift(const string& shift) { this->shift = shift; }
string SecurityGuard::toString() const {
    stringstream ss;
    ss << "SecurityGuard{" << Employee::toString() << ", shift=" << shift << "}";
    return ss.str();
}
ostream& operator<<(ostream& os, const SecurityGuard& sg) { os << sg.toString(); return os; }
istream& operator>>(istream& is, SecurityGuard& sg) {
    is >> static_cast<Employee&>(sg) >> sg.shift; return is;
}