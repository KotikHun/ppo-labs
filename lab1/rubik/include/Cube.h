#pragma once

#include "Face.h"
#include "Color.h"
#include <iostream>

/**
 * @brief Кубик Рубика 3x3x3.
 *
 * Хранит 6 граней. Умеет поворачивать грани, проверять собранность,
 * загружать из потока и сохранять в поток.
 */

class Cube
{
private:
    Face faces[6];   // U, D, L, R, F, B — по индексам 0..5};

public:
    Cube();
    Cube(const Cube& other);
    Cube& operator=(const Cube& other);
    ~Cube();

    Face getFace(int index) const;
    void setFace(int index, const Face& face);

    void rotateFace(int faceIndex, bool clockwise);

    bool isSolved() const;
    void randomize();

    void loadFromStream(std::istream& is);
    void saveToStream(std::ostream& os) const;

    bool operator==(const Cube& other) const;
    bool operator!=(const Cube& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Cube& c);
    friend std::istream& operator>>(std::istream& is, Cube& c);
};