#pragma once

#include "HotelException.h"

/**
 * @brief Thrown when a room is not found.
 */
class RoomNotFoundException : public HotelException {
public:
    explicit RoomNotFoundException(const std::string& message)
        : HotelException(message) {
    }
};