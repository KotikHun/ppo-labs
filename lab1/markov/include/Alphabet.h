#pragma once

#include <set>
#include <iostream>

/**
 * @brief Алфавит нормального алгорифма Маркова.
 *
 * Хранит множество символов, с которыми работает алгоритм.
 * Символы не повторяются (это множество).
 */

class Alphabet {
private:
    std::set<char> symbols;
public:
    Alphabet();
    Alphabet(const Alphabet& other);
    Alphabet& operator=(const Alphabet& other);
    ~Alphabet();

    void add(char c);
    bool contains(char c) const;
    std::set<char> getAll() const;
    size_t size() const;

    bool operator==(const Alphabet& other) const;
    bool operator!=(const Alphabet& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Alphabet& a);
    friend std::istream& operator>>(std::istream& is, Alphabet& a);
};
















