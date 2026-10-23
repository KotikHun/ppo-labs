#include "Rating.h"
#include <sstream>

using namespace std;

Rating::Rating() : score(5) {}
Rating::Rating(int score) : score(score) {}
Rating::Rating(const Rating& other) : score(other.score) {}

Rating& Rating::operator=(const Rating& other) {
    if (this == &other) return *this;
    score = other.score;
    return *this;
}
Rating::~Rating() {}

int Rating::getScore() const { return score; }

void Rating::setScore(int score) {
    // Простая валидация: оценка от 1 до 5
    if (score >= 1 && score <= 5) {
        this->score = score;
    }
}

string Rating::toString() const {
    stringstream ss;
    ss << score << "/5";
    return ss.str();
}

bool Rating::operator==(const Rating& other) const { return score == other.score; }
bool Rating::operator!=(const Rating& other) const { return !(*this == other); }

ostream& operator<<(ostream& os, const Rating& r) { os << r.toString(); return os; }