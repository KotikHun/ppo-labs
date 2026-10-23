#include "Review.h"
#include <sstream>
using namespace std;

Review::Review() : rating(), comment(), reviewDate() {}
Review::Review(const Id& guestId, const Rating& rating, const Comment& comment, const Date& reviewDate)
    : guestId(guestId), rating(rating), comment(comment), reviewDate(reviewDate) {}

Review::Review(const Review& other)
    : id(other.id), guestId(other.guestId), rating(other.rating), comment(other.comment), reviewDate(other.reviewDate) {}

Review& Review::operator=(const Review& other) {
    if (this == &other) return *this;
    id = other.id;
    guestId = other.guestId;
    rating = other.rating;
    comment = other.comment;
    reviewDate = other.reviewDate;
    return *this;
}
Review::~Review() {}

Id Review::getId() const { return id; }
Id Review::getGuestId() const { return guestId; }
Rating Review::getRating() const { return rating; }
Comment Review::getComment() const { return comment; }
Date Review::getReviewDate() const { return reviewDate; }

string Review::toString() const {
    stringstream ss;
    ss << "Review{guest=" << guestId.toString() << ", rating=" << rating.toString()
       << ", " << comment.toString() << "}";
    return ss.str();
}
ostream& operator<<(ostream& os, const Review& r) { os << r.toString(); return os; }