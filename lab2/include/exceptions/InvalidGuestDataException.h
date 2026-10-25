#pragma once

#include "HotelException.h"

/**
 * @brief Thrown when guest data is invalid.
 */
class InvalidGuestDataException : public HotelException {
public:
    explicit InvalidGuestDataException(const std::string& message)
        : HotelException(message) {
    }
};