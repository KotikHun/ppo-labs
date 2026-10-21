#include "Reservation.h"
#include <sstream>

using namespace std;

Reservation::Reservation()
    : startDate(), endDate(), totalAmount(), status(BookingStatus::Pending) {
}

Reservation::Reservation(const Id& guestId, const Id& roomId, const Date& startDate, const Date& endDate, const Money& totalAmount)
    : guestId(guestId), roomId(roomId), startDate(startDate), endDate(endDate), totalAmount(totalAmount), status(BookingStatus::Pending) {
}

Reservation::Reservation(const Reservation& other)
    : id(other.id), guestId(other.guestId), roomId(other.roomId),
      startDate(other.startDate), endDate(other.endDate),
      totalAmount(other.totalAmount), status(other.status) {
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
    return *this;
}

Reservation::~Reservation() {
}

Id Reservation::getId() const { return id; }
Id Reservation::getGuestId() const { return guestId; }
Id Reservation::getRoomId() const { return roomId; }
BookingStatus Reservation::getStatus() const { return status; }

void Reservation::setStatus(BookingStatus status) { this->status = status; }

// Реализация Bookable
Date Reservation::getStartDate() const { return startDate; }
Date Reservation::getEndDate() const { return endDate; }

// Реализация Payable
Money Reservation::getTotalAmount() const { return totalAmount; }
void Reservation::pay(const Money& amount) {
    // В простейшем случае: если оплатили достаточно, меняем статус на Confirmed
    if (amount >= totalAmount) {
        status = BookingStatus::Confirmed;
    }
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

bool Reservation::operator==(const Reservation& other) const {
    return id == other.id;
}

bool Reservation::operator!=(const Reservation& other) const {
    return !(*this == other);
}

ostream& operator<<(ostream& os, const Reservation& r) {
    os << r.toString();
    return os;
}

istream& operator>>(istream& is, Reservation& r) {
    // Для простоты пока не реализуем полный ввод, так как много полей Id и Date
    return is;
}