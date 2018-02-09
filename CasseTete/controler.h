#ifndef CONTROLER_H
#define CONTROLER_H

#include <iostream>
#include <string>
#include <ctime>
#include "View/interface.h"
#include "Model/solver.h"

class Controler : public InterfaceCommunication, public SolverCommunication {
private:
    Interface* interface;
    Solver* solver;
    time_t start_time;
    time_t end_time;
public:
    Controler();
    void startSolving();
    void finishSearch();
};

#endif // CONTROLER_H
