#pragma once

#include "Person.h"
#include <string>
#include <iostream>

/**
 * @brief Base class for hotel employees.
 *
 * Inherits from Person using protected inheritance, so the fact that
 * Employee is a Person is hidden from the outside world.
 */
class Employee : virtual protected Person {
protected:
    std::string position;
    double salary;
    std::string department;
    Date hireDate;

public:
    Employee();
    Employee(const std::string& firstName,
             const std::string& lastName,
             const Date& birthDate,
             const ContactInfo& contacts,
             Gender gender,
             const std::string& position,
             double salary);
    Employee(const Employee& other);
    Employee& operator=(const Employee& other);
    virtual ~Employee();

    std::string getPosition() const;
    double getSalary() const;
    std::string getDepartment() const;
    Date getHireDate() const;

    Id getId() const;

    void setPosition(const std::string& position);
    void setSalary(double salary);
    void setDepartment(const std::string& dept);
    void setHireDate(const Date& date);

    std::string toString() const override;

    bool operator==(const Employee& other) const;
    bool operator!=(const Employee& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Employee& e);
    friend std::istream& operator>>(std::istream& is, Employee& e);
};
