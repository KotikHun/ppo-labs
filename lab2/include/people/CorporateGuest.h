#pragma once

#include "Guest.h"
#include <string>
#include <iostream>

/**
 * @brief Corporate guest representing a company.
 */
class CorporateGuest : public Guest {
private:
    std::string companyName;

public:
    CorporateGuest();
    CorporateGuest(const std::string& firstName,
                   const std::string& lastName,
                   const Date& birthDate,
                   const ContactInfo& contacts,
                   Gender gender,
                   const std::string& passportNumber,
                   const std::string& companyName);
    CorporateGuest(const CorporateGuest& other);
    CorporateGuest& operator=(const CorporateGuest& other);
    virtual ~CorporateGuest();

    std::string getCompanyName() const;
    void setCompanyName(const std::string& companyName);

    std::string toString() const override;

    bool operator==(const CorporateGuest& other) const;
    bool operator!=(const CorporateGuest& other) const;

    friend std::ostream& operator<<(std::ostream& os, const CorporateGuest& cg);
    friend std::istream& operator>>(std::istream& is, CorporateGuest& cg);
};