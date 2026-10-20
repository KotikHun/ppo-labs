#pragma once

#include <string>
#include <iostream>

/**
 * @brief Represents a floor in a building.
 */
class Floor {
private:
    int number;
    int roomsCount;
    std::string description;

public:
    Floor();
    Floor(int number, int roomsCount, const std::string& description);
    Floor(const Floor& other);
    Floor& operator=(const Floor& other);
    ~Floor();

    int getNumber() const;
    int getRoomsCount() const;
    std::string getDescription() const;

    void setNumber(int number);
    void setRoomsCount(int roomsCount);
    void setDescription(const std::string& description);

    std::string toString() const;

    bool operator==(const Floor& other) const;
    bool operator!=(const Floor& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Floor& f);
    friend std::istream& operator>>(std::istream& is, Floor& f);
};