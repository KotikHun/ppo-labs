#pragma once

#include "HotelException.h"

/**
 * @brief Thrown when a room is already booked.
 */
class RoomAlreadyBookedException : public HotelException {
public:
    explicit RoomAlreadyBookedException(const std::string& message)
        : HotelException(message) {
    }
};