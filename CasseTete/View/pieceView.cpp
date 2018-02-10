#include "pieceView.h"

PieceView::PieceView() {
    display = true;
    is_used = true;
    position = new Position(0, 0, 0);
    rotation = new Position(0, 0, 0);
}

void PieceView::setPosition(int x, int y, int z) {
    position->setX(x);
    position->setY(y);
    position->setZ(z);
}

void PieceView::setRotation(int x, int y, int z) {
    rotation->setX(x);
    rotation->setY(y);
    rotation->setZ(z);
}

void PieceView::reverseDisplay() {
    display = !display;
}

void PieceView::setIsUsed(bool b) {
    is_used = b;
}
