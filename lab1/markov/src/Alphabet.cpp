#include "Alphabet.h"
using namespace std;

Alphabet::Alphabet() {
}

Alphabet::Alphabet(const Alphabet& other) : symbols(other.symbols) {
}

Alphabet::~Alphabet() {
}

Alphabet& Alphabet::operator=(const Alphabet& other){
    if (his == &other){
        return *this;
    }
    symbols = other.symbols;
    return *this;
}

void Alphabet::add(char c){
    symbols.insert(c);
}

bool Alphabet::contains(char c) const{
    return symbols.count(c) > 0;
}

set<char> Alphabet::getAll() const {
    return symbols;
}

size_t Alphabet::size() const {
    return symbols.size();
}

bool Alphabet::operator==(const Alphabet& other) const {
    return symbols == other.symbols;
}

bool Alphabet::operator!=(const Alphabet& other) const {
    return !(*this == other);
}

ostream& operator<<(ostream& os, const Alphabet& a) {
    for (char c : a.symbols) {
        os << c;
    }
    return os;
}

istream& operator>>(istream& is, Alphabet& a) {
    string input;
    is >> input;
    for (char c : input) {
        a.add(c);
    }
    return is;
}











