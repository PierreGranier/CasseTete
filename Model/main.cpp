#include "PieceRepresentation.h"
#include "PieceAngle.h"
#include "PieceZ.h"
#include "PieceY.h"
#include "PieceP.h"
#include "Piece.h"
#include "Solution.h"
#include <stdlib.h>
#include <map>
#include <time.h>

#include <list>
#include<string>
#include <iostream>
#include<omp.h>
#include<typeinfo>



/** Calcul de combinaisons possible 
	Renvoi l'ensemble des forme Possible d'une piece (type) dans un problème donné
 */
std::map<int,Piece*> formesPossibles(Piece* pa, Solution sol){

	Solution S=sol;
	//PieceRepresentation* pr=pa->getRepresentation();
	PieceRepresentation* prS=sol.getRepresentation();
	int nombre_totale=0;


	std::map<int,Piece*> pieces;
	//S.suppressionPiece("PieceAngle");
	for(int i=0; i<prS->getX();++i){ // pour tout les X
		for(int j=0; j<prS->getY(); ++j){ // Pour tous les Y
			for(int k=0;k<prS->getZ(); ++k){ // Pour tous les Z
				for (int rotx=0;rotx<4;++rotx){  // pour tout les rotx
					for (int roty=0;roty<4;++roty){ // pour toute les rotation en y
						for (int rotz=0;rotz<4;++rotz){ // pour toutes les rotation en z
						int angleX=0; int angleY=0; int angleZ=0;
							if ((rotx!=0 && roty==0 && rotz==0) || (rotx==0 && roty!=0 && rotz==0) || (rotx==0 && roty==0 && rotz!=0) || (rotx==0 && roty==0 && rotz==0) ){

								Position posI(i,j,k);
								pa->setPosition(posI); // Modification de la position
											// modification de la rotation
								int angleX=0; int angleY=0; int angleZ=0;
								if(rotx>0){
									 angleX=4-rotx;
								}

								if(roty>0){
									 angleY=4-roty;
								}

								if(rotz>0){
									 angleZ=4-rotz;
								}

								PieceRepresentation* p=pa->rotate(rotx,roty,rotz);
								pa->setRepresentation(p);
								if(S.ajoutPiecePossible(pa)==true){
									nombre_totale=nombre_totale+1;
									Piece *pt=pa->Clone();
									pieces[nombre_totale]=pt; 

								}

								PieceRepresentation* pi=pa->rotate(angleX,angleY,angleZ);

								pa->setRepresentation(pi);

								Position posJ(0,0,0);
								pa->setPosition(posJ);


							}

						}
					}
				}
			}

		}
	}
	return pieces;
}



/** Mise à jour des indices suivants */

void maj_suivants(int indice_actuel, int* indices, int taille){
	for(int i=indice_actuel+1; i<taille;i++){
		indices[i]=1;
	}
}


 /* calcul de temps d'execution */
void duree(time_t _begin, time_t _end)
{
  double temp;
  double hours=0, min=0, sec=0;
  double dureeCalc = difftime(_end, _begin);
  temp = modf(dureeCalc/3600., &hours);
  temp = modf(temp*60., &min);
  temp = modf(temp*60., &sec);
  std::cout<<"Duree du calcul : "<<hours<<" h "<<min<<" min "<<sec<<" sec"<<std::endl;
}



std::vector<Solution*>  solution_auxiliaire( std::map<int, std::map<int,Piece*>> vectPieces,int nb_pieces_solution,PieceRepresentation* probleme){

	std::vector<Solution*> liste_solutions;
	int nombre_types_pieces=vectPieces.size(); // nombre de pieces;
	int* indice= new int[nombre_types_pieces]; // tout les entier sont à 1

		/**
		1) Initialisation des position à 1
		*/
	for(int i=0;i< nombre_types_pieces;++i){
		indice[i]=1;	
	}
	int ok= false; 
	
	int* taille_ensemblePieces=new int[nombre_types_pieces];
		/**
		 2) Mises des tailles des ensembles de type De Pieces
		*/

	for(int i=0;i<nombre_types_pieces; ++i){
		taille_ensemblePieces[i]=vectPieces.find(i)->second.size();
			
	}

	if( nombre_types_pieces==nb_pieces_solution){
		
		// On rentre dans la boucle
		while(ok==false){
			Solution* S= new Solution(probleme);

			/*for(int i=0;i< nombre_types_pieces;++i){
				std::cout<<indice[i];
				std::cout<<"--";
				 
			}
			std::cout<<std::endl;*/

			for(int i=0; i<nombre_types_pieces;++i){
				
				if(i==0 && nombre_types_pieces>1){		// si nous sommes au premier type de pièce
					
					if (indice[i]<(taille_ensemblePieces[i]+1) &&  S->ajoutPiecePossible(vectPieces.find(i)->second.find(indice[i])->second)==true){
						S->ajoutPiece(vectPieces.find(i)->second.find(indice[i])->second);
						
					}
					
					else {  if (indice[i]<(taille_ensemblePieces[i]+1))  {
							
							indice[i]=indice[i]+1;maj_suivants(i, indice,nombre_types_pieces);  
							
						}else{
							ok=true; std::cout<<"aucun resultat"<<std::endl;
						} 
					
					break;
					}
				}
				
				// cas 2 Pieces entre le deuxième et l'avant dernière pièce

				if(i>0 && i<nombre_types_pieces-1){ 
					if (indice[i]<(taille_ensemblePieces[i]+1) &&  S->ajoutPiecePossible(vectPieces.find(i)->second.find(indice[i])->second)==true){
						S->ajoutPiece(vectPieces.find(i)->second.find(indice[i])->second);
					}else {
						if (indice[i]<taille_ensemblePieces[i]+1) {
							indice[i]=indice[i]+1;
							maj_suivants(i, indice,nombre_types_pieces); 
						} else {
							indice[i-1]=indice[i-1]+1;
							indice[i]=1;
							maj_suivants(i+1, indice,nombre_types_pieces); 
						} 
					break;	
					}
					
				}

				/* Cas 3  dernier type de Piece */

				if(i==nombre_types_pieces-1){
					if (indice[i]<(taille_ensemblePieces[i]+1) &&  S->ajoutPiecePossible(vectPieces.find(i)->second.find(indice[i])->second)==true){
						S->ajoutPiece(vectPieces.find(i)->second.find(indice[i])->second);
					}else {
						if (indice[i]<taille_ensemblePieces[i]+1) {indice[i]=indice[i]+1;  
						}else {
							indice[i-1]=indice[i-1]+1; indice[i]=1;
						} 
					break;	
					}	

				}

			//fin boucle for
			}


			if (S->getNbPiece()==nb_pieces_solution){
				S->getRepresentation()->print();
				liste_solutions.push_back(S);
				ok=true;  // Commenter cette ligne ou la supprimer si on veut rechercher toute les solutions
  		 		
			}
			delete S;
			
		//fin while
		}

	//fin if 
	}

return liste_solutions;	
}



/**
	Algorithme de recherche de solution. 
		Paramètres: 
			-probleme: de type pieces Representation
			-pieces_utiles: Un tableau d'entier de taille 9  dans lequel chaque valeurs (0 ou 1) defini si une pieces est utilisée ou pas.	

				piecesplus -> 0
				piecesangle -> 1
				pieceZ -> 2
				pieceY -> 3
				pieceP ->4
				pieceD ->5
				pieceG -> 6
				pieceL ->7
				pieceT ->8

			 Ex : si la Piece Plus est utilisée, pieces_utiles[0]=1. ET pieces_utiles[0]=0 si elle n'est pas utilisée

		Cet aglorithme  renvoi un Vector de solution . 
			


*/

std::vector<Solution*> recherche_solution(PieceRepresentation* probleme,int* pieces_utiles){

	std::vector<Solution*> liste_solutions; // l'ensemble de solutions

	std::cout << " Recherche en cours......." << std::endl;	

	Solution a= new Solution(probleme);

	/*Instances de chaque type de Pieces */
	Piece* pa= new PieceAngle();
	Piece *pz=new PieceZ();
	Piece *py= new PieceY();
	Piece *pp= new PieceP();
	Piece *pd= new PieceD();
	Piece *pg= new PieceG();
	Piece *pl= new PieceL();
	Piece *pt= new PieceT();
	Piece *pplus= new PiecePlus();
	
	/* Map representant l'ensemble des formes possibles (que chaque Pieces peut avoir dans la solution : en fonction de la position et la rotation) */
	std::map<int,Piece*> piecesAngle;
	std::map<int,Piece*> piecesT;
	std::map<int,Piece*> piecesZ;
	std::map<int,Piece*> piecesY;
	std::map<int,Piece*> piecesP;
	std::map<int,Piece*> piecesD;
	std::map<int,Piece*> piecesL;
	std::map<int,Piece*> piecesPlus;
	std::map<int,Piece*> piecesG;

	/* Remplissages des conteneurs (Map) dans  quand la Piece est utilisée dans la solution */

	std::map<int, std::map<int,Piece*>> vectPieces;

	int ind_type_piece=-1;

	if (pieces_utiles[0]==1){piecesPlus= formesPossibles(pplus,a);} if(piecesPlus.size()>0){ind_type_piece=ind_type_piece+1; vectPieces[ind_type_piece]=piecesPlus; }
	if (pieces_utiles[1]==1){piecesAngle=formesPossibles(pa,a);}	if(piecesAngle.size()>0){ind_type_piece=ind_type_piece+1; vectPieces[ind_type_piece]=piecesAngle; }
	if (pieces_utiles[2]==1){piecesZ= formesPossibles(pz,a);}	if(piecesZ.size()>0){ind_type_piece=ind_type_piece+1; vectPieces[ind_type_piece]=piecesZ; }
	if (pieces_utiles[3]==1){piecesY= formesPossibles(py,a);}	if(piecesY.size()>0){ind_type_piece=ind_type_piece+1; vectPieces[ind_type_piece]=piecesY; }
	if (pieces_utiles[4]==1){piecesP= formesPossibles(pp,a);}	if(piecesP.size()>0){ind_type_piece=ind_type_piece+1; vectPieces[ind_type_piece]=piecesP; } 	  
	if (pieces_utiles[5]==1){piecesD= formesPossibles(pd,a);}	if(piecesD.size()>0){ind_type_piece=ind_type_piece+1; vectPieces[ind_type_piece]=piecesD; }
	if (pieces_utiles[6]==1){piecesG= formesPossibles(pg,a);}	if(piecesG.size()>0){ind_type_piece=ind_type_piece+1; vectPieces[ind_type_piece]=piecesG; }
	if (pieces_utiles[7]==1){piecesL= formesPossibles(pl,a);}	if(piecesL.size()>0){ind_type_piece=ind_type_piece+1; vectPieces[ind_type_piece]=piecesL; }
	if (pieces_utiles[8]==1){piecesT= formesPossibles(pt,a);}	if(piecesT.size()>0){ind_type_piece=ind_type_piece+1; vectPieces[ind_type_piece]=piecesT; }


	/* Calcul du nombre de type  pièces finalment disponible à utiliser pour la recherche de solution*/

	int nb_pieces_solution=vectPieces.size();


	/* Calcul du nombre de type de Pieces dont la solution à besoin  */

	int nb_pieces_besoin= a.getNbPiecesBesoins();
	
	if (nb_pieces_solution<nb_pieces_besoin){

		std::cout<<"Pas le solution Possible. Le nombre de pièces utilsées est inferieur au nombre de pieces à utiliser pour resoudre ce probleme"<<std::endl;
	}
	else{
		 if(nb_pieces_solution==nb_pieces_besoin){
			liste_solutions=solution_auxiliaire(vectPieces ,nb_pieces_solution,probleme);	
		}

	}

	return liste_solutions;	
}



int main (int argc, char *argv[]) {


	std::cout << "*************************Test de la classe solution *****************" << std::endl;

	/* Cretaion des problème Poblème */



		/*---------------------Probleme 1: le cas 5*4*2, sans la piece Plus ---------------------------------*/

	int* vect= new int[40];

	for(int i=0;i<40;++i){
		vect[i]=1;

	}

	PieceRepresentation *probleme= new PieceRepresentation(5,4,2,vect);


		/*---------------------Probleme 2: Un cas simple : avec 2 pieces : ( Angle et T)  ou (G & Y) /  @Maxime-----------------------*/


	/*
	int* c = new int[18];
	for (int i = 0; i < 18; ++i) {
		c[i] = -1;
	}
	c[0] = c[1] = c[2] = c[4] = c[7] = c[9] = c[12] = c[15] = c[16] = c[17] = 1;

	PieceRepresentation *probleme = new PieceRepresentation(3, 3, 2, c);

	*/

		/*--------------------- Probleme 9: le cas 5*5*2, avec l'une d'entre elle representrée en negatif-----------------------*/

	/*
	int* c= new int[50];

	for(int i=0;i<50;++i){
		c[i]=1;

	}
	
	c[25]=c[26]=c[27]=c[28]=c[30]=-1;
	PieceRepresentation *probleme= new PieceRepresentation(5,5,2,c);

	probleme->print();
	 */


					/*---------------------Probleme 24: -----------------------*/

	/*
	
	int* c= new int[84];

	for(int i=0;i<42;++i){
		c[i]=1;

	}

	for(int i=42;i<84;++i){
		c[i]=-1;

	}
	
	c[50]=c[52]=c[54]=1;
	PieceRepresentation *probleme= new PieceRepresentation(7,6,2,c);

	probleme->print();	

	*/

				/*************** recherche de Solution Pour un problème defini********************************** */



	/**  Code representant les pieces dans le vecteur  d'utilité des Pièces
		piecesplus -> 0
		piecesangle -> 1
		pieceZ -> 2
		pieceY -> 3
		pieceP ->4
		pieceD ->5
		pieceG -> 6
		pieceL ->7
		pieceT ->8
	 */

	
	int* pieces_utilisation = new int[9];
	for(int i=0;i<9;++i){
		pieces_utilisation[i]=1;
	}

	/**
		Pour les pieces nom utilisées dans la solution, il faut les desactiver dans la recherche de solution
			 : ex: pieces_utilisation[0] desactive la pieces <<plus>>
	*/

	pieces_utilisation[0]=0;
	/** 
	La Piece <plus> est non utilisée . 
	En faire de meme si le probleme tester comporte d'autres et plusieurs pièces nom utilisées
	 */

		
	time_t begin=time(NULL);

	std::vector<Solution*> liste_solutions=recherche_solution(probleme,pieces_utilisation);

	time_t end=time(NULL);

	duree(begin,end);

	std::cout<<" Le nombre de solution trouvées est égal à "<<liste_solutions.size()<< std::endl;

	return 0;
}
