#ifndef PIECED_H
#define PIECED_H

#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>

class PieceD : protected QOpenGLFunctions
{
public:
    PieceD();
    bool visible = true;
    void drawPieceD(QOpenGLShaderProgram *program);

private:
     void initPieceD();
     QOpenGLBuffer arrayBuf;
     QOpenGLBuffer indexBuf;
};

#endif // PIECED_H
