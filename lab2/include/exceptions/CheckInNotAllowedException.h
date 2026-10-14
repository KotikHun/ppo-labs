#pragma once

#include "HotelException.h"

/**
 * @brief Thrown when check-in is not allowed.
 */
class CheckInNotAllowedException : public HotelException {
public:
    explicit CheckInNotAllowedException(const std::string& message)
        : HotelException(message) {
    }
};