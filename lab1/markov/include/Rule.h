#pragma once

#include <string>
#include <iostream>

/**
 * @brief Правило подстановки нормального алгорифма Маркова.
 *
 * Хранит левую часть (что искать), правую часть (на что заменить)
 * и признак заключительного правила.
 */

class Rule {
private:
    std::string left;
    std::string right;
    bool isFinal;
public:
    Rule();
    Rule(const std::string& left, const std::string& right, bool isFinal);
    Rule(const Rule& other);
    Rule& operator=(const Rule& other);
    ~Rule();

    std::string getLeft() const;
    std::string getRight() const;
    bool getIsFinal() const;

    bool isApplicable(const std::string& tape) const;

    bool apply(std::string& tape) const;

    bool operator==(const Rule& other) const;
    bool operator!=(const Rule& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Rule& r);
    friend std::istream& operator>>(std::istream& is, Rule& r);

};