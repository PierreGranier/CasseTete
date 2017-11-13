#ifndef PIECEP_H
#define PIECEP_H

#include "Piece.h"



/*
	definition de la Matrice   
*/


class PieceP : public Piece {
private:
	PieceRepresentation* representation;
	
	
public:
	PieceP() : Piece() {
		/* Matrice de representation de la Piece  :
		 *  z0
		 * 1 1
		 * 1 1 
		 * 1 0  
		 */
		int* c = new int[6];
		for (int i = 0; i < 6; ++i) {
			c[i] = 0;
		}
		c[0] = c[1] = c[2] = c[3] = c[4] = 1;
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
		Modifications des positions après une rotation effectuée

	*/

	
};

#endif
