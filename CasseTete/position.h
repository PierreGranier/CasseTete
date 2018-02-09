#ifndef POSITION_H
#define POSITION_H

class Position {
private:
    int x;
    int y;
    int z;
public:
    Position(int a, int b, int c);
    Position(Position* p);
    int getX();
    int getY();
    int getZ();
    int get(int i);
    void setX(int a);
    void setY(int b);
    void setZ(int c);
    bool equals(Position* p);
};

#endif // POSITION_H
