#pragma once

#include <iostream>
#include <string>

/**
 * @brief Simple logger for the hotel.
 */
class Logger {
public:
    virtual ~Logger() = default;

    void log(const std::string& message) const {
        std::cout << "[LOG] " << message << std::endl;
    }
};