#ifndef POSITION_H
#define POSITION_H

#include <iostream>

class Position {
  
private:
	int x;
	int y;
	int z;
  
public:
	Position(int a, int b, int c) : x(a), y(b), z(c) {};
	Position(Position &pos) : x(pos.getX()), y(pos.getY()), z(pos.getZ()) {};

	void setX(int a) {
		x = a;
	}
	void setY(int a) {
		y = a;
	}
	void setZ(int a) {
		z = a;
	}

	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
	int getZ() {
		return z;
	}
};

#endif
