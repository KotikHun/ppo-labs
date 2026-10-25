#pragma once
#include "Document.h"
#include "Money.h"

/** @brief Receipt document. */
class Receipt : public Document {
private:
    Money totalAmount;
public:
    Receipt();
    Receipt(const std::string& documentNumber, const Date& issueDate, const Date& expiryDate, const Money& totalAmount);
    Receipt(const Receipt& other);
    Receipt& operator=(const Receipt& other);
    virtual ~Receipt();

    Money getTotalAmount() const;
    void setTotalAmount(const Money& totalAmount);

    bool isValid(const Date& currentDate) const override;
    std::string toString() const override;
    friend std::ostream& operator<<(std::ostream& os, const Receipt& r);
};