#pragma once
#include "Service.h"

/** @brief Food service. */
class FoodService : public Service {
private:
    bool isRoomService;
public:
    FoodService();
    FoodService(const std::string& name, const Money& baseCost, bool isRoomService);
    FoodService(const FoodService& other);
    FoodService& operator=(const FoodService& other);
    virtual ~FoodService();

    bool getIsRoomService() const;
    void setIsRoomService(bool isRoomService);

    Money calculateCost() const override;
    std::string toString() const override;
    friend std::ostream& operator<<(std::ostream& os, const FoodService& fs);
};