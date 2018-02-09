#include "position.h"

Position::Position(int a, int b, int c) : x(a), y(b), z(c) {

}

Position::Position(Position* p) {
    x = p->getX();
    y = p->getY();
    z = p->getZ();
}

int Position::getX() {
    return x;
}

int Position::getY() {
    return y;
}

int Position::getZ() {
    return z;
}

int Position::get(int i) {
    return ((i == 0) ? x : (i == 1) ? y : z);
}

void Position::setX(int a) {
    x = a;
}

void Position::setY(int b) {
    y = b;
}

void Position::setZ(int c) {
    z = c;
}

bool Position::equals(Position* p) {
    return x == p->getX() && y == p->getY() && z == p->getZ();
}
