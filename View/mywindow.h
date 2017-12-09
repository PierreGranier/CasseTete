/*
 * classe d'implémentation d'opengl
*/
#ifndef MYWINDOW_H
#define MYWINDOW_H
#include <QImage>
#include "glclass.h"
#include <GL/glu.h>
#include <math.h>
#include <QDebug>
#include <QMatrix4x4>
#include "transform3d.h"
#include "camera3d.h"
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>

class QOpenGLShaderProgram;
class mywindow : public Glclass,protected QOpenGLFunctions
{
    Q_OBJECT



public:
    //Constructeur
    explicit mywindow(QWidget *parent = 0);


    //Requête
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();
    void teardownGL();

    QOpenGLTexture *texture[9];


private :



     //Informations du Shader
     int u_modelToWorld;
     int u_worldToView;
     int u_worldToCamera;
     int u_cameraToView;
     QMatrix4x4 m_projection;

     //Variable de transformation
     Transform3D m_transform;



};

#endif // MYWINDOW_H

