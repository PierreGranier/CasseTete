#include "pieceView.h"

PieceView::PieceView() {
    display = true;
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

int* PieceView::multiplyMatrix(int *m1, int *m2) {
    int* m3 = new int[9];

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            m3[i * 3 + j] = 0;
            for (int k = 0; k < 3; ++k) {
                m3[i * 3 + j] += m1[i * 3 + k] * m2[k * 3 + j];
            }
        }
    }

    return m3;
}
