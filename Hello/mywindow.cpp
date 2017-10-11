
#include "mywindow.h"
#include<iostream>
#include<cube.h>
#include<vertex.h>
#include <QOpenGLShaderProgram>

//Constructeur
mywindow::mywindow(QWidget *parent)
    : Glclass(60, parent, "Casse tete 3D")
{
    m_transform.translate(0.0f, 0.0f, -5.0f);

}


//Initialisation de la scene
void mywindow::initializeGL()
{
  // Initialisation de l'arriere de la scène
     initializeOpenGLFunctions();
     QTimer *timer = new QTimer(this);
     connect(timer, SIGNAL(timeout()), this, SLOT(update()));
     timer->start(100);

     // Set global information
     glEnable(GL_CULL_FACE);
     glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

     // Application-specific initialization

       // Create Shader (Do not release until VAO is created)
       m_program = new QOpenGLShaderProgram();
       m_program->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/simple.vert");
       m_program->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/simple.frag");
       m_program->link();
       m_program->bind();

       // Location du "Cache Uniform"
       u_modelToWorld = m_program->uniformLocation("modelToWorld");
       u_worldToView = m_program->uniformLocation("worldToView");
       u_worldToCamera = m_program->uniformLocation("worldToCamera");
       u_cameraToView = m_program->uniformLocation("cameraToView");


       // Créer un tampon (Ne pas relâcher avant la création de VAO)
       m_vertex.create();
       m_vertex.bind();
       m_vertex.setUsagePattern(QOpenGLBuffer::StaticDraw);
       m_vertex.allocate(sg_vertexes, sizeof(sg_vertexes));

       // Créer un objet de tableau Vertex
       cube1.m_object.create();
       cube1.m_object.bind();
       m_program->enableAttributeArray(0);
       m_program->enableAttributeArray(1);
       m_program->setAttributeBuffer(0, GL_FLOAT, Vertex::positionOffset(), Vertex::PositionTupleSize, Vertex::stride());
       m_program->setAttributeBuffer(1, GL_FLOAT, Vertex::colorOffset(), Vertex::ColorTupleSize, Vertex::stride());

       // Libérer (délier) tout
       cube1.m_object.release();
       m_vertex.release();
       m_program->release();


      //Initialisation du second objet
       m_program1 = new QOpenGLShaderProgram();
       m_program1->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/simple.vert");
       m_program1->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/simple.frag");
       m_program1->link();
       m_program1->bind();

       // Location du "Cache Uniform"
       u_modelToWorld = m_program->uniformLocation("modelToWorld");
       u_worldToView = m_program->uniformLocation("worldToView");
       u_worldToCamera = m_program->uniformLocation("worldToCamera");
       u_cameraToView = m_program->uniformLocation("cameraToView");

       //Créer un tampon (Ne pas relâcher avant la création de VAO)
       m_vertex1.create();
       m_vertex1.bind();
       m_vertex1.setUsagePattern(QOpenGLBuffer::StaticDraw);
       m_vertex1.allocate(plus, sizeof(plus));

       // Créer un objet de tableau Vertex
       cube2.m_object.create();
       cube2.m_object.bind();
       m_program1->enableAttributeArray(0);
       m_program1->enableAttributeArray(1);
       m_program1->setAttributeBuffer(0, GL_FLOAT, Vertex::positionOffset(), Vertex::PositionTupleSize, Vertex::stride());
       m_program1->setAttributeBuffer(1, GL_FLOAT, Vertex::colorOffset(), Vertex::ColorTupleSize, Vertex::stride());

       //Libérer (délier) tout
       cube2.m_object.release();
       m_vertex1.release();
       m_program1->release();

}




void mywindow::resizeGL(int width, int height)
{
    if(height == 0)
        height = 1;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (GLfloat)width/(GLfloat)height, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    m_projection.setToIdentity();
    m_projection.perspective(45.0f, width / float(height), 0.0f, 1000.0f);

}


//Dessin des objets sur la scène
void mywindow::paintGL()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    /*glLoadIdentity();
    m_program->bind();
    m_program->setUniformValue(u_worldToCamera, m_camera.toMatrix());
    m_program->setUniformValue(u_cameraToView, m_projection);
    m_program->setUniformValue(u_worldToView, m_projection);
         {
           cube1.m_object.bind();
           m_program->setUniformValue(u_modelToWorld, m_transform.toMatrix());
           cube1.dessinerRec();
           cube1.m_object.release();
         }
         m_program->release();

         //Remplace la matrice actuelle par une matrice identité
              glLoadIdentity();
              glRotatef(45.0, 1.0, 0.0, 0.0);*/
        m_program1->bind();
        m_program1->setUniformValue(u_worldToCamera, m_camera.toMatrix());
        m_program1->setUniformValue(u_cameraToView, m_projection);
        m_program1->setUniformValue(u_worldToView, m_projection);
              {
         cube2.m_object.bind();
         m_program1->setUniformValue(u_modelToWorld, m_transform.toMatrix());
         cube2.dessinerRec();
         cube2.m_object.release();
         }
         m_program1->release();
}

/*void mywindow::loadTexture(QString textureName)
{
    QImage qim_Texture;
    QImage qim_TempTexture;
    qim_TempTexture.load(textureName);
    qim_Texture = QGLWidget::convertToGLFormat( qim_TempTexture );
    glGenTextures( 1, &texture[0] );
    glBindTexture( GL_TEXTURE_2D, texture[0] );
    glTexImage2D( GL_TEXTURE_2D, 0, 3, qim_Texture.width(), qim_Texture.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, qim_Texture.bits() );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
}
*/


void mywindow::update()
{
  // Update instance information
  m_transform.rotate(1.0f, QVector3D(0.4f, 0.3f, 0.3f));

  // Schedule a redraw
  //QOpenGLWindow::update();
}

