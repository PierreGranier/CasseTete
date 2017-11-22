#include "PieceRepresentation.h"
#include "PieceAngle.h"
#include "PieceZ.h"
#include "PieceY.h"
#include "PieceP.h"
#include "PieceD.h"
#include "PieceG.h"
#include "PiecePlus.h"
#include "PieceL.h"
#include "PieceT.h"
#include "Piece.h"
#include "Solution.h"
#include <stdlib.h>

#include <list>
#include <iostream> 

void  fill_tab(char *t,int N, int K){

	for(int i=0; i<N*K;i++){
		char car_alea = (rand() % 26) + 'A';
		std:: cout << car_alea <<std::endl;
		t[N*K]=car_alea;

	}
	
}


//  Methode 1 :comparaison


int compare(char* t, int N,int K){
	int compteur_difference=0;
	for(int idx_chaine =0; idx_chaine<N-1;++ idx_chaine){

		for(int idx_caractere=0;idx_caractere<K;++idx_caractere){
			std:: cout <<"comparaison entre"  << t[idx_chaine*idx_caractere]<< "et" <<t[(idx_chaine+1)*idx_caractere]<< std:: endl;
			if(((t[idx_chaine*idx_caractere])-(t[(idx_chaine+1)*idx_caractere]))!=0){

				compteur_difference=compteur_difference+1;
			}

		}

	}
	return compteur_difference;
}


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
	PiecePlus PL;
	for (int x = 0; x < 4; ++x) {
		for (int y = 0; y < 4; ++y) {
			for (int z = 0; z < 4; ++z) {
				PieceRepresentation* pr = PL.rotate(x, y, z);
				
/*std::cout << "Rotations de la piece" << std::endl;
	
	for (int x = 0; x < 4; ++x) {
		for (int y = 0; y < 4; ++y) {
			for (int z = 0; z < 4; ++z) {
				PieceRepresentation* pr = piece.rotate(x, y, z);

				std::cout << "Rotation avec x = " << (x * 90) << ", y = " << (y * 90) << ", z = " << (z * 90) << std::endl;
				pr->print();
				std::cout << std::endl;
			}
		}
	}*/
		
	
	std::cout << "*************************Test d'egalité entre deux piece *****************" << std::endl;
	
	PieceAngle pieceAngleA;
	PieceAngle pieceAngleB;	
	PieceRepresentation *prb = pieceAngleB.rotate(0, 0, 0);
	PieceRepresentation *pra = pieceAngleA.rotate(0, 0, 0);
	bool result_test= pra->equals(prb);
	std::cout << " resulat du test d'egalité :"<< result_test <<std::endl; 

	std::cout << "*************************Test de la classe solution *****************" << std::endl;
		
	
	// test Classe Solution

	Solution S;
	PieceRepresentation *prS= S.getRepresentation();
	std::cout <<"Etat de la solution "<<std::endl;
	prS->print();
	
	std::cout <<"nombre de pieces dans la solution "<<S.getNbPiece() <<std::endl;
	//PieceAngle *pa=new PieceAngle();
	
	PieceY *pa=new PieceY();
	std::cout <<"Piece à rajouter "<<std::endl;
	pa->print();
	
	Position pos(3,0,0);
	pa->setPosition(pos);	

	S.ajoutPiece(pa);
	std::cout <<"Etat de la solution "<<std::endl;
	prS->print();	
	std::cout <<"nombre de pieces dans la solution "<<S.getNbPiece() <<std::endl;
	
	
	
	Position pos2(2,0,0);
	pa->setPosition(pos2);	
	std::cout <<"Piece à rajouter "<<std::endl;
	pa->print();

	S.ajoutPiece(pa);
	

	std::cout <<"Etat de la solution "<<std::endl;
	prS->print();
	std::cout <<"nombre de pieces dans la solution "<<S.getNbPiece() <<std::endl;

	PieceZ *pz=new PieceZ();
	std::cout <<"Piece à rajouter "<<std::endl;
	pz->print();

	S.ajoutPiece(pz);
	
	prS->print();
	
	std::cout <<"nombre de pieces dans la solution "<<S.getNbPiece() <<std::endl;
	return 0;
}
