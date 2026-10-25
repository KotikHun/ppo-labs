#pragma once

#include "Payment.h"
#include "InvalidPaymentException.h"
#include <vector>
#include <iostream>

/** @brief Manages payments. */
class PaymentManager {
private:
    std::vector<Payment*> payments;

public:
    PaymentManager();
    ~PaymentManager(); // Не забудь удалить память!

    void addPayment(Payment* payment);
    Payment* findPaymentById(const Id& id);
    void processPayment(const Id& id);
    
    void printAllPayments() const;
    size_t getPaymentCount() const;
};