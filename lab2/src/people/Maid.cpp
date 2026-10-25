#include "Maid.h"
#include <sstream>
using namespace std;

Maid::Maid() : Employee(), cleanedRoomsCount(0) {}
Maid::Maid(const string& fName, const string& lName, const Date& bDate, const ContactInfo& contacts, Gender gender, const string& position, double salary, int cleanedRoomsCount)
    : Employee(fName, lName, bDate, contacts, gender, position, salary), cleanedRoomsCount(cleanedRoomsCount) {}
Maid::Maid(const Maid& other) : Employee(other), cleanedRoomsCount(other.cleanedRoomsCount) {}
Maid& Maid::operator=(const Maid& other) {
    if (this == &other) return *this;
    Employee::operator=(other);
    cleanedRoomsCount = other.cleanedRoomsCount;
    return *this;
}
Maid::~Maid() {}
int Maid::getCleanedRoomsCount() const { return cleanedRoomsCount; }
void Maid::setCleanedRoomsCount(int count) { cleanedRoomsCount = count; }
void Maid::cleanRoom() { cleanedRoomsCount++; }
string Maid::toString() const {
    stringstream ss;
    ss << "Maid{" << Employee::toString() << ", cleanedRooms=" << cleanedRoomsCount << "}";
    return ss.str();
}
ostream& operator<<(ostream& os, const Maid& m) { os << m.toString(); return os; }
istream& operator>>(istream& is, Maid& m) {
    is >> static_cast<Employee&>(m) >> m.cleanedRoomsCount; return is;
}