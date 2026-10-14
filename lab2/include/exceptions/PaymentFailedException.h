#pragma once

#include "HotelException.h"

/**
 * @brief Thrown when a payment fails.
 */
class PaymentFailedException : public HotelException {
public:
    explicit PaymentFailedException(const std::string& message)
        : HotelException(message) {
    }
};