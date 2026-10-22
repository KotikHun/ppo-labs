#include "LaundryService.h"
#include <sstream>
using namespace std;

LaundryService::LaundryService() : Service(), itemsCount(1) {}
LaundryService::LaundryService(const string& name, const Money& baseCost, int itemsCount)
    : Service(name, ServiceCategory::Laundry, baseCost), itemsCount(itemsCount) {}
LaundryService::LaundryService(const LaundryService& other) : Service(other), itemsCount(other.itemsCount) {}
LaundryService& LaundryService::operator=(const LaundryService& other) {
    if (this == &other) return *this;
    Service::operator=(other);
    itemsCount = other.itemsCount;
    return *this;
}
LaundryService::~LaundryService() {}
int LaundryService::getItemsCount() const { return itemsCount; }
void LaundryService::setItemsCount(int itemsCount) { this->itemsCount = itemsCount; }

Money LaundryService::calculateCost() const {
    Money cost = baseCost.multiply(itemsCount);
    if (itemsCount > 10) return cost.multiply(0.9);
    return cost;
}

string LaundryService::toString() const {
    stringstream ss;
    ss << "LaundryService{" << Service::toString() << ", items=" << itemsCount << "}";
    return ss.str();
}
ostream& operator<<(ostream& os, const LaundryService& ls) { os << ls.toString(); return os; }