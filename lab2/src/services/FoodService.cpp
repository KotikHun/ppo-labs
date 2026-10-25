#include "FoodService.h"
#include <sstream>
using namespace std;

namespace {
constexpr double ROOM_SERVICE_MULTIPLIER = 1.2;
constexpr double REGULAR_SERVICE_MULTIPLIER = 1.0;
}

FoodService::FoodService() : Service(), isRoomService(false) {}
FoodService::FoodService(const string& name, const Money& baseCost, bool isRoomService)
    : Service(name, ServiceCategory::Food, baseCost), isRoomService(isRoomService) {}
FoodService::FoodService(const FoodService& other) : Service(other), isRoomService(other.isRoomService) {}
FoodService& FoodService::operator=(const FoodService& other) {
    if (this == &other) return *this;
    Service::operator=(other);
    isRoomService = other.isRoomService;
    return *this;
}
FoodService::~FoodService() {}
bool FoodService::getIsRoomService() const { return isRoomService; }
void FoodService::setIsRoomService(bool isRoomService) { this->isRoomService = isRoomService; }

Money FoodService::calculateCost() const {
    if (isRoomService) return baseCost.multiply(ROOM_SERVICE_MULTIPLIER);
    return baseCost.multiply(REGULAR_SERVICE_MULTIPLIER);
}

string FoodService::toString() const {
    stringstream ss;
    ss << "FoodService{" << Service::toString() << ", roomService=" << (isRoomService ? "yes" : "no") << "}";
    return ss.str();
}
ostream& operator<<(ostream& os, const FoodService& fs) { os << fs.toString(); return os; }
