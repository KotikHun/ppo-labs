#include "SuiteRoom.h"
#include <sstream>
using namespace std;

SuiteRoom::SuiteRoom() : Room(), hasPrivatePool(false) {}
SuiteRoom::SuiteRoom(int roomNumber, int capacity, RoomStatus status, const Money& basePrice, bool hasPrivatePool)
    : Room(roomNumber, capacity, RoomCategory::Suite, status, basePrice), hasPrivatePool(hasPrivatePool) {}
SuiteRoom::SuiteRoom(const SuiteRoom& other) : Room(other), hasPrivatePool(other.hasPrivatePool) {}
SuiteRoom& SuiteRoom::operator=(const SuiteRoom& other) {
    if (this == &other) return *this;
    Room::operator=(other);
    hasPrivatePool = other.hasPrivatePool;
    return *this;
}
SuiteRoom::~SuiteRoom() {}
bool SuiteRoom::getHasPrivatePool() const { return hasPrivatePool; }
void SuiteRoom::setHasPrivatePool(bool hasPrivatePool) { this->hasPrivatePool = hasPrivatePool; }
Money SuiteRoom::calculatePrice() const { return basePrice.multiply(3.0); }
string SuiteRoom::toString() const {
    stringstream ss;
    ss << "SuiteRoom{" << Room::toString() << ", hasPool=" << (hasPrivatePool ? "yes" : "no") << "}";
    return ss.str();
}
ostream& operator<<(ostream& os, const SuiteRoom& sr) { os << sr.toString(); return os; }
istream& operator>>(istream& is, SuiteRoom& sr) { is >> static_cast<Room&>(sr) >> sr.hasPrivatePool; return is; }