#ifndef PROBLEM_H
#define PROBLEM_H

#include <position.h>

class Problem {
private:
    Position* size;
    int* matrix;
    int nb_of_pieces;
public:
    Problem(Position* p, int* m);
    Position* getSize();
    int* getMatrix();
    int getNbOfPieces();
};

#endif // PROBLEM_H
