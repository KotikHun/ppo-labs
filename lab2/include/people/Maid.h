#pragma once
#include "Employee.h"
#include <string>
#include <iostream>

/** @brief Hotel maid. */
class Maid : public Employee {
private:
    int cleanedRoomsCount;
public:
    Maid();
    Maid(const std::string& fName, const std::string& lName, const Date& bDate, const ContactInfo& contacts, Gender gender, const std::string& position, double salary, int cleanedRoomsCount);
    Maid(const Maid& other);
    Maid& operator=(const Maid& other);
    virtual ~Maid();

    int getCleanedRoomsCount() const;
    void setCleanedRoomsCount(int count);
    void cleanRoom();
    std::string toString() const override;
    friend std::ostream& operator<<(std::ostream& os, const Maid& m);
    friend std::istream& operator>>(std::istream& is, Maid& m);
};