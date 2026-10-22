#include "CardPayment.h"
#include <sstream>
using namespace std;

CardPayment::CardPayment() : Payment(), cardNumber("") {}
CardPayment::CardPayment(const Money& amount, const Date& paymentDate, const string& cardNumber)
    : Payment(amount, paymentDate), cardNumber(cardNumber) {}
CardPayment::CardPayment(const CardPayment& other) : Payment(other), cardNumber(other.cardNumber) {}
CardPayment& CardPayment::operator=(const CardPayment& other) {
    if (this == &other) return *this;
    Payment::operator=(other);
    cardNumber = other.cardNumber;
    return *this;
}
CardPayment::~CardPayment() {}

string CardPayment::getCardNumber() const { return cardNumber; }
void CardPayment::setCardNumber(const string& cardNumber) { this->cardNumber = cardNumber; }

bool CardPayment::processPayment() {
    if (cardNumber.empty()) {
        status = PaymentStatus::Failed;
        return false;
    }
    status = PaymentStatus::Success;
    return true;
}

string CardPayment::toString() const {
    stringstream ss;
    ss << "CardPayment{" << Payment::toString() << ", card=****}"; // Скрываем номер
    return ss.str();
}
ostream& operator<<(ostream& os, const CardPayment& cp) { os << cp.toString(); return os; }