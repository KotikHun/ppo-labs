#pragma once

#include <stdexcept>
#include <string>

namespace hotel::exceptions {

/**
 * @brief Base exception for all domain-specific errors in Hotel Management System.
 *
 * Inherits from std::runtime_error. Stores human-readable diagnostic message.
 */
class HotelException : public std::runtime_error {
public:
    explicit HotelException(const std::string& message)
        : std::runtime_error(message) {
    }

    ~HotelException() noexcept override = default;
};

} // namespace hotel::exceptions

using hotel::exceptions::HotelException;
