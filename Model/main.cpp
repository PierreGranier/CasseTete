#include "PieceRepresentation.h"
#include "PieceAngle.h"
#include "PieceZ.h"
#include "PieceY.h"
#include "PieceP.h"

int main (int argc, char *argv[]) {
	/*
	 * Décommenter les deux lignes correspondant à la piece à tester
	 */

	/** Test de la piece T **/
//	std::cout << "Test de la piece T" << std::endl;
//	PieceT piece;
	
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
	std::cout << "Rotations de la piece" << std::endl;
	PieceAngle PA;
	for (int x = 0; x < 4; ++x) {
		for (int y = 0; y < 4; ++y) {
			for (int z = 0; z < 4; ++z) {
				PieceRepresentation* pr = PA.rotate(x, y, z);
				std::cout << "Rotation avec x = " << (x * 90) << ", y = " << (y * 90) << ", z = " << (z * 90) << std::endl;
				pr->print();
				std::cout << std::endl;
			}
		}
	}
	
	
	return 0;
}
