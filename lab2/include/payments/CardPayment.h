#pragma once
#include "Payment.h"
#include <string>

/** @brief Card payment. */
class CardPayment : public Payment {
private:
    std::string cardNumber;
public:
    CardPayment();
    CardPayment(const Money& amount, const Date& paymentDate, const std::string& cardNumber);
    CardPayment(const CardPayment& other);
    CardPayment& operator=(const CardPayment& other);
    virtual ~CardPayment();

    std::string getCardNumber() const;
    void setCardNumber(const std::string& cardNumber);

    bool processPayment() override;
    std::string toString() const override;
    friend std::ostream& operator<<(std::ostream& os, const CardPayment& cp);
};