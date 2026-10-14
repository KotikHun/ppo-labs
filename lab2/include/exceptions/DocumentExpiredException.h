#pragma once

#include "HotelException.h"

/**
 * @brief Thrown when a document is expired.
 */
class DocumentExpiredException : public HotelException {
public:
    explicit DocumentExpiredException(const std::string& message)
        : HotelException(message) {
    }
};