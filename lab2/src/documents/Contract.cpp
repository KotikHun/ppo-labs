#include "Contract.h"
#include <sstream>
using namespace std;

Contract::Contract() : Document() {}
Contract::Contract(const string& documentNumber, const Date& issueDate, const Date& expiryDate, const Id& guestId)
    : Document(documentNumber, issueDate, expiryDate), guestId(guestId) {}
Contract::Contract(const Contract& other) : Document(other), guestId(other.guestId) {}
Contract& Contract::operator=(const Contract& other) {
    if (this == &other) return *this;
    Document::operator=(other);
    guestId = other.guestId;
    return *this;
}
Contract::~Contract() {}

Id Contract::getGuestId() const { return guestId; }
void Contract::setGuestId(const Id& guestId) { this->guestId = guestId; }

bool Contract::isValid(const Date& currentDate) const {
    return currentDate < expiryDate || currentDate == expiryDate;
}

string Contract::toString() const {
    stringstream ss;
    ss << "Contract{" << Document::toString() << ", guest=" << guestId.toString() << "}";
    return ss.str();
}
ostream& operator<<(ostream& os, const Contract& c) { os << c.toString(); return os; }