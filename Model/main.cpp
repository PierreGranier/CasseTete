#include "PieceRepresentation.h"
#include "PieceAngle.h"
#include "PieceZ.h"
#include "PieceY.h"
#include "PieceP.h"
#include "PieceT.h"
#include "PieceL.h"
#include "PieceG.h"
#include "PieceD.h"
#include "PiecePlus.h"

#include <list>
#include <iostream> 

int main (int argc, char *argv[]) {
	/*
	 * Décommenter les deux lignes correspondant à la piece à tester
	 */

	/** Test de la piece T **/
	std::cout << "Test de la piece T" << std::endl;
	PieceT piece;
	
	/** Test de la piece L **/
//	std::cout << "Test de la piece L" << std::endl;
//	PieceL piece;
	
	/** Test de la piece + **/
//	std::cout << "Test de la piece +" << std::endl;
//	PiecePlus piece;
	
	/** Test de la piece G **/
//	std::cout << "Test de la piece G" << std::endl;
//	PieceG piece;
	
	/** Test de la piece D **/
//	std::cout << "Test de la piece D" << std::endl;
//	PieceD piece;
	
	
	/** Pour chaque rotation possible, affiche la piece **/
	/*
	std::cout << "Rotations de la piece" << std::endl;
	for (int x = 0; x < 4; ++x) {
		for (int y = 0; y < 4; ++y) {
			for (int z = 0; z < 4; ++z) {
				PieceRepresentation* pr = piece.rotate(x, y, z);
				std::cout << "Rotation avec x = " << (x * 90) << ", y = " << (y * 90) << ", z = " << (z * 90) << std::endl;
				pr->print();
				std::cout << std::endl;
			}
		}
	}
	*/
	
	std::cout << "-----------------------------Test d'egalité entre deux piece -----------------------------" << std::endl;
		std::cout <<" cas 1: deux instance de la meme pièce"<<std::endl;
	PieceAngle pieceAngleA;
	PieceAngle pieceAngleB;
	PieceRepresentation *pra = pieceAngleA.rotate(0, 0, 0);	
	PieceRepresentation *prb = pieceAngleB.rotate(0, 0, 0);
	std::cout <<" Piece 1"<<std::endl;
	pieceAngleA.print();
	std::cout <<std::endl;
	std::cout <<" Piece 2"<<std::endl;
	prb->print();
	bool result_test= pra->equals(prb);
	std::cout << " resulat du test d'egalité t :"<< result_test <<std::endl;
	std::cout <<" Après rotation 90 en X sur la piece 2"<<std::endl;
	prb = pieceAngleB.rotate(1, 0, 0);
	std::cout <<std::endl;
	prb->print();
	result_test= pra->equals(prb);
	std::cout << " resulat du test d'egalité :"<< result_test <<std::endl;
	
	return 0;
}
