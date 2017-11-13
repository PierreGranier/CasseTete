#ifndef PIECEPLUS_H
#define PIECEPLUS_H

#include "Piece.h"

class PiecePlus : public Piece {
private:
	PieceRepresentation* representation;
	
public:
	PiecePlus() : Piece() {
		/* Matrice de representation de la Piece :
		 *  z0
		 * 0 1 0
		 * 1 1 1 
		 * 0 1 0
		 */
		 
<<<<<<< HEAD
		int* c = new int[9];
		for (int i = 0; i < 9; ++i) {
			c[i] = 0;
		}
		c[1] = c[3] = c[4] = c[5] = c[7] = 1;
		representation = new PieceRepresentation(3, 3, 1, c);
=======
		// TO DO...
>>>>>>> origin/master
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
