#include "RoomManager.h"

using namespace std;

RoomManager::RoomManager() {
}

RoomManager::~RoomManager() {
    // Поскольку мы храним указатели, нам нужно их удалить, чтобы не было утечек!
    for (size_t i = 0; i < rooms.size(); ++i) {
        delete rooms[i];
    }
}

void RoomManager::addRoom(Room* room) {
    if (room != nullptr) {
        rooms.push_back(room);
    }
}

Room* RoomManager::findRoomById(const Id& id) {
    for (size_t i = 0; i < rooms.size(); ++i) {
        if (rooms[i]->getId() == id) {
            return rooms[i];
        }
    }
    throw RoomNotFoundException("Room with this ID was not found.");
}

Room* RoomManager::findRoomByNumber(int number) {
    for (size_t i = 0; i < rooms.size(); ++i) {
        if (rooms[i]->getRoomNumber() == number) {
            return rooms[i];
        }
    }
    throw RoomNotFoundException("Room with this number was not found.");
}

void RoomManager::changeRoomStatus(const Id& id, RoomStatus newStatus) {
    Room* room = findRoomById(id);
    room->setStatus(newStatus);
}

void RoomManager::printAllRooms() const {
    cout << "--- All Rooms ---" << endl;
    for (size_t i = 0; i < rooms.size(); ++i) {
        // Благодаря виртуальному toString() выведется правильный тип (StandardRoom, LuxRoom и т.д.)
        cout << rooms[i]->toString() << endl; 
    }
    cout << "-----------------" << endl;
}

size_t RoomManager::getRoomCount() const {
    return rooms.size();
}