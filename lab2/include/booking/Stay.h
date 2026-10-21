#pragma once

#include "Id.h"
#include "Date.h"
#include <string>
#include <iostream>

/**
 * @brief Represents a guest's stay in a room.
 */
class Stay {
private:
    Id guestId;
    Id roomId;
    Date checkInDate;
    Date checkOutDate;

public:
    Stay();
    Stay(const Id& guestId, const Id& roomId, const Date& checkInDate, const Date& checkOutDate);
    Stay(const Stay& other);
    Stay& operator=(const Stay& other);
    ~Stay();

    Id getGuestId() const;
    Id getRoomId() const;
    Date getCheckInDate() const;
    Date getCheckOutDate() const;

    void setCheckOutDate(const Date& checkOutDate);

    std::string toString() const;
    bool operator==(const Stay& other) const;
    bool operator!=(const Stay& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Stay& s);
};