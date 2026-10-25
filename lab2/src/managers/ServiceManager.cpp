#include "ServiceManager.h"

using namespace std;

ServiceManager::ServiceManager() {}
ServiceManager::~ServiceManager() {}

void ServiceManager::addOrder(const ServiceOrder& order) {
    orders.push_back(order);
}

ServiceOrder* ServiceManager::findOrderById(const Id& id) {
    for (size_t i = 0; i < orders.size(); ++i) {
        if (orders[i].getId() == id) {
            return &orders[i];
        }
    }
    throw ServiceNotAvailableException("Service order not found.");
}

void ServiceManager::completeOrder(const Id& id) {
    ServiceOrder* order = findOrderById(id);
    order->setStatus(ServiceStatus::Completed);
}

void ServiceManager::printAllOrders() const {
    cout << "--- All Service Orders ---" << endl;
    for (size_t i = 0; i < orders.size(); ++i) {
        cout << orders[i].toString() << endl;
    }
}

size_t ServiceManager::getOrderCount() const {
    return orders.size();
}