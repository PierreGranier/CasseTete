#ifndef PIECEPLUS_H
#define PIECEPLUS_H

#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>

class PiecePlus : protected QOpenGLFunctions
{
public:
    PiecePlus();
    bool visible = true;
    void drawPiecePlus(QOpenGLShaderProgram *program);

private:
     void initPiecePlus();
     QOpenGLBuffer arrayBuf;
     QOpenGLBuffer indexBuf;
};

#endif // PIECEPLUS_H
