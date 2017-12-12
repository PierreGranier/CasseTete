#ifndef PIECEANGLE_H
#define PIECEANGLE_H

#include "Piece.h"

class PieceAngle : public Piece {
private:
	PieceRepresentation* representation;
	int numPiece;
	
public:
	PieceAngle() : Piece() {
		/* Matrice de representation de la Piece :
		 *  z0
		 * 1 0 0
		 * 1 0 0
		 * 1 1 1
		 */
		int* c = new int[9];
		for (int i = 0; i < 9; ++i) {
			c[i] = 0;
		}
		c[0] = c[3] = c[6] = c[7] = c[8] = 1;
		representation = new PieceRepresentation(3, 3, 1, c);

		numPiece=1;
	}

	Piece* Clone(){ 
       	 	return new PieceAngle( *this ); 
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

	PieceRepresentation* getRepresentation(){
		return representation;
	}

	void print() {
		representation->print();
	}

	int getType(){
	
		return numPiece;
	}
};

#endif
