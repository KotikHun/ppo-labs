#pragma once

#include "Id.h"
#include "Date.h"
#include <string>
#include <iostream>

/** @brief Represents a check-in process. */
class CheckIn {
private:
    Id reservationId;
    Date checkInDate;
    std::string employeeName; // кто заселил

public:
    CheckIn();
    CheckIn(const Id& reservationId, const Date& checkInDate, const std::string& employeeName);
    CheckIn(const CheckIn& other);
    CheckIn& operator=(const CheckIn& other);
    ~CheckIn();

    Id getReservationId() const;
    Date getCheckInDate() const;
    std::string getEmployeeName() const;

    std::string toString() const;
    
    friend std::ostream& operator<<(std::ostream& os, const CheckIn& ci);
};