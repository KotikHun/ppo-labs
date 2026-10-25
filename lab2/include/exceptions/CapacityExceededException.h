#pragma once

#include "HotelException.h"
#include <string>

namespace hotel::exceptions {

/**
 * @brief Thrown when guest count exceeds the maximum room capacity.
 */
class CapacityExceededException : public HotelException {
public:
    explicit CapacityExceededException(const std::string& message)
        : HotelException(message) {
    }

    ~CapacityExceededException() noexcept override = default;
};

} // namespace hotel::exceptions

using hotel::exceptions::CapacityExceededException;
