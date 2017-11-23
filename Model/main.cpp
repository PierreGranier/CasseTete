#include "PieceRepresentation.h"
#include "Piece.h"
#include "PieceAngle.h"
#include "PieceZ.h"
#include "PieceY.h"
#include "PieceP.h"
#include "PieceT.h"
#include "PieceL.h"
#include "PieceG.h"
#include "PieceD.h"
#include "PiecePlus.h"
#include "Solution.h"
#include <stdlib.h>

#include <vector>
#include <string>
#include <iostream>

/*
 * Recherche si une rotation donnant une représentation identique a déjà été ajoutée dans la liste de srotations de la pièce
 * Renvoie vrai si la représentation peut être ajouté, non sinon
 */
bool canAdd(std::vector<PieceRepresentation*>* v, PieceRepresentation* pr) {
	for (int i = 0; i < v->size(); ++i) {
		if (v->at(i)->equals(pr)) {
			return false;
		}
	}
	return true;
}

/*
 * Renvoie la liste des rotations (x, y, z) sans doublon pour la pièce
 */
std::vector<Position*> getRotations(Piece* p) {
	std::vector<PieceRepresentation*> v;
	std::vector<Position*>pos;
	for (int x = 0; x < 4; ++x) {
		for (int y = 0; y < 4; ++y) {
			for (int z = 0; z < 4; ++z) {
				PieceRepresentation* pr = p->rotate(x, y, z);
				if (canAdd(&v, pr)) {
					v.push_back(pr);
					pos.push_back(new Position(x, y, z));
				}
			}
		}
	}
	return pos;
}

/*
 * Problème à résoudre
 * Solution courante
 * Liste des solutions trouvées
 * Liste des pièces
 */
PieceRepresentation* probleme;
Solution* solution_courante;
std::vector<Solution*> liste_solutions;
std::vector<Piece*> liste_pieces;

/*
 * Fonction récursive de recherche de solution
 * On passe en paramètre la case dans la solution à partir de laquelle on commence la recherche
 * Si la solution courante est égale au problème, on ajoute une copie de la solution dans la liste des solutions trouvées et on signifie qu'on ne recherche pas plus loin dans cette branche
 * Si la position courante n'est pas dans la solution, on signifie que l'on ne recherche pas plus loin dans cette branche
 * Pour chaque case dans la solution à partir de la position courante
 * Pour chaque pièce
 * Si la pièce n'est pas utilisée dans la solution
 * Pour chaque rotation sans doublon
 * Si on peut ajouter la pièce dans la solution à la position courante et avec la rotation donnée
 * On ajoute la pièce à la solution
 * On appelle la fonction récursive en incrémentant la case courante
 * On supprime la pièce de la solution courante
 */
void recursive(int r) {
	if (solution_courante->getRepresentation()->equals(probleme)) {
		liste_solutions.push_back(new Solution(solution_courante));
		return;
	}
	else if (r >= solution_courante->getRepresentation()->getSize()) {
		return;
	}
	for (int i = r; i < solution_courante->getRepresentation()->getSize(); ++i) {
		for (int j = 0; j < liste_pieces.size(); ++j) {
			if (!solution_courante->hasPiece(liste_pieces[j])) {
				int x = i % solution_courante->getX();
				int y = i / solution_courante->getX() % solution_courante->getY();
				int z = i / (solution_courante->getX() * solution_courante->getY()) % solution_courante->getZ();
				Position pos(x, y, z);
				liste_pieces[j]->setPosition(pos);
				std::vector<Position*> rotations = getRotations(liste_pieces[j]);
				for (int k = 0; k < rotations.size(); ++k) {
					liste_pieces[j]->setRotation(rotations[k]->getX(), rotations[k]->getY(), rotations[k]->getZ());
					if (solution_courante->ajoutPiecePossible(liste_pieces[j])) {
						solution_courante->ajoutPiece(liste_pieces[j]);
						recursive(r + 1);
						solution_courante->enlevePiece();
					}
				}
			}
		}
	}
}

int main (int argc, char *argv[]) {
	/** Liste pieces **/
	PieceAngle* pa = new PieceAngle();
	PieceZ* pz = new PieceZ();
	PieceY* py = new PieceY();
	PieceP* pp = new PieceP();
	PieceT* pt = new PieceT();
	PieceL* pl = new PieceL();
	PiecePlus* ppl = new PiecePlus();
	PieceG* pg = new PieceG();
	PieceD* pd = new PieceD();
	
	liste_pieces.push_back(pa);
	liste_pieces.push_back(pz);
	liste_pieces.push_back(py);
	liste_pieces.push_back(pp);
	liste_pieces.push_back(pt);
	liste_pieces.push_back(pl);
	liste_pieces.push_back(ppl);
	liste_pieces.push_back(pg);
	liste_pieces.push_back(pd);
	
	/** Probleme **/
	/** Test qui fait planter mon pc **/
/*
	int* c = new int[27];
	for (int i = 0; i < 27; ++i) {
		c[i] = -1;
	}
	c[0] = c[1] = c[2] = c[3] = c[4] = c[6] = c[7] = c[10] = c[12] = c[13] = c[15] = c[16] = c[18] = c[19] = c[20] = c[22] = c[23] = c[24] = c[25] = c[26] = 1;
*/
	/** Pas testé **/
/*
	int* c = new int[18];
	for (int i = 0; i < 18; ++i) {
		c[i] = -1;
	}
	c[0] = c[1] = c[2] = c[3] = c[4] = c[5] = c[7] = c[8] = c[10] = c[11] = c[12] = c[13] = c[14] = c[16] = c[17] = 1;
	probleme = new PieceRepresentation(3, 3, 2, c);
*/
	/** Test concluant et rapide **/
	int* c = new int[18];
	for (int i = 0; i < 18; ++i) {
		c[i] = -1;
	}
	c[0] = c[1] = c[2] = c[4] = c[7] = c[9] = c[12] = c[15] = c[16] = c[17] = 1;
	probleme = new PieceRepresentation(3, 3, 2, c);
	probleme->print();
	
	/** Solution courante **/
	solution_courante = new Solution(probleme);
	
	recursive(0);
	std::cout << "Nombre de solutions " << liste_solutions.size() << std::endl;
	for (int i = 0; i < liste_solutions.size(); ++i) {
		liste_solutions[i]->getRepresentation()->print();
		for (int j = 0; j < liste_solutions[i]->getListePieces().size(); ++j) {
			std::cout << typeid(*liste_solutions[i]->getListePieces()[j]).name() << std::endl;
		}
		std::cout << std::endl;
	}
	
	return 0;	
}
