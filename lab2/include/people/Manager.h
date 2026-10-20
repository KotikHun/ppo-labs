#pragma once

#include "Employee.h"
#include "Guest.h"
#include <string>
#include <iostream>

/**
 * @brief Hotel manager.
 *
 * Multiple inheritance: a manager is both an Employee and a Guest.
 * Uses virtual inheritance to avoid the diamond problem with Person.
 */
class Manager : public Employee, public Guest {
private:
    std::string department;

public:
    Manager();
    Manager(const std::string& firstName,
            const std::string& lastName,
            const Date& birthDate,
            const ContactInfo& contacts,
            Gender gender,
            const std::string& position,
            double salary,
            const std::string& passportNumber,
            const std::string& department);
    Manager(const Manager& other);
    Manager& operator=(const Manager& other);
    virtual ~Manager();

    std::string getDepartment() const;
    void setDepartment(const std::string& department);

    std::string toString() const override;

    friend std::ostream& operator<<(std::ostream& os, const Manager& m);
    friend std::istream& operator>>(std::istream& is, Manager& m);
};