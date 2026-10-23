#include "Visa.h"
#include <sstream>
using namespace std;

Visa::Visa() : Document(), visaType("") {}
Visa::Visa(const string& documentNumber, const Date& issueDate, const Date& expiryDate, const string& visaType)
    : Document(documentNumber, issueDate, expiryDate), visaType(visaType) {}
Visa::Visa(const Visa& other) : Document(other), visaType(other.visaType) {}
Visa& Visa::operator=(const Visa& other) {
    if (this == &other) return *this;
    Document::operator=(other);
    visaType = other.visaType;
    return *this;
}
Visa::~Visa() {}

string Visa::getVisaType() const { return visaType; }
void Visa::setVisaType(const string& visaType) { this->visaType = visaType; }

bool Visa::isValid(const Date& currentDate) const {
    return currentDate < expiryDate || currentDate == expiryDate;
}

string Visa::toString() const {
    stringstream ss;
    ss << "Visa{" << Document::toString() << ", type=" << visaType << "}";
    return ss.str();
}
ostream& operator<<(ostream& os, const Visa& v) { os << v.toString(); return os; }