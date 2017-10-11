#include "Position.h"


using namespace std; 


Position::Position(int x, int y, int z):m_x(x),m_y(y),m_z(z)
{

}

Position::Position(const Position& pos):m_x(pos.m_x),m_y(pos.m_y),m_z(pos.m_z)
{

}
Position::Position()
{

}

