#ifndef PIECEG_H
#define PIECEG_H

#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>

class PieceG : protected QOpenGLFunctions
{
public:
    PieceG();
    bool visible = true;
    void drawPieceG(QOpenGLShaderProgram *program);

private:
     void initPieceG();
     QOpenGLBuffer arrayBuf;
     QOpenGLBuffer indexBuf;
};

#endif // PIECEG_H
