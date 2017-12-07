#ifndef PIECEG_H
#define PIECEG_H

#include "Piece.h"

class PieceG : public Piece {
private:
	PieceRepresentation* representation;
	int numPiece;
	
public:
	PieceG() : Piece() {
		/* Matrice de representation de la Piece :
		 *  z0		z1
		 * 1 1		1 0
		 * 0 0 		1 0
		 * 0 0		1 0
		 */
		int* c = new int[12];
		for (int i = 0; i < 12; ++i) {
			c[i] = 0;
		}
		c[0] = c[1] = c[6] = c[8] = c[10] = 1;
		representation = new PieceRepresentation(2, 3, 2, c);
		numPiece=6;
	}

	Piece* Clone(){  
       	 	return new PieceG( *this ); 
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
