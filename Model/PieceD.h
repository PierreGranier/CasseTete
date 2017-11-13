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
		 
<<<<<<< HEAD
		// 
		int* c = new int[12];
		for (int i = 0; i < 12; ++i) {
			c[i] = 0;
		}
		c[0] = c[1] = c[7] = c[9] = c[11] = 1;
		representation = new PieceRepresentation(2, 3, 2, c);
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
