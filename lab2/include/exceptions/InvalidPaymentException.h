#pragma once

#include "HotelException.h"

/**
 * @brief Thrown when a payment is invalid.
 */
class InvalidPaymentException : public HotelException {
public:
    explicit InvalidPaymentException(const std::string& message)
        : HotelException(message) {
    }
};