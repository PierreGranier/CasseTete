#ifndef PIECEMODEL_H
#define PIECEMODEL_H

#include "../position.h"

typedef enum PieceType {
    TypePieceT,
    TypePieceAngle,
    TypePiecePlus,
    TypePieceL,
    TypePieceZ,
    TypePieceP,
    TypePieceY,
    TypePieceD,
    TypePieceG
} PieceType;

class PieceModel {
private:
    bool is_used;
    PieceType piece_type;
    Position* position;
    Position* rotation;

public:
    PieceModel(PieceType t);
    PieceModel(PieceModel* p);
    void setPosition(int x, int y, int z);
    Position* getPosition();
    void setRotation(int x, int y, int z);
    Position* getRotation();
    PieceType getType();
    void setUsed(bool b);
    bool isUsed();
};

#endif // PIECEMODEL_H
