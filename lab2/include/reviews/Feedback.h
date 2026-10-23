#pragma once
#include "Comment.h"
#include "Date.h"
#include <string>
#include <iostream>

/** @brief General guest feedback. */
class Feedback {
private:
    Comment comment;
    Date feedbackDate;
    std::string channel; // "Email", "Website", "In-person"

public:
    Feedback();
    Feedback(const Comment& comment, const Date& feedbackDate, const std::string& channel);
    Feedback(const Feedback& other);
    Feedback& operator=(const Feedback& other);
    ~Feedback();

    Comment getComment() const;
    Date getFeedbackDate() const;
    std::string getChannel() const;

    std::string toString() const;
    friend std::ostream& operator<<(std::ostream& os, const Feedback& f);
};