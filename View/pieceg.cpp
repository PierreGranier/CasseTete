#include "pieceg.h"

#include <QVector2D>
#include <QVector3D>

struct VertexData
{
    QVector3D position;
    QVector2D texCoord;
};

PieceG::PieceG() : indexBuf(QOpenGLBuffer::IndexBuffer)
{
    initializeOpenGLFunctions();

    // Generate 2 VBOs
    arrayBuf.create();
    indexBuf.create();

}


void PieceG::initPieceG()
{
    // For cube we would need only 8 vertices but we have to
    // duplicate vertex for each face because texture coordinate
    // is different.
    VertexData vertices[] = {

        {QVector3D(1.0f,-1.0f,-1.0f), QVector2D(0.0f, 0.0f)},  // v0
        {QVector3D(1.0f,-1.0f,1.0f), QVector2D(0.0f, 0.0f)}, // v1
        {QVector3D(-1.0f,-1.0f,1.0f), QVector2D(0.0f, 0.0f)},  // v2
        {QVector3D(-1.0f,-1.0f,-1.0f), QVector2D(0.0f, 0.0f)}, // v3

        {QVector3D(1.0f,1.0f,-1.0f), QVector2D(0.0f, 0.0f)},  // v4
        {QVector3D(1.0f,1.0f,1.0f), QVector2D(0.0f, 0.0f)}, // v5
        {QVector3D(-1.0f,1.0f,1.0f), QVector2D(0.0f, 0.0f)},  // v6
        {QVector3D(-1.0f,1.0f,-1.0f), QVector2D(0.0f, 0.0f)}, // v7

        {QVector3D(5.0f,-1.0f,-1.0f), QVector2D(0.0f, 0.0f)},  // v8
        {QVector3D(5.0f,-1.0f,1.0f), QVector2D(0.0f, 0.0f)}, // v9
        {QVector3D(5.0f,1.0f,-1.0f), QVector2D(0.0f, 0.0f)},  // v10
        {QVector3D(5.0f,1.0f,1.0f), QVector2D(0.0f, 0.0f)}, // v11

        {QVector3D(1.0f,-1.0f,-3.0f), QVector2D(0.0f, 0.0f)},  // v12
        {QVector3D(-1.0f,-1.0f,-3.0f), QVector2D(0.0f, 0.0f)}, // v13
        {QVector3D(1.0f,1.0f,-3.0f), QVector2D(0.0f, 0.0f)},  // v14
        {QVector3D(-1.0f,1.0f,-3.0f), QVector2D(0.0f, 0.0f)}, // v15


        {QVector3D(1.0f,3.0f,-1.0f), QVector2D(0.0f, 0.0f)},  // v16
        {QVector3D(-1.0f,3.0f,-1.0f), QVector2D(0.0f, 0.0f)}, // v17
        {QVector3D(1.0f,3.0f,-3.0f), QVector2D(0.0f, 0.0f)},  // v18
        {QVector3D(-1.0f,3.0f,-3.0f), QVector2D(0.0f, 0.0f)} // v19


    };
    GLushort indices[] = {

       1, 3, 0,
       7, 5, 4,
       1, 11, 5,
       5, 2, 1,
       2, 7, 3,
       0, 14, 4,
       10, 9, 8,
       4, 8, 0,
       1, 8, 9,
       4, 11, 10,
       12, 15, 14,
       7, 19, 15,
       7, 13, 3,
       0,13, 12,
       16, 19, 17,
       4, 17, 7,
       14, 16, 4,
       15, 18, 14,
       1, 2, 3,
       7, 6, 5,
       1, 9, 11,
       5, 6, 2,
       2, 6, 7,
       0, 12, 14,
       10, 11, 9,
       4, 10, 8,
       1, 0, 8,
       4, 5, 11,
       12, 13, 15,
       7, 17, 19,
       7, 15, 13,
       0, 3, 13,
       16, 18, 19,
       4, 16, 17,
       14, 18, 16,
       15, 19, 18
    };

    // Transfer vertex data to VBO 0
    arrayBuf.bind();
    arrayBuf.allocate(vertices, 20 * sizeof(VertexData));

    // Transfer index data to VBO 1
    indexBuf.bind();
    indexBuf.allocate(indices, 108 * sizeof(GLushort));
}

void PieceG::drawPieceG(QOpenGLShaderProgram *program)
{
    initPieceG();
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

