#ifndef H_POSITION
#define H_POSITION

#include <iostream>

class position {
  
private:
  int p_x;
  int p_y;
  int p_z;
  
public:
  void set_x(int a)
  {
    p_x = a;
  }
  
  void set_y(int a)
  {
    p_y = a;
  }
  
  void set_z(int a)
  {
    p_z = a;
  }
  
  int get_x()
  {
    return p_x;
  }
  int get_y()
  {
    return p_y;
  }
  int get_z()
  {
    return p_z;
  }
};

#endif
