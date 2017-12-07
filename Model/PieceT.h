#ifndef PIECET_H
#define PIECET_H

#include "Piece.h"

class PieceT : public Piece {
private:
	PieceRepresentation* representation;
	int numPiece;
	
public:
	PieceT() : Piece() {
		/* Matrice de representation de la Piece :
		 *  z0
		 * 1 1 1
		 * 0 1 0 
		 * 0 1 0
		 */
		int* c = new int[9];
		for (int i = 0; i < 9; ++i) {
			c[i] = 0;
		}
		c[0] = c[1] = c[2] = c[4] = c[7] = 1;
		representation = new PieceRepresentation(3, 3, 1, c);
		numPiece=8;
	}

	Piece* Clone(){  
       	 	return new PieceT( *this ); 
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
		setRotation(x,y,z);
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
