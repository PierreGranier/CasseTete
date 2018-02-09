#include "problem.h"

Problem::Problem(Position* p, int* m) : size(p), matrix(m){
}

Position* Problem::getSize() {
    return size;
}

int* Problem::getMatrix() {
    return matrix;
}
