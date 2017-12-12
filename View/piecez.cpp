#include "piecez.h"

#include <QVector2D>
#include <QVector3D>

struct VertexData
{
    QVector3D position;
    QVector2D texCoord;
};

PieceZ::PieceZ()
    : indexBuf(QOpenGLBuffer::IndexBuffer)
{
    initializeOpenGLFunctions();

    // Generate 2 VBOs
    arrayBuf.create();
    indexBuf.create();
}


void PieceZ::initPieceZ()
{

    VertexData vertices[] = {

        {QVector3D(1.0f,-1.0f,-1.0f), QVector2D(0.0f, 0.0f)},  // v0
        {QVector3D(1.0f,-1.0f,1.0f), QVector2D(0.0f, 0.0f)}, // v1
        {QVector3D(-1.0f,-1.0f,1.0f), QVector2D(0.0f, 0.0f)},  // v2
        {QVector3D(-1.0f,-1.0f,-1.0f), QVector2D(0.0f, 0.0f)}, // v3


        {QVector3D(1.0f,1.0f,-1.0f), QVector2D(0.0f, 0.0f)},  // v4
        {QVector3D(1.0f,1.0f,1.0f), QVector2D(0.0f, 0.0f)}, // v5
        {QVector3D(-1.0f,1.0f,1.0f), QVector2D(0.0f, 0.0f)},  // v6
        {QVector3D(-1.0f,1.0f,-1.0f), QVector2D(0.0f, 0.0f)}, // v7


        {QVector3D(1.0f,-1.0f,3.0f), QVector2D(0.0f, 0.0f)},  // v8
        {QVector3D(-1.0f,-1.0f,3.0f), QVector2D(0.0f, 0.0f)}, // v9
        {QVector3D(1.0f,1.0f,3.0f), QVector2D(0.0f, 0.0f)},  // v10
        {QVector3D(-1.0f,1.0f,3.0f), QVector2D(0.0f, 0.0f)}, // v11


        {QVector3D(-1.0f,-1.0f,1.0f), QVector2D(0.0f, 0.0f)},  // v12
        {QVector3D(-1.0f,-1.0f,-1.0f), QVector2D(0.0f, 0.0f)}, // v13
        {QVector3D(-1.0f,1.0f,1.0f), QVector2D(0.0f, 0.0f)},  // v14
        {QVector3D(-1.0f,1.0f,-1.0f), QVector2D(0.0f, 0.0f)}, // v15



        {QVector3D(-3.0f,-1.0f, 1.0f), QVector2D(0.0f, 0.0f)},  // v16
        {QVector3D(-3.0f,-1.0f,-1.0f), QVector2D(0.0f, 0.0f)}, // v17
        {QVector3D(-3.0f,1.0f,1.0f), QVector2D(0.0f, 0.0f)},  // v18
        {QVector3D( -3.0f,1.0f,-1.0f), QVector2D(0.0f, 0.0f)}, // v19


        {QVector3D(5.0f,-1.0f,1.0f), QVector2D(0.0f, 0.0f)},  // v20
        {QVector3D(5.0f,1.0f,1.0f), QVector2D(0.0f, 0.0f)}, // v21
        {QVector3D(5.0f,-1.0f,3.0f), QVector2D(0.0f, 0.0f)},  // v22
        {QVector3D(5.0f,1.0f,3.0f), QVector2D(0.0f, 0.0f)}, // v23


    };


    GLushort indices[] = {
        1, 3, 0,
        7, 5, 4,
        4, 1, 0,
        2, 11, 6,
        6, 12, 2,
        0, 7, 4,
        10, 9, 8,
        5, 20, 1,
        1, 9, 2,
        5, 11, 10,
        15, 17, 19,
        7, 14, 6,
        3, 15, 7,
        2, 13, 3,
        18, 17, 16,
        12, 17, 13,
        15, 18, 14,
        12, 18, 16,
        21, 22, 20,
        8, 23, 10,
        10, 21, 5,
        1, 22, 8,
        1, 2, 3,
        7, 6, 5,
        4, 5, 1,
        2, 9, 11,
        6, 14, 12,
        0, 3, 7,
        10, 11, 9,
        5, 21, 20,
        1, 8, 9,
        5, 6, 11,
        15, 13, 17,
        7, 15, 14,
        3, 13, 15,
        2, 12, 13,
        18, 19, 17,
        12, 16, 17,
        15, 19, 18,
        12, 14, 18,
        21, 23, 22,
        8, 22, 23,
        10, 23, 21,
        1, 20, 22
    };

    // Transfer vertex data to VBO 0
    arrayBuf.bind();
    arrayBuf.allocate(vertices, 24 * sizeof(VertexData));

    // Transfer index data to VBO 1
    indexBuf.bind();
    indexBuf.allocate(indices, 132 * sizeof(GLushort));
}

void PieceZ::drawPieceZ(QOpenGLShaderProgram *program)
{
    initPieceZ();
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
    glDrawElements(GL_TRIANGLES, 132, GL_UNSIGNED_SHORT, 0);
}
