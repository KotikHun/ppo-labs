#pragma once

#include "HotelException.h"

/**
 * @brief Thrown when check-out is not allowed.
 */
class CheckOutNotAllowedException : public HotelException {
public:
    explicit CheckOutNotAllowedException(const std::string& message)
        : HotelException(message) {
    }
};