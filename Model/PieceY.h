#ifndef PIECEY_H
#define PIECEY_H

#include "Piece.h"

class PieceY : public Piece {
private:
	PieceRepresentation* representation;
	int numPiece;
	
public:
	PieceY() : Piece() {
		/* Matrice de representation de la Piece :
		 *  z0		 z1	
		 * 1 1 1	0 1 0
		 * 0 0 0	0 1 0	
		 *  
		 */
		int* c = new int[12];
		for (int i = 0; i < 12; ++i) {
			c[i] = 0;
		}
		c[0] = c[1] = c[2] = c[7] = c[10] = 1;
		representation = new PieceRepresentation(3, 2, 2, c);
		numPiece=8;
	}

	Piece* Clone(){ 
       	 	return new PieceY( *this ); 
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

	int getType(){
	
		return numPiece;
	}
	
	PieceRepresentation* getRepresentation(){
		return representation;
	}
	
	void print() {
		representation->print();
	}
};

#endif
