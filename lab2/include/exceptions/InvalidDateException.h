#pragma once

#include "HotelException.h"

/**
 * @brief Thrown when a date is invalid.
 */
class InvalidDateException : public HotelException {
public:
    explicit InvalidDateException(const std::string& message)
        : HotelException(message) {
    }
};