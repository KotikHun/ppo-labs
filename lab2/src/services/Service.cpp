#include "Service.h"
#include <sstream>

using namespace std;

Service::Service() : name(""), category(ServiceCategory::Cleaning), baseCost() {}

Service::Service(const string& name, ServiceCategory category, const Money& baseCost)
    : name(name), category(category), baseCost(baseCost) {}

Service::Service(const Service& other)
    : id(other.id), name(other.name), category(other.category), baseCost(other.baseCost) {}

Service& Service::operator=(const Service& other) {
    if (this == &other) return *this;
    id = other.id;
    name = other.name;
    category = other.category;
    baseCost = other.baseCost;
    return *this;
}

Service::~Service() {}

Id Service::getId() const { return id; }
string Service::getName() const { return name; }
ServiceCategory Service::getCategory() const { return category; }
Money Service::getBaseCost() const { return baseCost; }

void Service::setName(const string& name) { this->name = name; }
void Service::setCategory(ServiceCategory category) { this->category = category; }
void Service::setBaseCost(const Money& baseCost) { this->baseCost = baseCost; }

string Service::toString() const {
    stringstream ss;
    ss << "Service{id=" << id.toString() << ", name=" << name << ", cost=" << baseCost.toString() << "}";
    return ss.str();
}

bool Service::operator==(const Service& other) const { return id == other.id; }
bool Service::operator!=(const Service& other) const { return !(*this == other); }

ostream& operator<<(ostream& os, const Service& s) {
    os << s.toString();
    return os;
}