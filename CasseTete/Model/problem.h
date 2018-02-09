#ifndef PROBLEM_H
#define PROBLEM_H

#include <position.h>

class Problem {
private:
    Position* size;
    int* matrix;
public:
    Problem(Position* p, int* m);
    Position* getSize();
    int* getMatrix();
};

#endif // PROBLEM_H
