#include "controler.h"

Controler::Controler() {
    interface = new Interface();
    interface->setInterfaceCommunication(this);
    solver = new Solver();
    solver->setSolverCommunication(this);

    interface->show();
}

void Controler::startSolving() {
    start_time = time(0);
    /** Si on recherche toutes les solutions **/
    if (interface->getAllSolutions()) {
        int* matrix = new int[25];
        for (int i = 0; i < 25; ++i) {
            if (!(i == 3 || i == 4 || i == 13 || i == 23 || i == 24)) {
                matrix[i] = 1;
            }
            else {
                matrix[i] = -1;
            }
        }
        Problem* problem = new Problem(new Position(5, 5, 1), matrix);
        solver->startSolving(true, problem);
    }
    else {
        std::cout << "Je cherche une seule solution" << std::endl;
    }

}

void Controler::finishSearch() {
    end_time = time(0);
    std::vector<Solution*> sol = solver->getSolutions();
    interface->calculFinished((int) sol.size(), (int) end_time - (int) start_time, &sol);
}
