#pragma once

#include "Guest.h"
#include <string>
#include <iostream>

/**
 * @brief VIP guest with a personal discount.
 */
class VipGuest : public Guest {
private:
    int discountPercent;

public:
    VipGuest();
    VipGuest(const std::string& firstName,
             const std::string& lastName,
             const Date& birthDate,
             const ContactInfo& contacts,
             Gender gender,
             const std::string& passportNumber,
             int discountPercent);
    VipGuest(const VipGuest& other);
    VipGuest& operator=(const VipGuest& other);
    virtual ~VipGuest();

    int getDiscountPercent() const;
    void setDiscountPercent(int discountPercent);

    std::string toString() const override;

    bool operator==(const VipGuest& other) const;
    bool operator!=(const VipGuest& other) const;

    friend std::ostream& operator<<(std::ostream& os, const VipGuest& vg);
    friend std::istream& operator>>(std::istream& is, VipGuest& vg);
};