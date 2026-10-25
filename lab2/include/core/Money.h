#pragma once

#include "Currency.h"
#include <string>
#include <iostream>

/**
 * @brief Monetary value with currency.
 *
 * Stores amount and currency. Supports arithmetic operations,
 * comparison, and text input/output.
 */
class Money {
private:
    double amount;
    Currency currency;

public:
    Money();
    Money(double amount, Currency currency);
    Money(const Money& other);
    Money& operator=(const Money& other);
    ~Money();

    double getAmount() const;
    Currency getCurrency() const;

    Money add(const Money& other) const;
    Money subtract(const Money& other) const;
    Money multiply(double factor) const;

    std::string toString() const;

    bool operator==(const Money& other) const;
    bool operator!=(const Money& other) const;
    bool operator<(const Money& other) const;
    bool operator>(const Money& other) const;
    bool operator<=(const Money& other) const;
    bool operator>=(const Money& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Money& m);
    friend std::istream& operator>>(std::istream& is, Money& m);
};