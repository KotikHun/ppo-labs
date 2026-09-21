#pragma once

#include "Color.h"
#include <iostream>

/**
 * @brief Одна грань кубика Рубика (3x3 клеток).
 *
 * Хранит цвета девяти клеток. Умеет поворачиваться на 90°
 * по часовой и против часовой стрелки.
 */

class Face {

private:
    Color cells[3][3];

public:
    Face();
    Face(Color color);
    Face(const Face& other);
    Face& operator=(const Face& other);
    ~Face();

    Color getCell(int row, int col) const;
    void setCell(int row, int col, Color color);

    void rotateClockwise();
    void rotateCounterClockwise();

    bool operator==(const Face& other) const;
    bool operator!=(const Face& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Face& f);
    friend std::istream& operator>>(std::istream& is, Face& f);

};






















