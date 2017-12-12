#include "piecep.h"


#include <QVector2D>
#include <QVector3D>

struct VertexData
{
    QVector3D position;
    QVector2D texCoord;
};
PieceP::PieceP()
    : indexBuf(QOpenGLBuffer::IndexBuffer)
{
    initializeOpenGLFunctions();

    // Generate 2 VBOs
    arrayBuf.create();
    indexBuf.create();
}


void PieceP::initPieceP()
{

    VertexData vertices[] = {
        {QVector3D(1.0f, -1.0f, -1.0f), QVector2D(0.0f, 0.0f)},  // v0
        {QVector3D(1.0f, -1.0f, 1.0f), QVector2D(0.0f, 0.0f)}, // v1
        {QVector3D(-1.0f, -1.0f, 1.0f), QVector2D(0.0f, 0.0f)},  // v2
        {QVector3D(-1.0f, -1.0f, -1.0f), QVector2D(0.0f, 0.0f)}, // v3
        {QVector3D(1.0f, 1.0f, -1.0f), QVector2D(0.0f, 0.0f)}, // v4
        {QVector3D(1.0f, 1.0f, 1.0f), QVector2D(0.0f, 0.0f)}, // v5
        {QVector3D(-1.0f, 1.0f, 1.0f), QVector2D(0.0f, 0.0f)},  // v6
        {QVector3D(-1.0f, 1.0f, -1.0f), QVector2D(0.0f, 0.0f)}, // v7
        {QVector3D(1.0f,0.005f,-1.0f), QVector2D(0.0f, 0.0f)}, // v8
        {QVector3D(1.0f,-0.005f,1.0f), QVector2D(0.0f, 0.0f)},  // v9
        {QVector3D(2.0f,0.005f,-1.0f), QVector2D(0.0f, 0.0f)}, // v10
        {QVector3D( 2.0f,1.0f,-1.0f), QVector2D(0.0f, 0.0f)},  // v11
        {QVector3D( 2.0f,-0.005f,1.0f), QVector2D(0.0f, 0.0f)}, // v12
        {QVector3D(2.0f,1.0f,1.0f), QVector2D(0.0f, 0.0f)}  // v13

    };

  GLushort indices[] = {
        1,3,0,
        7,5,4,
        0,9,1,
        9,6,2,
        2,6,3,
        8,3,7,
        5,11,4,
        10,13,12,
        9,13,5,
        4,10,8,
        9,10,12,
        1,2,3,
        7,6,5,
        0,8,9,
        2,1,9,
        9,5,6,
        2,6,7,
        7,4,8,
        8,0,3,
        5,13,11,
        10,11,13,
        9,12,13,
        4,11,10,
        9,8,10
    };
    // Transfer vertex data to VBO 0
    arrayBuf.bind();
    arrayBuf.allocate(vertices, 16* sizeof(VertexData));

    // Transfer index data to VBO 1
    indexBuf.bind();
    indexBuf.allocate(indices, 72 * sizeof(GLushort));
}

void PieceP::drawPieceP(QOpenGLShaderProgram *program)
{
    initPieceP();
    // Tell OpenGL which VBOs to use
    arrayBuf.bind();
    indexBuf.bind();

    // Offset for position
    quintptr offset = 0;

    // Tell OpenGL programmable pipeline how to locate vertex position data
    int vertexLocation = program->attributeLocation("a_position");
    program->enableAttributeArray(vertexLocation);
    program->setAttributeBuffer(vertexLocation, GL_FLOAT, offset, 3, sizeof(VertexData));

    // Offset for texture coordinate
    offset += sizeof(QVector3D);

    // Tell OpenGL programmable pipeline how to locate vertex texture coordinate data
    int texcoordLocation = program->attributeLocation("a_texcoord");
    program->enableAttributeArray(texcoordLocation);
    program->setAttributeBuffer(texcoordLocation, GL_FLOAT, offset, 2, sizeof(VertexData));

    // Draw cube geometry using indices from VBO 1
    glDrawElements(GL_TRIANGLES, 72, GL_UNSIGNED_SHORT, 0);
}
