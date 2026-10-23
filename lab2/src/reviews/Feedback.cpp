#include "Feedback.h"
#include <sstream>
using namespace std;

Feedback::Feedback() : comment(), feedbackDate(), channel("") {}
Feedback::Feedback(const Comment& comment, const Date& feedbackDate, const string& channel)
    : comment(comment), feedbackDate(feedbackDate), channel(channel) {}
Feedback::Feedback(const Feedback& other)
    : comment(other.comment), feedbackDate(other.feedbackDate), channel(other.channel) {}

Feedback& Feedback::operator=(const Feedback& other) {
    if (this == &other) return *this;
    comment = other.comment;
    feedbackDate = other.feedbackDate;
    channel = other.channel;
    return *this;
}
Feedback::~Feedback() {}

Comment Feedback::getComment() const { return comment; }
Date Feedback::getFeedbackDate() const { return feedbackDate; }
string Feedback::getChannel() const { return channel; }

string Feedback::toString() const {
    stringstream ss;
    ss << "Feedback{" << channel << ", " << comment.toString() << "}";
    return ss.str();
}
ostream& operator<<(ostream& os, const Feedback& f) { os << f.toString(); return os; }