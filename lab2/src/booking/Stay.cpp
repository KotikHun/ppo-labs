#include "Stay.h"
#include <sstream>
using namespace std;

Stay::Stay() : checkInDate(), checkOutDate() {}
Stay::Stay(const Id& guestId, const Id& roomId, const Date& checkInDate, const Date& checkOutDate)
    : guestId(guestId), roomId(roomId), checkInDate(checkInDate), checkOutDate(checkOutDate) {}
Stay::Stay(const Stay& other)
    : guestId(other.guestId), roomId(other.roomId), checkInDate(other.checkInDate), checkOutDate(other.checkOutDate) {}

Stay& Stay::operator=(const Stay& other) {
    if (this == &other) return *this;
    guestId = other.guestId;
    roomId = other.roomId;
    checkInDate = other.checkInDate;
    checkOutDate = other.checkOutDate;
    return *this;
}
Stay::~Stay() {}

Id Stay::getGuestId() const { return guestId; }
Id Stay::getRoomId() const { return roomId; }
Date Stay::getCheckInDate() const { return checkInDate; }
Date Stay::getCheckOutDate() const { return checkOutDate; }

void Stay::setCheckOutDate(const Date& checkOutDate) { this->checkOutDate = checkOutDate; }

string Stay::toString() const {
    stringstream ss;
    ss << "Stay{guest=" << guestId.toString() << ", room=" << roomId.toString()
       << ", in=" << checkInDate.toString() << ", out=" << checkOutDate.toString() << "}";
    return ss.str();
}

bool Stay::operator==(const Stay& other) const {
    return guestId == other.guestId && roomId == other.roomId && checkInDate == other.checkInDate;
}
bool Stay::operator!=(const Stay& other) const { return !(*this == other); }

ostream& operator<<(ostream& os, const Stay& s) { os << s.toString(); return os; }