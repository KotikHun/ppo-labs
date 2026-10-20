#pragma once
#include "Employee.h"
#include <string>
#include <iostream>

/** @brief Hotel security guard. */
class SecurityGuard : public Employee {
private:
    std::string shift;
public:
    SecurityGuard();
    SecurityGuard(const std::string& fName, const std::string& lName, const Date& bDate, const ContactInfo& contacts, Gender gender, const std::string& position, double salary, const std::string& shift);
    SecurityGuard(const SecurityGuard& other);
    SecurityGuard& operator=(const SecurityGuard& other);
    virtual ~SecurityGuard();

    std::string getShift() const;
    void setShift(const std::string& shift);
    std::string toString() const override;
    friend std::ostream& operator<<(std::ostream& os, const SecurityGuard& sg);
    friend std::istream& operator>>(std::istream& is, SecurityGuard& sg);
};