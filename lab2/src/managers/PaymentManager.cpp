#include "PaymentManager.h"

using namespace std;

PaymentManager::PaymentManager() {}

PaymentManager::~PaymentManager() {
    for (size_t i = 0; i < payments.size(); ++i) {
        delete payments[i];
    }
}

void PaymentManager::addPayment(Payment* payment) {
    if (payment != nullptr) {
        payments.push_back(payment);
    }
}

Payment* PaymentManager::findPaymentById(const Id& id) {
    for (size_t i = 0; i < payments.size(); ++i) {
        if (payments[i]->getId() == id) {
            return payments[i];
        }
    }
    throw InvalidPaymentException("Payment not found.");
}

void PaymentManager::processPayment(const Id& id) {
    Payment* p = findPaymentById(id);
    p->processPayment(); // Вызывается полиморфный метод!
}

void PaymentManager::printAllPayments() const {
    cout << "--- All Payments ---" << endl;
    for (size_t i = 0; i < payments.size(); ++i) {
        cout << payments[i]->toString() << endl;
    }
}

size_t PaymentManager::getPaymentCount() const {
    return payments.size();
}