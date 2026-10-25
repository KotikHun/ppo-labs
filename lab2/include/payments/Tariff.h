#pragma once
#include "Season.h"
#include "Money.h"
#include <string>
#include <iostream>

/** @brief Seasonal tariff rules. */
class Tariff {
private:
    std::string name;
    Season season;
    double multiplier; // насколько умножаем базовую цену

public:
    Tariff();
    Tariff(const std::string& name, Season season, double multiplier);
    Tariff(const Tariff& other);
    Tariff& operator=(const Tariff& other);
    ~Tariff();

    std::string getName() const;
    Season getSeason() const;
    double getMultiplier() const;

    Money apply(const Money& basePrice) const;

    std::string toString() const;
    friend std::ostream& operator<<(std::ostream& os, const Tariff& t);
};