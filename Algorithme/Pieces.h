#include <iostream>
#include "position.h"

struct Rotation
{
  int x;int y;int z;
};
  

class pieces {

private :
  
  position p;
  int rotation_x;
  int rotation_y;
  int rotation_z;
public :
   void set_position(position n)
   {
      p.set_x(n.get_x());
      p.set_y(n.get_y());
      p.set_z(n.get_z());
   }
   
   
   void set_rotation (int x,int y,int z)
   {
      rotation_x = x;
      rotation_y = y;
      rotation_z = z;
   }
   
   
   position get_position()
  
   {
     position a;
	
	a.set_x(p.get_x());
	a.set_y(p.get_y());
	a.set_z(p.get_z());
	
	return a;
   }
   
   Rotation get_rotation()
   {
      Rotation a;
      a.x = rotation_x;
      a.y = rotation_y;
      a.z = rotation_z;
     
    }
     
};
    };
     
  
};

