#include "Apartment.h"
#include <sstream>
using namespace std;

Apartment::Apartment() : Room(), roomCount(1) {}
Apartment::Apartment(int roomNumber, int capacity, RoomStatus status, const Money& basePrice, int roomCount)
    : Room(roomNumber, capacity, RoomCategory::Apartment, status, basePrice), roomCount(roomCount) {}
Apartment::Apartment(const Apartment& other) : Room(other), roomCount(other.roomCount) {}
Apartment& Apartment::operator=(const Apartment& other) {
    if (this == &other) return *this;
    Room::operator=(other);
    roomCount = other.roomCount;
    return *this;
}
Apartment::~Apartment() {}
int Apartment::getRoomCount() const { return roomCount; }
void Apartment::setRoomCount(int roomCount) { this->roomCount = roomCount; }
Money Apartment::calculatePrice() const { return basePrice.multiply(2.0); }
string Apartment::toString() const {
    stringstream ss;
    ss << "Apartment{" << Room::toString() << ", rooms=" << roomCount << "}";
    return ss.str();
}
ostream& operator<<(ostream& os, const Apartment& a) { os << a.toString(); return os; }
istream& operator>>(istream& is, Apartment& a) { is >> static_cast<Room&>(a) >> a.roomCount; return is; }