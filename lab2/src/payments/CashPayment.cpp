#include "CashPayment.h"
#include <sstream>
using namespace std;

CashPayment::CashPayment() : Payment(), changeGiven() {}
CashPayment::CashPayment(const Money& amount, const Date& paymentDate, const Money& changeGiven)
    : Payment(amount, paymentDate), changeGiven(changeGiven) {}
CashPayment::CashPayment(const CashPayment& other) : Payment(other), changeGiven(other.changeGiven) {}
CashPayment& CashPayment::operator=(const CashPayment& other) {
    if (this == &other) return *this;
    Payment::operator=(other);
    changeGiven = other.changeGiven;
    return *this;
}
CashPayment::~CashPayment() {}

Money CashPayment::getChangeGiven() const { return changeGiven; }
void CashPayment::setChangeGiven(const Money& changeGiven) { this->changeGiven = changeGiven; }

bool CashPayment::processPayment() {
    status = PaymentStatus::Success;
    return true;
}

string CashPayment::toString() const {
    stringstream ss;
    ss << "CashPayment{" << Payment::toString() << ", change=" << changeGiven.toString() << "}";
    return ss.str();
}
ostream& operator<<(ostream& os, const CashPayment& cp) { os << cp.toString(); return os; }