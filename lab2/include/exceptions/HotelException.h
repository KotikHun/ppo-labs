#pragma once

#include <stdexcept>
#include <string>

/**
 * @brief Base exception for all hotel errors.
 *
 * Inherits from std::runtime_error, so what() returns the message
 * passed to the constructor. All hotel-specific exceptions should
 * inherit from this class.
 */
class HotelException : public std::runtime_error {
public:
    explicit HotelException(const std::string& message)
        : std::runtime_error(message) {
    }
};