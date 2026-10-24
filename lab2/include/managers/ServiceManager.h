#pragma once

#include "ServiceOrder.h"
#include "ServiceNotAvailableException.h"
#include <vector>
#include <iostream>

/** @brief Manages service orders. */
class ServiceManager {
private:
    std::vector<ServiceOrder> orders;

public:
    ServiceManager();
    ~ServiceManager();

    void addOrder(const ServiceOrder& order);
    ServiceOrder* findOrderById(const Id& id);
    void completeOrder(const Id& id);
    
    void printAllOrders() const;
    size_t getOrderCount() const;
};