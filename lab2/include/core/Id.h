#pragma once

#include <string>
#include <iostream>

/**
 * @brief Unique identifier.
 *
 * Generates a new unique id automatically on default construction.
 * The id value can also be set explicitly (e.g. when loading from JSON).
 */
class Id {
private:
    int value;

    static int nextId;

public:
    Id();
    explicit Id(int value);
    Id(const Id& other);
    Id& operator=(const Id& other);
    ~Id();

    int getValue() const;
    void setValue(int value);

    std::string toString() const;

    bool operator==(const Id& other) const;
    bool operator!=(const Id& other) const;
    bool operator<(const Id& other) const;
    bool operator>(const Id& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Id& id);
    friend std::istream& operator>>(std::istream& is, Id& id);
};