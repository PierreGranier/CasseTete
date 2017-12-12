#ifndef PIECEZ_H
#define PIECEZ_H

#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>


class PieceZ : protected QOpenGLFunctions
{
public:
    PieceZ();
    bool visible = true;
    void drawPieceZ(QOpenGLShaderProgram *program);

private:
    void initPieceZ();
    QOpenGLBuffer arrayBuf;
    QOpenGLBuffer indexBuf;
};

#endif // PIECEZ_H
