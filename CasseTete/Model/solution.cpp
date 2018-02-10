#include "solution.h"

Solution::Solution(Position* p, int* m) {
    piece_t = new PieceModel(TypePieceT);
    piece_angle = new PieceModel(TypePieceAngle);
    piece_plus = new PieceModel(TypePiecePlus);
    piece_l = new PieceModel(TypePieceL);
    piece_z = new PieceModel(TypePieceZ);
    piece_p = new PieceModel(TypePieceP);
    piece_y = new PieceModel(TypePieceY);
    piece_d = new PieceModel(TypePieceD);
    piece_g = new PieceModel(TypePieceG);
    size = new Position(p);
    matrix = new int[(int) size->getX() * (int) size->getY() * (int) size->getZ()];
    for (int i = 0; i < size->getX() * size->getY() * size->getZ(); ++i) {
        if (m[i] == -1) {
            matrix[i] = m[i];
        }
        else {
            matrix[i] = 0;
        }
    }
}

Solution::Solution(Solution* s) {
    piece_t = new PieceModel(s->getPiece(TypePieceT));
    piece_angle = new PieceModel(s->getPiece(TypePieceAngle));
    piece_plus = new PieceModel(s->getPiece(TypePiecePlus));
    piece_l = new PieceModel(s->getPiece(TypePieceL));
    piece_z = new PieceModel(s->getPiece(TypePieceZ));
    piece_p = new PieceModel(s->getPiece(TypePieceP));
    piece_y = new PieceModel(s->getPiece(TypePieceY));
    piece_d = new PieceModel(s->getPiece(TypePieceD));
    piece_g = new PieceModel(s->getPiece(TypePieceG));

    size = new Position(s->getSize());

    int* m = s->getMatrix();
    matrix = new int[size->getX() * size->getY() * size->getZ()];
    for (int i = 0; i < size->getX() * size->getY() * size->getZ(); ++i) {
        matrix[i] = m[i];
    }
}

Solution::Solution(Problem* prob) {
    piece_t = new PieceModel(TypePieceT);
    piece_angle = new PieceModel(TypePieceAngle);
    piece_plus = new PieceModel(TypePiecePlus);
    piece_l = new PieceModel(TypePieceL);
    piece_z = new PieceModel(TypePieceZ);
    piece_p = new PieceModel(TypePieceP);
    piece_y = new PieceModel(TypePieceY);
    piece_d = new PieceModel(TypePieceD);
    piece_g = new PieceModel(TypePieceG);

    size = new Position(prob->getSize());

    int* m = prob->getMatrix();
    matrix = new int[(int) size->getX() * (int) size->getY() * (int) size->getZ()];
    for (int i = 0; i < size->getX() * size->getY() * size->getZ(); ++i) {
        if (m[i] == -1) {
            matrix[i] = m[i];
        }
        else {
            matrix[i] = 0;
        }
    }
}

bool Solution::compare(Problem* p) {
    for (int i = 0; i < size->getX() * size->getY() * size->getZ(); ++i) {
        if (p->getMatrix()[i] != matrix[i]) {
            return false;
        }
    }
    return true;
}

bool Solution::canAddPiece(std::vector<Position*> p, PieceType t, Position ppos) {
    if (getPiece(t)->isUsed()) {
        return false;
    }
    for (unsigned int i = 0; i < p.size(); ++i) {
        int pos = p[i]->getX() + ppos.getX() + (p[i]->getY() + ppos.getY()) * size->getX() + (p[i]->getZ() +  ppos.getZ()) * size->getX() * size->getY();
        if (pos < 0 || pos > size->getX() * size->getY() * size->getZ() || matrix[pos] != 0) {
            return false;
        }
    }
    return true;
}

void Solution::addPiece(std::vector<Position *> p, PieceType t, Position ppos, Position rot) {
    for (unsigned int i = 0; i < p.size(); ++i) {
        int pos = p[i]->getX() + ppos.getX() + (p[i]->getY() + ppos.getY()) * size->getX() + (p[i]->getZ() +  ppos.getZ()) * size->getX() * size->getY();
        matrix[pos] = 1;
    }
    PieceModel* piece = getPiece(t);
    piece->setUsed(true);
    piece->setPosition(ppos.getX(), ppos.getY(), ppos.getZ());
    piece->setRotation(rot.getX(), rot.getY(), rot.getZ());
}

void Solution::removePiece(std::vector<Position *> p, PieceType t, Position ppos) {
    for (unsigned int i = 0; i < p.size(); ++i) {
        int pos = p[i]->getX() + ppos.getX() + (p[i]->getY() + ppos.getY()) * size->getX() + (p[i]->getZ() +  ppos.getZ()) * size->getX() * size->getY();
        matrix[pos] = 0;
    }
    getPiece(t)->setUsed(false);
}

PieceModel* Solution::getPiece(PieceType t) {
    PieceModel* ret = piece_t;
    switch (t) {
        case TypePieceT:
            ret = piece_t;
            break;
        case TypePieceAngle:
            ret = piece_angle;
            break;
        case TypePiecePlus:
            ret = piece_plus;
            break;
        case TypePieceL:
            ret = piece_l;
            break;
        case TypePieceZ:
            ret = piece_z;
            break;
        case TypePieceP:
            ret = piece_p;
            break;
        case TypePieceY:
            ret = piece_y;
            break;
        case TypePieceD:
            ret = piece_d;
            break;
        case TypePieceG:
            ret = piece_g;
            break;
        default:
            break;
    }
    return ret;
}

int* Solution::getMatrix() {
    return matrix;
}

Position* Solution::getSize() {
    return size;
}
