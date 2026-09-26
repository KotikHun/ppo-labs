#pragma once

#include <string>
#include <vector>
#include <iostream>
#include "Alphabet.h"
#include "Rule.h"

/**
 * @brief Нормальный алгорифм Маркова.
 *
 * Объединяет алфавит, набор правил подстановки и ленту.
 * Умеет выполнять шаги алгоритма и запускать его до конца.
 */

class MarkovAlgorithm {
private:
    Alphabet alphabet;
    std::vector<Rule> rules;
    std::string tape;

public:
    MarkovAlgorithm();
    MarkovAlgorithm(const MarkovAlgorithm& other);
    MarkovAlgorithm& operator=(const MarkovAlgorithm& other);
    ~MarkovAlgorithm();

    void setAlphabet(const Alphabet& newAlphabet);
    Alphabet getAlphabet() const;

    void addRule(const Rule& newRule);
    void removeRule(size_t index);
    std::vector<Rule> getRules() const;
    size_t ruleCount() const;

    void setTape(const std::string& newTape);
    std::string getTape() const;

    bool step();
    void run();

    void loadFromStream(std::istream& is);
    void saveToStream(std::ostream& os) const;

    bool operator==(const MarkovAlgorithm& other) const;
    bool operator!=(const MarkovAlgorithm& other) const;

    friend std::ostream& operator<<(std::ostream& os, const MarkovAlgorithm& m);
    friend std::istream& operator>>(std::istream& is, MarkovAlgorithm& m);
};