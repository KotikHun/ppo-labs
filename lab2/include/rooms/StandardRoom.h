#pragma once

#include "Room.h"
#include <string>
#include <iostream>

/**
 * @brief Standard hotel room.
 */
class StandardRoom : public Room {
private:
    bool hasBalcony;

public:
    StandardRoom();
    StandardRoom(int roomNumber, int capacity, RoomStatus status, const Money& basePrice, bool hasBalcony);
    StandardRoom(const StandardRoom& other);
    StandardRoom& operator=(const StandardRoom& other);
    virtual ~StandardRoom();

    bool getHasBalcony() const;
    void setHasBalcony(bool hasBalcony);

    // Переопределяем чисто виртуальный метод!
    Money calculatePrice() const override;

    std::string toString() const override;

    friend std::ostream& operator<<(std::ostream& os, const StandardRoom& sr);
    friend std::istream& operator>>(std::istream& is, StandardRoom& sr);
};