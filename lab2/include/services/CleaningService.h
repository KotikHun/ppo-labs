#pragma once
#include "Service.h"

/** @brief Cleaning service. */
class CleaningService : public Service {
private:
    int roomsCount;
public:
    CleaningService();
    CleaningService(const std::string& name, const Money& baseCost, int roomsCount);
    CleaningService(const CleaningService& other);
    CleaningService& operator=(const CleaningService& other);
    virtual ~CleaningService();

    int getRoomsCount() const;
    void setRoomsCount(int roomsCount);

    Money calculateCost() const override;
    std::string toString() const override;
    friend std::ostream& operator<<(std::ostream& os, const CleaningService& cs);
};