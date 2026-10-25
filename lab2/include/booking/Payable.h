#pragma once

#include "Money.h"

/**
 * @brief Interface for objects that can be paid for.
 */
class Payable {
public:
    virtual ~Payable() = default;
    virtual Money getTotalAmount() const = 0;
    virtual void pay(const Money& amount) = 0;
};