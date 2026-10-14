#pragma once

#include "HotelException.h"

/**
 * @brief Thrown when a service is not available.
 */
class ServiceNotAvailableException : public HotelException {
public:
    explicit ServiceNotAvailableException(const std::string& message)
        : HotelException(message) {
    }
};