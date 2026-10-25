#include "Building.h"
#include <sstream>

using namespace std;

Building::Building()
    : number(1), name("Main"), address(), floorsCount(1),
      constructionYear(2020), description("Main building") {}

Building::Building(int number, const string& name, const Address& address, int floorsCount)
    : number(number), name(name), address(address), floorsCount(floorsCount),
      constructionYear(2020), description("Building") {}

Building::Building(const Building& other)
    : number(other.number), name(other.name), address(other.address),
      floorsCount(other.floorsCount), constructionYear(other.constructionYear),
      description(other.description) {}

Building& Building::operator=(const Building& other) {
    if (this == &other) return *this;
    number = other.number;
    name = other.name;
    address = other.address;
    floorsCount = other.floorsCount;
    constructionYear = other.constructionYear;
    description = other.description;
    return *this;
}

Building::~Building() {}

int Building::getNumber() const { return number; }
string Building::getName() const { return name; }
Address Building::getAddress() const { return address; }
int Building::getFloorsCount() const { return floorsCount; }
int Building::getConstructionYear() const { return constructionYear; }
string Building::getDescription() const { return description; }

void Building::setNumber(int number) { this->number = number; }
void Building::setName(const string& name) { this->name = name; }
void Building::setAddress(const Address& address) { this->address = address; }
void Building::setFloorsCount(int floorsCount) { this->floorsCount = floorsCount; }
void Building::setConstructionYear(int year) { this->constructionYear = year; }
void Building::setDescription(const string& desc) { this->description = desc; }

string Building::toString() const {
    stringstream ss;
    ss << "Building{" << number << ", " << name << ", floors=" << floorsCount << ", " << address.toString() << "}";
    return ss.str();
}

bool Building::operator==(const Building& other) const {
    return number == other.number && name == other.name && address == other.address && floorsCount == other.floorsCount;
}

bool Building::operator!=(const Building& other) const { return !(*this == other); }

ostream& operator<<(ostream& os, const Building& b) { os << b.toString(); return os; }
istream& operator>>(istream& is, Building& b) {
    is >> b.number >> b.name >> b.address >> b.floorsCount;
    return is;
}
