#include "Invoice.h"
#include <sstream>
using namespace std;

Invoice::Invoice() : amount(), issueDate(), isPaid(false) {}
Invoice::Invoice(const Id& reservationId, const Money& amount, const Date& issueDate)
    : reservationId(reservationId), amount(amount), issueDate(issueDate), isPaid(false) {}
Invoice::Invoice(const Invoice& other)
    : id(other.id), reservationId(other.reservationId), amount(other.amount), issueDate(other.issueDate), isPaid(other.isPaid) {}

Invoice& Invoice::operator=(const Invoice& other) {
    if (this == &other) return *this;
    id = other.id;
    reservationId = other.reservationId;
    amount = other.amount;
    issueDate = other.issueDate;
    isPaid = other.isPaid;
    return *this;
}
Invoice::~Invoice() {}

Id Invoice::getId() const { return id; }
Id Invoice::getReservationId() const { return reservationId; }
Money Invoice::getAmount() const { return amount; }
Date Invoice::getIssueDate() const { return issueDate; }
bool Invoice::getIsPaid() const { return isPaid; }

void Invoice::markAsPaid() { isPaid = true; }

string Invoice::toString() const {
    stringstream ss;
    ss << "Invoice{id=" << id.toString() << ", res=" << reservationId.toString()
       << ", amount=" << amount.toString() << ", paid=" << (isPaid ? "yes" : "no") << "}";
    return ss.str();
}
ostream& operator<<(ostream& os, const Invoice& i) { os << i.toString(); return os; }