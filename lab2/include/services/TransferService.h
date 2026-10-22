#pragma once
#include "Service.h"

/** @brief Transfer service. */
class TransferService : public Service {
private:
    double distanceKm;
public:
    TransferService();
    TransferService(const std::string& name, const Money& baseCost, double distanceKm);
    TransferService(const TransferService& other);
    TransferService& operator=(const TransferService& other);
    virtual ~TransferService();

    double getDistanceKm() const;
    void setDistanceKm(double distanceKm);

    Money calculateCost() const override;
    std::string toString() const override;
    friend std::ostream& operator<<(std::ostream& os, const TransferService& ts);
};