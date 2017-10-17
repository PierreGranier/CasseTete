#ifndef PIECEREPRENSENTATION_H
#define PIECEREPRENSENTATION_H

#include<iostream>
#include <string>
#include<math.h>
#include<algorithm>



class PieceRepresentation {

  
private:
    int m_x; 
    int m_y;
    int m_z;
    int m_vecteur[];
    
protected:    
    int matrice_x[][4];//la matrice de rotation selon l'axe X.
    int matrice_y[][4];//la matrice de rotation selon l'axe Y.
    int matrice_z[][4];//la matrice de rotation selon l'axe Z.
    int teta;//l'angle de rotation de la pièce.
    
 
public:
    
   PieceRepresentation();
   
    PieceRepresentation(int x, int y, int z, int *vect);
    PieceRepresentation(const PieceRepresentation &);
   
    PieceRepresentation(int *tab)
        {
            for(int i=0;i<sizeof(m_vecteur);i++)
           m_vecteur[i] = tab[i];
        }
      
        void affiche()
        {
	  for(int i=0;i<sizeof(m_vecteur);i++)
           // std::cout<<"("<<m_vecteur[0]<<","<<m_vecteur[1]<<","<<m_vecteur[2]<<")"<<std::endl;
	    std::cout<<m_vecteur[i]<<std::endl;
        }
        

        

 

   
 //getters & setters
 
    void setX(int x){m_x=x;}
    int getX(){return m_x;}
 
    void setY(int y){m_y=y;}
    int getY(){return m_y;}
    
     void setZ(int z){m_z=z;}
    int getZ(){return m_z;}


   
    
  int getValue(int x,int y,int z);
  void setValue(int x, int y,int z,int val);
  // getPieceRepresentation();
  
  PieceRepresentation rotateX();
  PieceRepresentation rotateY();
  PieceRepresentation rotateZ();
  
  



  
  
  

  
  
  
   
};

#endif