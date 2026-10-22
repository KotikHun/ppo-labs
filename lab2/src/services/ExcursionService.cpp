#include "ExcursionService.h"
#include <sstream>
using namespace std;

ExcursionService::ExcursionService() : Service(), peopleCount(1) {}
ExcursionService::ExcursionService(const string& name, const Money& baseCost, int peopleCount)
    : Service(name, ServiceCategory::Excursion, baseCost), peopleCount(peopleCount) {}
ExcursionService::ExcursionService(const ExcursionService& other) : Service(other), peopleCount(other.peopleCount) {}
ExcursionService& ExcursionService::operator=(const ExcursionService& other) {
    if (this == &other) return *this;
    Service::operator=(other);
    peopleCount = other.peopleCount;
    return *this;
}
ExcursionService::~ExcursionService() {}
int ExcursionService::getPeopleCount() const { return peopleCount; }
void ExcursionService::setPeopleCount(int peopleCount) { this->peopleCount = peopleCount; }

Money ExcursionService::calculateCost() const { return baseCost.multiply(peopleCount); }

string ExcursionService::toString() const {
    stringstream ss;
    ss << "ExcursionService{" << Service::toString() << ", people=" << peopleCount << "}";
    return ss.str();
}
ostream& operator<<(ostream& os, const ExcursionService& es) { os << es.toString(); return os; }