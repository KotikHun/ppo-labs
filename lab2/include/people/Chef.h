#pragma once
#include "Employee.h"
#include <string>
#include <iostream>

/** @brief Hotel chef. */
class Chef : public Employee {
private:
    std::string specialty;
public:
    Chef();
    Chef(const std::string& fName, const std::string& lName, const Date& bDate, const ContactInfo& contacts, Gender gender, const std::string& position, double salary, const std::string& specialty);
    Chef(const Chef& other);
    Chef& operator=(const Chef& other);
    virtual ~Chef();

    std::string getSpecialty() const;
    void setSpecialty(const std::string& specialty);
    std::string toString() const override;
    friend std::ostream& operator<<(std::ostream& os, const Chef& c);
    friend std::istream& operator>>(std::istream& is, Chef& c);
};