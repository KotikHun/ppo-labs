#include "Reservation.h"
#include <sstream>

using namespace std;

Reservation::Reservation()
    : startDate(), endDate(), totalAmount(), status(BookingStatus::Pending),
      specialNotes(""), guestCount(1) {
}

Reservation::Reservation(const Id& guestId, const Id& roomId, const Date& startDate, const Date& endDate, const Money& totalAmount)
    : guestId(guestId), roomId(roomId), startDate(startDate), endDate(endDate), totalAmount(totalAmount),
      status(BookingStatus::Pending), specialNotes(""), guestCount(1) {
}

Reservation::Reservation(const Reservation& other)
    : id(other.id), guestId(other.guestId), roomId(other.roomId),
      startDate(other.startDate), endDate(other.endDate),
      totalAmount(other.totalAmount), status(other.status),
      specialNotes(other.specialNotes), guestCount(other.guestCount) {
}

Reservation& Reservation::operator=(const Reservation& other) {
    if (this == &other) {
        return *this;
    }
    id = other.id;
    guestId = other.guestId;
    roomId = other.roomId;
    startDate = other.startDate;
    endDate = other.endDate;
    totalAmount = other.totalAmount;
    status = other.status;
    specialNotes = other.specialNotes;
    guestCount = other.guestCount;
    return *this;
}

Reservation::~Reservation() {}

Id Reservation::getId() const { return id; }
Id Reservation::getGuestId() const { return guestId; }
Id Reservation::getRoomId() const { return roomId; }
BookingStatus Reservation::getStatus() const { return status; }
string Reservation::getSpecialNotes() const { return specialNotes; }
int Reservation::getGuestCount() const { return guestCount; }

void Reservation::setStatus(BookingStatus status) { this->status = status; }
void Reservation::setSpecialNotes(const string& notes) { this->specialNotes = notes; }
void Reservation::setGuestCount(int count) { this->guestCount = count; }

Date Reservation::getStartDate() const { return startDate; }
Date Reservation::getEndDate() const { return endDate; }
Money Reservation::getTotalAmount() const { return totalAmount; }
void Reservation::pay(const Money& amount) {
    totalAmount = totalAmount.subtract(amount);
}

string Reservation::toString() const {
    stringstream ss;
    ss << "Reservation{id=" << id.toString()
       << ", guest=" << guestId.toString()
       << ", room=" << roomId.toString()
       << ", dates=" << startDate.toString() << "-" << endDate.toString()
       << ", amount=" << totalAmount.toString() << "}";
    return ss.str();
}

bool Reservation::operator==(const Reservation& other) const { return id == other.id; }
bool Reservation::operator!=(const Reservation& other) const { return !(*this == other); }

ostream& operator<<(ostream& os, const Reservation& r) {
    os << r.toString();
    return os;
}

istream& operator>>(istream& is, Reservation& r) {
    int gId, rId;
    is >> gId >> rId;
    return is;
}
