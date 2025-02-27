#include "position.h"

Position::Position() {
    x = 0;
    y = 0;
    z = 0;
}

bool Position::operator==(const Position& p1) {
    if (x == p1.x && y == p1.y && z == p1.z) {
        return true;
    }

    return false;
}

Position::Position(int _x, int _y, int _z)  {
    x = _x;
    y = _y;
    z = _z;
}