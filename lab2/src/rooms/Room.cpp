#include "Room.h"
#include <sstream>

using namespace std;

Room::Room()
    : roomNumber(0), capacity(0), category(RoomCategory::Standard),
      status(RoomStatus::Available), basePrice() {
}

Room::Room(int roomNumber, int capacity, RoomCategory category, RoomStatus status, const Money& basePrice)
    : roomNumber(roomNumber), capacity(capacity), category(category),
      status(status), basePrice(basePrice) {
}

Room::Room(const Room& other)
    : id(other.id), roomNumber(other.roomNumber), capacity(other.capacity),
      category(other.category), status(other.status), basePrice(other.basePrice) {
}

Room& Room::operator=(const Room& other) {
    if (this == &other) {
        return *this;
    }
    id = other.id;
    roomNumber = other.roomNumber;
    capacity = other.capacity;
    category = other.category;
    status = other.status;
    basePrice = other.basePrice;
    return *this;
}

Room::~Room() {
}

int Room::getRoomNumber() const {
    return roomNumber;
}

int Room::getCapacity() const {
    return capacity;
}

RoomCategory Room::getCategory() const {
    return category;
}

RoomStatus Room::getStatus() const {
    return status;
}

Money Room::getBasePrice() const {
    return basePrice;
}

Id Room::getId() const {
    return id;
}

void Room::setRoomNumber(int roomNumber) {
    this->roomNumber = roomNumber;
}

void Room::setCapacity(int capacity) {
    this->capacity = capacity;
}

void Room::setCategory(RoomCategory category) {
    this->category = category;
}

void Room::setStatus(RoomStatus status) {
    this->status = status;
}

void Room::setBasePrice(const Money& basePrice) {
    this->basePrice = basePrice;
}

string Room::toString() const {
    stringstream ss;
    ss << "Room{id=" << id.toString()
       << ", number=" << roomNumber
       << ", capacity=" << capacity
       << ", basePrice=" << basePrice.toString() << "}";
    return ss.str();
}

bool Room::operator==(const Room& other) const {
    return id == other.id;
}

bool Room::operator!=(const Room& other) const {
    return !(*this == other);
}

ostream& operator<<(ostream& os, const Room& r) {
    os << r.toString();
    return os;
}

istream& operator>>(istream& is, Room& r) {
    int catInt, statInt;
    is >> r.roomNumber >> r.capacity >> catInt >> statInt >> r.basePrice;
    r.category = static_cast<RoomCategory>(catInt);
    r.status = static_cast<RoomStatus>(statInt);
    return is;
}

