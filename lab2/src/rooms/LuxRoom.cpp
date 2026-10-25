#include "LuxRoom.h"
#include <sstream>
using namespace std;

namespace {
constexpr double LUX_MULTIPLIER = 1.5;
}

LuxRoom::LuxRoom() : Room(), hasJacuzzi(false) {}
LuxRoom::LuxRoom(int roomNumber, int capacity, RoomStatus status, const Money& basePrice, bool hasJacuzzi)
    : Room(roomNumber, capacity, RoomCategory::Lux, status, basePrice), hasJacuzzi(hasJacuzzi) {}
LuxRoom::LuxRoom(const LuxRoom& other) : Room(other), hasJacuzzi(other.hasJacuzzi) {}
LuxRoom& LuxRoom::operator=(const LuxRoom& other) {
    if (this == &other) return *this;
    Room::operator=(other);
    hasJacuzzi = other.hasJacuzzi;
    return *this;
}
LuxRoom::~LuxRoom() {}
bool LuxRoom::getHasJacuzzi() const { return hasJacuzzi; }
void LuxRoom::setHasJacuzzi(bool hasJacuzzi) { this->hasJacuzzi = hasJacuzzi; }
Money LuxRoom::calculatePrice() const { return basePrice.multiply(LUX_MULTIPLIER); }
string LuxRoom::toString() const {
    stringstream ss;
    ss << "LuxRoom{" << Room::toString() << ", jacuzzi=" << (hasJacuzzi ? "yes" : "no") << "}";
    return ss.str();
}
ostream& operator<<(ostream& os, const LuxRoom& r) { os << r.toString(); return os; }
istream& operator>>(istream& is, LuxRoom& r) { is >> static_cast<Room&>(r) >> r.hasJacuzzi; return is; }
