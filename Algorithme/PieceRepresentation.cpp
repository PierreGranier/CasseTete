#include "PieceRepresentation.h"


PieceRepresentation::PieceRepresentation()
{

}


PieceRepresentation::PieceRepresentation(int x, int y, int z,int *vect):m_x(x),m_y(y),m_z(z){
for(int i(0); i<sizeof(vect); ++i)

{

  m_vecteur[i]=vect[i];

}
}


PieceRepresentation::PieceRepresentation(const PieceRepresentation &p)
{
    m_x = p.m_x;
    m_y = p.m_y;
    m_z = p.m_z;

for(int i(0); i<sizeof(p.m_vecteur); ++i)

{

  m_vecteur[i]=p.m_vecteur[i];

}
}


PieceRepresentation PieceRepresentation::rotateX()
{




    for(int i=0;i<4;i++)
    {
        for(int j=0;j<sizeof(m_vecteur);j++){
	  
	  
   matrice_x[1][1]=1;
   matrice_x[1][2]=0;
   matrice_x[1][3]=0;
   matrice_x[1][4]=0;
   
   matrice_x[2][1]=0;
   matrice_x[2][2]=cos(teta);
   matrice_x[2][3]=sin(teta);
   matrice_x[2][4]=0;
   
   matrice_x[3][1]=0;
   matrice_x[3][2]=-sin(teta);
   matrice_x[3][3]=cos(teta);
   matrice_x[3][4]=0;
   
   matrice_x[4][1]=0;
   matrice_x[4][2]=0;
   matrice_x[4][3]=0;
   matrice_x[4][4]=1; 
   
   
           m_vecteur[i] += matrice_x[i][j] * m_vecteur[j];
        }
    }
    return *this;
}


PieceRepresentation PieceRepresentation::rotateY()
{
  
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<sizeof(m_vecteur);j++){
	  
	  
   matrice_y[1][1]=cos(teta);
   matrice_y[1][2]=0;
   matrice_y[1][3]=-sin(teta);
   matrice_y[1][4]=0;
   
   matrice_y[2][1]=0;
   matrice_y[2][2]=1;
   matrice_y[2][3]=0;
   matrice_y[2][4]=0;
   
   matrice_y[3][1]=sin(teta);
   matrice_y[3][2]=0;
   matrice_y[3][3]=cos(teta);
   matrice_y[3][4]=0;
   
   matrice_y[4][1]=0;
   matrice_y[4][2]=0;
   matrice_y[4][3]=0;
   matrice_y[4][4]=1; 
   
   
           m_vecteur[i] += matrice_y[i][j] * m_vecteur[j];
        }
    }
    return *this;

}

PieceRepresentation PieceRepresentation::rotateZ()
{

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<sizeof(m_vecteur);j++){
	  
	  
   matrice_z[1][1]=cos(teta);
   matrice_z[1][2]=sin(teta);
   matrice_z[1][3]=0;
   matrice_z[1][4]=0;
   
   matrice_z[2][1]=-sin(teta);
   matrice_z[2][2]=cos(teta);
   matrice_z[2][3]=0;
   matrice_z[2][4]=0;
   
   matrice_z[3][1]=0;
   matrice_z[3][2]=0;
   matrice_z[3][3]=1;
   matrice_z[3][4]=0;
   
   matrice_z[4][1]=0;
   matrice_z[4][2]=0;
   matrice_z[4][3]=0;
   matrice_z[4][4]=1; 
   
   
           m_vecteur[i] += matrice_z[i][j] * m_vecteur[j];
        }
    }
    return *this;

}



 