#ifndef PIECEL_H
#define PIECEL_H

#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>

class PieceL : protected QOpenGLFunctions
{
public:
    PieceL();
    bool visible = true;
    void drawPieceL(QOpenGLShaderProgram *program);
private:
    void initPieceL();
    QOpenGLBuffer arrayBuf;
    QOpenGLBuffer indexBuf;
};

#endif // PIECEL_H
