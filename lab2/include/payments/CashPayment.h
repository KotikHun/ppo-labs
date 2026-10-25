#pragma once
#include "Payment.h"

/** @brief Cash payment. */
class CashPayment : public Payment {
private:
    Money changeGiven;
public:
    CashPayment();
    CashPayment(const Money& amount, const Date& paymentDate, const Money& changeGiven);
    CashPayment(const CashPayment& other);
    CashPayment& operator=(const CashPayment& other);
    virtual ~CashPayment();

    Money getChangeGiven() const;
    void setChangeGiven(const Money& changeGiven);

    bool processPayment() override;
    std::string toString() const override;
    friend std::ostream& operator<<(std::ostream& os, const CashPayment& cp);
};