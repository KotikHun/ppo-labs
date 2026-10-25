#pragma once

#include "Id.h"
#include "Date.h"
#include <string>
#include <iostream>

/** @brief Represents a check-out process. */
class CheckOut {
private:
    Id reservationId;
    Date checkOutDate;
    bool roomCleaned; // был ли номер убран после выезда

public:
    CheckOut();
    CheckOut(const Id& reservationId, const Date& checkOutDate, bool roomCleaned);
    CheckOut(const CheckOut& other);
    CheckOut& operator=(const CheckOut& other);
    ~CheckOut();

    Id getReservationId() const;
    Date getCheckOutDate() const;
    bool getRoomCleaned() const;

    std::string toString() const;
    
    friend std::ostream& operator<<(std::ostream& os, const CheckOut& co);
};