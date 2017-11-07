#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include "../Position.h"

class Piece {

protected:
	Position position;
	Position rotation;
	
public:
	Piece() : position(0, 0, 0), rotation(0, 0, 0) {
	};

	void setPosition(Position pos) {
	  position.setX(pos.getX());
	  position.setY(pos.getY());
	  position.setZ(pos.getZ());
	}


	void setRotation(int x, int y, int z) {
	  rotation.setX(x);
	  rotation.setY(y);
	  rotation.setZ(z);
	}

	Position getPosition() {
		return position;
	}

	Position getRotation() {
		return rotation;
	}
	
	virtual PieceRepresentation* rotate(int x, int y, int z) =0;
};

#endif
