#ifndef SOLVER_H
#define SOLVER_H

#include <ctime>
#include <vector>
#include <map>
#include <thread>
#include <iostream>
#include "position.h"
#include "piecemodel.h"
#include "piecerotation.h"
#include "problem.h"
#include "solution.h"

class SolverCommunication {
public:
    virtual void finishSearch() =0;
};

class Solver {
private:
    SolverCommunication* comm;

    std::map<PieceType, std::vector<PieceRotation*>*> pieces;
    std::vector<Solution*> solutions;
    std::time_t starting_time;
    std::thread* thread;
public:
    Solver();
    void setSolverCommunication(SolverCommunication* c);
    void startSolving(bool all_sol, Problem* p);
    void solveThread(bool all_sol, Problem* p);
    void solve(Solution* current, Problem* p, int n);
    bool solveOne(Solution* current, Problem* p, int n);
    void getPieceRotation(PieceType t, std::vector<Position*>& piece);
    float* getRotationMatrix(int x, int y, int z);
    float* multiplyMatrix(float* m1, float* m2);
    Position* multiply(Position* p, float* m);
    std::vector<Solution*> getSolutions();
};

#endif // SOLVER_H
