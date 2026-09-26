#include "Cube.h"
#include <cstdlib>
#include <ctime>

using namespace std;

Cube::Cube() {
    faces[0] = Face(Color::White);    // U - верхняя
    faces[1] = Face(Color::Yellow);   // D - нижняя
    faces[2] = Face(Color::Orange);   // L - левая
    faces[3] = Face(Color::Red);      // R - правая
    faces[4] = Face(Color::Green);    // F - передняя
    faces[5] = Face(Color::Blue);     // B - задняя
}

Cube::Cube(const Cube& other) {
    for (int i = 0; i < 6; ++i) {
        faces[i] = other.faces[i];
    }
}

Cube& Cube::operator=(const Cube& other) {
    if (this == &other) {
        return *this;
    }
    for (int i = 0; i < 6; ++i) {
        faces[i] = other.faces[i];
    }
    return *this;
}

Cube::~Cube() {
}

Face Cube::getFace(int index) const {
    return faces[index];
}

void Cube::setFace(int index, const Face& face) {
    faces[index] = face;
}

bool Cube::isSolved() const {
    for (int f = 0; f < 6; ++f) {
        Color first = faces[f].getCell(0, 0);
        for (int r = 0; r < 3; ++r) {
            for (int c = 0; c < 3; ++c) {
                if (faces[f].getCell(r, c) != first) {
                    return false;
                }
            }
        }
    }
    return true;
}

void Cube::randomize() {
    faces[0] = Face(Color::White);
    faces[1] = Face(Color::Yellow);
    faces[2] = Face(Color::Orange);
    faces[3] = Face(Color::Red);
    faces[4] = Face(Color::Green);
    faces[5] = Face(Color::Blue);

    srand(static_cast<unsigned>(time(nullptr)));
    for (int i = 0; i < 25; ++i) {
        int faceIndex = rand() % 6;
        bool clockwise = (rand() % 2 == 0);
        rotateFace(faceIndex, clockwise);
    }
}

void Cube::rotateFace(int faceIndex, bool clockwise) {
    if (faceIndex == 0) {
        // U - верхняя
        if (clockwise) {
            faces[0].rotateClockwise();
            Color temp[3];
            for (int c = 0; c < 3; ++c) temp[c] = faces[4].getCell(0, c);
            for (int c = 0; c < 3; ++c) faces[4].setCell(0, c, faces[3].getCell(0, c));
            for (int c = 0; c < 3; ++c) faces[3].setCell(0, c, faces[5].getCell(0, c));
            for (int c = 0; c < 3; ++c) faces[5].setCell(0, c, faces[2].getCell(0, c));
            for (int c = 0; c < 3; ++c) faces[2].setCell(0, c, temp[c]);
        } else {
            faces[0].rotateCounterClockwise();
            Color temp[3];
            for (int c = 0; c < 3; ++c) temp[c] = faces[4].getCell(0, c);
            for (int c = 0; c < 3; ++c) faces[4].setCell(0, c, faces[2].getCell(0, c));
            for (int c = 0; c < 3; ++c) faces[2].setCell(0, c, faces[5].getCell(0, c));
            for (int c = 0; c < 3; ++c) faces[5].setCell(0, c, faces[3].getCell(0, c));
            for (int c = 0; c < 3; ++c) faces[3].setCell(0, c, temp[c]);
        }
    } else if (faceIndex == 1) {
        // D - нижняя
        if (clockwise) {
            faces[1].rotateClockwise();
            Color temp[3];
            for (int c = 0; c < 3; ++c) temp[c] = faces[4].getCell(2, c);
            for (int c = 0; c < 3; ++c) faces[4].setCell(2, c, faces[2].getCell(2, c));
            for (int c = 0; c < 3; ++c) faces[2].setCell(2, c, faces[5].getCell(2, c));
            for (int c = 0; c < 3; ++c) faces[5].setCell(2, c, faces[3].getCell(2, c));
            for (int c = 0; c < 3; ++c) faces[3].setCell(2, c, temp[c]);
        } else {
            faces[1].rotateCounterClockwise();
            Color temp[3];
            for (int c = 0; c < 3; ++c) temp[c] = faces[4].getCell(2, c);
            for (int c = 0; c < 3; ++c) faces[4].setCell(2, c, faces[3].getCell(2, c));
            for (int c = 0; c < 3; ++c) faces[3].setCell(2, c, faces[5].getCell(2, c));
            for (int c = 0; c < 3; ++c) faces[5].setCell(2, c, faces[2].getCell(2, c));
            for (int c = 0; c < 3; ++c) faces[2].setCell(2, c, temp[c]);
        }
    }

    else if (faceIndex == 2) {
    // L - левая грань
    if (clockwise) {
        faces[2].rotateClockwise();
        Color temp[3];
        for (int r = 0; r < 3; ++r) temp[r] = faces[0].getCell(r, 0);
        for (int r = 0; r < 3; ++r) faces[0].setCell(r, 0, faces[5].getCell(2 - r, 2));
        for (int r = 0; r < 3; ++r) faces[5].setCell(2 - r, 2, faces[1].getCell(r, 0));
        for (int r = 0; r < 3; ++r) faces[1].setCell(r, 0, faces[4].getCell(r, 0));
        for (int r = 0; r < 3; ++r) faces[4].setCell(r, 0, temp[r]);
    } else {
        faces[2].rotateCounterClockwise();
        Color temp[3];
        for (int r = 0; r < 3; ++r) temp[r] = faces[0].getCell(r, 0);
        for (int r = 0; r < 3; ++r) faces[0].setCell(r, 0, faces[4].getCell(r, 0));
        for (int r = 0; r < 3; ++r) faces[4].setCell(r, 0, faces[1].getCell(r, 0));
        for (int r = 0; r < 3; ++r) faces[1].setCell(r, 0, faces[5].getCell(2 - r, 2));
        for (int r = 0; r < 3; ++r) faces[5].setCell(2 - r, 2, temp[r]);
    }
}

    else if (faceIndex == 3) {
    // R - правая грань
        if (clockwise) {
        faces[3].rotateClockwise();
        Color temp[3];
        for (int r = 0; r < 3; ++r) temp[r] = faces[0].getCell(r, 2);
        for (int r = 0; r < 3; ++r) faces[0].setCell(r, 2, faces[4].getCell(r, 2));
        for (int r = 0; r < 3; ++r) faces[4].setCell(r, 2, faces[1].getCell(r, 2));
        for (int r = 0; r < 3; ++r) faces[1].setCell(r, 2, faces[5].getCell(2 - r, 0));
        for (int r = 0; r < 3; ++r) faces[5].setCell(2 - r, 0, temp[r]);
        } else {
        faces[3].rotateCounterClockwise();
        Color temp[3];
        for (int r = 0; r < 3; ++r) temp[r] = faces[0].getCell(r, 2);
        for (int r = 0; r < 3; ++r) faces[0].setCell(r, 2, faces[5].getCell(2 - r, 0));
        for (int r = 0; r < 3; ++r) faces[5].setCell(2 - r, 0, faces[1].getCell(r, 2));
        for (int r = 0; r < 3; ++r) faces[1].setCell(r, 2, faces[4].getCell(r, 2));
        for (int r = 0; r < 3; ++r) faces[4].setCell(r, 2, temp[r]);
        }
    }
    else if (faceIndex == 5) {
        // B - задняя грань
        if (clockwise) {
            faces[5].rotateClockwise();
            Color temp[3];
            for (int c = 0; c < 3; ++c) temp[c] = faces[0].getCell(0, c);
            for (int c = 0; c < 3; ++c) faces[0].setCell(0, c, faces[3].getCell(2 - c, 2));
            for (int c = 0; c < 3; ++c) faces[3].setCell(2 - c, 2, faces[1].getCell(2, c));
            for (int c = 0; c < 3; ++c) faces[1].setCell(2, c, faces[2].getCell(c, 0));
            for (int c = 0; c < 3; ++c) faces[2].setCell(c, 0, temp[c]);
        } else {
            faces[5].rotateCounterClockwise();
            Color temp[3];
            for (int c = 0; c < 3; ++c) temp[c] = faces[0].getCell(0, c);
            for (int c = 0; c < 3; ++c) faces[0].setCell(0, c, faces[2].getCell(c, 0));
            for (int c = 0; c < 3; ++c) faces[2].setCell(c, 0, faces[1].getCell(2, c));
            for (int c = 0; c < 3; ++c) faces[1].setCell(2, c, faces[3].getCell(2 - c, 2));
            for (int c = 0; c < 3; ++c) faces[3].setCell(2 - c, 2, temp[c]);
        }
    }
}

void Cube::loadFromStream(istream& is) {
    for (int f = 0; f < 6; ++f) {
        is >> faces[f];
    }
}

void Cube::saveToStream(ostream& os) const {
    for (int f = 0; f < 6; ++f) {
        os << faces[f];
    }
}

bool Cube::operator==(const Cube& other) const {
    for (int f = 0; f < 6; ++f) {
        if (faces[f] != other.faces[f]) {
            return false;
        }
    }
    return true;
}

bool Cube::operator!=(const Cube& other) const {
    return !(*this == other);
}

ostream& operator<<(ostream& os, const Cube& c) {
    for (int f = 0; f < 6; ++f) {
        os << c.faces[f] << endl;
    }
    return os;
}

istream& operator>>(istream& is, Cube& c) {
    for (int f = 0; f < 6; ++f) {
        is >> c.faces[f];
    }
    return is;
}