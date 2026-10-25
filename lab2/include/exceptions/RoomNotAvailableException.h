#pragma once

#include "HotelException.h"

/**
 * @brief Thrown when a room is not available for booking.
 */
class RoomNotAvailableException : public HotelException {
public:
    explicit RoomNotAvailableException(const std::string& message)
        : HotelException(message) {
    }
};