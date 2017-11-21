#ifndef PIECEP_H
#define PIECEP_H

#include "Piece.h"

class PieceP : public Piece {
private:
	PieceRepresentation* representation;
		
public:
	PieceP() : Piece() {
		/* Matrice de representation de la Piece :
		 *  z0
		 * 1 0
		 * 1 1 
		 * 1 1  
		 */
		int* c = new int[6];
		for (int i = 0; i < 6; ++i) {
			c[i] = 0;
		}
		c[0] = c[2] = c[3] = c[4] = c[5] = 1;
		representation = new PieceRepresentation(2, 3, 1, c);
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
