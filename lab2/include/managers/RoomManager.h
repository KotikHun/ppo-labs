#pragma once

#include "Room.h"
#include "RoomNotFoundException.h"
#include <vector>
#include <iostream>

/**
 * @brief Manages all rooms in the hotel.
 */
class RoomManager {
private:
    std::vector<Room*> rooms; // Храним указатели из-за полиморфизма!

public:
    RoomManager();
    ~RoomManager();

    void addRoom(Room* room);
    Room* findRoomById(const Id& id);
    Room* findRoomByNumber(int number);
    
    void changeRoomStatus(const Id& id, RoomStatus newStatus);
    void printAllRooms() const;
    
    size_t getRoomCount() const;
};