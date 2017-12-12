#ifndef PIECEY_H
#define PIECEY_H

#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>

class PieceY : protected QOpenGLFunctions
{
public:
    PieceY();
    bool visible = true;
    void drawPieceY(QOpenGLShaderProgram *program);
private:
     void initPieceY();
     QOpenGLBuffer arrayBuf;
     QOpenGLBuffer indexBuf;
};

#endif // PIECEY_H
