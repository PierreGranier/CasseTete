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
<<<<<<< HEAD
class Solution{
	
	private:
		int x;
		int y;
		int z;
		std::map<std::string,Piece*> listePiece; // ensemble des pièce de la solution	
		PieceRepresentation* representation;  // represention
	
		
	public:
		
		Solution(PieceRepresentation* P)/*: listePiece(0)*/ {
			
			this->x=P->getX();
			this->y=P->getY();
			this->z=P->getX();
			
			int* c = new int[40];
				for (int i = 0; i <40; ++i) {
				c[i] = 0;
			}
			representation=new PieceRepresentation(x,y,z,c);
			
		};

		/*-------------------------- 	Getter et Setter---------------------------------------------------- */
		
		int get_X(){
		  return this->x;
		}
		int get_Y(){
		  return this->y;
		}
		int get_Z(){
		  return this->z;
		}
		

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
				
			
				
=======
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
>>>>>>> 6b2d802b109976c10b96cd351fc6946d618ef48c
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
};
#endif
