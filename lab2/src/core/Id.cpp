#include "Id.h"
#include <sstream>

using namespace std;

int Id::nextId = 1;

Id::Id() : value(nextId++) {
}

Id::Id(int value) : value(value) {
}

Id::Id(const Id& other) : value(other.value) {
}

Id& Id::operator=(const Id& other) {
    if (this == &other) {
        return *this;
    }
    value = other.value;
    return *this;
}

Id::~Id() {
}

int Id::getValue() const {
    return value;
}

void Id::setValue(int value) {
    this->value = value;
}

string Id::toString() const {
    stringstream ss;
    ss << "ID-" << value;
    return ss.str();
}

bool Id::operator==(const Id& other) const {
    return value == other.value;
}

bool Id::operator!=(const Id& other) const {
    return !(*this == other);
}

bool Id::operator<(const Id& other) const {
    return value < other.value;
}

bool Id::operator>(const Id& other) const {
    return other < *this;
}

ostream& operator<<(ostream& os, const Id& id) {
    os << id.toString();
    return os;
}

istream& operator>>(istream& is, Id& id) {
    is >> id.value;
    return is;
}