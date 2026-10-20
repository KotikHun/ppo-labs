#pragma once
#include "Room.h"
#include <string>
#include <iostream>

/** @brief Lux room. */
class LuxRoom : public Room {
private:
    bool hasJacuzzi;
public:
    LuxRoom();
    LuxRoom(int roomNumber, int capacity, RoomStatus status, const Money& basePrice, bool hasJacuzzi);
    LuxRoom(const LuxRoom& other);
    LuxRoom& operator=(const LuxRoom& other);
    virtual ~LuxRoom();

    bool getHasJacuzzi() const;
    void setHasJacuzzi(bool hasJacuzzi);
    Money calculatePrice() const override;
    std::string toString() const override;
    friend std::ostream& operator<<(std::ostream& os, const LuxRoom& lr);
    friend std::istream& operator>>(std::istream& is, LuxRoom& lr);
};