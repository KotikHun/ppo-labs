#include "TransferService.h"
#include <sstream>
using namespace std;

TransferService::TransferService() : Service(), distanceKm(1.0) {}
TransferService::TransferService(const string& name, const Money& baseCost, double distanceKm)
    : Service(name, ServiceCategory::Transfer, baseCost), distanceKm(distanceKm) {}
TransferService::TransferService(const TransferService& other) : Service(other), distanceKm(other.distanceKm) {}
TransferService& TransferService::operator=(const TransferService& other) {
    if (this == &other) return *this;
    Service::operator=(other);
    distanceKm = other.distanceKm;
    return *this;
}
TransferService::~TransferService() {}
double TransferService::getDistanceKm() const { return distanceKm; }
void TransferService::setDistanceKm(double distanceKm) { this->distanceKm = distanceKm; }

Money TransferService::calculateCost() const { return baseCost.multiply(distanceKm); }

string TransferService::toString() const {
    stringstream ss;
    ss << "TransferService{" << Service::toString() << ", km=" << distanceKm << "}";
    return ss.str();
}
ostream& operator<<(ostream& os, const TransferService& ts) { os << ts.toString(); return os; }