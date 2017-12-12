#include "piecet.h"


#include <QVector2D>
#include <QVector3D>

struct VertexData
{
    QVector3D position;
    QVector2D texCoord;
};

PieceT::PieceT() : indexBuf(QOpenGLBuffer::IndexBuffer)
{
    initializeOpenGLFunctions();

    // Generate 2 VBOs
    arrayBuf.create();
    indexBuf.create();

}

void PieceT::initPieceT()
{

    VertexData vertices[] = {
        {QVector3D(1.0f, -1.0f,-1.0f), QVector2D(0.0f, 0.0f)},  // v0
        {QVector3D(1.0f, -1.0f, 3.0f), QVector2D(0.0f, 0.0f)},  // v1
        {QVector3D(-1.0f,-1.0f, 3.0f), QVector2D(0.0f, 0.0f)},  // v2
        {QVector3D(-1.0f,-1.0f,-1.0f), QVector2D(0.0f, 0.0f)},  // v3

        {QVector3D(1.0f, 1.0f, -1.0f), QVector2D(0.0f, 0.0f)},  // v4
        {QVector3D(1.0f, 1.0f,  3.0f), QVector2D(0.0f, 0.0f)},  // v5
        {QVector3D(-1.0f,1.0f,  3.0f), QVector2D(0.0f, 0.0f)},  // v6
        {QVector3D(-1.0f,1.0f, -1.0f), QVector2D(0.0f, 0.0f)},  // v7


        {QVector3D(1.0f, -1.0f,-3.0f), QVector2D(0.0f, 0.0f)},  // v8
        {QVector3D(-1.0f,-1.0f,-3.0f), QVector2D(0.0f, 0.0f)},  // v9
        {QVector3D(1.0f,  1.0f,-3.0f), QVector2D(0.0f, 0.0f)},  // v10
        {QVector3D(-1.0f, 1.0f,-3.0f), QVector2D(0.0f, 0.0f)},  // v11

        {QVector3D(3.0f,-1.0f, -1.0f), QVector2D(0.0f, 0.0f)},  // v12
        {QVector3D(3.0f, 1.0f, -1.0f), QVector2D(0.0f, 0.0f)},  // v13
        {QVector3D(3.0f,-1.0f, -3.0f), QVector2D(0.0f, 0.0f)},  // v14
        {QVector3D(3.0f,1.0f,  -3.0f), QVector2D(0.0f, 0.0f)},  // v15

        {QVector3D(-3.0f,-1.0f,-1.0f), QVector2D(0.0f, 0.0f)},  // v16
        {QVector3D(-3.0f, 1.0f,-1.0f), QVector2D(0.0f, 0.0f)},  // v17
        {QVector3D(-3.0f,-1.0f,-3.0f), QVector2D(0.0f, 0.0f)},  // v18
        {QVector3D(-3.0f, 1.0f,-3.0f), QVector2D(0.0f, 0.0f)}   // v19

    };

    GLushort indices[] = {

        1, 3, 0,
        4, 6, 5,
        4, 1, 0,
        5, 2, 1,
        6, 5, 2,
        0, 9, 8,
        8, 11, 10,
        8, 12, 0,
        4, 11, 7,
        3, 18, 9,
        12, 15, 13,
        0, 13, 4,
        10, 14, 8,
        4, 15, 10,
        17, 18, 16,
        9, 19, 11,
        11, 17, 7,
        7, 16, 3,
        1, 2, 3,
        4, 7, 6,
        4, 5, 1,
        5, 6, 2,
        6, 7, 3,
        0, 3, 9,
        8, 9, 11,
        8, 14, 12,
        4, 10, 11,
        3, 16, 18,
        12, 14, 15,
        0, 12, 13,
        10, 15, 14,
        4, 13, 15,
        17, 19, 18,
        9, 18, 19,
        11, 19, 17,
        7, 17, 16
    };

    // Transfer vertex data to VBO 0
    arrayBuf.bind();
    arrayBuf.allocate(vertices, 20 * sizeof(VertexData));

    // Transfer index data to VBO 1
    indexBuf.bind();
    indexBuf.allocate(indices, 108 * sizeof(GLushort));
}

void PieceT::drawPieceT(QOpenGLShaderProgram *program)
{
    initPieceT();
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
    glDrawElements(GL_TRIANGLES, 108, GL_UNSIGNED_SHORT, 0);
}
