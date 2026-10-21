#pragma once

#include "Address.h"
#include <string>
#include <iostream>

/** @brief Represents a company for corporate bookings. */
class Company {
private:
    std::string name;
    std::string taxId; // ИНН / Tax ID
    Address address;

public:
    Company();
    Company(const std::string& name, const std::string& taxId, const Address& address);
    Company(const Company& other);
    Company& operator=(const Company& other);
    ~Company();

    std::string getName() const;
    std::string getTaxId() const;
    Address getAddress() const;

    void setName(const std::string& name);
    void setTaxId(const std::string& taxId);
    void setAddress(const Address& address);

    std::string toString() const;
    bool operator==(const Company& other) const;
    bool operator!=(const Company& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Company& c);
    friend std::istream& operator>>(std::istream& is, Company& c);
};