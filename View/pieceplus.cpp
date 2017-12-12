#include "pieceplus.h"


#include <QVector2D>
#include <QVector3D>

struct VertexData
{
    QVector3D position;
    QVector2D texCoord;
};

PiecePlus::PiecePlus()
    : indexBuf(QOpenGLBuffer::IndexBuffer)
{
    initializeOpenGLFunctions();
    // Generate 2 VBOs
    arrayBuf.create();
    indexBuf.create();
}


void PiecePlus::initPiecePlus()
{
    VertexData vertices[] = {
        {QVector3D(1.0f, -1.0f, -1.0f), QVector2D(0.0f, 0.0f)},  // v0
        {QVector3D(1.0f,-1.0f,1.0f), QVector2D(0.0f, 0.0f)}, // v1
        {QVector3D(-1.0f,-1.0f,1.0f), QVector2D(0.0f, 0.0f)},  // v2
        {QVector3D(-1.0f,-1.0f,-1.0f), QVector2D(0.0f, 0.0f)}, // v3


        {QVector3D(1.0f,1.0f,-1.0f), QVector2D(0.0f, 0.0f)}, // v4
        {QVector3D(1.0f,1.0f,1.0f), QVector2D(0.0f, 0.0f)}, // v5
        {QVector3D(-1.0f,1.0f,1.0f), QVector2D(0.0f, 0.0f)},  // v6
        {QVector3D(-1.0f,1.0f,-1.0f), QVector2D(0.0f, 0.0f)}, // v7


        {QVector3D(3.0f,-1.0f,-1.0f), QVector2D(0.0f, 0.0f)}, // v8
        {QVector3D(3.0f,-1.0f,1.0f), QVector2D(0.0f, 0.0f)},  // v9
        {QVector3D(3.0f,1.0f,-1.0f), QVector2D(0.0f, 0.0f)}, // v10
        {QVector3D(3.0f,1.0f,1.0f), QVector2D(0.0f, 0.0f)},  // v11


        {QVector3D(-3.0f,-1.0f,1.0f), QVector2D(0.0f, 0.0f)}, // v12
        {QVector3D(-3.0f, -1.0f, -1.0f), QVector2D(0.0f, 0.0f)},  // v13
        {QVector3D(-3.0f,1.0f,1.0f), QVector2D(0.0f, 0.0f)}, // v14
        {QVector3D(-3.0f,1.0f,-1.0f), QVector2D(0.0f, 0.0f)},  // v15


        {QVector3D(1.0f,-1.0f,-3.0f), QVector2D(0.0f, 0.0f)}, // v16
        {QVector3D(-1.0f,-1.0f,-3.0f), QVector2D(0.0f, 0.0f)}, // v17
        {QVector3D(1.0f,1.0f,-3.0f), QVector2D(0.0f, 0.0f)}, // v18
        {QVector3D(-1.0f,1.0f,-3.0f), QVector2D(0.0f, 0.0f)}, // v19

        {QVector3D(1.0f, -1.0f,  3.0f), QVector2D(0.0f, 0.0f)}, // v20
        {QVector3D(-1.0f, -1.0f,  3.0f), QVector2D(0.0f, 0.0f)}, // v21
        {QVector3D(1.0f,  1.0f, 3.0f), QVector2D(0.0f, 0.0f)},// v22
        {QVector3D(-1.0f,  1.0f, 3.0f), QVector2D(0.0f, 0.0f)}// v23
    };


    GLushort indices[] = {

        1, 3, 0,
        7, 5, 4,
        4, 11, 10,
        1, 21, 2,
        2, 13, 3,
        0, 17, 16,
        10, 9, 8,
        1, 11, 5,
        4, 8, 0,
        1 ,8, 9,
        14, 13, 12,
        2, 14, 12,
        7, 14, 6,
        7, 13, 15,
        16, 19, 18,
        2, 18, 4,
        4, 19, 7,
        7, 17, 3,
        22, 21, 20,
        5, 23, 22,
        2, 23, 6,
        5, 20, 1,
        1, 2, 3,
        7, 6, 5,
        4, 5, 11,
        1, 20, 21,
        2, 12, 13,
        0, 3, 17,
        10, 11, 9,
        1, 9, 11,
        4, 10, 8,
        1, 0, 8,
        14, 15, 13,
        2, 6, 14,
        7, 15, 14,
        7, 3, 13,
        16, 17, 19,
        0, 16, 18,
        4, 18, 19,
        7, 19, 17,
        22, 23, 21,
        5, 6, 23,
        2, 21, 23,
        5, 22, 20


    };

    // Transfer vertex data to VBO 0
    arrayBuf.bind();
    arrayBuf.allocate(vertices, 24 * sizeof(VertexData));

    // Transfer index data to VBO 1
    indexBuf.bind();
    indexBuf.allocate(indices, 135 * sizeof(GLushort));
}

void PiecePlus::drawPiecePlus(QOpenGLShaderProgram *program)
{
    initPiecePlus();
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
    glDrawElements(GL_TRIANGLES, 135, GL_UNSIGNED_SHORT, 0);
}
