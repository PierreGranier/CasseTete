#ifndef PIECED_H
#define PIECED_H

#include "Piece.h"

class PieceD : public Piece {
private:
	PieceRepresentation* representation;
	
public:
	PieceD() : Piece() {
		/* Matrice de representation de la Piece :
		 *  z0		z1
		 * 1 1		0 1
		 * 0 0 		0 1
		 * 0 0		0 1
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
