#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include "piecemodel.h"
#include "../position.h"
#include "problem.h"

class Solution {
private:
    PieceModel* piece_t;
    PieceModel* piece_angle;
    PieceModel* piece_plus;
    PieceModel* piece_l;
    PieceModel* piece_z;
    PieceModel* piece_p;
    PieceModel* piece_y;
    PieceModel* piece_d;
    PieceModel* piece_g;
    Position* size;
    int* matrix;
public:
    Solution(Position* p, int* m);
    Solution(Solution* s);
    Solution(Problem* prob);
    bool compare(Problem* p);
    bool canAddPiece(std::vector<Position*> p, PieceType t, Position ppos);
    void addPiece(std::vector<Position*> p, PieceType t, Position ppos, Position rot);
    void removePiece(std::vector<Position*> p, PieceType t, Position ppos);
    PieceModel* getPiece(PieceType t);
    int* getMatrix();
    Position* getSize();
    int getNbOfPieces();
};

#endif // SOLUTION_H
