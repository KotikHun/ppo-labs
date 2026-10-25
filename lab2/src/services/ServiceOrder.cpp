#include "ServiceOrder.h"
#include <sstream>

using namespace std;

ServiceOrder::ServiceOrder()
    : quantity(1), status(ServiceStatus::Ordered), totalCost() {
}

ServiceOrder::ServiceOrder(const Id& guestId, const Id& serviceId, int quantity, const Money& totalCost)
    : guestId(guestId), serviceId(serviceId), quantity(quantity),
      status(ServiceStatus::Ordered), totalCost(totalCost) {
}

ServiceOrder::ServiceOrder(const ServiceOrder& other)
    : id(other.id), guestId(other.guestId), serviceId(other.serviceId),
      quantity(other.quantity), status(other.status), totalCost(other.totalCost) {
}

ServiceOrder& ServiceOrder::operator=(const ServiceOrder& other) {
    if (this == &other) {
        return *this;
    }
    id = other.id;
    guestId = other.guestId;
    serviceId = other.serviceId;
    quantity = other.quantity;
    status = other.status;
    totalCost = other.totalCost;
    return *this;
}

ServiceOrder::~ServiceOrder() {
}

Id ServiceOrder::getId() const { return id; }
Id ServiceOrder::getGuestId() const { return guestId; }
Id ServiceOrder::getServiceId() const { return serviceId; }
int ServiceOrder::getQuantity() const { return quantity; }
ServiceStatus ServiceOrder::getStatus() const { return status; }
Money ServiceOrder::getTotalCost() const { return totalCost; }

void ServiceOrder::setStatus(ServiceStatus status) { this->status = status; }

string ServiceOrder::toString() const {
    stringstream ss;
    ss << "ServiceOrder{id=" << id.toString()
       << ", guest=" << guestId.toString()
       << ", service=" << serviceId.toString()
       << ", qty=" << quantity
       << ", cost=" << totalCost.toString() << "}";
    return ss.str();
}

bool ServiceOrder::operator==(const ServiceOrder& other) const {
    return id == other.id;
}

bool ServiceOrder::operator!=(const ServiceOrder& other) const {
    return !(*this == other);
}

ostream& operator<<(ostream& os, const ServiceOrder& so) {
    os << so.toString();
    return os;
}