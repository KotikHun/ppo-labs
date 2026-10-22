#pragma once

#include "Id.h"
#include "Money.h"
#include "PaymentStatus.h"
#include "Date.h"
#include <string>
#include <iostream>

/**
 * @brief Abstract base class for all payment methods.
 */
class Payment {
protected:
    Id id;
    Money amount;
    Date paymentDate;
    PaymentStatus status;

public:
    Payment();
    Payment(const Money& amount, const Date& paymentDate);
    Payment(const Payment& other);
    Payment& operator=(const Payment& other);
    virtual ~Payment();

    Id getId() const;
    Money getAmount() const;
    Date getPaymentDate() const;
    PaymentStatus getStatus() const;

    void setStatus(PaymentStatus status);

    // Чисто виртуальный метод
    virtual bool processPayment() = 0;

    virtual std::string toString() const;

    bool operator==(const Payment& other) const;
    bool operator!=(const Payment& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Payment& p);
};