#include "piecemodel.h"

PieceModel::PieceModel(PieceType t) : piece_type(t), is_used(false) {
    position = new Position(0, 0, 0);
    rotation = new Position(0, 0, 0);
}

PieceModel::PieceModel(PieceModel* p) {
    is_used = p->isUsed();
    piece_type = p->getType();
    position = new Position(p->getPosition());
    rotation = new Position(p->getRotation());
}

void PieceModel::setPosition(int x, int y, int z) {
    position->setX(x);
    position->setY(y);
    position->setZ(z);
}

Position* PieceModel::getPosition() {
    return position;
}

void PieceModel::setRotation(int x, int y, int z) {
    rotation->setX(x);
    rotation->setY(y);
    rotation->setZ(z);
}

Position* PieceModel::getRotation() {
    return rotation;
}

PieceType PieceModel::getType() {
    return piece_type;
}

void PieceModel::setUsed(bool b) {
    is_used = b;
}

bool PieceModel::isUsed() {
    return is_used;
}
