#pragma once
#include "Service.h"

/** @brief Spa service. */
class SpaService : public Service {
private:
    int hours;
public:
    SpaService();
    SpaService(const std::string& name, const Money& baseCost, int hours);
    SpaService(const SpaService& other);
    SpaService& operator=(const SpaService& other);
    virtual ~SpaService();

    int getHours() const;
    void setHours(int hours);

    Money calculateCost() const override;
    std::string toString() const override;
    friend std::ostream& operator<<(std::ostream& os, const SpaService& ss);
};