#pragma once
#include <iostream>

/**
 * @brief Represents a rating score (1 to 5).
 */
class Rating {
private:
    int score;

public:
    Rating();
    Rating(int score);
    Rating(const Rating& other);
    Rating& operator=(const Rating& other);
    ~Rating();

    int getScore() const;
    void setScore(int score);

    std::string toString() const;
    bool operator==(const Rating& other) const;
    bool operator!=(const Rating& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Rating& r);
};