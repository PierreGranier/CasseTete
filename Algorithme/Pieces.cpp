#include <iostream>

struct Position{
  int x;
  int y;
  int z;
} ;
struct Rotation{
  int x;int y;int z;
};
  

class pieces {

private :
  
  int position_x;
  int position_y;
  int position_z;
  int rotation_x;
  int rotation_y;
  int rotation_z;
  
public :
   void set_position(Position n)
   {
      position_x = n.x;
      position_y = n.y;
      position_z = n.z;
   }
   
   
   void set_rotation (int x,int y,int z)
   {
      rotation_x = x;
      rotation_y = y;
      rotation_z = z;
   }
   
   
   Position get_position()
  
   {
     Position a;
	
	a.x = position_x;
	a.y = position_y;
	a.z = position_z;
	
	return a;
   }
   
   Rotation get_rotation()
   {
      Rotation a;
      a.x = rotation_x;
      a.y = rotation_y;
      a.z = rotation_z;
     
    };
     
  
};

