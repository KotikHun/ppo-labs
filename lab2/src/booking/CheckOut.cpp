#include "CheckOut.h"
#include <sstream>
using namespace std;

CheckOut::CheckOut() : checkOutDate(), roomCleaned(false) {}
CheckOut::CheckOut(const Id& reservationId, const Date& checkOutDate, bool roomCleaned)
    : reservationId(reservationId), checkOutDate(checkOutDate), roomCleaned(roomCleaned) {}
CheckOut::CheckOut(const CheckOut& other)
    : reservationId(other.reservationId), checkOutDate(other.checkOutDate), roomCleaned(other.roomCleaned) {}

CheckOut& CheckOut::operator=(const CheckOut& other) {
    if (this == &other) return *this;
    reservationId = other.reservationId;
    checkOutDate = other.checkOutDate;
    roomCleaned = other.roomCleaned;
    return *this;
}
CheckOut::~CheckOut() {}

Id CheckOut::getReservationId() const { return reservationId; }
Date CheckOut::getCheckOutDate() const { return checkOutDate; }
bool CheckOut::getRoomCleaned() const { return roomCleaned; }

string CheckOut::toString() const {
    stringstream ss;
    ss << "CheckOut{res=" << reservationId.toString() << ", date=" << checkOutDate.toString()
       << ", cleaned=" << (roomCleaned ? "yes" : "no") << "}";
    return ss.str();
}

ostream& operator<<(ostream& os, const CheckOut& co) { os << co.toString(); return os; }