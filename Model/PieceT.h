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
		 
		// TO DO...
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
	
	void print() {
		representation->print();
	}
};

#endif
