#ifndef SOLUTON_H
#define SOLUTION_H

#include "PieceRepresentation.h"
#include "PieceAngle.h"
#include "PieceZ.h"
#include "PieceY.h"
#include "PieceP.h"
#include "Piece.h"

#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>

#include <vector>
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
		
		std::vector<Piece*> listePiece; // ensemble des pièce de la solutio	
		PieceRepresentation* representation;  // represention
		int nombrePieces; 			// nombre de pieces dans la solution
		
	public:
		
		Solution(): listePiece(0) {
	
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


		int getNbPiece(){
			return listePiece.size();
		}

		const std::vector<Piece*>& getListePiece(){
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
			std::cout<<"ajout de la Piece Angle Possible en ("<< posX << "," <<posY <<"," <<posZ <<")" <<  std::endl;
				
			}
			else{
				result=false;	
				std::cout<<"ajout de la Piece Angle non Possible en ("<< posX << "," <<posY <<"," <<posZ <<")" <<  std::endl;		
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
				std::cout<<"ajout de la Piece Angle dans la solution"<< std::endl;
				listePiece.push_back(P);
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
				std::cout<<"ajout de la Piece Z Possible en ("<< posX << "," <<posY <<"," <<posZ <<")" <<  std::endl;
				
			}
			else{
				result=false;
				std::cout<<"ajout de la Piece Z non Possible en ("<< posX << "," <<posY <<"," <<posZ <<")" <<  std::endl;		
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
				std::cout<<"ajout de la Piece Z dans la solution"<< std::endl;
				listePiece.push_back(P);
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
			std::cout<<"ajout de la Piece Y Possible en ("<< posX << "," <<posY <<"," <<posZ <<")" <<  std::endl;
				
			}
			else{
				result=false;	
				std::cout<<"ajout de la Piece Y non Possible en ("<< posX << "," <<posY <<"," <<posZ <<")" <<  std::endl;		
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
				std::cout<<"ajout de la Piece Y dans la solution"<< std::endl;
				listePiece.push_back(P);
			}
				
			
				
		}
		
		

};
#endif
























