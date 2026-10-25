#pragma once
#include "Id.h"
#include "Comment.h"
#include <string>
#include <iostream>

/** @brief Guest complaint. */
class Complaint {
private:
    Id id;
    Id guestId;
    Comment description;
    int priority; // 1 (low) to 3 (high)
    bool isResolved;

public:
    Complaint();
    Complaint(const Id& guestId, const Comment& description, int priority);
    Complaint(const Complaint& other);
    Complaint& operator=(const Complaint& other);
    ~Complaint();

    Id getId() const;
    Id getGuestId() const;
    Comment getDescription() const;
    int getPriority() const;
    bool getIsResolved() const;

    void resolve();

    std::string toString() const;
    friend std::ostream& operator<<(std::ostream& os, const Complaint& c);
};