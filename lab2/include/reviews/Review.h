#pragma once
#include "Id.h"
#include "Rating.h"
#include "Comment.h"
#include "Date.h"
#include <iostream>

/** @brief Guest review containing rating and comment. */
class Review {
private:
    Id id;
    Id guestId;
    Rating rating;
    Comment comment;
    Date reviewDate;

public:
    Review();
    Review(const Id& guestId, const Rating& rating, const Comment& comment, const Date& reviewDate);
    Review(const Review& other);
    Review& operator=(const Review& other);
    ~Review();

    Id getId() const;
    Id getGuestId() const;
    Rating getRating() const;
    Comment getComment() const;
    Date getReviewDate() const;

    std::string toString() const;
    friend std::ostream& operator<<(std::ostream& os, const Review& r);
};