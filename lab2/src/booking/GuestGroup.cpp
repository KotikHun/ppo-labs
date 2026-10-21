#include "GuestGroup.h"
#include <sstream>
#include <algorithm> // для std::find
using namespace std;

GuestGroup::GuestGroup() : groupName("") {}
GuestGroup::GuestGroup(const string& groupName) : groupName(groupName) {}
GuestGroup::GuestGroup(const GuestGroup& other) : id(other.id), guestIds(other.guestIds), groupName(other.groupName) {}

GuestGroup& GuestGroup::operator=(const GuestGroup& other) {
    if (this == &other) return *this;
    id = other.id;
    guestIds = other.guestIds;
    groupName = other.groupName;
    return *this;
}
GuestGroup::~GuestGroup() {}

Id GuestGroup::getId() const { return id; }
string GuestGroup::getGroupName() const { return groupName; }
vector<Id> GuestGroup::getGuestIds() const { return guestIds; }

void GuestGroup::setGroupName(const string& groupName) { this->groupName = groupName; }

void GuestGroup::addGuest(const Id& guestId) {
    guestIds.push_back(guestId);
}

void GuestGroup::removeGuest(const Id& guestId) {
    auto it = find(guestIds.begin(), guestIds.end(), guestId);
    if (it != guestIds.end()) {
        guestIds.erase(it);
    }
}

string GuestGroup::toString() const {
    stringstream ss;
    ss << "GuestGroup{" << groupName << ", guests=" << guestIds.size() << "}";
    return ss.str();
}

bool GuestGroup::operator==(const GuestGroup& other) const {
    return id == other.id;
}
bool GuestGroup::operator!=(const GuestGroup& other) const { return !(*this == other); }

ostream& operator<<(ostream& os, const GuestGroup& gg) { os << gg.toString(); return os; }