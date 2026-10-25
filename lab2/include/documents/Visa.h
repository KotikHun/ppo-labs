#pragma once
#include "Document.h"

/** @brief Visa document. */
class Visa : public Document {
private:
    std::string visaType;
public:
    Visa();
    Visa(const std::string& documentNumber, const Date& issueDate, const Date& expiryDate, const std::string& visaType);
    Visa(const Visa& other);
    Visa& operator=(const Visa& other);
    virtual ~Visa();

    std::string getVisaType() const;
    void setVisaType(const std::string& visaType);

    bool isValid(const Date& currentDate) const override;
    std::string toString() const override;
    friend std::ostream& operator<<(std::ostream& os, const Visa& v);
};