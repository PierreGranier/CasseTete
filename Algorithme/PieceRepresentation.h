#ifndef PIECEREPRENSENTATION_H
#define PIECEREPRENSENTATION_H



class PieceRepresentation {

    int m_x; 
    int m_y;
    int m_z;
    int m_vecteur[];
    
 
public:
   
    PieceRepresentation(int x, int y, int z, int *vect);
    PieceRepresentation(const PieceRepresentation &);

 

   
 //getters & setters
 
    void setX(int x){m_x=x;}
    int getX(){return m_x;}
 
    void setY(int y){m_y=y;}
    int getY(){return m_y;}
    
     void setZ(int x){m_z=z;}
    int getZ(){return m_z;}
};
 
#endif
    
    
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
        
    }
};
 
#endif
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
    
  int getValue(int x,int y,int z);
  void setValue(int x, int y,int z,int val);
  // getPieceRepresentation();
  PieceRepresentation rotateX();
  PieceRepresentation rotateY();
  PieceRepresentation rotateZ();
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
};

#endif
