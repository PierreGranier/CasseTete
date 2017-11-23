#ifndef PIECET_H
#define PIECET_H

#include "Piece.h"

class PieceT : public Piece {
private:
	PieceRepresentation* representation;
	
public:
	PieceT() : Piece() {
		/* Matrice de representation de la Piece :
		 *  z0
		 * 1 1 1
		 * 0 1 0 
		 * 0 1 0
		 */
		int* c = new int[9];
		for (int i = 0; i < 9; ++i) {
			c[i] = 0;
		}
		c[0] = c[1] = c[2] = c[4] = c[7] = 1;
		representation = new PieceRepresentation(3, 3, 1, c);
	}
	
	PieceRepresentation* rotate(int x, int y, int z) {
		PieceRepresentation* pr = representation;
		if (x !=0) {
			pr = pr->rotateX(x);
		}
		if (y != 0) {
			pr = pr->rotateY(y);
		}
		if (z != 0) {
			pr = pr->rotateZ(z);
		}
		
		return pr;
	}
	
	void setRepresentation( PieceRepresentation* pr){
		representation=pr;	
	}

	
	void print() {
		representation->print();
	}
	
	PieceT* copy() {
		PieceT* p = new PieceT;
		Position pos(position.getX(), position.getY(), position.getZ());
		p->setPosition(pos);
		p->setRotation(rotation.getX(), rotation.getY(), rotation.getZ());
		
		return p;
	}
};

#endif
