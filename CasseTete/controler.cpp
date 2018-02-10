#include "controler.h"

Controler::Controler() {
    interface = new Interface();
    interface->setInterfaceCommunication(this);
    solver = new Solver();
    solver->setSolverCommunication(this);

    /** Problème 1 **/
    int* m1 = new int[25];
    for (int i = 0; i < 25; ++i) {
        if (!(i == 3 || i == 4 || i == 13 || i == 23 || i == 24)) {
            m1[i] = 1;
        }
        else {
            m1[i] = -1;
        }
    }
    problems[0] = new Problem(new Position(5, 5, 1), m1);

    /** Problème 2 **/
    int* m2 = new int[36];
    for (int i = 0; i < 36; ++i) {
        if (!(i == 4 || i == 8 || i == 9 || i == 10 || i == 24 || i == 28)) {
            m2[i] = 1;
        }
        else {
            m2[i] = -1;
        }
    }
    problems[1] = new Problem(new Position(4, 3, 3), m2);

    /** Problème 3 **/
    int* m3 = new int[40];
    for (int i = 0; i < 40; ++i) {
        m3[i] = 1;
    }
    problems[2] = new Problem(new Position(5, 4, 2), m3);

    /** Problème 4 **/
    int* m4 = new int[45];
    for (int i = 0; i < 45; ++i) {
        m4[i] = 1;
    }
    problems[3] = new Problem(new Position(5, 3, 3), m4);

    interface->show();
}

void Controler::startSolving() {
    start_time = time(0);
    /** On recupere les parametres et on lance la recherche **/
    int prob = interface->getProblem();
    if (prob > -1) {
        solver->startSolving(interface->getAllSolutions(), problems[prob]);
    }
}

void Controler::finishSearch() {
    end_time = time(0);
    std::vector<Solution*> sol = solver->getSolutions();
    interface->calculFinished((int) sol.size(), (int) end_time - (int) start_time, &sol);
}
