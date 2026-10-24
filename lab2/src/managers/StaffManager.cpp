#include "StaffManager.h"

using namespace std;

StaffManager::StaffManager() {}

StaffManager::~StaffManager() {
    for (size_t i = 0; i < employees.size(); ++i) {
        delete employees[i];
    }
}

void StaffManager::addEmployee(Employee* emp) {
    if (emp != nullptr) {
        employees.push_back(emp);
    }
}

Employee* StaffManager::findEmployeeById(const Id& id) {
    for (size_t i = 0; i < employees.size(); ++i) {
        if (employees[i]->getId() == id) {
            return employees[i];
        }
    }
    throw GuestNotFoundException("Employee not found."); // Пока используем это исключение
}

void StaffManager::removeEmployee(const Id& id) {
    for (size_t i = 0; i < employees.size(); ++i) {
        if (employees[i]->getId() == id) {
            delete employees[i]; // Удаляем из памяти!
            employees.erase(employees.begin() + i);
            return;
        }
    }
    throw GuestNotFoundException("Employee not found.");
}

void StaffManager::printAllEmployees() const {
    cout << "--- All Employees ---" << endl;
    for (size_t i = 0; i < employees.size(); ++i) {
        cout << employees[i]->toString() << endl;
    }
}

size_t StaffManager::getEmployeeCount() const {
    return employees.size();
}