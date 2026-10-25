#include "Payment.h"
#include <sstream>

using namespace std;

Payment::Payment()
    : amount(), paymentDate(), status(PaymentStatus::Pending), transactionCode("TXN-000") {}

Payment::Payment(const Money& amount, const Date& paymentDate)
    : amount(amount), paymentDate(paymentDate), status(PaymentStatus::Pending), transactionCode("TXN-000") {}

Payment::Payment(const Payment& other)
    : id(other.id), amount(other.amount), paymentDate(other.paymentDate),
      status(other.status), transactionCode(other.transactionCode) {}

Payment& Payment::operator=(const Payment& other) {
    if (this == &other) return *this;
    id = other.id;
    amount = other.amount;
    paymentDate = other.paymentDate;
    status = other.status;
    transactionCode = other.transactionCode;
    return *this;
}

Payment::~Payment() {}

Id Payment::getId() const { return id; }
Money Payment::getAmount() const { return amount; }
Date Payment::getPaymentDate() const { return paymentDate; }
PaymentStatus Payment::getStatus() const { return status; }
string Payment::getTransactionCode() const { return transactionCode; }

void Payment::setStatus(PaymentStatus status) { this->status = status; }
void Payment::setTransactionCode(const string& code) { this->transactionCode = code; }

string Payment::toString() const {
    stringstream ss;
    ss << "Payment{id=" << id.toString() << ", amount=" << amount.toString()
       << ", date=" << paymentDate.toString() << "}";
    return ss.str();
}

bool Payment::operator==(const Payment& other) const { return id == other.id; }
bool Payment::operator!=(const Payment& other) const { return !(*this == other); }

ostream& operator<<(ostream& os, const Payment& p) {
    os << p.toString();
    return os;
}
