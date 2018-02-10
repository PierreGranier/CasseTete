#ifndef PIECEVIEW_H
#define PIECEVIEW_H

#include <QtOpenGL>
#include <QGLWidget>
#include <GL/glu.h>
#include "../position.h"

class PieceView {
protected:
    bool display;
    bool is_used;
    Position* position;
    Position* rotation;
public:
    PieceView();
    void setPosition(int x, int y, int z);
    void setRotation(int x, int y, int z);
    void reverseDisplay();
    void setIsUsed(bool b);
    virtual void show() =0;
};

#endif // PIECEVIEW_H
