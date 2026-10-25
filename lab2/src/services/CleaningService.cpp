#include "CleaningService.h"
#include <sstream>
using namespace std;

CleaningService::CleaningService() : Service(), roomsCount(1) {}
CleaningService::CleaningService(const string& name, const Money& baseCost, int roomsCount)
    : Service(name, ServiceCategory::Cleaning, baseCost), roomsCount(roomsCount) {}
CleaningService::CleaningService(const CleaningService& other) : Service(other), roomsCount(other.roomsCount) {}
CleaningService& CleaningService::operator=(const CleaningService& other) {
    if (this == &other) return *this;
    Service::operator=(other);
    roomsCount = other.roomsCount;
    return *this;
}
CleaningService::~CleaningService() {}
int CleaningService::getRoomsCount() const { return roomsCount; }
void CleaningService::setRoomsCount(int roomsCount) { this->roomsCount = roomsCount; }

Money CleaningService::calculateCost() const { return baseCost.multiply(roomsCount); }

string CleaningService::toString() const {
    stringstream ss;
    ss << "CleaningService{" << Service::toString() << ", rooms=" << roomsCount << "}";
    return ss.str();
}
ostream& operator<<(ostream& os, const CleaningService& cs) { os << cs.toString(); return os; }