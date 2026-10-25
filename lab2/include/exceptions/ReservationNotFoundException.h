#pragma once

#include "HotelException.h"

/**
 * @brief Thrown when a reservation is not found.
 */
class ReservationNotFoundException : public HotelException {
public:
    explicit ReservationNotFoundException(const std::string& message)
        : HotelException(message) {
    }
};