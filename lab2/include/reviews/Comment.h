#pragma once
#include <string>
#include <iostream>

/**
 * @brief Represents a text comment.
 */
class Comment {
private:
    std::string text;
    std::string author;

public:
    Comment();
    Comment(const std::string& text, const std::string& author);
    Comment(const Comment& other);
    Comment& operator=(const Comment& other);
    ~Comment();

    std::string getText() const;
    std::string getAuthor() const;

    void setText(const std::string& text);
    void setAuthor(const std::string& author);

    std::string toString() const;
    bool operator==(const Comment& other) const;
    bool operator!=(const Comment& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Comment& c);
};