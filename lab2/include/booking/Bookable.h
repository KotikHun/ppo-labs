#pragma once

#include "Date.h"

/**
 * @brief Interface for objects that can be booked for a period of time.
 */
class Bookable {
public:
    virtual ~Bookable() = default;
    virtual Date getStartDate() const = 0;
    virtual Date getEndDate() const = 0;
};