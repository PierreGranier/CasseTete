#ifndef SOLUTON_H
#define SOLUTION_H

#include "PieceRepresentation.h"
#include "PieceAngle.h"
#include "PieceZ.h"
#include "PieceY.h"
#include "PieceP.h"
#include "PieceD.h"
#include "PieceG.h"
#include "PieceL.h"
#include "PiecePlus.h"
#include "PieceT.h"

#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>

#include <vector>
#include <map>
#include "Piece.h"
#include <stdlib.h>

#include <list>
#include <iostream>
#include <typeinfo> 

#include "../Position.h"

/**
	Class Solution: qui represente une solution à un Casse-tete 3D
		
*/
class Solution{


private:
	std::vector<Piece*> liste_pieces; // ensemble des pièce de la solution	
	PieceRepresentation* representation;  // represention

public:		
	Solution(PieceRepresentation* probleme) {
		int* c = new int[probleme->getSize()];
			for (int i = 0; i < probleme->getSize(); ++i) {
			if (probleme->getValue(i) == -1) {
				c[i] = -1;
			}
			else if (probleme->getValue(i) == 1) {
				c[i] = 0;
			}
		}
		representation = new PieceRepresentation(probleme->getX(), probleme->getY(), probleme->getZ(),c);
	}
	
	Solution(Solution* sol) {
		representation = new PieceRepresentation(sol->getRepresentation());
		for (int i = 0; i < sol->getListePieces().size(); ++i) {
			liste_pieces.push_back(sol->getListePieces()[i]->copy());
		}
	}

	PieceRepresentation* getRepresentation() {	
		return representation;
	}
	
	int getX() {
		return representation->getX();
	}
	
	int getY() {
		return representation->getX();
	}
	
	int getZ() {
		return representation->getX();
	}

	int getNbPiece() {
		return liste_pieces.size();
	}

	const std::vector<Piece*>& getListePieces(){
		return liste_pieces;
	}
	
	bool hasPiece(Piece* p) {
		for (int i = 0; i < liste_pieces.size(); ++i) {
			if (typeid(*liste_pieces[i]) == typeid(*p)) {
				return true;
			}
		}
		return false;
	}

	bool ajoutPiecePossible(Piece* p) {
		// recuperation de la Position de rotation de la Piece
		PieceRepresentation* prP = p->rotate(p->getRotation().getX(), p->getRotation().getY(), p->getRotation().getZ());		
	
		int dimX = prP->getX();
		int dimY = prP->getY();
		int dimZ = prP->getZ();

		//Position *posPiece= P->getPosition();
		int posX = p->getPosition().getX();
		int posY = p->getPosition().getY();
		int posZ = p->getPosition().getZ();
	
		if(posX + dimX > representation->getX() || posY + dimY > representation->getY() || posZ + dimZ > representation->getZ()) {
			return false;
		}
		for(int z = 0; z < dimZ; ++z) {
			for(int x = 0; x < dimX; ++x) {
				for(int y = 0; y < dimY; ++y) {
					if ((representation->getValue(x + posX, y + posY, z + posZ) == 1 || representation->getValue(x + posX, y + posY, z + posZ) == -1) && prP->getValue(x, y, z) == 1) {
						return false;
					}
				}
			}
	
		}
		return true;		
	}

	void ajoutPiece(Piece* p) {
		//  Mise à jour de la solution si elle est possible
		if (ajoutPiecePossible(p) == true) {
			// recuperation de la Position de rotation de la Piece
			PieceRepresentation* prP = p->rotate(p->getRotation().getX(), p->getRotation().getY(), p->getRotation().getZ());		
	
			int dimX = prP->getX();
			int dimY = prP->getY();
			int dimZ = prP->getZ();

			//Position *posPiece= P->getPosition();
			int posX = p->getPosition().getX();
			int posY = p->getPosition().getY();
			int posZ = p->getPosition().getZ();
	
			for(int z = 0; z < dimZ; ++z) {
				for(int x = 0; x < dimX; ++x) {
					for(int y = 0; y < dimY; ++y) {
						int value;
						if ((value = prP->getValue(x, y, z)) == 1) {
							representation->setValue(x + posX, y + posY, z + posZ, value);
						}
					}
				}
			}
			liste_pieces.push_back(p);
		}	
	}
	
	void enlevePiece() {
		Piece* p = liste_pieces.back();
		PieceRepresentation* prP = p->rotate(p->getRotation().getX(), p->getRotation().getY(), p->getRotation().getZ());		
	
			int dimX = prP->getX();
			int dimY = prP->getY();
			int dimZ = prP->getZ();

			//Position *posPiece= P->getPosition();
			int posX = p->getPosition().getX();
			int posY = p->getPosition().getY();
			int posZ = p->getPosition().getZ();
	
			for(int z = 0; z < dimZ; ++z) {
				for(int x = 0; x < dimX; ++x) {
					for(int y = 0; y < dimY; ++y) {
						int value;
						if ((value = prP->getValue(x, y, z)) == 1) {
							representation->setValue(x + posX, y + posY, z + posZ, 0);
						}
					}
				}
			}
		liste_pieces.pop_back();
	}
 void afficherTest(){  std::cout << "Je suis une solution temporaire";}

};
#endif
