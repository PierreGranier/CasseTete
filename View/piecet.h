#ifndef PIECET_H
#define PIECET_H

#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>

class PieceT : protected QOpenGLFunctions
{
public:
    PieceT();
    bool visible = true;
    void drawPieceT(QOpenGLShaderProgram *program);
private:
    void initPieceT();
    QOpenGLBuffer arrayBuf;
    QOpenGLBuffer indexBuf;

};

#endif // PIECET_H
