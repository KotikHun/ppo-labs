#include "Comment.h"
#include <sstream>

using namespace std;

Comment::Comment() : text(""), author("") {}
Comment::Comment(const string& text, const string& author) : text(text), author(author) {}
Comment::Comment(const Comment& other) : text(other.text), author(other.author) {}

Comment& Comment::operator=(const Comment& other) {
    if (this == &other) return *this;
    text = other.text;
    author = other.author;
    return *this;
}
Comment::~Comment() {}

string Comment::getText() const { return text; }
string Comment::getAuthor() const { return author; }

void Comment::setText(const string& text) { this->text = text; }
void Comment::setAuthor(const string& author) { this->author = author; }

string Comment::toString() const {
    stringstream ss;
    ss << author << ": " << text;
    return ss.str();
}

bool Comment::operator==(const Comment& other) const {
    return text == other.text && author == other.author;
}
bool Comment::operator!=(const Comment& other) const { return !(*this == other); }

ostream& operator<<(ostream& os, const Comment& c) { os << c.toString(); return os; }