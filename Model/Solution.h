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

#include "../Position.h"




/**
	Class Solution: qui represente une solution à une Casse 3D
		
*/
class Solution{
	
	private:
		
		std::map<std::string,Piece*> listePiece; // ensemble des pièce de la solution	
		PieceRepresentation* representation;  // represention
		int nombrePieces; 			// nombre de pieces dans la solution
		
	public:
		
		Solution()/*: listePiece(0)*/ {
	
			int* c = new int[40];
				for (int i = 0; i <40; ++i) {
				c[i] = 0;
			}
			representation=new PieceRepresentation(5,4,2,c);
			nombrePieces=0;
		};



		
		/*-------------------------- 	Getter et Setter---------------------------------------------------- */

		 PieceRepresentation * getRepresentation(){
		
			return representation;
		}


		
		int getNbPiece()     {
			return listePiece.size();
		}

		const std::map<std::string,Piece*>& getListePiece(){
			return listePiece;
		}
		

		/*-----------------Les methodes verification de possibilité d'ajout des pieces  (et leur ajout) si possible dans la Solution------------------ */
		
		/**
			Verifie si l'ajout d'une pièce Angle est possible
		*/

		bool ajoutPiecePossible(PieceAngle* P){
			// recuperation de la Position de rotation de la Piece	
			
			PieceRepresentation *prP= P->rotate(0,0,0);		
			
			int dimX= prP->getX();
			int dimY= prP->getY();
			int dimZ= prP->getZ();

			//Position *posPiece= P->getPosition();
			int posX=P->getPosition().getX();
			int posY=P->getPosition().getY();
			int posZ=P->getPosition().getZ();

			int val_test=1;
			
			int i=0;
			
			if(posX+dimX>representation-> getX() || posY+dimY>representation-> getY() || posZ+dimZ>representation-> getZ()){
				val_test=0;

			}
			else{			

				for(int z=posZ;z<posZ+dimZ;++z){
					for(int x=posX;x<posX+dimX;++x){
						for(int y=posY;y<posY+dimY;++y){
					
							//id=id+1;
							//int idx= ycord*tailleX+xcord
							int idx=z*(representation->getX())*representation->getY() + y*(representation->getX())+x;
							int of=(z-posZ)*(prP->getX())*prP->getY() + (y-posY)*(prP->getX())+(x-posX);
		
							if(representation->getVal()[idx]== 1 && prP->getVal()[of]==1){
						
								val_test=val_test*0;
							}
							else{	
								val_test=val_test*1;	
							}
				
						}
			
					}
			
				}
			}
			bool result;
			if (val_test==1){
				result=true;
			//std::cout<<"ajout de la Piece Angle Possible en ("<< posX << "," <<posY <<"," <<posZ <<")" <<  std::endl;
				
			}
			else{
				result=false;	
			//	std::cout<<"ajout de la Piece Angle non Possible en ("<< posX << "," <<posY <<"," <<posZ <<")" <<  std::endl;		
			}
			
			
			return result;		
		}


		/**
			Ajout de PieceAngle
		*/
		

		void ajoutPiece(PieceAngle* P){

			// recuperation de la Position de rotation de la Piece	
			
			PieceRepresentation *prP= P->rotate(0,0,0);		
			
			int dimX= prP->getX();
			int dimY= prP->getY();
			int dimZ= prP->getZ();

			//Position *posPiece= P->getPosition();
			int posX=P->getPosition().getX();
			int posY=P->getPosition().getY();
			int posZ=P->getPosition().getZ();

			int val_test=1;
			
			int i=0;

			//  Mise à jour de la solution si elle est possible
			if (ajoutPiecePossible(P)==true){
				for(int z=posZ;z<posZ+dimZ;++z){

					for(int x=posX;x<posX+dimX;++x){
						for(int y=posY;y<posY+dimY;++y){
					
						
							//int idx= ycord*tailleX+xcord
							int idx=z*(representation->getX())*representation->getY() + y*(representation->getX())+x;
							int of=(z-posZ)*(prP->getX())*prP->getY() + (y-posY)*(prP->getX())+(x-posX);
							
							//std::cout<<"x="<<x<<"--" <<"y="<<y<<"--"<<"idx="<<idx<< "of"<<prP->getVal()[of]<< std::endl;
							representation->setValue(idx,prP->getVal()[of]);//[idx]=prP->getVal()[id];
						

						}
			
					}
				}
				//std::cout<<"ajout de la Piece Angle dans la solution"<< std::endl;
				//listePiece.push_back(P); 

				Piece* A=P;
				listePiece["PieceAngle"]=A;
			}
				
				
		}

		
		
		/**
			Verifie si l'ajout d'une pièce Z est possible
		*/
		bool ajoutPiecePossible(PieceZ* P){
			// recuperation de la Position de rotation de la Piece	
			
			PieceRepresentation *prP= P->rotate(0,0,0);		
			
			int dimX= prP->getX();
			int dimY= prP->getY();
			int dimZ= prP->getZ();

			//Position *posPiece= P->getPosition();
			int posX=P->getPosition().getX();
			int posY=P->getPosition().getY();
			int posZ=P->getPosition().getZ();

			int val_test=1;
			
			int i=0;
			
			int id=0;
			
			if(posX+dimX>representation-> getX() || posY+dimY>representation-> getY() || posZ+dimZ>representation-> getZ()){
				val_test=0;

			}
			else{			

				for(int z=posZ;z<posZ+dimZ;++z){
					for(int x=posX;x<posX+dimX;++x){
						for(int y=posY;y<posY+dimY;++y){
					
							//id=id+1;
							//int idx= ycord*tailleX+xcord
							int idx=z*(representation->getX())*representation->getY() + y*(representation->getX())+x;
							int of=(z-posZ)*(prP->getX())*prP->getY() + (y-posY)*(prP->getX())+(x-posX);
		
							if(representation->getVal()[idx]== 1 && prP->getVal()[of]==1){
						
								val_test=val_test*0;
							}
							else{	
								val_test=val_test*1;	
							}
				
						}
			
					}
			
				}
			}	
			
			
			bool result;
			if (val_test==1){
				result=true;
			//	std::cout<<"ajout de la Piece Z Possible en ("<< posX << "," <<posY <<"," <<posZ <<")" <<  std::endl;
				
			}
			else{
				result=false;
			//	std::cout<<"ajout de la Piece Z non Possible en ("<< posX << "," <<posY <<"," <<posZ <<")" <<  std::endl;		
			}
			
			
			return result;		
		}
		

		
		/**
			Ajout de Piece Z
		*/

		
		void ajoutPiece(PieceZ* P){

			// recuperation de la Position de rotation de la Piece	
			
			PieceRepresentation *prP= P->rotate(0,0,0);		
			
			int dimX= prP->getX();
			int dimY= prP->getY();
			int dimZ= prP->getZ();

			//Position *posPiece= P->getPosition();
			int posX=P->getPosition().getX();
			int posY=P->getPosition().getY();
			int posZ=P->getPosition().getZ();

			int val_test=1;
			
			int i=0;
			//  Mise à jour de la solution si elle est possible
			if (ajoutPiecePossible(P)==true){
				for(int z=posZ;z<posZ+dimZ;++z){

					for(int x=posX;x<posX+dimX;++x){
						for(int y=posY;y<posY+dimY;++y){
					
						
							//int idx= ycord*tailleX+xcord
							int idx=z*(representation->getX())*representation->getY() + y*(representation->getX())+x;
							int of=(z-posZ)*(prP->getX())*prP->getY() + (y-posY)*(prP->getX())+(x-posX);
							
							//std::cout<<"x="<<x<<"--" <<"y="<<y<<"--"<<"idx="<<idx<< "of"<<prP->getVal()[of]<< std::endl;
							representation->setValue(idx,prP->getVal()[of]);//[idx]=prP->getVal()[id];
						

						}
			
					}
				}
				//std::cout<<"ajout de la Piece Z dans la solution"<< std::endl;
				//listePiece.push_back(P); 

				Piece* A=P;
				listePiece["PieceZ"]=A;
				//listePiece["PieceZ"]=P;
			}
				
			
		}

		
		

		

		/**
			Verifie si l'ajout d'une pièce Y est possible
		*/
		bool ajoutPiecePossible(PieceY* P){
			// recuperation de la Position de rotation de la Piece	
			
			PieceRepresentation *prP= P->rotate(0,0,0);		
			
			int dimX= prP->getX();
			int dimY= prP->getY();
			int dimZ= prP->getZ();

			//Position *posPiece= P->getPosition();
			int posX=P->getPosition().getX();
			int posY=P->getPosition().getY();
			int posZ=P->getPosition().getZ();

			int val_test=1;
			
			int i=0;
			if(posX+dimX>representation-> getX() || posY+dimY>representation-> getY() || posZ+dimZ>representation-> getZ()){
				val_test=0;

			}
			else{			

				for(int z=posZ;z<posZ+dimZ;++z){
					for(int x=posX;x<posX+dimX;++x){
						for(int y=posY;y<posY+dimY;++y){
					
							//id=id+1;
							//int idx= ycord*tailleX+xcord
							int idx=z*(representation->getX())*representation->getY() + y*(representation->getX())+x;
							int of=(z-posZ)*(prP->getX())*prP->getY() + (y-posY)*(prP->getX())+(x-posX);
		
							if(representation->getVal()[idx]== 1 && prP->getVal()[of]==1){
						
								val_test=val_test*0;
							}
							else{	
								val_test=val_test*1;	
							}
				
						}
			
					}
			
				}
			}
			
			bool result;
			if (val_test==1){
				result=true;
			//std::cout<<"ajout de la Piece Y Possible en ("<< posX << "," <<posY <<"," <<posZ <<")" <<  std::endl;
				
			}
			else{
				result=false;	
			//	std::cout<<"ajout de la Piece Y non Possible en ("<< posX << "," <<posY <<"," <<posZ <<")" <<  std::endl;		
			}
			
			
			return result;		
		}


		/**
			Ajout de Piece Y
		*/
		

		void ajoutPiece(PieceY* P){

			// recuperation de la Position de rotation de la Piece	
			
			PieceRepresentation *prP= P->rotate(0,0,0);		
			
			int dimX= prP->getX();
			int dimY= prP->getY();
			int dimZ= prP->getZ();

			//Position *posPiece= P->getPosition();
			int posX=P->getPosition().getX();
			int posY=P->getPosition().getY();
			int posZ=P->getPosition().getZ();

			int val_test=1;
			
			int i=0;

			//  Mise à jour de la solution si elle est possible
			if (ajoutPiecePossible(P)==true){
				for(int z=posZ;z<posZ+dimZ;++z){

					for(int x=posX;x<posX+dimX;++x){
						for(int y=posY;y<posY+dimY;++y){
					
						
							//int idx= ycord*tailleX+xcord
							int idx=z*(representation->getX())*representation->getY() + y*(representation->getX())+x;
							int of=(z-posZ)*(prP->getX())*prP->getY() + (y-posY)*(prP->getX())+(x-posX);
							
							//std::cout<<"x="<<x<<"--" <<"y="<<y<<"--"<<"idx="<<idx<< "of"<<prP->getVal()[of]<< std::endl;
							representation->setValue(idx,prP->getVal()[of]);//[idx]=prP->getVal()[id];
						

						}
			
					}
				}
				//std::cout<<"ajout de la Piece Y dans la solution"<< std::endl;
				//listePiece.push_back(P);
				Piece* A=P; 
				listePiece["PieceY"]=A;
			}
				
			
				
		}

		
		/**
			Verifie si l'ajout d'une pièce P est possible
		*/

		bool ajoutPiecePossible(PieceP* P){
			// recuperation de la Position de rotation de la Piece	
			
			PieceRepresentation *prP= P->rotate(0,0,0);		
			
			int dimX= prP->getX();
			int dimY= prP->getY();
			int dimZ= prP->getZ();

			//Position *posPiece= P->getPosition();
			int posX=P->getPosition().getX();
			int posY=P->getPosition().getY();
			int posZ=P->getPosition().getZ();

			int val_test=1;
			
			int i=0;
			
			if(posX+dimX>representation-> getX() || posY+dimY>representation-> getY() || posZ+dimZ>representation-> getZ()){
				val_test=0;

			}
			else{			

				for(int z=posZ;z<posZ+dimZ;++z){
					for(int x=posX;x<posX+dimX;++x){
						for(int y=posY;y<posY+dimY;++y){
					
							//id=id+1;
							//int idx= ycord*tailleX+xcord
							int idx=z*(representation->getX())*representation->getY() + y*(representation->getX())+x;
							int of=(z-posZ)*(prP->getX())*prP->getY() + (y-posY)*(prP->getX())+(x-posX);
		
							if(representation->getVal()[idx]== 1 && prP->getVal()[of]==1){
						
								val_test=val_test*0;
							}
							else{	
								val_test=val_test*1;	
							}
				
						}
			
					}
			
				}
			}
			bool result;
			if (val_test==1){
				result=true;
			//std::cout<<"ajout de la Piece P Possible en ("<< posX << "," <<posY <<"," <<posZ <<")" <<  std::endl;
				
			}
			else{
				result=false;	
			//	std::cout<<"ajout de la Piece P non Possible en ("<< posX << "," <<posY <<"," <<posZ <<")" <<  std::endl;		
			}
			
			
			return result;		
		}


		/**
			Ajout de PieceP
		*/
		

		void ajoutPiece(PieceP* P){

			// recuperation de la Position de rotation de la Piece	
			
			PieceRepresentation *prP= P->rotate(0,0,0);		
			
			int dimX= prP->getX();
			int dimY= prP->getY();
			int dimZ= prP->getZ();

			//Position *posPiece= P->getPosition();
			int posX=P->getPosition().getX();
			int posY=P->getPosition().getY();
			int posZ=P->getPosition().getZ();

			int val_test=1;
			
			int i=0;

			//  Mise à jour de la solution si elle est possible
			if (ajoutPiecePossible(P)==true){
				for(int z=posZ;z<posZ+dimZ;++z){

					for(int x=posX;x<posX+dimX;++x){
						for(int y=posY;y<posY+dimY;++y){
					
						
							//int idx= ycord*tailleX+xcord
							int idx=z*(representation->getX())*representation->getY() + y*(representation->getX())+x;
							int of=(z-posZ)*(prP->getX())*prP->getY() + (y-posY)*(prP->getX())+(x-posX);
							
							//std::cout<<"x="<<x<<"--" <<"y="<<y<<"--"<<"idx="<<idx<< "of"<<prP->getVal()[of]<< std::endl;
							representation->setValue(idx,prP->getVal()[of]);//[idx]=prP->getVal()[id];
						

						}
			
					}
				}
				//std::cout<<"ajout de la Piece P dans la solution"<< std::endl;
				//listePiece.push_back(P); 
				Piece* A=P;
				listePiece["PieceP"]=A;
			}
				
				
		}

		
		/**
			Verifie si l'ajout d'une pièce D est possible
		*/

		bool ajoutPiecePossible(PieceD* P){
			// recuperation de la Position de rotation de la Piece	
			
			PieceRepresentation *prP= P->rotate(0,0,0);		
			
			int dimX= prP->getX();
			int dimY= prP->getY();
			int dimZ= prP->getZ();

			//Position *posPiece= P->getPosition();
			int posX=P->getPosition().getX();
			int posY=P->getPosition().getY();
			int posZ=P->getPosition().getZ();

			int val_test=1;
			
			int i=0;
			
			if(posX+dimX>representation-> getX() || posY+dimY>representation-> getY() || posZ+dimZ>representation-> getZ()){
				val_test=0;

			}
			else{			

				for(int z=posZ;z<posZ+dimZ;++z){
					for(int x=posX;x<posX+dimX;++x){
						for(int y=posY;y<posY+dimY;++y){
					
							//id=id+1;
							//int idx= ycord*tailleX+xcord
							int idx=z*(representation->getX())*representation->getY() + y*(representation->getX())+x;
							int of=(z-posZ)*(prP->getX())*prP->getY() + (y-posY)*(prP->getX())+(x-posX);
		
							if(representation->getVal()[idx]== 1 && prP->getVal()[of]==1){
						
								val_test=val_test*0;
							}
							else{	
								val_test=val_test*1;	
							}
				
						}
			
					}
			
				}
			}
			bool result;
			if (val_test==1){
				result=true;
			//std::cout<<"ajout de la Piece D Possible en ("<< posX << "," <<posY <<"," <<posZ <<")" <<  std::endl;
				
			}
			else{
				result=false;	
			//	std::cout<<"ajout de la Piece D non Possible en ("<< posX << "," <<posY <<"," <<posZ <<")" <<  std::endl;		
			}
			
			
			return result;		
		}


		/**
			Ajout de PieceD
		*/
		

		void ajoutPiece(PieceD* P){

			// recuperation de la Position de rotation de la Piece	
			
			PieceRepresentation *prP= P->rotate(0,0,0);		
			
			int dimX= prP->getX();
			int dimY= prP->getY();
			int dimZ= prP->getZ();

			//Position *posPiece= P->getPosition();
			int posX=P->getPosition().getX();
			int posY=P->getPosition().getY();
			int posZ=P->getPosition().getZ();

			int val_test=1;
			
			int i=0;

			//  Mise à jour de la solution si elle est possible
			if (ajoutPiecePossible(P)==true){
				for(int z=posZ;z<posZ+dimZ;++z){

					for(int x=posX;x<posX+dimX;++x){
						for(int y=posY;y<posY+dimY;++y){
					
						
							//int idx= ycord*tailleX+xcord
							int idx=z*(representation->getX())*representation->getY() + y*(representation->getX())+x;
							int of=(z-posZ)*(prP->getX())*prP->getY() + (y-posY)*(prP->getX())+(x-posX);
							
							//std::cout<<"x="<<x<<"--" <<"y="<<y<<"--"<<"idx="<<idx<< "of"<<prP->getVal()[of]<< std::endl;
							representation->setValue(idx,prP->getVal()[of]);//[idx]=prP->getVal()[id];
						

						}
			
					}
				}
				//std::cout<<"ajout de la Piece D dans la solution"<< std::endl;
				//listePiece.push_back(P); 
				Piece* A=P;
				listePiece["PieceD"]=A;
			}
				
				
		}

		
		/**
			Verifie si l'ajout d'une pièce G est possible
		*/

		bool ajoutPiecePossible(PieceG* P){
			// recuperation de la Position de rotation de la Piece	
			
			PieceRepresentation *prP= P->rotate(0,0,0);		
			
			int dimX= prP->getX();
			int dimY= prP->getY();
			int dimZ= prP->getZ();

			//Position *posPiece= P->getPosition();
			int posX=P->getPosition().getX();
			int posY=P->getPosition().getY();
			int posZ=P->getPosition().getZ();

			int val_test=1;
			
			int i=0;
			
			if(posX+dimX>representation-> getX() || posY+dimY>representation-> getY() || posZ+dimZ>representation-> getZ()){
				val_test=0;

			}
			else{			

				for(int z=posZ;z<posZ+dimZ;++z){
					for(int x=posX;x<posX+dimX;++x){
						for(int y=posY;y<posY+dimY;++y){
					
							//id=id+1;
							//int idx= ycord*tailleX+xcord
							int idx=z*(representation->getX())*representation->getY() + y*(representation->getX())+x;
							int of=(z-posZ)*(prP->getX())*prP->getY() + (y-posY)*(prP->getX())+(x-posX);
		
							if(representation->getVal()[idx]== 1 && prP->getVal()[of]==1){
						
								val_test=val_test*0;
							}
							else{	
								val_test=val_test*1;	
							}
				
						}
			
					}
			
				}
			}
			bool result;
			if (val_test==1){
				result=true;
			//std::cout<<"ajout de la Piece Angle G en ("<< posX << "," <<posY <<"," <<posZ <<")" <<  std::endl;
				
			}
			else{
				result=false;	
			//	std::cout<<"ajout de la Piece G non Possible en ("<< posX << "," <<posY <<"," <<posZ <<")" <<  std::endl;		
			}
			
			
			return result;		
		}


		/**
			Ajout de PieceG
		*/
		

		void ajoutPiece(PieceG* P){

			// recuperation de la Position de rotation de la Piece	
			
			PieceRepresentation *prP= P->rotate(0,0,0);		
			
			int dimX= prP->getX();
			int dimY= prP->getY();
			int dimZ= prP->getZ();

			//Position *posPiece= P->getPosition();
			int posX=P->getPosition().getX();
			int posY=P->getPosition().getY();
			int posZ=P->getPosition().getZ();

			int val_test=1;
			
			int i=0;

			//  Mise à jour de la solution si elle est possible
			if (ajoutPiecePossible(P)==true){
				for(int z=posZ;z<posZ+dimZ;++z){

					for(int x=posX;x<posX+dimX;++x){
						for(int y=posY;y<posY+dimY;++y){
					
						
							//int idx= ycord*tailleX+xcord
							int idx=z*(representation->getX())*representation->getY() + y*(representation->getX())+x;
							int of=(z-posZ)*(prP->getX())*prP->getY() + (y-posY)*(prP->getX())+(x-posX);
							
							//std::cout<<"x="<<x<<"--" <<"y="<<y<<"--"<<"idx="<<idx<< "of"<<prP->getVal()[of]<< std::endl;
							representation->setValue(idx,prP->getVal()[of]);//[idx]=prP->getVal()[id];
						

						}
			
					}
				}
				//std::cout<<"ajout de la Piece G dans la solution"<< std::endl;
				//listePiece.push_back(P); 
				Piece* A=P;
				listePiece["PieceG"]=A;
			}
				
				
		}

		
		/**
			Verifie si l'ajout d'une pièce L est possible
		*/

		bool ajoutPiecePossible(PieceL* P){
			// recuperation de la Position de rotation de la Piece	
			
			PieceRepresentation *prP= P->rotate(0,0,0);		
			
			int dimX= prP->getX();
			int dimY= prP->getY();
			int dimZ= prP->getZ();

			//Position *posPiece= P->getPosition();
			int posX=P->getPosition().getX();
			int posY=P->getPosition().getY();
			int posZ=P->getPosition().getZ();

			int val_test=1;
			
			int i=0;
			
			if(posX+dimX>representation-> getX() || posY+dimY>representation-> getY() || posZ+dimZ>representation-> getZ()){
				val_test=0;

			}
			else{			

				for(int z=posZ;z<posZ+dimZ;++z){
					for(int x=posX;x<posX+dimX;++x){
						for(int y=posY;y<posY+dimY;++y){
					
							//id=id+1;
							//int idx= ycord*tailleX+xcord
							int idx=z*(representation->getX())*representation->getY() + y*(representation->getX())+x;
							int of=(z-posZ)*(prP->getX())*prP->getY() + (y-posY)*(prP->getX())+(x-posX);
		
							if(representation->getVal()[idx]== 1 && prP->getVal()[of]==1){
						
								val_test=val_test*0;
							}
							else{	
								val_test=val_test*1;	
							}
				
						}
			
					}
			
				}
			}
			bool result;
			if (val_test==1){
				result=true;
			//std::cout<<"ajout de la Piece L Possible en ("<< posX << "," <<posY <<"," <<posZ <<")" <<  std::endl;
				
			}
			else{
				result=false;	
			//	std::cout<<"ajout de la Piece L non Possible en ("<< posX << "," <<posY <<"," <<posZ <<")" <<  std::endl;		
			}
			
			
			return result;		
		}


		/**
			Ajout de PieceL
		*/
		

		void ajoutPiece(PieceL* P){

			// recuperation de la Position de rotation de la Piece	
			
			PieceRepresentation *prP= P->rotate(0,0,0);		
			
			int dimX= prP->getX();
			int dimY= prP->getY();
			int dimZ= prP->getZ();

			//Position *posPiece= P->getPosition();
			int posX=P->getPosition().getX();
			int posY=P->getPosition().getY();
			int posZ=P->getPosition().getZ();

			int val_test=1;
			
			int i=0;

			//  Mise à jour de la solution si elle est possible
			if (ajoutPiecePossible(P)==true){
				for(int z=posZ;z<posZ+dimZ;++z){

					for(int x=posX;x<posX+dimX;++x){
						for(int y=posY;y<posY+dimY;++y){
					
						
							//int idx= ycord*tailleX+xcord
							int idx=z*(representation->getX())*representation->getY() + y*(representation->getX())+x;
							int of=(z-posZ)*(prP->getX())*prP->getY() + (y-posY)*(prP->getX())+(x-posX);
							
							//std::cout<<"x="<<x<<"--" <<"y="<<y<<"--"<<"idx="<<idx<< "of"<<prP->getVal()[of]<< std::endl;
							representation->setValue(idx,prP->getVal()[of]);//[idx]=prP->getVal()[id];
						

						}
			
					}
				}
				std::cout<<"ajout de la Piece L dans la solution"<< std::endl;
				//listePiece.push_back(P);
				Piece* A=P; 
				listePiece["PieceL"]=P;
			}
				
				
		}

		
		/**
			Verifie si l'ajout d'une pièce Plus est possible
		*/

		bool ajoutPiecePossible(PiecePlus* P){
			// recuperation de la Position de rotation de la Piece	
			
			PieceRepresentation *prP= P->rotate(0,0,0);		
			
			int dimX= prP->getX();
			int dimY= prP->getY();
			int dimZ= prP->getZ();

			//Position *posPiece= P->getPosition();
			int posX=P->getPosition().getX();
			int posY=P->getPosition().getY();
			int posZ=P->getPosition().getZ();

			int val_test=1;
			
			int i=0;
			
			if(posX+dimX>representation-> getX() || posY+dimY>representation-> getY() || posZ+dimZ>representation-> getZ()){
				val_test=0;

			}
			else{			

				for(int z=posZ;z<posZ+dimZ;++z){
					for(int x=posX;x<posX+dimX;++x){
						for(int y=posY;y<posY+dimY;++y){
					
							//id=id+1;
							//int idx= ycord*tailleX+xcord
							int idx=z*(representation->getX())*representation->getY() + y*(representation->getX())+x;
							int of=(z-posZ)*(prP->getX())*prP->getY() + (y-posY)*(prP->getX())+(x-posX);
		
							if(representation->getVal()[idx]== 1 && prP->getVal()[of]==1){
						
								val_test=val_test*0;
							}
							else{	
								val_test=val_test*1;	
							}
				
						}
			
					}
			
				}
			}
			bool result;
			if (val_test==1){
				result=true;
			//std::cout<<"ajout de la Piece Plus Possible en ("<< posX << "," <<posY <<"," <<posZ <<")" <<  std::endl;
				
			}
			else{
				result=false;	
				//std::cout<<"ajout de la Piece Plus non Possible en ("<< posX << "," <<posY <<"," <<posZ <<")" <<  std::endl;		
			}
			
			
			return result;		
		}


		/**
			Ajout de PiecePlus
		*/
		

		void ajoutPiece(PiecePlus* P){

			// recuperation de la Position de rotation de la Piece	
			
			PieceRepresentation *prP= P->rotate(0,0,0);		
			
			int dimX= prP->getX();
			int dimY= prP->getY();
			int dimZ= prP->getZ();

			//Position *posPiece= P->getPosition();
			int posX=P->getPosition().getX();
			int posY=P->getPosition().getY();
			int posZ=P->getPosition().getZ();

			int val_test=1;
			
			int i=0;

			//  Mise à jour de la solution si elle est possible
			if (ajoutPiecePossible(P)==true){
				for(int z=posZ;z<posZ+dimZ;++z){

					for(int x=posX;x<posX+dimX;++x){
						for(int y=posY;y<posY+dimY;++y){
					
						
							//int idx= ycord*tailleX+xcord
							int idx=z*(representation->getX())*representation->getY() + y*(representation->getX())+x;
							int of=(z-posZ)*(prP->getX())*prP->getY() + (y-posY)*(prP->getX())+(x-posX);
							
							//std::cout<<"x="<<x<<"--" <<"y="<<y<<"--"<<"idx="<<idx<< "of"<<prP->getVal()[of]<< std::endl;
							representation->setValue(idx,prP->getVal()[of]);//[idx]=prP->getVal()[id];
						

						}
			
					}
				}
				//std::cout<<"ajout de la Piece Plus dans la solution"<< std::endl;
				//listePiece.push_back(P); 
				Piece* A=P;
				listePiece["PiecePlus"]=A;
			}
				
				
		}

		
		/**
			Verifie si l'ajout d'une pièce T est possible
		*/

		bool ajoutPiecePossible(PieceT* P){
			// recuperation de la Position de rotation de la Piece	
			
			PieceRepresentation *prP= P->rotate(0,0,0);		
			
			int dimX= prP->getX();
			int dimY= prP->getY();
			int dimZ= prP->getZ();

			//Position *posPiece= P->getPosition();
			int posX=P->getPosition().getX();
			int posY=P->getPosition().getY();
			int posZ=P->getPosition().getZ();

			int val_test=1;
			
			int i=0;
			
			if(posX+dimX>representation-> getX() || posY+dimY>representation-> getY() || posZ+dimZ>representation-> getZ()){
				val_test=0;

			}
			else{			

				for(int z=posZ;z<posZ+dimZ;++z){
					for(int x=posX;x<posX+dimX;++x){
						for(int y=posY;y<posY+dimY;++y){
					
							//id=id+1;
							//int idx= ycord*tailleX+xcord
							int idx=z*(representation->getX())*representation->getY() + y*(representation->getX())+x;
							int of=(z-posZ)*(prP->getX())*prP->getY() + (y-posY)*(prP->getX())+(x-posX);
		
							if(representation->getVal()[idx]== 1 && prP->getVal()[of]==1){
						
								val_test=val_test*0;
							}
							else{	
								val_test=val_test*1;	
							}
				
						}
			
					}
			
				}
			}
			bool result;
			if (val_test==1){
				result=true;
			//std::cout<<"ajout de la Piece T Possible en ("<< posX << "," <<posY <<"," <<posZ <<")" <<  std::endl;
				
			}
			else{
				result=false;	
			//	std::cout<<"ajout de la Piece T non Possible en ("<< posX << "," <<posY <<"," <<posZ <<")" <<  std::endl;		
			}
			
			
			return result;		
		}


		/**
			Ajout de PieceT
		*/
		

		void ajoutPiece(PieceT* P){

			// recuperation de la Position de rotation de la Piece	
			
			PieceRepresentation *prP= P->rotate(0,0,0);		
			
			int dimX= prP->getX();
			int dimY= prP->getY();
			int dimZ= prP->getZ();

			//Position *posPiece= P->getPosition();
			int posX=P->getPosition().getX();
			int posY=P->getPosition().getY();
			int posZ=P->getPosition().getZ();

			int val_test=1;
			
			int i=0;

			//  Mise à jour de la solution si elle est possible
			if (ajoutPiecePossible(P)==true){
				for(int z=posZ;z<posZ+dimZ;++z){

					for(int x=posX;x<posX+dimX;++x){
						for(int y=posY;y<posY+dimY;++y){
					
						
							//int idx= ycord*tailleX+xcord
							int idx=z*(representation->getX())*representation->getY() + y*(representation->getX())+x;
							int of=(z-posZ)*(prP->getX())*prP->getY() + (y-posY)*(prP->getX())+(x-posX);
							
							//std::cout<<"x="<<x<<"--" <<"y="<<y<<"--"<<"idx="<<idx<< "of"<<prP->getVal()[of]<< std::endl;
							representation->setValue(idx,prP->getVal()[of]);//[idx]=prP->getVal()[id];
						

						}
			
					}
				}
				//std::cout<<"ajout de la Piece T dans la solution"<< std::endl;
				//listePiece.push_back(P); 
				Piece* A=P;
				listePiece["PieceT"]=A;
			}
				
				
		}




		/** Methode de suppression d'un Element dans la Solution:
			Prend un paramère :
				-une chaine de caractère: correspondant au type de la Pièce;
			Supprime une Pièce de la Map si elle existe deja;			 

		*/

		 void suppressionPiece(std::string type_piece){

			std::map<std::string,Piece*>::iterator piece =listePiece.find(type_piece);
		
			if(piece==listePiece.end()){
				//std::cout<<type_piece<< " n'est pas dans la solution" <<std:: endl;			
			}
			else{
				Piece* P=  piece->second; // On recupere la representation de la Piece
				
				listePiece.erase(type_piece); // 1- On supprime la Piece de la MAP

				

				//
				// 1- Suppression de la Solution


				// recuperation de la Position de rotation de la Piece	
			
				PieceRepresentation *prP= P->rotate(0,0,0);		
			
				int dimX= prP->getX();
				int dimY= prP->getY();
				int dimZ= prP->getZ();
				
				

				//Position *posPiece= P->getPosition();
				int posX=P->getPosition().getX();
				int posY=P->getPosition().getY();
				int posZ=P->getPosition().getZ();

				int val_test=1;
			
				int i=0;

				//  Mise à jour de la solution si elle est possible
				for(int z=posZ;z<posZ+dimZ;++z){

					for(int x=posX;x<posX+dimX;++x){
						for(int y=posY;y<posY+dimY;++y){
				
					
							//int idx= ycord*tailleX+xcord
							int idx=z*(representation->getX())*representation->getY() + y*(representation->getX())+x;
							int of=(z-posZ)*(prP->getX())*prP->getY() + (y-posY)*(prP->getX())+(x-posX);
				
							if(prP->getVal()[of]==1){
						
							//std::cout<<"x="<<x<<"--" <<"y="<<y<<"--"<<"idx="<<idx<< "of"<<prP->getVal()[of]<< std::endl;
								representation->setValue(idx,0);//[idx]=prP->getVal()[id];
					
							}
						}
		
					}
				}
				
			//	std::cout<< "Suppression de "<<type_piece<<" de la solution" << std::endl;
			}
			


		} 


		

};
#endif
























