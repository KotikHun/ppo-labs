#pragma once

#include "Guest.h"
#include "GuestNotFoundException.h"
#include <vector>
#include <iostream>

/**
 * @brief Manages all guests in the hotel.
 */
class GuestManager {
private:
    std::vector<Guest> guests;

public:
    GuestManager();
    ~GuestManager();

    void addGuest(const Guest& guest);
    Guest* findGuestById(const Id& id);
    void removeGuest(const Id& id);
    
    void printAllGuests() const;
    size_t getGuestCount() const;
};