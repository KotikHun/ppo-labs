#pragma once
#include "Money.h"
#include <string>
#include <iostream>

/** @brief Discount rule. */
class Discount {
private:
    std::string description;
    int percent;

public:
    Discount();
    Discount(const std::string& description, int percent);
    Discount(const Discount& other);
    Discount& operator=(const Discount& other);
    ~Discount();

    std::string getDescription() const;
    int getPercent() const;

    Money apply(const Money& amount) const;

    std::string toString() const;
    friend std::ostream& operator<<(std::ostream& os, const Discount& d);
};