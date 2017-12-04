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

=======
class Solution{
	
	private:
		
		std::map<int,Piece*> listePiece; // ensemble des pièces de la solution	
		PieceRepresentation* representation;  // representation
		int nombrePieces; 			// nombre de pieces dans la solution
		
		
	public:
		/**
			Le contructeur de la classe prend en paramètre le problme à resoudre qui est de type "PieceRepresentation"
		*/

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


			
>>>>>>> 0d7a734730bcfd8c0e2df9821285282b9dd58785
		}
	

		/* Solution */
		Solution(Solution* source){
			representation=source->getRepresentation();
			nombrePieces=source->getNbPiece();
			listePiece=source->getListePiece();	
		}

		
		/*-------------------------- 	Getters et Setters---------------------------------------------------- */

		 PieceRepresentation * getRepresentation(){
		
			return representation;
		}


		
		int getNbPiece() {
			return listePiece.size();
		}

		const std::map<int,Piece*>& getListePiece(){
			return listePiece;
		}

		
		/* renvoie le  nombre de pièces à utiliser pour resoudre le problème */
		int getNbPiecesBesoins(){
			int cpt=0;
			int taille_solutions= representation->getSize();
			for (int i=0; i<taille_solutions; ++i){
				if (representation->getValue(i)==0){
					cpt=cpt+1;	
				}
			}

		return (cpt/5);
		}
		
		


		/**
			Verifie si l'ajout d'une pièce dans la solution est possible
		*/

		bool ajoutPiecePossible(Piece* P){
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
					
							int idx=z*(representation->getX())*representation->getY() + y*(representation->getX())+x;
							int of=(z-posZ)*(prP->getX())*prP->getY() + (y-posY)*(prP->getX())+(x-posX);
		
							if ( (representation->getValue(idx)== 1 ||representation->getValue(idx)== -1)  && prP->getValue(of)==1 ){
						
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
			}
			else{
				result=false;			
			}
			
			
			return result;		
		}




		/**
			Methode d'ahout d'une Piece dans la solution;
		*/
		
		
		void ajoutPiece(Piece* P){

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
			//if (ajoutPiecePossible(P)==true){
				for(int z=posZ;z<posZ+dimZ;++z){

					for(int x=posX;x<posX+dimX;++x){
						for(int y=posY;y<posY+dimY;++y){
					
						
							//int idx= ycord*tailleX+xcord
							int idx=z*(representation->getX())*representation->getY() + y*(representation->getX())+x;
							int of=(z-posZ)*(prP->getX())*prP->getY() + (y-posY)*(prP->getX())+(x-posX);
							
							//std::cout<<"x="<<x<<"--" <<"y="<<y<<"--"<<"idx="<<idx<< "of"<<prP->getVal()[of]<< std::endl;
							if (prP->getValue(of)==1 && representation->getValue(idx)!=-1 ){
							representation->setValue(x,y,z,prP->getValue(of));} // à verifier
							
						
						}
			
					}
				}
				//std::cout<<"ajout de la Piece T dans la solution"<< std::endl;
				//listePiece.push_back(P); 
				int type= P->getType();
				listePiece[type]=P;

		}




		/** Methode de suppression d'un Element dans la Solution:
			Prend un paramère :
				-une chaine de caractère: correspondant au type de la Pièce;
			Supprime une Pièce de la Map si elle existe deja;			 

		*/

		 void suppressionPiece(int type_piece){

			std::map<int,Piece*>::iterator piece =listePiece.find(type_piece);
		
			if(piece==listePiece.end()){
				//std::cout<<type_piece<< " n'est pas dans la solution" <<std:: endl;			
			}
			else{
				Piece* P=  piece->second; 
				listePiece.erase(type_piece); // 1- On supprime la Piece de la MAP

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
				
							if(prP->getValue(of)==1){

								representation->setValue(x,y,z,0);//[idx]=prP->getVal()[id];
							}
						}
		
					}
				}

			}

		} 


		/* Affichage de la solution */

		void print(){
			representation->print();
		}

		

};
#endif



