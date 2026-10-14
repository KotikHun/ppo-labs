#pragma once

#include "HotelException.h"

/**
 * @brief Thrown when room capacity is exceeded.
 */
class CapacityExceededException : public HotelException {
public:
    explicit CapacityExceededException(const std::string& message)
        : HotelException(message) {
    }
};