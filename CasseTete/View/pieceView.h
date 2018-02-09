#ifndef PIECEVIEW_H
#define PIECEVIEW_H

#include <QtOpenGL>
#include <QGLWidget>
#include <GL/glu.h>
#include "../position.h"

class PieceView {
protected:
    bool display;
    Position* position;
    Position* rotation;
public:
    PieceView();
    void setPosition(int x, int y, int z);
    void setRotation(int x, int y, int z);
    void reverseDisplay();
    virtual void show() =0;
    int* multiplyMatrix(int* m1, int* m2);
};

#endif // PIECEVIEW_H
