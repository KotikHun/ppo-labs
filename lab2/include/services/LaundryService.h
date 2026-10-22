#pragma once
#include "Service.h"

/** @brief Laundry service. */
class LaundryService : public Service {
private:
    int itemsCount;
public:
    LaundryService();
    LaundryService(const std::string& name, const Money& baseCost, int itemsCount);
    LaundryService(const LaundryService& other);
    LaundryService& operator=(const LaundryService& other);
    virtual ~LaundryService();

    int getItemsCount() const;
    void setItemsCount(int itemsCount);

    Money calculateCost() const override;
    std::string toString() const override;
    friend std::ostream& operator<<(std::ostream& os, const LaundryService& ls);
};