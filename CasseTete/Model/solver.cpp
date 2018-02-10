#include "solver.h"

Solver::Solver() {
    std::vector<Position*>* v1 = new std::vector<Position*>;
    v1->push_back(new Position(0, 0, 0));
    v1->push_back(new Position(1, 0, 0));
    v1->push_back(new Position(2, 0, 0));
    v1->push_back(new Position(1, 1, 0));
    v1->push_back(new Position(1, 2, 0));
    getPieceRotation(PieceT, *v1);

    std::vector<Position*>* v2 = new std::vector<Position*>;
    v2->push_back(new Position(0, 0, 0));
    v2->push_back(new Position(0, 1, 0));
    v2->push_back(new Position(0, 2, 0));
    v2->push_back(new Position(1, 2, 0));
    v2->push_back(new Position(2, 2, 0));
    getPieceRotation(PieceAngle, *v2);

    std::vector<Position*>* v3 = new std::vector<Position*>;
    v3->push_back(new Position(1, 0, 0));
    v3->push_back(new Position(0, 1, 0));
    v3->push_back(new Position(1, 1, 0));
    v3->push_back(new Position(2, 1, 0));
    v3->push_back(new Position(1, 2, 0));
    getPieceRotation(PiecePlus, *v3);

    std::vector<Position*>* v4 = new std::vector<Position*>;
    v4->push_back(new Position(0, 0, 0));
    v4->push_back(new Position(0, 1, 0));
    v4->push_back(new Position(0, 2, 0));
    v4->push_back(new Position(0, 3, 0));
    v4->push_back(new Position(1, 3, 0));
    getPieceRotation(PieceL, *v4);

    std::vector<Position*>* v5 = new std::vector<Position*>;
    v5->push_back(new Position(0, 0, 0));
    v5->push_back(new Position(0, 1, 0));
    v5->push_back(new Position(0, 2, 0));
    v5->push_back(new Position(1, 2, 0));
    v5->push_back(new Position(1, 3, 0));
    getPieceRotation(PieceZ, *v5);

    std::vector<Position*>* v6 = new std::vector<Position*>;
    v6->push_back(new Position(0, 0, 0));
    v6->push_back(new Position(0, 1, 0));
    v6->push_back(new Position(1, 1, 0));
    v6->push_back(new Position(0, 2, 0));
    v6->push_back(new Position(1, 2, 0));
    getPieceRotation(PieceP, *v6);

    std::vector<Position*>* v7 = new std::vector<Position*>;
    v7->push_back(new Position(0, 0, 0));
    v7->push_back(new Position(1, 0, 0));
    v7->push_back(new Position(2, 0, 0));
    v7->push_back(new Position(1, 0, 1));
    v7->push_back(new Position(1, 1, 1));
    getPieceRotation(PieceY, *v7);

    std::vector<Position*>* v8 = new std::vector<Position*>;
    v8->push_back(new Position(0, 0, 0));
    v8->push_back(new Position(1, 0, 0));
    v8->push_back(new Position(1, 0, 1));
    v8->push_back(new Position(1, 1, 1));
    v8->push_back(new Position(1, 2, 1));
    getPieceRotation(PieceD, *v8);

    std::vector<Position*>* v9 = new std::vector<Position*>;
    v9->push_back(new Position(0, 0, 0));
    v9->push_back(new Position(1, 0, 0));
    v9->push_back(new Position(0, 0, 1));
    v9->push_back(new Position(0, 1, 1));
    v9->push_back(new Position(0, 2, 1));
    getPieceRotation(PieceG, *v9);

    starting_time = time(0);
}

void Solver::setSolverCommunication(SolverCommunication* c) {
    comm = c;
}

void Solver::startSolving(bool all_sol, Problem* p) {
    solutions.clear();
    thread = new std::thread(&Solver::solveThread, this, all_sol, p);
    thread->detach();
}

void Solver::solveThread(bool all_sol, Problem* p) {
    Solution* current = new Solution(p);
    if (all_sol) {
        solve(current, p, 0);
    }
    else {
        if (solveOne(current, p, 0)) {
            solutions.push_back(current);
        }
    }
    comm->finishSearch();
}

void Solver::solve(Solution* current, Problem* p, int n) {
    /** Si on a testé toutes les pieces **/
    if (n >= 9) {
        return;
    }

    /** Pour toutes les rotations de la piece courante n **/
    std::vector<PieceRotation*> vect = *(pieces[(PieceType) n]);
    for (unsigned int i = 0; i < vect.size(); ++i) {
        /** Pour toutes les positions du probleme **/
        Position* size = p->getSize();
        for (int x = 0; x < size->getX(); ++x) {
            for (int y = 0; y < size->getY(); ++y) {
                for (int z = 0; z < size->getZ(); ++z) {
                    Position pos(x, y, z);
                    if (current->canAddPiece(vect[i]->getPosition(), (PieceType) n, pos)) {
                        current->addPiece(vect[i]->getPosition(), (PieceType) n, pos, vect[i]->getRotation());
                        /** Si la solution courante est egale au probleme, on l'ajoute a la liste des solutions **/
                        if (current->compare(p)) {
                            Solution* new_solution = new Solution(current);
                            solutions.push_back(new_solution);
                            time_t current_time = time(0);
                            std::cout << "Time : " << (current_time - starting_time) << " solutions : " << solutions.size() << std::endl;
                        }
                        /** Sinon on continue la recherche **/
                        else {
                            solve(current, p, n + 1);
                        }
                        current->removePiece(vect[i]->getPosition(), (PieceType) n, pos);
                    }
                }
            }
        }
    }
    solve(current, p, n + 1);
}

bool Solver::solveOne(Solution* current, Problem* p, int n) {
    /** Si la solution est égale au probleme on retourne vrai **/
    if (current->compare(p)) {
        return true;
    }
    /** Si on a teste toutes les pieces on retourne faux **/
    if (n >= 9) {
        return false;
    }
    /** On test toutes les rotations de la piece courante **/
    std::vector<PieceRotation*> vect = *(pieces[(PieceType) n]);
    for (unsigned int i = 0; i < vect.size(); ++i) {
        /** Pour toutes les positions du probleme **/
        Position* size = p->getSize();
        for (int x = 0; x < size->getX(); ++x) {
            for (int y = 0; y < size->getY(); ++y) {
                for (int z = 0; z < size->getZ(); ++z) {
                    Position pos(x, y, z);
                    if (current->canAddPiece(vect[i]->getPosition(), (PieceType) n, pos)) {
                        current->addPiece(vect[i]->getPosition(), (PieceType) n, pos, vect[i]->getRotation());
                        /** Si la solution courante mene a une bonne solution on retourne vrai **/
                        if (solveOne(current, p, n + 1)) {
                            return true;
                        }
                        /** Sinon on enleve la piece et on continue la recherche **/
                        else {
                            current->removePiece(vect[i]->getPosition(), (PieceType) n, pos);
                        }
                    }
                }
            }
        }
    }
    /** Si aucune solution avec la piece courante n'est trouvee, on continue la recherche **/
    return solveOne(current, p, n + 1);
}

void Solver::getPieceRotation(PieceType t, std::vector<Position*>& piece) {
    std::vector<PieceRotation*>* rotations = new std::vector<PieceRotation*>;
    /** On fait toutes les rotations sur la piece **/
    for (int x = 0; x < 4; ++x) {
        for (int y = 0; y < 4; ++y) {
            for (int z = 0; z < 4; ++z) {
                /** On multiplie les positions de la piece par la matrice de rotation obtenue **/
                std::vector<Position*> p;
                float* matrix = getRotationMatrix(x, y, z);
                for (unsigned int i = 0; i < piece.size(); ++i) {
                    p.push_back(multiply(piece[i], matrix));
                }
                /** On test si la rotation est deja dans la liste des rotations de la piece **/
                PieceRotation* pr = new PieceRotation(p, new Position(x, y, z));
                bool ok = true;
                for (unsigned int k = 0; k < rotations->size(); ++k) {
                    if (pr->equals(rotations->at(k))) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    rotations->push_back(pr);
                }
            }
        }
    }
    pieces[t] = rotations;
}

float* Solver::getRotationMatrix(int x, int y, int z) {
    float* m1 = new float[9];
    m1[0] = 1;
    m1[1] = 0;
    m1[2] = 0;
    m1[3] = 0;
    m1[4] = (x == 1 || x == 3) ? 0 : (x == 0) ? 1 : -1;
    m1[5] = -((x == 0 || x == 2) ? 0 : (x == 1) ? 1 : -1);
    m1[6] = 0;
    m1[7] = (x == 0 || x == 2) ? 0 : (x == 1) ? 1 : -1;
    m1[8] = (x == 1 || x == 3) ? 0 : (x == 0) ? 1 : -1;

    float* m2 = new float[9];
    m2[0] = (y == 1 || y == 3) ? 0 : (y == 0) ? 1 : -1;
    m2[1] = 0;
    m2[2] = (y == 0 || y == 2) ? 0 : (y == 1) ? 1 : -1;
    m2[3] = 0;
    m2[4] = 1;
    m2[5] = 0;
    m2[6] = -((y == 0 || y == 2) ? 0 : (y == 1) ? 1 : -1);
    m2[7] = 0;
    m2[8] = (y == 1 || y == 3) ? 0 : (y == 0) ? 1 : -1;

    float* m3 = new float[9];
    m3[0] = (z == 1 || z == 3) ? 0 : (z == 0) ? 1 : -1;
    m3[1] = -((z == 0 || z == 2) ? 0 : (z == 1) ? 1 : -1);
    m3[2] = 0;
    m3[3] = (z == 0 || z == 2) ? 0 : (z == 1) ? 1 : -1;
    m3[4] = (z == 1 || z == 3) ? 0 : (z == 0) ? 1 : -1;
    m3[5] = 0;
    m3[6] = 0;
    m3[7] = 0;
    m3[8] = 1;

    return multiplyMatrix(multiplyMatrix(m1, m2), m3);
}

float* Solver::multiplyMatrix(float* m1, float* m2) {
    float* m3 = new float[9];
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

Position* Solver::multiply(Position* p, float* m) {
    float* pos = new float[3];

    for (int i = 0; i < 3; ++i) {
        pos[i] = 0;
        for (int j = 0; j < 3; ++j) {
            pos[i] += m[i * 3 + j] * p->get(j);
        }
    }

    return new Position(pos[0], pos[1], pos[2]);
}

std::vector<Solution*> Solver::getSolutions() {
    return solutions;
}
