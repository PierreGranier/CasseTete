


// https://codereview.stackexchange.com/questions/9293/mathematical-programming-puzzles?rq=1 



#include "Piece.h"
 
Piece::Piece()
{
   
}
 
Piece::Piece(int type, int orientation)
{
    m_type = type;
    m_orientation = orientation;
}
 
Piece::Piece(const Piece &p)
{
    m_type = p.m_type;
    m_orientation = p.m_orientation;
  
    m_x = p.m_x;
    m_y = p.m_y;
    m_z = p.m_z
}
 
