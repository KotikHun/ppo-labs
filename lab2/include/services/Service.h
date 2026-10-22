#pragma once

#include "Id.h"
#include "Money.h"
#include "ServiceCategory.h"
#include <string>
#include <iostream>

/**
 * @brief Abstract base class for hotel services.
 */
class Service {
protected:
    Id id;
    std::string name;
    ServiceCategory category;
    Money baseCost;

public:
    Service();
    Service(const std::string& name, ServiceCategory category, const Money& baseCost);
    Service(const Service& other);
    Service& operator=(const Service& other);
    virtual ~Service();

    Id getId() const;
    std::string getName() const;
    ServiceCategory getCategory() const;
    Money getBaseCost() const;

    void setName(const std::string& name);
    void setCategory(ServiceCategory category);
    void setBaseCost(const Money& baseCost);

    // Чисто виртуальный метод
    virtual Money calculateCost() const = 0;

    virtual std::string toString() const;

    bool operator==(const Service& other) const;
    bool operator!=(const Service& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Service& s);
};