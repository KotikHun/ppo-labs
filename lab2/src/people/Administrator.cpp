#include "Administrator.h"
#include <sstream>
using namespace std;

Administrator::Administrator() : Employee(), deskNumber(0) {}
Administrator::Administrator(const string& fName, const string& lName, const Date& bDate, const ContactInfo& contacts, Gender gender, const string& position, double salary, int deskNumber)
    : Employee(fName, lName, bDate, contacts, gender, position, salary), deskNumber(deskNumber) {}
Administrator::Administrator(const Administrator& other) : Employee(other), deskNumber(other.deskNumber) {}
Administrator& Administrator::operator=(const Administrator& other) {
    if (this == &other) return *this;
    Employee::operator=(other);
    deskNumber = other.deskNumber;
    return *this;
}
Administrator::~Administrator() {}
int Administrator::getDeskNumber() const { return deskNumber; }
void Administrator::setDeskNumber(int deskNumber) { this->deskNumber = deskNumber; }
string Administrator::toString() const {
    stringstream ss;
    ss << "Administrator{" << Employee::toString() << ", desk=" << deskNumber << "}";
    return ss.str();
}
ostream& operator<<(ostream& os, const Administrator& a) { os << a.toString(); return os; }
istream& operator>>(istream& is, Administrator& a) {
    is >> static_cast<Employee&>(a) >> a.deskNumber; return is;
}