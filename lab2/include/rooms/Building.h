#pragma once

#include "Address.h"
#include <string>
#include <iostream>

/**
 * @brief Represents a building in the hotel complex.
 */
class Building {
private:
    int number;
    std::string name;
    Address address;
    int floorsCount;

public:
    Building();
    Building(int number, const std::string& name, const Address& address, int floorsCount);
    Building(const Building& other);
    Building& operator=(const Building& other);
    ~Building();

    int getNumber() const;
    std::string getName() const;
    Address getAddress() const;
    int getFloorsCount() const;

    void setNumber(int number);
    void setName(const std::string& name);
    void setAddress(const Address& address);
    void setFloorsCount(int floorsCount);

    std::string toString() const;

    bool operator==(const Building& other) const;
    bool operator!=(const Building& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Building& b);
    friend std::istream& operator>>(std::istream& is, Building& b);
};