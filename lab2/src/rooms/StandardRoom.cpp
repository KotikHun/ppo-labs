#include "StandardRoom.h"
#include <sstream>

using namespace std;

StandardRoom::StandardRoom()
    : Room(), hasBalcony(false) {
}

StandardRoom::StandardRoom(int roomNumber, int capacity, RoomStatus status, const Money& basePrice, bool hasBalcony)
    : Room(roomNumber, capacity, RoomCategory::Standard, status, basePrice),
      hasBalcony(hasBalcony) {
}

StandardRoom::StandardRoom(const StandardRoom& other)
    : Room(other), hasBalcony(other.hasBalcony) {
}

StandardRoom& StandardRoom::operator=(const StandardRoom& other) {
    if (this == &other) {
        return *this;
    }
    Room::operator=(other);
    hasBalcony = other.hasBalcony;
    return *this;
}

StandardRoom::~StandardRoom() {
}

bool StandardRoom::getHasBalcony() const {
    return hasBalcony;
}

void StandardRoom::setHasBalcony(bool hasBalcony) {
    this->hasBalcony = hasBalcony;
}

// РЕАЛИЗАЦИЯ ЧИСТО ВИРТУАЛЬНОГО МЕТОДА
Money StandardRoom::calculatePrice() const {
    // Базовая цена без наценки
    return basePrice.multiply(1.0); 
}

string StandardRoom::toString() const {
    stringstream ss;
    ss << "StandardRoom{" << Room::toString()
       << ", hasBalcony=" << (hasBalcony ? "yes" : "no") << "}";
    return ss.str();
}

ostream& operator<<(ostream& os, const StandardRoom& sr) {
    os << sr.toString();
    return os;
}

istream& operator>>(istream& is, StandardRoom& sr) {
    is >> static_cast<Room&>(sr);
    is >> sr.hasBalcony;
    return is;
}