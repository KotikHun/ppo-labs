#include "Company.h"
#include <sstream>
using namespace std;

Company::Company() : name(""), taxId(""), address() {}
Company::Company(const string& name, const string& taxId, const Address& address)
    : name(name), taxId(taxId), address(address) {}
Company::Company(const Company& other) : name(other.name), taxId(other.taxId), address(other.address) {}

Company& Company::operator=(const Company& other) {
    if (this == &other) return *this;
    name = other.name;
    taxId = other.taxId;
    address = other.address;
    return *this;
}
Company::~Company() {}

string Company::getName() const { return name; }
string Company::getTaxId() const { return taxId; }
Address Company::getAddress() const { return address; }

void Company::setName(const string& name) { this->name = name; }
void Company::setTaxId(const string& taxId) { this->taxId = taxId; }
void Company::setAddress(const Address& address) { this->address = address; }

string Company::toString() const {
    stringstream ss;
    ss << "Company{" << name << ", taxId=" << taxId << "}";
    return ss.str();
}

bool Company::operator==(const Company& other) const {
    return taxId == other.taxId;
}
bool Company::operator!=(const Company& other) const { return !(*this == other); }

ostream& operator<<(ostream& os, const Company& c) { os << c.toString(); return os; }
istream& operator>>(istream& is, Company& c) { is >> c.name >> c.taxId >> c.address; return is; }