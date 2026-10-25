#include "Receipt.h"
#include <sstream>
using namespace std;

Receipt::Receipt() : Document(), totalAmount() {}
Receipt::Receipt(const string& documentNumber, const Date& issueDate, const Date& expiryDate, const Money& totalAmount)
    : Document(documentNumber, issueDate, expiryDate), totalAmount(totalAmount) {}
Receipt::Receipt(const Receipt& other) : Document(other), totalAmount(other.totalAmount) {}
Receipt& Receipt::operator=(const Receipt& other) {
    if (this == &other) return *this;
    Document::operator=(other);
    totalAmount = other.totalAmount;
    return *this;
}
Receipt::~Receipt() {}

Money Receipt::getTotalAmount() const { return totalAmount; }
void Receipt::setTotalAmount(const Money& totalAmount) { this->totalAmount = totalAmount; }

bool Receipt::isValid(const Date& currentDate) const {
    return currentDate < expiryDate || currentDate == expiryDate;
}

string Receipt::toString() const {
    stringstream ss;
    ss << "Receipt{" << Document::toString() << ", amount=" << totalAmount.toString() << "}";
    return ss.str();
}
ostream& operator<<(ostream& os, const Receipt& r) { os << r.toString(); return os; }