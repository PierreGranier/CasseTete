#ifndef PIECE_H
#define PIECE_H
 
#include "PieceRepresentation.h"
 

 
/* Les coordonnées du point de pivot de la pièce */
//const int PIVOT_X = 1;
//const int PIVOT_Y = 2;
 
class Piece
{
 
private:
    int m_type; // Le type de la pièce
    int m_orientation; // sa rotation courante
 
 
    int m_x; 
    int m_y;
    int m_z;
    
 
public:
    Piece();
    Piece(int type, int orientation);
    Piece(const Piece &p);
 
    void setType(int t){m_type=t;}
    void setOrientation(int o){m_orientation=o;}
 
    int getType(){return m_type;}
    int getOrientation(){return m_orientation;}
 
   
 //getters & setters
 
    void setX(int x){m_x=x;}
    int getX(){return m_x;}
 
    void setY(int y){m_y=y;}
    int getY(){return m_y;}
    
     void setZ(int x){m_z=z;}
    int getZ(){return m_z;}
};
 
#endif
    
    
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
