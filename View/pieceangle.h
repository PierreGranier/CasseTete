#ifndef PIECEANGLE_H
#define PIECEANGLE_H

#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>

class PieceAngle : protected QOpenGLFunctions
{
public:
    PieceAngle();
    bool visible = true;
    void drawPieceAngle(QOpenGLShaderProgram *program);

private:
     void initPieceAngle();
     QOpenGLBuffer arrayBuf;
     QOpenGLBuffer indexBuf;
};

#endif // PIECEANGLE_H
