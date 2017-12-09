#ifndef PIECEZ_H
#define PIECEZ_H

#include "Piece.h"

class PieceZ : public Piece {
private:
	PieceRepresentation* representation;
	int numPiece;
	
public:
	PieceZ() : Piece() {
		/* Matrice de representation de la Piece :
		 *  z0
		 * 1 0
		 * 1 0 
		 * 1 1 
		 * 0 1 
		 */
		int* c = new int[8];
		for (int i = 0; i < 8; ++i) {
			c[i] = 0;
		}
		c[0] = c[2] = c[4] = c[5] = c[7] = 1;
		representation = new PieceRepresentation(2, 4, 1, c);
		numPiece=2;
	}

	Piece* Clone(){ 
       	 	return new PieceZ( *this ); 
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
