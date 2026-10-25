#pragma once
#include "Service.h"

/** @brief Excursion service. */
class ExcursionService : public Service {
private:
    int peopleCount;
public:
    ExcursionService();
    ExcursionService(const std::string& name, const Money& baseCost, int peopleCount);
    ExcursionService(const ExcursionService& other);
    ExcursionService& operator=(const ExcursionService& other);
    virtual ~ExcursionService();

    int getPeopleCount() const;
    void setPeopleCount(int peopleCount);

    Money calculateCost() const override;
    std::string toString() const override;
    friend std::ostream& operator<<(std::ostream& os, const ExcursionService& es);
};