#ifndef PIECEROTATION_H
#define PIECEROTATION_H

#include <vector>
#include "../position.h"

class PieceRotation {
private:
    std::vector<Position*> pos;
    Position* rotation;
public:
    PieceRotation(std::vector<Position*> v, Position* r);
    std::vector<Position*> getPosition();
    Position* getRotation();
    bool equals(PieceRotation* pr);
};

#endif // PIECEROTATION_H
