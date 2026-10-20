#pragma once

#include "Id.h"
#include "Money.h"
#include "RoomCategory.h"
#include "RoomStatus.h"
#include <string>
#include <iostream>

/**
 * @brief Abstract base class for all hotel rooms.
 *
 * Cannot be instantiated because calculatePrice() is pure virtual.
 */
class Room {
protected:
    Id id;
    int roomNumber;
    int capacity;
    RoomCategory category;
    RoomStatus status;
    Money basePrice;

public:
    Room();
    Room(int roomNumber, int capacity, RoomCategory category, RoomStatus status, const Money& basePrice);
    Room(const Room& other);
    Room& operator=(const Room& other);
    virtual ~Room(); // Обязательно виртуальный!

    int getRoomNumber() const;
    int getCapacity() const;
    RoomCategory getCategory() const;
    RoomStatus getStatus() const;
    Money getBasePrice() const;
    Id getId() const;

    void setRoomNumber(int roomNumber);
    void setCapacity(int capacity);
    void setCategory(RoomCategory category);
    void setStatus(RoomStatus status);
    void setBasePrice(const Money& basePrice);

    // ЧИСТО ВИРТУАЛЬНЫЙ МЕТОД (абстрактный класс)
    virtual Money calculatePrice() const = 0;

    virtual std::string toString() const;

    bool operator==(const Room& other) const;
    bool operator!=(const Room& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Room& r);
    friend std::istream& operator>>(std::istream& is, Room& r);
};