#pragma once

#include "Guest.h"
#include <string>
#include <iostream>

/**
 * @brief Regular guest with a visit counter.
 *
 * Inherits from Guest and adds tracking of how many times the guest stayed.
 */
class RegularGuest : public Guest {
private:
    int visitCount;

public:
    RegularGuest();
    RegularGuest(const std::string& firstName,
                 const std::string& lastName,
                 const Date& birthDate,
                 const ContactInfo& contacts,
                 Gender gender,
                 const std::string& passportNumber);
    RegularGuest(const RegularGuest& other);
    RegularGuest& operator=(const RegularGuest& other);
    virtual ~RegularGuest();

    int getVisitCount() const;
    void setVisitCount(int visitCount);
    void incrementVisitCount();

    std::string toString() const override;

    bool operator==(const RegularGuest& other) const;
    bool operator!=(const RegularGuest& other) const;

    friend std::ostream& operator<<(std::ostream& os, const RegularGuest& rg);
    friend std::istream& operator>>(std::istream& is, RegularGuest& rg);
};