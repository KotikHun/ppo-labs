#include "Address.h"
#include <sstream>

using namespace std;

Address::Address() : country(""), city(""), street(""), house("") {
}

Address::Address(const string& country,
                 const string& city,
                 const string& street,
                 const string& house)
    : country(country), city(city), street(street), house(house) {
}

Address::Address(const Address& other)
    : country(other.country), city(other.city),
      street(other.street), house(other.house) {
}

Address& Address::operator=(const Address& other) {
    if (this == &other) {
        return *this;
    }
    country = other.country;
    city = other.city;
    street = other.street;
    house = other.house;
    return *this;
}

Address::~Address() {
}

string Address::getCountry() const {
    return country;
}

string Address::getCity() const {
    return city;
}

string Address::getStreet() const {
    return street;
}

string Address::getHouse() const {
    return house;
}

void Address::setCountry(const string& country) {
    this->country = country;
}

void Address::setCity(const string& city) {
    this->city = city;
}

void Address::setStreet(const string& street) {
    this->street = street;
}

void Address::setHouse(const string& house) {
    this->house = house;
}

string Address::toString() const {
    stringstream ss;
    ss << country << ", " << city << ", " << street << ", " << house;
    return ss.str();
}

bool Address::operator==(const Address& other) const {
    return country == other.country
        && city == other.city
        && street == other.street
        && house == other.house;
}

bool Address::operator!=(const Address& other) const {
    return !(*this == other);
}

bool Address::operator<(const Address& other) const {
    if (country != other.country) {
        return country < other.country;
    }
    if (city != other.city) {
        return city < other.city;
    }
    if (street != other.street) {
        return street < other.street;
    }
    return house < other.house;
}

bool Address::operator>(const Address& other) const {
    return other < *this;
}

ostream& operator<<(ostream& os, const Address& a) {
    os << a.toString();
    return os;
}

istream& operator>>(istream& is, Address& a) {
    string country, city, street, house;
    is >> country >> city >> street >> house;
    a = Address(country, city, street, house);
    return is;
}