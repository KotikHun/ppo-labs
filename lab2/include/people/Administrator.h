#pragma once
#include "Employee.h"
#include <string>
#include <iostream>

/** @brief Hotel administrator. */
class Administrator : public Employee {
private:
    int deskNumber;
public:
    Administrator();
    Administrator(const std::string& fName, const std::string& lName, const Date& bDate, const ContactInfo& contacts, Gender gender, const std::string& position, double salary, int deskNumber);
    Administrator(const Administrator& other);
    Administrator& operator=(const Administrator& other);
    virtual ~Administrator();

    int getDeskNumber() const;
    void setDeskNumber(int deskNumber);
    std::string toString() const override;
    friend std::ostream& operator<<(std::ostream& os, const Administrator& a);
    friend std::istream& operator>>(std::istream& is, Administrator& a);
};