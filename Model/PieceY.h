#ifndef PIECEY_H
#define PIECEY_H

#include "Piece.h"

class PieceY : public Piece {
private:
	PieceRepresentation* representation;
	
	
public:
	PieceY() : Piece() {
		/* Matrice de representation de la Piece  :
		 *  z0		 z1	
		 * 0 1 0	0 1 0
		 * 1 1 1	0 0 0	
		 *  
		 */
		int* c = new int[12];
		for (int i = 0; i < 12; ++i) {
			c[i] = 0;
		}
		c[1] = c[3] = c[4] = c[5] = c[7] = 1;
		representation = new PieceRepresentation(3, 2, 2, c);
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

	/*
		Differentes rotation de la pièces selon les axes :
		 X -> rotationX()
		 Y -> rotatioY()
		 Z -> rotationZ()

	*/
	
	void rotationX(int x){
		representation= representation->rotateX(x);

	}
	
	void rotationY(int y){
		representation=representation->rotateY(y);
	}

	void rotationZ(int z){
		representation= representation->rotateZ(z);
	}

	/*
		Modifications des positions 

	*/

	
};

#endif
