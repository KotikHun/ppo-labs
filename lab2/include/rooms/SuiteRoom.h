#pragma once
#include "Room.h"
#include <string>
#include <iostream>

/** @brief Suite (presidential) room. */
class SuiteRoom : public Room {
private:
    bool hasPrivatePool;
public:
    SuiteRoom();
    SuiteRoom(int roomNumber, int capacity, RoomStatus status, const Money& basePrice, bool hasPrivatePool);
    SuiteRoom(const SuiteRoom& other);
    SuiteRoom& operator=(const SuiteRoom& other);
    virtual ~SuiteRoom();

    bool getHasPrivatePool() const;
    void setHasPrivatePool(bool hasPrivatePool);
    Money calculatePrice() const override;
    std::string toString() const override;
    friend std::ostream& operator<<(std::ostream& os, const SuiteRoom& sr);
    friend std::istream& operator>>(std::istream& is, SuiteRoom& sr);
};