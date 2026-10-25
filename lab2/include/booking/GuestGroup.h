#pragma once

#include "Id.h"
#include <vector>
#include <string>
#include <iostream>

/** @brief Represents a group of guests booking together. */
class GuestGroup {
private:
    Id id;
    std::vector<Id> guestIds;
    std::string groupName;

public:
    GuestGroup();
    GuestGroup(const std::string& groupName);
    GuestGroup(const GuestGroup& other);
    GuestGroup& operator=(const GuestGroup& other);
    ~GuestGroup();

    Id getId() const;
    std::string getGroupName() const;
    std::vector<Id> getGuestIds() const;

    void setGroupName(const std::string& groupName);
    void addGuest(const Id& guestId);
    void removeGuest(const Id& guestId);

    std::string toString() const;
    bool operator==(const GuestGroup& other) const;
    bool operator!=(const GuestGroup& other) const;

    friend std::ostream& operator<<(std::ostream& os, const GuestGroup& gg);
};