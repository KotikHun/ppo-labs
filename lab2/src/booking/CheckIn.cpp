#include "CheckIn.h"
#include <sstream>
using namespace std;

CheckIn::CheckIn() : checkInDate(), employeeName("") {}
CheckIn::CheckIn(const Id& reservationId, const Date& checkInDate, const string& employeeName)
    : reservationId(reservationId), checkInDate(checkInDate), employeeName(employeeName) {}
CheckIn::CheckIn(const CheckIn& other)
    : reservationId(other.reservationId), checkInDate(other.checkInDate), employeeName(other.employeeName) {}

CheckIn& CheckIn::operator=(const CheckIn& other) {
    if (this == &other) return *this;
    reservationId = other.reservationId;
    checkInDate = other.checkInDate;
    employeeName = other.employeeName;
    return *this;
}
CheckIn::~CheckIn() {}

Id CheckIn::getReservationId() const { return reservationId; }
Date CheckIn::getCheckInDate() const { return checkInDate; }
string CheckIn::getEmployeeName() const { return employeeName; }

string CheckIn::toString() const {
    stringstream ss;
    ss << "CheckIn{res=" << reservationId.toString() << ", date=" << checkInDate.toString()
       << ", by=" << employeeName << "}";
    return ss.str();
}

ostream& operator<<(ostream& os, const CheckIn& ci) { os << ci.toString(); return os; }