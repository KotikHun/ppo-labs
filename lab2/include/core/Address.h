#pragma once

#include <string>
#include <iostream>

/**
 * @brief Postal address.
 *
 * Stores country, city, street and house number.
 * House is a string because it may contain letters (e.g. "12A").
 */
class Address {
private:
    std::string country;
    std::string city;
    std::string street;
    std::string house;

public:
    Address();
    Address(const std::string& country,
            const std::string& city,
            const std::string& street,
            const std::string& house);
    Address(const Address& other);
    Address& operator=(const Address& other);
    ~Address();

    std::string getCountry() const;
    std::string getCity() const;
    std::string getStreet() const;
    std::string getHouse() const;

    void setCountry(const std::string& country);
    void setCity(const std::string& city);
    void setStreet(const std::string& street);
    void setHouse(const std::string& house);

    std::string toString() const;

    bool operator==(const Address& other) const;
    bool operator!=(const Address& other) const;
    bool operator<(const Address& other) const;
    bool operator>(const Address& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Address& a);
    friend std::istream& operator>>(std::istream& is, Address& a);
};