#pragma once
#include "Document.h"

/** @brief Passport document. */
class Passport : public Document {
private:
    std::string country;
public:
    Passport();
    Passport(const std::string& documentNumber, const Date& issueDate, const Date& expiryDate, const std::string& country);
    Passport(const Passport& other);
    Passport& operator=(const Passport& other);
    virtual ~Passport();

    std::string getCountry() const;
    void setCountry(const std::string& country);

    bool isValid(const Date& currentDate) const override;
    std::string toString() const override;
    friend std::ostream& operator<<(std::ostream& os, const Passport& p);
};