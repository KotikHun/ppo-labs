#include "Floor.h"
#include <sstream>

using namespace std;

Floor::Floor() : number(1), roomsCount(0), description("") {}

Floor::Floor(int number, int roomsCount, const string& description)
    : number(number), roomsCount(roomsCount), description(description) {}

Floor::Floor(const Floor& other)
    : number(other.number), roomsCount(other.roomsCount), description(other.description) {}

Floor& Floor::operator=(const Floor& other) {
    if (this == &other) return *this;
    number = other.number;
    roomsCount = other.roomsCount;
    description = other.description;
    return *this;
}

Floor::~Floor() {}

int Floor::getNumber() const { return number; }
int Floor::getRoomsCount() const { return roomsCount; }
string Floor::getDescription() const { return description; }

void Floor::setNumber(int number) { this->number = number; }
void Floor::setRoomsCount(int roomsCount) { this->roomsCount = roomsCount; }
void Floor::setDescription(const string& description) { this->description = description; }

string Floor::toString() const {
    stringstream ss;
    ss << "Floor{" << number << ", rooms=" << roomsCount << ", " << description << "}";
    return ss.str();
}

bool Floor::operator==(const Floor& other) const {
    return number == other.number && roomsCount == other.roomsCount && description == other.description;
}

bool Floor::operator!=(const Floor& other) const { return !(*this == other); }

ostream& operator<<(ostream& os, const Floor& f) { os << f.toString(); return os; }
istream& operator>>(istream& is, Floor& f) {
    is >> f.number >> f.roomsCount >> f.description;
    return is;
}