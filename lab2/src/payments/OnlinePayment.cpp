#include "OnlinePayment.h"
#include <sstream>
using namespace std;

OnlinePayment::OnlinePayment() : Payment(), email("") {}
OnlinePayment::OnlinePayment(const Money& amount, const Date& paymentDate, const string& email)
    : Payment(amount, paymentDate), email(email) {}
OnlinePayment::OnlinePayment(const OnlinePayment& other) : Payment(other), email(other.email) {}
OnlinePayment& OnlinePayment::operator=(const OnlinePayment& other) {
    if (this == &other) return *this;
    Payment::operator=(other);
    email = other.email;
    return *this;
}
OnlinePayment::~OnlinePayment() {}

string OnlinePayment::getEmail() const { return email; }
void OnlinePayment::setEmail(const string& email) { this->email = email; }

bool OnlinePayment::processPayment() {
    if (email.find('@') == string::npos) {
        status = PaymentStatus::Failed;
        return false;
    }
    status = PaymentStatus::Success;
    return true;
}

string OnlinePayment::toString() const {
    stringstream ss;
    ss << "OnlinePayment{" << Payment::toString() << ", email=" << email << "}";
    return ss.str();
}
ostream& operator<<(ostream& os, const OnlinePayment& op) { os << op.toString(); return os; }