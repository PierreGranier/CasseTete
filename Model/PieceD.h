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
<<<<<<< HEAD
		 * 
		*/
		 
=======
		 */ 
>>>>>>> 097a5adfc27e8e02079b71cfabc70d0824e9f0c3
		int* c = new int[12];
		for (int i = 0; i < 12; ++i) {
			c[i] = 0;
		}
		c[0] = c[1] = c[7] = c[9] = c[11] = 1;
		representation = new PieceRepresentation(2, 3, 2, c);
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
};

#endif
