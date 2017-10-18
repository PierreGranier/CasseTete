
#include "mywindow.h"
#include<iostream>
#include<cube.h>
#include<vertex.h>
#include <QOpenGLShaderProgram>

//Constructeur
mywindow::mywindow(QWidget *parent)
    : Glclass(60, parent, "Casse tete 3D")
{
    cube1.m_transform.translate(-4.0f, 0.0f, -6.0f);
    cube1.m_transform.rotate(90.0f,1.0f,0.0f,0.0f);
    cube2.m_transform.translate(-3.0f, 0.0f, -8.0f);
    cube2.m_transform.rotate(90.0f,1.0f,0.0f,0.0f);
    cube3.m_transform.translate(0.0f, 0.0f, -10.0f);
    cube3.m_transform.rotate(90.0f,-1.0f,0.0f,0.0f);
    cube4.m_transform.translate(4.0f, 0.0f, -12.0f);
    cube4.m_transform.rotate(90.0f,1.0f,0.0f,0.0f);
    cube5.m_transform.translate(8.0f, 0.0f, -14.0f);
    cube5.m_transform.rotate(90.0f,1.0f,0.0f,0.0f);
}


//Initialisation de la scene
void mywindow::initializeGL()
{
  // Initialisation de l'arriere de la scène
     initializeOpenGLFunctions();
    /* QTimer *timer = new QTimer(this);
     connect(timer, SIGNAL(timeout()), this, SLOT(update()));
     timer->start(100);*/

     // Set global information
     glEnable(GL_CULL_FACE);
     glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

     // Application-specific initialization

       // Create Shader (Do not release until VAO is created)
       cube1.m_program = new QOpenGLShaderProgram();
       cube1.m_program->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/simple.vert");
       cube1.m_program->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/simple.frag");
       cube1.m_program->link();
       cube1.m_program->bind();

       // Location du "Cache Uniform"
       u_modelToWorld = cube1.m_program->uniformLocation("modelToWorld");
       u_worldToView = cube1.m_program->uniformLocation("worldToView");
       u_worldToCamera = cube1.m_program->uniformLocation("worldToCamera");
       u_cameraToView = cube1.m_program->uniformLocation("cameraToView");



       // Location du "Cache Uniform"
       cube1.u_modelToWorld = cube1.m_program->uniformLocation("modelToWorld");
       cube1.u_worldToView = cube1.m_program->uniformLocation("worldToView");
       cube1.u_worldToCamera = cube1.m_program->uniformLocation("worldToCamera");
       cube1.u_cameraToView = cube1.m_program->uniformLocation("cameraToView");



       // Créer un tampon (Ne pas relâcher avant la création de VAO)
       cube1.m_vertex.create();
       cube1.m_vertex.bind();
       cube1.m_vertex.setUsagePattern(QOpenGLBuffer::StaticDraw);
       cube1.m_vertex.allocate(p, sizeof(p));

       // Créer un objet de tableau Vertex
       cube1.m_object.create();
       cube1.m_object.bind();
       cube1.m_program->enableAttributeArray(0);
       cube1.m_program->enableAttributeArray(1);
       cube1.m_program->setAttributeBuffer(0, GL_FLOAT, Vertex::positionOffset(), Vertex::PositionTupleSize, Vertex::stride());
       cube1.m_program->setAttributeBuffer(1, GL_FLOAT, Vertex::colorOffset(), Vertex::ColorTupleSize, Vertex::stride());

       // Libérer (délier) tout
       cube1.m_object.release();
       cube1.m_vertex.release();
       cube1.m_program->release();


      //Initialisation du second objet
       cube2.m_program = new QOpenGLShaderProgram();
       cube2.m_program->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/simple.vert");
       cube2.m_program->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/simple.frag");
       cube2.m_program->link();
       cube2.m_program->bind();

       // Location du "Cache Uniform"
       cube2.u_modelToWorld = cube2.m_program->uniformLocation("modelToWorld");
       cube2.u_worldToView = cube2.m_program->uniformLocation("worldToView");
       cube2.u_worldToCamera = cube2.m_program->uniformLocation("worldToCamera");
       cube2.u_cameraToView = cube2.m_program->uniformLocation("cameraToView");

       //Créer un tampon (Ne pas relâcher avant la création de VAO)
       cube2.m_vertex.create();
       cube2.m_vertex.bind();
       cube2.m_vertex.setUsagePattern(QOpenGLBuffer::StaticDraw);
       cube2.m_vertex.allocate(plus, sizeof(plus));

       // Créer un objet de tableau Vertex
       cube2.m_object.create();
       cube2.m_object.bind();
       cube2.m_program->enableAttributeArray(0);
       cube2.m_program->enableAttributeArray(1);
       cube2.m_program->setAttributeBuffer(0, GL_FLOAT, Vertex::positionOffset(), Vertex::PositionTupleSize, Vertex::stride());
       cube2.m_program->setAttributeBuffer(1, GL_FLOAT, Vertex::colorOffset(), Vertex::ColorTupleSize, Vertex::stride());

       //Libérer (délier) tout
       cube2.m_object.release();
       cube2.m_vertex.release();
       cube2.m_program->release();



       //Initialisation du troisieme objet
        cube3.m_program = new QOpenGLShaderProgram();
        cube3.m_program->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/simple.vert");
        cube3.m_program->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/simple.frag");
        cube3.m_program->link();
        cube3.m_program->bind();

        // Location du "Cache Uniform"
        cube3.u_modelToWorld = cube3.m_program->uniformLocation("modelToWorld");
        cube3.u_worldToView = cube3.m_program->uniformLocation("worldToView");
        cube3.u_worldToCamera = cube3.m_program->uniformLocation("worldToCamera");
        cube3.u_cameraToView = cube3.m_program->uniformLocation("cameraToView");

        //Créer un tampon (Ne pas relâcher avant la création de VAO)
        cube3.m_vertex.create();
        cube3.m_vertex.bind();
        cube3.m_vertex.setUsagePattern(QOpenGLBuffer::StaticDraw);
        cube3.m_vertex.allocate(t, sizeof(t));

        // Créer un objet de tableau Vertex
        cube3.m_object.create();
        cube3.m_object.bind();
        cube3.m_program->enableAttributeArray(0);
        cube3.m_program->enableAttributeArray(1);
        cube3.m_program->setAttributeBuffer(0, GL_FLOAT, Vertex::positionOffset(), Vertex::PositionTupleSize, Vertex::stride());
        cube3.m_program->setAttributeBuffer(1, GL_FLOAT, Vertex::colorOffset(), Vertex::ColorTupleSize, Vertex::stride());

        //Libérer (délier) tout
        cube3.m_object.release();
        cube3.m_vertex.release();
        cube3.m_program->release();



        //Initialisation du quatrième objet
         cube4.m_program = new QOpenGLShaderProgram();
         cube4.m_program->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/simple.vert");
         cube4.m_program->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/simple.frag");
         cube4.m_program->link();
         cube4.m_program->bind();

         // Location du "Cache Uniform"
         cube4.u_modelToWorld = cube4.m_program->uniformLocation("modelToWorld");
         cube4.u_worldToView = cube4.m_program->uniformLocation("worldToView");
         cube4.u_worldToCamera = cube4.m_program->uniformLocation("worldToCamera");
         cube4.u_cameraToView = cube4.m_program->uniformLocation("cameraToView");

         //Créer un tampon (Ne pas relâcher avant la création de VAO)
         cube4.m_vertex.create();
         cube4.m_vertex.bind();
         cube4.m_vertex.setUsagePattern(QOpenGLBuffer::StaticDraw);
         cube4.m_vertex.allocate(l, sizeof(l));

         // Créer un objet de tableau Vertex
         cube4.m_object.create();
         cube4.m_object.bind();
         cube4.m_program->enableAttributeArray(0);
         cube4.m_program->enableAttributeArray(1);
         cube4.m_program->setAttributeBuffer(0, GL_FLOAT, Vertex::positionOffset(), Vertex::PositionTupleSize, Vertex::stride());
         cube4.m_program->setAttributeBuffer(1, GL_FLOAT, Vertex::colorOffset(), Vertex::ColorTupleSize, Vertex::stride());

         //Libérer (délier) tout
         cube4.m_object.release();
         cube4.m_vertex.release();
         cube4.m_program->release();


         //Initialisation du cinquième objet
          cube5.m_program = new QOpenGLShaderProgram();
          cube5.m_program->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/simple.vert");
          cube5.m_program->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/simple.frag");
          cube5.m_program->link();
          cube5.m_program->bind();

          // Location du "Cache Uniform"
          cube5.u_modelToWorld = cube5.m_program->uniformLocation("modelToWorld");
          cube5.u_worldToView = cube5.m_program->uniformLocation("worldToView");
          cube5.u_worldToCamera = cube5.m_program->uniformLocation("worldToCamera");
          cube5.u_cameraToView = cube5.m_program->uniformLocation("cameraToView");

          //Créer un tampon (Ne pas relâcher avant la création de VAO)
          cube5.m_vertex.create();
          cube5.m_vertex.bind();
          cube5.m_vertex.setUsagePattern(QOpenGLBuffer::StaticDraw);
          cube5.m_vertex.allocate(ang, sizeof(ang));

          // Créer un objet de tableau Vertex
          cube5.m_object.create();
          cube5.m_object.bind();
          cube5.m_program->enableAttributeArray(0);
          cube5.m_program->enableAttributeArray(1);
          cube5.m_program->setAttributeBuffer(0, GL_FLOAT, Vertex::positionOffset(), Vertex::PositionTupleSize, Vertex::stride());
          cube5.m_program->setAttributeBuffer(1, GL_FLOAT, Vertex::colorOffset(), Vertex::ColorTupleSize, Vertex::stride());

          //Libérer (délier) tout
          cube5.m_object.release();
          cube5.m_vertex.release();
          cube5.m_program->release();


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
    cube1.m_projection.setToIdentity();
    cube1.m_projection.perspective(45.0f, width / float(height), 0.0f, 1000.0f);
    cube2.m_projection.setToIdentity();
    cube2.m_projection.perspective(45.0f, width / float(height), 0.0f, 1000.0f);
    cube3.m_projection.setToIdentity();
    cube3.m_projection.perspective(45.0f, width / float(height), 0.0f, 1000.0f);
    cube4.m_projection.setToIdentity();
    cube4.m_projection.perspective(45.0f, width / float(height), 0.0f, 1000.0f);
    cube5.m_projection.setToIdentity();
    cube5.m_projection.perspective(45.0f, width / float(height), 0.0f, 1000.0f);

}


//Dessin des objets sur la scène
void mywindow::paintGL()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    cube1.dessinerP();
   //Remplace la matrice actuelle par une matrice identité
    glLoadIdentity();
   //update();
    cube2.m_transform.setTranslation(-3.0f, 0.0f, -8.0f);
    cube2.dessinerPlus();
    glLoadIdentity();
    //update();
    cube3.m_transform.setTranslation(0.0f, 0.0f, -10.0f);
    cube3.dessinerT();
    glLoadIdentity();
    //update();
    cube4.m_transform.setTranslation(4.0f, 0.0f, -12.0f);
    cube4.dessinerL();
    //update();
    cube5.m_transform.setTranslation(8.0f, 0.0f, -14.0f);
    cube5.dessinerAngle();

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
  cube1.m_transform.rotate(1.0f, QVector3D(0.4f, 0.3f, 0.3f));

  // Schedule a redraw
  //QOpenGLWindow::update();
}

