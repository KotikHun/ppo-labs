#pragma once

#include "HotelException.h"

/**
 * @brief Thrown when a guest is not found.
 */
class GuestNotFoundException : public HotelException {
public:
    explicit GuestNotFoundException(const std::string& message)
        : HotelException(message) {
    }
};