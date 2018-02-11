#include "problem.h"

Problem::Problem(Position* p, int* m) : size(p), matrix(m) {
    int q = 0;
    for (int i = 0; i < p->getX() * p->getY() * p->getZ(); ++i) {
        if (matrix[i] == 1) {
            ++q;
        }
    }
    nb_of_pieces = q / 5;
}

Position* Problem::getSize() {
    return size;
}

int* Problem::getMatrix() {
    return matrix;
}

int Problem::getNbOfPieces() {
    return nb_of_pieces;
}
