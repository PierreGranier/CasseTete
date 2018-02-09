#include "piecerotation.h"

PieceRotation::PieceRotation(std::vector<Position*> v, Position* r) : pos(v), rotation(r) {

}

std::vector<Position*> PieceRotation::getPosition() {
    return pos;
}

Position* PieceRotation::getRotation() {
    return rotation;
}

bool PieceRotation::equals(PieceRotation* pr) {
    std::vector<Position*> pp = pr->getPosition();
    int x_dif = 0, y_dif = 0, z_dif = 0, x2_dif = 0, y2_dif = 0, z2_dif = 0;
    for (unsigned int i = 0; i < pos.size(); ++i) {
        Position* p1 = pos[i];
        if (p1->getX() < x_dif) {
            x_dif = p1->getX();
        }
        if (p1->getY() < y_dif) {
            y_dif = p1->getY();
        }
        if (p1->getZ() < z_dif) {
            z_dif = p1->getZ();
        }
        Position* p2 = pp[i];
        if (p2->getX() < x2_dif) {
            x2_dif = p2->getX();
        }
        if (p2->getY() < y2_dif) {
            y2_dif = p2->getY();
        }
        if (p2->getZ() < z2_dif) {
            z2_dif = p2->getZ();
        }
    }

    bool same = true;
    for (unsigned int i = 0; i < pos.size(); ++i) {
        Position* p1 = pos[i];
        bool identical = false;
        for (unsigned int j = 0; j < pp.size(); ++j) {
            Position* p2 = pp[j];
            if (p1->getX() - x_dif == p2->getX() - x2_dif && p1->getY() - y_dif == p2->getY() - y2_dif && p1->getZ() - z_dif == p2->getZ() - z2_dif) {
                identical = true;
                break;
            }
        }
        if (!identical) {
            same = false;
            break;
        }
    }
    return same;
}
