#include "Face.h"

using namespace std;

Face::Face() {
    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 3; ++c) {
            cells[r][c] = Color::White;
        }
    }
}

Face::Face(Color color) {
    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 3; ++c) {
            cells[r][c] = color;
        }
    }
}

Face::Face(const Face& other) {
    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 3; ++c) {
            cells[r][c] = other.cells[r][c];
        }
    }
}

Face::~Face() {
}

Face& Face::operator=(const Face& other) {
    if (this == &other) {
        return *this;
    }
    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 3; ++c) {
            cells[r][c] = other.cells[r][c];
        }
    }
    return *this;
}

Color Face::getCell(int row, int col) const {
    return cells[row][col];
}

void Face::setCell(int row, int col, Color color) {
    cells[row][col] = color;
}

void Face::rotateClockwise() {
    Color copy[3][3];
    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 3; ++c) {
            copy[r][c] = cells[r][c];
        }
    }
    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 3; ++c) {
            cells[r][c] = copy[2 - c][r];
        }
    }
}

void Face::rotateCounterClockwise() {
    Color copy[3][3];
    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 3; ++c) {
            copy[r][c] = cells[r][c];
        }
    }
    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 3; ++c) {
            cells[r][c] = copy[c][2 - r];
        }
    }
}

bool Face::operator==(const Face& other) const {
    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 3; ++c) {
            if (cells[r][c] != other.cells[r][c]) {
                return false;
            }
        }
    }
    return true;
}

bool Face::operator!=(const Face& other) const {
    return !(*this == other);
}

ostream& operator<<(ostream& os, const Face& f) {
    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 3; ++c) {
            os << static_cast<int>(f.cells[r][c]) << " ";
        }
        os << endl;
    }
    return os;
}

istream& operator>>(istream& is, Face& f) {
    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 3; ++c) {
            int value;
            is >> value;
            f.cells[r][c] = static_cast<Color>(value);
        }
    }
    return is;
}

