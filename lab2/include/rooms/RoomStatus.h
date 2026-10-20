#pragma once

/**
 * @brief Current status of a room.
 */
enum class RoomStatus {
    Available,  // Свободен
    Occupied,   // Занят
    Cleaning,   // На уборке
    Maintenance // На ремонте
};