#pragma once

#include "Employee.h"
#include "GuestNotFoundException.h" // Или создай EmployeeNotFoundException
#include <vector>
#include <iostream>

/** @brief Manages hotel employees. */
class StaffManager {
private:
    std::vector<Employee*> employees;

public:
    StaffManager();
    ~StaffManager();

    void addEmployee(Employee* emp);
    Employee* findEmployeeById(const Id& id);
    void removeEmployee(const Id& id);
    
    void printAllEmployees() const;
    size_t getEmployeeCount() const;
};