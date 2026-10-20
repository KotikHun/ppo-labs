#pragma once

#include "Person.h"
#include <string>
#include <iostream>

/**
 * @brief Guest of the hotel.
 *
 * Inherits from Person and adds passport data and loyalty points.
 */
class Guest : virtual public Person {
protected:
    std::string passportNumber;
    int loyaltyPoints;

public:
    Guest();
    Guest(const std::string& firstName,
          const std::string& lastName,
          const Date& birthDate,
          const ContactInfo& contacts,
          Gender gender,
          const std::string& passportNumber);
    Guest(const Guest& other);
    Guest& operator=(const Guest& other);
    virtual ~Guest();

    std::string getPassportNumber() const;
    int getLoyaltyPoints() const;

    void setPassportNumber(const std::string& passportNumber);
    void setLoyaltyPoints(int loyaltyPoints);

    void addLoyaltyPoints(int points);

    std::string toString() const override;

    bool operator==(const Guest& other) const;
    bool operator!=(const Guest& other) const;
    bool operator<(const Guest& other) const;
    bool operator>(const Guest& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Guest& g);
    friend std::istream& operator>>(std::istream& is, Guest& g);
};