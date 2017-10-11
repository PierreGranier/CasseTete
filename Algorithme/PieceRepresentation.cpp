#include "PieceRepresentation.h"


PieceRepresentation::PieceRepresentation(int x, int y, int z,int *vect):m_x(x),m_y(y),m_z(z){
for(int i(0); i<vect.length; ++i)

{

  m_vecteur[i]=vect[i];

}
}


PieceRepresentation::PieceRepresentation(const PieceRepresentation &p)
{
    m_x = p.m_x;
    m_y = p.m_y;
    m_z = p.m_z;

for(int i(0); i<p.m_vecteur.length; ++i)

{

  m_vecteur[i]=p.m_vecteur[i];

}
}
 
