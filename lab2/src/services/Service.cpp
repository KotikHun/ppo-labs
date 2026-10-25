#include "Service.h"
#include <sstream>

using namespace std;

Service::Service()
    : name(""), category(ServiceCategory::Cleaning), baseCost(),
      description("Hotel service"), isAvailable(true) {}

Service::Service(const string& name, ServiceCategory category, const Money& baseCost)
    : name(name), category(category), baseCost(baseCost),
      description("Hotel service"), isAvailable(true) {}

Service::Service(const Service& other)
    : id(other.id), name(other.name), category(other.category),
      baseCost(other.baseCost), description(other.description),
      isAvailable(other.isAvailable) {}

Service& Service::operator=(const Service& other) {
    if (this == &other) return *this;
    id = other.id;
    name = other.name;
    category = other.category;
    baseCost = other.baseCost;
    description = other.description;
    isAvailable = other.isAvailable;
    return *this;
}

Service::~Service() {}

Id Service::getId() const { return id; }
string Service::getName() const { return name; }
ServiceCategory Service::getCategory() const { return category; }
Money Service::getBaseCost() const { return baseCost; }
string Service::getDescription() const { return description; }
bool Service::getIsAvailable() const { return isAvailable; }

void Service::setName(const string& name) { this->name = name; }
void Service::setCategory(ServiceCategory category) { this->category = category; }
void Service::setBaseCost(const Money& baseCost) { this->baseCost = baseCost; }
void Service::setDescription(const string& desc) { this->description = desc; }
void Service::setIsAvailable(bool available) { this->isAvailable = available; }

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
