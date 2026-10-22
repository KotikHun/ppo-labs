#pragma once

#include "Id.h"
#include "Service.h"
#include "ServiceStatus.h"
#include <string>
#include <iostream>

/**
 * @brief Represents an order for a hotel service.
 */
class ServiceOrder {
private:
    Id id;
    Id guestId;
    Id serviceId;
    int quantity;
    ServiceStatus status;
    Money totalCost;

public:
    ServiceOrder();
    ServiceOrder(const Id& guestId, const Id& serviceId, int quantity, const Money& totalCost);
    ServiceOrder(const ServiceOrder& other);
    ServiceOrder& operator=(const ServiceOrder& other);
    ~ServiceOrder();

    Id getId() const;
    Id getGuestId() const;
    Id getServiceId() const;
    int getQuantity() const;
    ServiceStatus getStatus() const;
    Money getTotalCost() const;

    void setStatus(ServiceStatus status);

    std::string toString() const;
    bool operator==(const ServiceOrder& other) const;
    bool operator!=(const ServiceOrder& other) const;

    friend std::ostream& operator<<(std::ostream& os, const ServiceOrder& so);
};