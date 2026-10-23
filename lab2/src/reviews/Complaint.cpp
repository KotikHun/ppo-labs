#include "Complaint.h"
#include <sstream>
using namespace std;

Complaint::Complaint() : description(), priority(1), isResolved(false) {}
Complaint::Complaint(const Id& guestId, const Comment& description, int priority)
    : guestId(guestId), description(description), priority(priority), isResolved(false) {}
Complaint::Complaint(const Complaint& other)
    : id(other.id), guestId(other.guestId), description(other.description),
      priority(other.priority), isResolved(other.isResolved) {}

Complaint& Complaint::operator=(const Complaint& other) {
    if (this == &other) return *this;
    id = other.id;
    guestId = other.guestId;
    description = other.description;
    priority = other.priority;
    isResolved = other.isResolved;
    return *this;
}
Complaint::~Complaint() {}

Id Complaint::getId() const { return id; }
Id Complaint::getGuestId() const { return guestId; }
Comment Complaint::getDescription() const { return description; }
int Complaint::getPriority() const { return priority; }
bool Complaint::getIsResolved() const { return isResolved; }

void Complaint::resolve() { isResolved = true; }

string Complaint::toString() const {
    stringstream ss;
    ss << "Complaint{guest=" << guestId.toString() << ", priority=" << priority
       << ", resolved=" << (isResolved ? "yes" : "no") << "}";
    return ss.str();
}
ostream& operator<<(ostream& os, const Complaint& c) { os << c.toString(); return os; }