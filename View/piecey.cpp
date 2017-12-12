#include "piecey.h"

#include <QVector2D>
#include <QVector3D>

struct VertexData
{
    QVector3D position;
    QVector2D texCoord;
};

PieceY::PieceY() : indexBuf(QOpenGLBuffer::IndexBuffer)
{
    initializeOpenGLFunctions();

    // Generate 2 VBOs
    arrayBuf.create();
    indexBuf.create();

}

void PieceY::initPieceY()
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


        {QVector3D(1.0f,3.0f,-1.0f), QVector2D(0.0f, 0.0f)},  // v8
        {QVector3D(1.0f,3.0f,1.0f), QVector2D(0.0f, 0.0f)}, // v9
        {QVector3D(-1.0f,3.0f,-1.0f), QVector2D(0.0f, 0.0f)},  // v10
        {QVector3D(-1.0f,3.0f,1.0f), QVector2D(0.0f, 0.0f)}, // v11


        {QVector3D(3.0f,-1.0f,-1.0f), QVector2D(0.0f, 0.0f)},  // v12
        {QVector3D(3.0f,-1.0f,1.0f), QVector2D(0.0f, 0.0f)}, // v13
        {QVector3D(3.0f,1.0f,-1.0f), QVector2D(0.0f, 0.0f)},  // v14
        {QVector3D(3.0f,1.0f,1.0f), QVector2D(0.0f, 0.0f)}, // v15


        {QVector3D(-3.0f,-1.0f,1.0f), QVector2D(0.0f, 0.0f)},  // v16
        {QVector3D(-3.0f,-1.0f,-1.0f), QVector2D(0.0f, 0.0f)}, // v17
        {QVector3D(-3.0f,1.0f,1.0f), QVector2D(0.0f, 0.0f)},  // v18
        {QVector3D(-3.0f,1.0f,-1.0f), QVector2D(0.0f, 0.0f)}, // v19


        {QVector3D(1.0f,1.0f,3.0f), QVector2D(0.0f, 0.0f)},  // v20
        {QVector3D(-1.0f,1.0f,3.0f), QVector2D(0.0f, 0.0f)}, // v21
        {QVector3D(1.0f,3.0f,3.0f), QVector2D(0.0f, 0.0f)},  // v22
        {QVector3D(-1.0f,3.0f,3.0f), QVector2D(0.0f, 0.0f)} // v23


    };


    GLushort indices[] = {
        1, 3, 0,
        6, 10, 7,
        1, 15, 5,
        5, 2, 1,
        2, 18, 16,
        0, 7, 4,
        10, 9, 8,
        7, 8, 4,
        6, 23, 11,
        4, 9, 5,
        14, 13, 12,
        4, 12, 0,
        1, 12, 13,
        4, 15, 14,
        18, 17, 16,
        7, 18, 6,
        7, 17, 19,
        2, 17, 3,
        20, 23, 21,
        11, 22, 9,
        6, 20, 21,
        9, 20, 5,
        1, 2, 3,
        6, 11, 10,
        1, 13, 15,
        5, 6, 2,
        2, 6, 18,
        0, 3, 7,
        10, 11, 9,
        7, 10, 8,
        6, 21, 23,
        4, 8, 9,
        14, 15, 13,
        4, 14, 12,
        1, 0, 12,
        4, 5, 15,
        18, 19, 17,
        7, 19, 18,
        7, 3, 17,
        2, 16, 17,
        20, 22, 23,
        11, 23, 22,
        6, 5, 20,
        9, 22, 20
    };

    // Transfer vertex data to VBO 0
    arrayBuf.bind();
    arrayBuf.allocate(vertices, 24 * sizeof(VertexData));

    // Transfer index data to VBO 1
    indexBuf.bind();
    indexBuf.allocate(indices, 132 * sizeof(GLushort));
}

void PieceY::drawPieceY(QOpenGLShaderProgram *program)
{
    initPieceY();
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

