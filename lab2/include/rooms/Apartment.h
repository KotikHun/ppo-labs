#pragma once
#include "Room.h"
#include <string>
#include <iostream>

/** @brief Apartment room. */
class Apartment : public Room {
private:
    int roomCount;
public:
    Apartment();
    Apartment(int roomNumber, int capacity, RoomStatus status, const Money& basePrice, int roomCount);
    Apartment(const Apartment& other);
    Apartment& operator=(const Apartment& other);
    virtual ~Apartment();

    int getRoomCount() const;
    void setRoomCount(int roomCount);
    Money calculatePrice() const override;
    std::string toString() const override;
    friend std::ostream& operator<<(std::ostream& os, const Apartment& a);
    friend std::istream& operator>>(std::istream& is, Apartment& a);
};