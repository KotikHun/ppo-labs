#include "Rating.h"
#include <sstream>

using namespace std;

namespace {
constexpr int DEFAULT_RATING = 5;
constexpr int MIN_RATING = 1;
constexpr int MAX_RATING = 5;
}

Rating::Rating() : score(DEFAULT_RATING) {}
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
    if (score >= MIN_RATING && score <= MAX_RATING) {
        this->score = score;
    }
}

string Rating::toString() const {
    stringstream ss;
    ss << score << "/" << MAX_RATING;
    return ss.str();
}

bool Rating::operator==(const Rating& other) const { return score == other.score; }
bool Rating::operator!=(const Rating& other) const { return !(*this == other); }

ostream& operator<<(ostream& os, const Rating& r) { os << r.toString(); return os; }
