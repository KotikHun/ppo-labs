#pragma once
#include "Payment.h"
#include <string>

/** @brief Online payment. */
class OnlinePayment : public Payment {
private:
    std::string email;
public:
    OnlinePayment();
    OnlinePayment(const Money& amount, const Date& paymentDate, const std::string& email);
    OnlinePayment(const OnlinePayment& other);
    OnlinePayment& operator=(const OnlinePayment& other);
    virtual ~OnlinePayment();

    std::string getEmail() const;
    void setEmail(const std::string& email);

    bool processPayment() override;
    std::string toString() const override;
    friend std::ostream& operator<<(std::ostream& os, const OnlinePayment& op);
};