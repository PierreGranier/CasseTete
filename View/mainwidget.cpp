/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtCore module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/
#include <iostream>
using namespace std;
#include "mainwidget.h"

#include <QMouseEvent>

#include <math.h>


MainWidget::MainWidget(QWidget *parent) :
    QOpenGLWidget(parent),

    pp(0),
    pz(0),
    pd(0),
    pg(0),
    pl(0),
    pt(0),
    py(0),
    pplus(0),
    pangle(0),
    texture(0),
    angularSpeed(0)
{
	angle_de_rotation = 0;
	X = 1; Y= 0; Z = -22.0;
}

MainWidget::~MainWidget()
{
    // Make sure the context is current when deleting the texture
    // and the buffers.
    makeCurrent();
    delete texture;
    delete pp;
    delete pz;
    delete pd;
    delete pl;
    delete pg;
    delete pt;
    delete py;
    delete pplus;
    delete pangle;
    doneCurrent();
}

void MainWidget::mousePressEvent(QMouseEvent *e)
{
    // Save mouse press position
    mousePressPosition = QVector2D(e->localPos());
}

void MainWidget::mouseReleaseEvent(QMouseEvent *e)
{
    // Mouse release position - mouse press position
    QVector2D diff = QVector2D(e->localPos()) - mousePressPosition;

    // Rotation axis is perpendicular to the mouse position difference
    // vector
    QVector3D n = QVector3D(diff.y(), diff.x(), 0.0).normalized();

    // Accelerate angular speed relative to the length of the mouse sweep
    qreal acc = diff.length() / 100.0;

    // Calculate new rotation axis as weighted sum
    rotationAxis = (rotationAxis * angularSpeed + n * acc).normalized();

    // Increase angular speed
    angularSpeed += acc;
}

void MainWidget::timerEvent(QTimerEvent *)
{
    // Decrease angular speed (friction)
    angularSpeed *= 0.99;

    // Stop rotation when speed goes below threshold
    if (angularSpeed < 0.01) {
        angularSpeed = 0.0;
    } else {
        // Update rotation
        rotation = QQuaternion::fromAxisAndAngle(rotationAxis, angularSpeed) * rotation;

        // Request an update

    }
    update();
}

void MainWidget::initializeGL()
{
    initializeOpenGLFunctions();

    glClearColor(0, 0, 0, 1);

    initShaders();
    initTextures();

    // Enable depth buffer
    glEnable(GL_DEPTH_TEST);

    // Enable back face culling
    glEnable(GL_CULL_FACE);

    pp = new PieceP;
    pplus = new PiecePlus;
    pz = new PieceZ;
    pangle = new PieceAngle;
    pd = new PieceD;
    pl = new PieceL;
    pg = new PieceG;
    pt = new PieceT;
    py = new PieceY;
    // Use QBasicTimer because its faster than QTimer
    timer.start(12, this);
}

void MainWidget::initShaders()
{
    // Compile vertex shader
    if (!program.addShaderFromSourceFile(QOpenGLShader::Vertex, ":/vshader.glsl"))
        close();

    // Compile fragment shader
    if (!program.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/fshader.glsl"))
        close();

    // Link shader pipeline
    if (!program.link())
        close();

    // Bind shader pipeline for use
    if (!program.bind())
        close();

}

void MainWidget::initTextures()
{
    // Load cube.png image
    texture = new QOpenGLTexture(QImage(":\cube.png"));
    // Set nearest filtering mode for texture minification
    texture->setMinificationFilter(QOpenGLTexture::Nearest);

    // Set bilinear filtering mode for texture magnification
    texture->setMagnificationFilter(QOpenGLTexture::Linear);

    // Wrap texture coordinates by repeating
    // f.ex. texture coordinate (1.1, 1.2) is same as (0.1, 0.2)
    texture->setWrapMode(QOpenGLTexture::Repeat);
}

void MainWidget::resizeGL(int w, int h)
{
    // Calculate aspect ratio
    qreal aspect = qreal(w) / qreal(h ? h : 1);

    // Set near plane to 3.0, far plane to 7.0, field of view 45 degrees
    const qreal zNear = 3.0, zFar = 27.0, fov = 45.0;

    // Reset projection
    projection.setToIdentity();

    // Set perspective projection
    projection.perspective(45.0, aspect, 27.0, 3.0);
}

void MainWidget::paintGL()
{
    // Clear color and depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    texture->bind();

    // Calculate model view transformation
    QMatrix4x4 matrix;
    matrix.translate(X, Y, Z);
    matrix.rotate(rotation);


	QMatrix4x4 mMatrix;
	QMatrix4x4 vMatrix;

	QMatrix4x4 cameraTransformation;
	cameraTransformation.rotate(mAlpha, 0, 1, 0); // mAlpha = 25
	cameraTransformation.rotate(mBeta, 1, 0, 0);  // mBeta = 25

	QVector3D cameraPosition = cameraTransformation * QVector3D(0, 0, mDistance);
	QVector3D cameraUpDirection = cameraTransformation * QVector3D(0, 1, 0);

	vMatrix.lookAt(cameraPosition, QVector3D(0, 0, 0), cameraUpDirection);

    // Set modelview-projection matrix
    program.setUniformValue("mvp_matrix", projection * vMatrix * mMatrix);

    // Use texture unit 0 which contains cube.png
    program.setUniformValue("texture", 0);

    // Draw cube geometry
    if(pp->visible == true)
    pp->drawPieceP(&program);

    if(pplus->visible == true)
    {
        QMatrix4x4 matr6;
        matr6.translate(-14.0f, 0.0f, 0.0f);
        program.setUniformValue("mvp_matrix", projection * vMatrix * mMatrix * matr6);
        pplus->drawPiecePlus(&program);
    }

    if(pz->visible == true)
    {
    QMatrix4x4 matr;
    matr.translate(8.0f, 0.0f, 0.0f);
    program.setUniformValue("mvp_matrix", projection * vMatrix * mMatrix * matr);
    pz->drawPieceZ(&program);

    }

     if(pangle->visible == true)
    {
    QMatrix4x4 matr1;
    matr1.translate(8.0f, -6.0f, 0.0f);
    program.setUniformValue("mvp_matrix", projection * vMatrix * mMatrix * matr1);
    pangle->drawPieceAngle(&program);
    }


   if(pd->visible == true)
    {
    QMatrix4x4 matr2;
    matr2.translate(0.0f, -6.0f, 0.0f);
    program.setUniformValue("mvp_matrix", projection * vMatrix * mMatrix * matr2);
    pd->drawPieceD(&program);
    }

   if(pg->visible == true)
    {
    QMatrix4x4 matr3;
    matr3.translate(-8.0f, 0.0f, 0.0f);
    program.setUniformValue("mvp_matrix", projection * vMatrix * mMatrix * matr3);
    pg->drawPieceG(&program);
    }


    if(pl->visible == true)
    {
    QMatrix4x4 matr4;
    matr4.translate(-8.0f, -6.0f, 0.0f);
    program.setUniformValue("mvp_matrix", projection * vMatrix * mMatrix * matr4);
    pl->drawPieceL(&program);
    }


    if(pt->visible == true)
    {
    QMatrix4x4 matr7;
    matr7.translate(-14.0f, -6.0f, 0.0f);
    program.setUniformValue("mvp_matrix", projection * vMatrix * mMatrix * matr7);
    pt->drawPieceT(&program);
    }


   if(py->visible == true)
    {
    QMatrix4x4 matr8;
    matr8.translate(14.0f, 0.0f, 0.0f);
    program.setUniformValue("mvp_matrix", projection * vMatrix * mMatrix * matr8);
    py->drawPieceY(&program);
    }

}

void MainWidget::keyPressEvent(QKeyEvent *event)
{
  if (event->isAutoRepeat())
  {
    event->ignore();
  }
  else
  {
    cout << "Pressed " << event->key() << endl;
    if (event->key() == 81) { // Q
       	mAlpha += 5;
    } else if (event->key() == 68) { // D
    	mAlpha -= 5;
    } else if (event->key() == 90) { // Z
    	mDistance += 2;
    } else if (event->key() == 83) { // S
    	mDistance -= 2;
    }  else if (event->key() == 16777235) { // cursor up
    	mBeta -= 5;
    }   else if (event->key() == 16777237) { // cursor down
    	mBeta += 5;
    } 

   	update();
  }
}
