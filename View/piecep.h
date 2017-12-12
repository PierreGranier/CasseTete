#ifndef PIECEP_H
#define PIECEP_H

#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>


class PieceP : protected QOpenGLFunctions
{
public:
    PieceP();
    bool visible = true;
    void drawPieceP(QOpenGLShaderProgram *program);
    float cubePositions[108];
private:
    void initCubeGeometry();
    void initPieceP();
    QOpenGLBuffer arrayBuf;
    QOpenGLBuffer indexBuf;
};

#endif // PIECEP_H
