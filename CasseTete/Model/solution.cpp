#include "solution.h"

Solution::Solution(Position* p, int* m) {
    piece_t = new PieceModel(PieceT);
    piece_angle = new PieceModel(PieceAngle);
    piece_plus = new PieceModel(PiecePlus);
    piece_l = new PieceModel(PieceL);
    piece_z = new PieceModel(PieceZ);
    piece_p = new PieceModel(PieceP);
    piece_y = new PieceModel(PieceY);
    piece_d = new PieceModel(PieceD);
    piece_g = new PieceModel(PieceG);
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
    piece_t = new PieceModel(s->getPiece(PieceT));
    piece_angle = new PieceModel(s->getPiece(PieceAngle));
    piece_plus = new PieceModel(s->getPiece(PiecePlus));
    piece_l = new PieceModel(s->getPiece(PieceL));
    piece_z = new PieceModel(s->getPiece(PieceZ));
    piece_p = new PieceModel(s->getPiece(PieceP));
    piece_y = new PieceModel(s->getPiece(PieceY));
    piece_d = new PieceModel(s->getPiece(PieceD));
    piece_g = new PieceModel(s->getPiece(PieceG));

    size = new Position(s->getSize());

    int* m = s->getMatrix();
    matrix = new int[size->getX() * size->getY() * size->getZ()];
    for (int i = 0; i < size->getX() * size->getY() * size->getZ(); ++i) {
        matrix[i] = m[i];
    }
}

Solution::Solution(Problem* prob) {
    piece_t = new PieceModel(PieceT);
    piece_angle = new PieceModel(PieceAngle);
    piece_plus = new PieceModel(PiecePlus);
    piece_l = new PieceModel(PieceL);
    piece_z = new PieceModel(PieceZ);
    piece_p = new PieceModel(PieceP);
    piece_y = new PieceModel(PieceY);
    piece_d = new PieceModel(PieceD);
    piece_g = new PieceModel(PieceG);

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
        case PieceT:
            ret = piece_t;
            break;
        case PieceAngle:
            ret = piece_angle;
            break;
        case PiecePlus:
            ret = piece_plus;
            break;
        case PieceL:
            ret = piece_l;
            break;
        case PieceZ:
            ret = piece_z;
            break;
        case PieceP:
            ret = piece_p;
            break;
        case PieceY:
            ret = piece_y;
            break;
        case PieceD:
            ret = piece_d;
            break;
        case PieceG:
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
