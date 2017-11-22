#include "PieceRepresentation.h"
#include "PieceAngle.h"
#include "PieceZ.h"
#include "PieceY.h"
#include "PieceP.h"
#include "Piece.h"
#include "Solution.h"
#include <stdlib.h>
#include <map>


#include <list>
#include<string>
#include <iostream> 


/* ensemble de Pieces Angle */
std::map<int,PieceAngle*> ensembleAngle(PieceAngle* pa){

	Solution S;
	PieceRepresentation *prS= S.getRepresentation();
	int nombre_totale=0;
	std::map<int,PieceAngle*> pieces;
	//S.suppressionPiece("PieceAngle");
	for(int i=0; i<prS->getX();++i){ // pour tout les X
		for(int j=0; j<prS->getY(); ++j){ // Pour tous les Y
			for(int k=0;k<prS->getZ(); ++k){ // Pour tous les Z
				for (int rotx=0;rotx<4;++rotx){  // pour tout les rotx
					for (int roty=0;roty<4;++roty){ // pour toute les rotation en y
						for (int rotz=0;rotz<4;++rotz){ // pour toutes les rotation en z
							if ((rotx!=0 && roty==0 && rotz==0) || (rotx==0 && roty!=0 && rotz==0) || (rotx==0 && roty==0 && rotz!=0) || (rotx==0 && roty==0 && rotz==0) ){
								Position posI(i,j,k);
								pa->setPosition(posI); // Modification de la position
											// modification de la rotation
								//pa->rotate(rotx,roty,rotz);
								PieceRepresentation* p=pa->rotate(rotx,roty,rotz);
								pa->setRepresentation(p);
								if(S.ajoutPiecePossible(pa)==true){
									nombre_totale=nombre_totale+1;
									//S.ajoutPiece(pa);
									//Piece* pi=pa;
									pieces[nombre_totale]=pa; // ajout de la piece paI dans la liste de solution
									//std::cout <<"Etat de la solution "<<std::endl;
									//prS->print();
									//S.suppressionPiece("PieceAngle");
								}
							}
						pa= new PieceAngle();	
						}
					}
				}
			}
				
		}
	}
	return pieces;
}

/* ensemble de Pieces Z */
std::map<int,PieceZ*> ensembleAngle(PieceZ* pa){

	Solution S;
	PieceRepresentation *prS= S.getRepresentation();
	int nombre_totale=0;
	std::map<int,PieceZ*> pieces;
	//S.suppressionPiece("PieceAngle");
	for(int i=0; i<prS->getX();++i){ // pour tout les X
		for(int j=0; j<prS->getY(); ++j){ // Pour tous les Y
			for(int k=0;k<prS->getZ(); ++k){ // Pour tous les Z
				for (int rotx=0;rotx<4;++rotx){  // pour tout les rotx
					for (int roty=0;roty<4;++roty){ // pour toute les rotation en y
						for (int rotz=0;rotz<4;++rotz){ // pour toutes les rotation en z
							if ((rotx!=0 && roty==0 && rotz==0) || (rotx==0 && roty!=0 && rotz==0) || (rotx==0 && roty==0 && rotz!=0) || (rotx==0 && roty==0 && rotz==0) ){
								Position posI(i,j,k);
								pa->setPosition(posI); // Modification de la position
											// modification de la rotation
								//pa->rotate(rotx,roty,rotz);
								PieceRepresentation* p=pa->rotate(rotx,roty,rotz);
								pa->setRepresentation(p);
								if(S.ajoutPiecePossible(pa)==true){
									nombre_totale=nombre_totale+1;
									//S.ajoutPiece(pa);
									//Piece* pi=pa;
									pieces[nombre_totale]=pa; // ajout de la piece paI dans la liste de solution
									//std::cout <<"Etat de la solution "<<std::endl;
									//prS->print();
									//S.suppressionPiece("PieceAngle");
								}
							}
						pa= new PieceZ();	
						}
					}
				}
			}
				
		}
	}
	return pieces;
}

/* ensemble de Pieces Y */
std::map<int,PieceY*> ensembleAngle(PieceY* pa){

	Solution S;
	PieceRepresentation *prS= S.getRepresentation();
	int nombre_totale=0;
	std::map<int,PieceY*> pieces;
	//S.suppressionPiece("PieceAngle");
	for(int i=0; i<prS->getX();++i){ // pour tout les X
		for(int j=0; j<prS->getY(); ++j){ // Pour tous les Y
			for(int k=0;k<prS->getZ(); ++k){ // Pour tous les Z
				for (int rotx=0;rotx<4;++rotx){  // pour tout les rotx
					for (int roty=0;roty<4;++roty){ // pour toute les rotation en y
						for (int rotz=0;rotz<4;++rotz){ // pour toutes les rotation en z
							if ((rotx!=0 && roty==0 && rotz==0) || (rotx==0 && roty!=0 && rotz==0) || (rotx==0 && roty==0 && rotz!=0) || (rotx==0 && roty==0 && rotz==0) ){
								Position posI(i,j,k);
								pa->setPosition(posI); // Modification de la position
											// modification de la rotation
								//pa->rotate(rotx,roty,rotz);
								PieceRepresentation* p=pa->rotate(rotx,roty,rotz);
								pa->setRepresentation(p);
								if(S.ajoutPiecePossible(pa)==true){
									nombre_totale=nombre_totale+1;
									//S.ajoutPiece(pa);
									//Piece* pi=pa;
									pieces[nombre_totale]=pa; // ajout de la piece paI dans la liste de solution
									//std::cout <<"Etat de la solution "<<std::endl;
									//prS->print();
									//S.suppressionPiece("PieceAngle");
								}
							}
						pa= new PieceY();	
						}
					}
				}
			}
				
		}
	}
	return pieces;
}

/* ensemble de Pieces P */
std::map<int,PieceP*> ensembleAngle(PieceP* pa){

	Solution S;
	PieceRepresentation *prS= S.getRepresentation();
	int nombre_totale=0;
	std::map<int,PieceP*> pieces;
	//S.suppressionPiece("PieceAngle");
	for(int i=0; i<prS->getX();++i){ // pour tout les X
		for(int j=0; j<prS->getY(); ++j){ // Pour tous les Y
			for(int k=0;k<prS->getZ(); ++k){ // Pour tous les Z
				for (int rotx=0;rotx<4;++rotx){  // pour tout les rotx
					for (int roty=0;roty<4;++roty){ // pour toute les rotation en y
						for (int rotz=0;rotz<4;++rotz){ // pour toutes les rotation en z
							if ((rotx!=0 && roty==0 && rotz==0) || (rotx==0 && roty!=0 && rotz==0) || (rotx==0 && roty==0 && rotz!=0) || (rotx==0 && roty==0 && rotz==0) ){
								Position posI(i,j,k);
								pa->setPosition(posI); // Modification de la position
											// modification de la rotation
								//pa->rotate(rotx,roty,rotz);
								PieceRepresentation* p=pa->rotate(rotx,roty,rotz);
								pa->setRepresentation(p);
								if(S.ajoutPiecePossible(pa)==true){
									nombre_totale=nombre_totale+1;
									//S.ajoutPiece(pa);
									//Piece* pi=pa;
									pieces[nombre_totale]=pa; // ajout de la piece paI dans la liste de solution
									//std::cout <<"Etat de la solution "<<std::endl;
									//prS->print();
									//S.suppressionPiece("PieceAngle");
								}
							}
						pa= new PieceP();	
						}
					}
				}
			}
				
		}
	}
	return pieces;
}

/* ensemble de Pieces D */
std::map<int,PieceD*> ensembleAngle(PieceD* pa){

	Solution S;
	PieceRepresentation *prS= S.getRepresentation();
	int nombre_totale=0;
	std::map<int,PieceD*> pieces;
	//S.suppressionPiece("PieceAngle");
	for(int i=0; i<prS->getX();++i){ // pour tout les X
		for(int j=0; j<prS->getY(); ++j){ // Pour tous les Y
			for(int k=0;k<prS->getZ(); ++k){ // Pour tous les Z
				for (int rotx=0;rotx<4;++rotx){  // pour tout les rotx
					for (int roty=0;roty<4;++roty){ // pour toute les rotation en y
						for (int rotz=0;rotz<4;++rotz){ // pour toutes les rotation en z
							if ((rotx!=0 && roty==0 && rotz==0) || (rotx==0 && roty!=0 && rotz==0) || (rotx==0 && roty==0 && rotz!=0) || (rotx==0 && roty==0 && rotz==0) ){
								Position posI(i,j,k);
								pa->setPosition(posI); // Modification de la position
											// modification de la rotation
								//pa->rotate(rotx,roty,rotz);
								PieceRepresentation* p=pa->rotate(rotx,roty,rotz);
								pa->setRepresentation(p);
								if(S.ajoutPiecePossible(pa)==true){
									nombre_totale=nombre_totale+1;
									//S.ajoutPiece(pa);
									//Piece* pi=pa;
									pieces[nombre_totale]=pa; // ajout de la piece paI dans la liste de solution
									//std::cout <<"Etat de la solution "<<std::endl;
									//prS->print();
									//S.suppressionPiece("PieceAngle");
								}
							}
						pa= new PieceD();	
						}
					}
				}
			}
				
		}
	}
	return pieces;
}

/* ensemble de Pieces G */
std::map<int,PieceG*> ensembleAngle(PieceG* pa){

	Solution S;
	PieceRepresentation *prS= S.getRepresentation();
	int nombre_totale=0;
	std::map<int,PieceG*> pieces;
	//S.suppressionPiece("PieceAngle");
	for(int i=0; i<prS->getX();++i){ // pour tout les X
		for(int j=0; j<prS->getY(); ++j){ // Pour tous les Y
			for(int k=0;k<prS->getZ(); ++k){ // Pour tous les Z
				for (int rotx=0;rotx<4;++rotx){  // pour tout les rotx
					for (int roty=0;roty<4;++roty){ // pour toute les rotation en y
						for (int rotz=0;rotz<4;++rotz){ // pour toutes les rotation en z
							if ((rotx!=0 && roty==0 && rotz==0) || (rotx==0 && roty!=0 && rotz==0) || (rotx==0 && roty==0 && rotz!=0) || (rotx==0 && roty==0 && rotz==0) ){
								Position posI(i,j,k);
								pa->setPosition(posI); // Modification de la position
											// modification de la rotation
								//pa->rotate(rotx,roty,rotz);
								PieceRepresentation* p=pa->rotate(rotx,roty,rotz);
								pa->setRepresentation(p);
								if(S.ajoutPiecePossible(pa)==true){
									nombre_totale=nombre_totale+1;
									//S.ajoutPiece(pa);
									//Piece* pi=pa;
									pieces[nombre_totale]=pa; // ajout de la piece paI dans la liste de solution
									//std::cout <<"Etat de la solution "<<std::endl;
									//prS->print();
									//S.suppressionPiece("PieceAngle");
								}
							}
						pa= new PieceG();	
						}
					}
				}
			}
				
		}
	}
	return pieces;
}

/* ensemble de Pieces L */
std::map<int,PieceL*> ensembleAngle(PieceL* pa){

	Solution S;
	PieceRepresentation *prS= S.getRepresentation();
	int nombre_totale=0;
	std::map<int,PieceL*> pieces;
	//S.suppressionPiece("PieceAngle");
	for(int i=0; i<prS->getX();++i){ // pour tout les X
		for(int j=0; j<prS->getY(); ++j){ // Pour tous les Y
			for(int k=0;k<prS->getZ(); ++k){ // Pour tous les Z
				for (int rotx=0;rotx<4;++rotx){  // pour tout les rotx
					for (int roty=0;roty<4;++roty){ // pour toute les rotation en y
						for (int rotz=0;rotz<4;++rotz){ // pour toutes les rotation en z
							if ((rotx!=0 && roty==0 && rotz==0) || (rotx==0 && roty!=0 && rotz==0) || (rotx==0 && roty==0 && rotz!=0) || (rotx==0 && roty==0 && rotz==0) ){
								Position posI(i,j,k);
								pa->setPosition(posI); // Modification de la position
											// modification de la rotation
								//pa->rotate(rotx,roty,rotz);
								PieceRepresentation* p=pa->rotate(rotx,roty,rotz);
								pa->setRepresentation(p);
								if(S.ajoutPiecePossible(pa)==true){
									nombre_totale=nombre_totale+1;
									//S.ajoutPiece(pa);
									//Piece* pi=pa;
									pieces[nombre_totale]=pa; // ajout de la piece paI dans la liste de solution
									//std::cout <<"Etat de la solution "<<std::endl;
									//prS->print();
									//S.suppressionPiece("PieceAngle");
								}
							}
						pa= new PieceL();	
						}
					}
				}
			}
				
		}
	}
	return pieces;
}

/* ensemble de Pieces T */
std::map<int,PieceT*> ensembleAngle(PieceT* pa){

	Solution S;
	PieceRepresentation *prS= S.getRepresentation();
	int nombre_totale=0;
	std::map<int,PieceT*> pieces;
	//S.suppressionPiece("PieceAngle");
	for(int i=0; i<prS->getX();++i){ // pour tout les X
		for(int j=0; j<prS->getY(); ++j){ // Pour tous les Y
			for(int k=0;k<prS->getZ(); ++k){ // Pour tous les Z
				for (int rotx=0;rotx<4;++rotx){  // pour tout les rotx
					for (int roty=0;roty<4;++roty){ // pour toute les rotation en y
						for (int rotz=0;rotz<4;++rotz){ // pour toutes les rotation en z
							if ((rotx!=0 && roty==0 && rotz==0) || (rotx==0 && roty!=0 && rotz==0) || (rotx==0 && roty==0 && rotz!=0) || (rotx==0 && roty==0 && rotz==0) ){
								Position posI(i,j,k);
								pa->setPosition(posI); // Modification de la position
											// modification de la rotation
								//pa->rotate(rotx,roty,rotz);
								PieceRepresentation* p=pa->rotate(rotx,roty,rotz);
								pa->setRepresentation(p);
								if(S.ajoutPiecePossible(pa)==true){
									nombre_totale=nombre_totale+1;
									//S.ajoutPiece(pa);
									//Piece* pi=pa;
									pieces[nombre_totale]=pa; // ajout de la piece paI dans la liste de solution
									//std::cout <<"Etat de la solution "<<std::endl;
									//prS->print();
									//S.suppressionPiece("PieceAngle");
								}
							}
						pa= new PieceT();	
						}
					}
				}
			}
				
		}
	}
	return pieces;
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
<<<<<<< HEAD

	std::cout << "Rotations de la piece" << std::endl;
	PiecePlus PL;
	for (int x = 0; x < 4; ++x) {
		for (int y = 0; y < 4; ++y) {
			for (int z = 0; z < 4; ++z) {
				PieceRepresentation* pr = PL.rotate(x, y, z);
			}
		}
	}
				
/*std::cout << "Rotations de la piece" << std::endl;
=======
	/*std::cout << "Rotations de la piece" << std::endl;
>>>>>>> 097a5adfc27e8e02079b71cfabc70d0824e9f0c3
	
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
		/*
	
	std::cout << "*************************Test d'egalité entre deux piece *****************" << std::endl;
	
	PieceAngle pieceAngleA;
	PieceAngle pieceAngleB;	
	PieceRepresentation *prb = pieceAngleB.rotate(0, 0, 0);
	PieceRepresentation *pra = pieceAngleA.rotate(0, 0, 0);
	bool result_test= pra->equals(prb);
	std::cout << " resulat du test d'egalité :"<< result_test <<std::endl; */

	std::cout << "*************************Test de la classe solution *****************" << std::endl;

	std::map<std::string,Piece*> pp;


	// test 2 de la  Classe Solution
	
	Solution S;
	PieceRepresentation *prS= S.getRepresentation();
	std::cout <<"Etat de la solution "<<std::endl;
	prS->print();
	
	std::cout <<"nombre de pieces dans la solution "<<S.getNbPiece() <<std::endl;
	//PieceAngle *pa=new PieceAngle();
	
	PieceAngle *pa=new PieceAngle();
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
	
	//Position pos3(1,0,0);
	//pz->setPosition(pos3);
	std::cout <<"Piece à rajouter "<<std::endl;
	pz->print();

	S.ajoutPiece(pz);
	std::cout <<"Etat de la solution "<<std::endl;
	prS->print();
	
	std::cout <<"nombre de pieces dans la solution "<<S.getNbPiece() <<std::endl;

	
	S.suppressionPiece("PieceZ");
	std::cout <<"Etat de la solution "<<std::endl;
	prS->print();

	std::cout <<"nombre de pieces dans la solution "<<S.getNbPiece() <<std::endl; 

	/*
	
	PieceAngle *pa=new PieceAngle();
	std::map<int,PieceAngle*> pieces= ensembleAngle(pa);
	//std::cout <<"taille Angle= "<<pieces.size()<<std::endl;

	PieceZ *pz=new PieceZ();
	std::map<int,PieceZ*> piecesZ= ensembleAngle(pz);
	//std::cout <<"taille Z= "<<piecesZ.size()<<std::endl;

	PieceY *py=new PieceY();
	std::map<int,PieceY*> piecesY= ensembleAngle(py);
	//std::cout <<"taille Y= "<<piecesY.size()<<std::endl; 


	PieceP *ppp=new PieceP();
	std::map<int,PieceP*> piecesP= ensembleAngle(ppp);
	//std::cout <<"taille P= "<<piecesP.size()<<std::endl;

	PieceG *pg=new PieceG();
	std::map<int,PieceG*> piecesG= ensembleAngle(pg);
	//std::cout <<"taille G= "<<piecesG.size()<<std::endl;

	PieceD *pd=new PieceD();
	std::map<int,PieceD*> piecesD= ensembleAngle(pd);
	//std::cout <<"taille D= "<<piecesD.size()<<std::endl;

	
	PieceT *pt=new PieceT();
	std::map<int,PieceT*> piecesT= ensembleAngle(pt);
	//std::cout <<"taille T= "<<piecesT.size()<<std::endl;

	PieceL *pl=new PieceL();
	std::map<int,PieceL*> piecesL= ensembleAngle(pl);
	//std::cout <<"taille L= "<<piecesL.size()<<std::endl;
	*/

	std::map<int,Solution*> ensembleSol;

	//boucle des combinaisons

	/*

	for(int angle=1;angle<(pieces.size()+1);++angle){
		for(int z=1;z<piecesZ.size()+1;++z){
			for(int y=1;y<piecesY.size()+1;++y){
				for(int p=1;p<piecesP.size()+1;++p){
					for(int d=1;d<piecesD.size()+1;++d){
						for(int g=1;g<piecesG.size()+1;++g){
							for(int l=1;l<piecesL.size()+1;++l){
								for(int t=1;t<piecesT.size()+1;++t){
								
									Solution* S=new Solution();
									//Piece * p=pieces.find(angle)->second;
									 S->ajoutPiece(pieces.find(angle)->second);
									 S->ajoutPiece(piecesZ.find(z)->second);
									 S->ajoutPiece(piecesY.find(y)->second);
								 	 S->ajoutPiece(piecesP.find(p)->second);
									 S->ajoutPiece(piecesD.find(d)->second);
									 S->ajoutPiece(piecesG.find(g)->second);
									 S->ajoutPiece(piecesL.find(l)->second);
									 S->ajoutPiece(piecesT.find(t)->second);	
								
									if (S->getNbPiece()==8){
										ensembleSol[1]=S;				
									}
	
								}
	
							}
	
						}
	
					}
				
	
				}
	
			}
		
	
		}
		
	
	} */


	//*   Avec BOUCLE While
	
	/*
	bool ok =false;
	int angle=1;
	int compteur=0;
	while(angle<(pieces.size()+1) && ok==false){
		int z=1;
		while(z<piecesZ.size()+1 && ok==false){
			int y=1;
			while(y<piecesY.size()+1 && ok==false){
				int p=1;
				while(p<piecesP.size()+1 && ok==false){
					int d=1;
					while(d<piecesD.size()+1 && ok==false){
						int g=1;
						while(g<piecesG.size()+1 && ok==false){
							int l=1;
							while(l<piecesL.size()+1 && ok==false){
								int t=1;
								while(t<piecesT.size()+1 && ok==false){
									compteur=compteur+1;			
									Solution* S=new Solution();
									std::cout <<angle<<"-"<<z<<"-"<<y<<"-"<<p<<"-"<<d<<"-"<<g<<"-"<<l<<"-"<<t <<std::endl;
									if (S->ajoutPiecePossible(pieces.find(angle)->second)==true){S->ajoutPiece(pieces.find(angle)->second);
										if(S->ajoutPiecePossible(piecesZ.find(z)->second)==true){ S->ajoutPiece(piecesZ.find(z)->second);			
											if(S->ajoutPiecePossible(piecesY.find(y)->second)==true){ S->ajoutPiece(piecesY.find(y)->second);
												if(S->ajoutPiecePossible(piecesP.find(p)->second)==true){S->ajoutPiece(piecesP.find(p)->second);
													if(S->ajoutPiecePossible(piecesD.find(d)->second)==true){ S->ajoutPiece(piecesD.find(d)->second);
														if(S->ajoutPiecePossible(piecesG.find(g)->second)==true){S->ajoutPiece(piecesG.find(g)->second);
														if(S->ajoutPiecePossible(piecesL.find(l)->second)==true){
															S->ajoutPiece(piecesL.find(l)->second);
															S->ajoutPiece(piecesT.find(t)->second);}
																
														}
													}
												}
												
											}
											
										}
										
									}
									

									
									// S->ajoutPiece(piecesZ.find(z)->second);
									// S->ajoutPiece(piecesY.find(y)->second);
								 	// S->ajoutPiece(piecesP.find(p)->second);
									// S->ajoutPiece(piecesD.find(d)->second);
									// S->ajoutPiece(piecesG.find(g)->second);
									// S->ajoutPiece(piecesL.find(l)->second);
									// S->ajoutPiece(piecesT.find(t)->second);
									std::cout <<"taille solution="<< S->getNbPiece()<<std::endl;
									if (S->getNbPiece()==8){
										ensembleSol[1]=S;
										
										ok=true;
									   std::cout <<"TROUVE "<<std::endl;
																	
									}
									delete S;
									t=t+1;
								}
							l=l+1;
							}
						g=g+1;
						}
					d=d+1;
					}
				
				p=p+1;
				}
			y=y+1;
			}
		
			z=z+1;
		}
		
	angle=angle+1;
	} 


	std::cout <<"nombre de Solution= "<<ensembleSol.size()<<std::endl; */

	return 0;


	
}
