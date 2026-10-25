#include "SpaService.h"
#include <sstream>
using namespace std;

namespace {
constexpr double SPA_SURCHARGE_FACTOR = 1.5;
}

SpaService::SpaService() : Service(), hours(1) {}
SpaService::SpaService(const string& name, const Money& baseCost, int hours)
    : Service(name, ServiceCategory::Spa, baseCost), hours(hours) {}
SpaService::SpaService(const SpaService& other) : Service(other), hours(other.hours) {}
SpaService& SpaService::operator=(const SpaService& other) {
    if (this == &other) return *this;
    Service::operator=(other);
    hours = other.hours;
    return *this;
}
SpaService::~SpaService() {}
int SpaService::getHours() const { return hours; }
void SpaService::setHours(int hours) { this->hours = hours; }

Money SpaService::calculateCost() const { return baseCost.multiply(hours).multiply(SPA_SURCHARGE_FACTOR); }

string SpaService::toString() const {
    stringstream ss;
    ss << "SpaService{" << Service::toString() << ", hours=" << hours << "}";
    return ss.str();
}
ostream& operator<<(ostream& os, const SpaService& ss) { os << ss.toString(); return os; }
