
#include "mywindow.h"
#include<iostream>
#include"piecep.h"
#include"pieceplus.h"
#include"pieceangle.h"
#include"piecet.h"
#include"piecel.h"
#include"piecey.h"
#include"pieceg.h"
#include"piecez.h"
#include"vertex.h"
#include <QOpenGLShaderProgram>

//Constructeur
mywindow::mywindow(QWidget *parent) : Glclass(60, parent, "Casse tete 3D")
{
    pp.m_transform.translate(-4.0f, 0.0f, -6.0f);
    pp.m_transform.rotate(90.0f,1.0f,0.0f,0.0f);
    plus.m_transform.translate(-3.0f, 0.0f, -8.0f);
    plus.m_transform.rotate(90.0f,1.0f,0.0f,0.0f);
    pt.m_transform.translate(0.0f, 0.0f, -10.0f);
    pt.m_transform.rotate(90.0f,-1.0f,0.0f,0.0f);
    pl.m_transform.translate(4.0f, 0.0f, -12.0f);
    pl.m_transform.rotate(90.0f,1.0f,0.0f,0.0f);
    pangle.m_transform.translate(8.0f, 0.0f, -14.0f);
    pangle.m_transform.rotate(90.0f,1.0f,0.0f,0.0f);
    py.m_transform.translate(-3.0f, -2.0f, -8.0f);
    py.m_transform.rotate(90.0f,0.0f,1.0f,0.0f);
    py.m_transform.rotate(90.0f,1.0f,0.0f,0.0f);
    pg.m_transform.translate(0.0f, -2.0f, -10.0f);
    pg.m_transform.rotate(90.0f,1.0f,0.0f,0.0f);
    pd.m_transform.translate(4.0f, -2.0f, -12.0f);
    pd.m_transform.rotate(90.0f,1.0f,0.0f,0.0f);
    pz.m_transform.translate(8.0f, -2.0f, -14.0f);
    pz.m_transform.rotate(90.0f,1.0f,0.0f,0.0f);
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
     //glEnable(GL_DEPTH_TEST);

     //loadTexture("images/1.jpg");
     glEnable(GL_TEXTURE_2D);

     glEnable(GL_CULL_FACE);
     glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
     // Application-specific initialization

       // Create Shader (Do not release until VAO is created)
       pp.m_program = new QOpenGLShaderProgram();
       pp.m_program->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/simple.vert");
       pp.m_program->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/simple.frag");
       pp.m_program->link();
       pp.m_program->bind();
       //pp.m_program->setUniformValue("textures", 0);




       // Location du "Cache Uniform"
       pp.u_modelToWorld = pp.m_program->uniformLocation("modelToWorld");
       pp.u_worldToView = pp.m_program->uniformLocation("worldToView");
       pp.u_worldToCamera = pp.m_program->uniformLocation("worldToCamera");
       pp.u_cameraToView = pp.m_program->uniformLocation("cameraToView");



       // Créer un tampon (Ne pas relâcher avant la création de VAO)
       pp.m_vertex.create();
       pp.m_vertex.bind();
       pp.m_vertex.setUsagePattern(QOpenGLBuffer::StaticDraw);
       pp.m_vertex.allocate(p, sizeof(p));

       // Créer un objet de tableau Vertex
       pp.m_object.create();
       pp.m_object.bind();
       pp.m_program->enableAttributeArray(0);
       pp.m_program->enableAttributeArray(1);
       pp.m_program->setAttributeBuffer(0, GL_FLOAT, Vertex::positionOffset(), Vertex::PositionTupleSize, Vertex::stride());
       pp.m_program->setAttributeBuffer(1, GL_FLOAT, Vertex::colorOffset(), Vertex::ColorTupleSize, Vertex::stride());

       // Libérer (délier) tout
       pp.m_object.release();
       pp.m_vertex.release();
       pp.m_program->release();


      //Initialisation du second objet
       plus.m_program = new QOpenGLShaderProgram();
       plus.m_program->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/simple.vert");
       plus.m_program->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/simple.frag");
       plus.m_program->link();
       plus.m_program->bind();

       // Location du "Cache Uniform"
       plus.u_modelToWorld = plus.m_program->uniformLocation("modelToWorld");
       plus.u_worldToView = plus.m_program->uniformLocation("worldToView");
       plus.u_worldToCamera = plus.m_program->uniformLocation("worldToCamera");
       plus.u_cameraToView = plus.m_program->uniformLocation("cameraToView");

       //Créer un tampon (Ne pas relâcher avant la création de VAO)
       plus.m_vertex.create();
       plus.m_vertex.bind();
       plus.m_vertex.setUsagePattern(QOpenGLBuffer::StaticDraw);
       plus.m_vertex.allocate(pluss, sizeof(pluss));

       // Créer un objet de tableau Vertex
       plus.m_object.create();
       plus.m_object.bind();
       plus.m_program->enableAttributeArray(0);
       plus.m_program->enableAttributeArray(1);
       plus.m_program->setAttributeBuffer(0, GL_FLOAT, Vertex::positionOffset(), Vertex::PositionTupleSize, Vertex::stride());
       plus.m_program->setAttributeBuffer(1, GL_FLOAT, Vertex::colorOffset(), Vertex::ColorTupleSize, Vertex::stride());

       //Libérer (délier) tout
       plus.m_object.release();
       plus.m_vertex.release();
       plus.m_program->release();



       //Initialisation du troisieme objet
        pt.m_program = new QOpenGLShaderProgram();
        pt.m_program->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/simple.vert");
        pt.m_program->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/simple.frag");
        pt.m_program->link();
        pt.m_program->bind();

        // Location du "Cache Uniform"
        pt.u_modelToWorld = pt.m_program->uniformLocation("modelToWorld");
        pt.u_worldToView = pt.m_program->uniformLocation("worldToView");
        pt.u_worldToCamera = pt.m_program->uniformLocation("worldToCamera");
        pt.u_cameraToView = pt.m_program->uniformLocation("cameraToView");

        //Créer un tampon (Ne pas relâcher avant la création de VAO)
        pt.m_vertex.create();
        pt.m_vertex.bind();
        pt.m_vertex.setUsagePattern(QOpenGLBuffer::StaticDraw);
        pt.m_vertex.allocate(t, sizeof(t));

        // Créer un objet de tableau Vertex
        pt.m_object.create();
        pt.m_object.bind();
        pt.m_program->enableAttributeArray(0);
        pt.m_program->enableAttributeArray(1);
        pt.m_program->setAttributeBuffer(0, GL_FLOAT, Vertex::positionOffset(), Vertex::PositionTupleSize, Vertex::stride());
        pt.m_program->setAttributeBuffer(1, GL_FLOAT, Vertex::colorOffset(), Vertex::ColorTupleSize, Vertex::stride());

        //Libérer (délier) tout
        pt.m_object.release();
        pt.m_vertex.release();
        pt.m_program->release();



        //Initialisation du quatrième objet
         pl.m_program = new QOpenGLShaderProgram();
         pl.m_program->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/simple.vert");
         pl.m_program->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/simple.frag");
         pl.m_program->link();
         pl.m_program->bind();

         // Location du "Cache Uniform"
         pl.u_modelToWorld = pl.m_program->uniformLocation("modelToWorld");
         pl.u_worldToView = pl.m_program->uniformLocation("worldToView");
         pl.u_worldToCamera = pl.m_program->uniformLocation("worldToCamera");
         pl.u_cameraToView = pl.m_program->uniformLocation("cameraToView");

         //Créer un tampon (Ne pas relâcher avant la création de VAO)
         pl.m_vertex.create();
         pl.m_vertex.bind();
         pl.m_vertex.setUsagePattern(QOpenGLBuffer::StaticDraw);
         pl.m_vertex.allocate(l, sizeof(l));

         // Créer un objet de tableau Vertex
         pl.m_object.create();
         pl.m_object.bind();
         pl.m_program->enableAttributeArray(0);
         pl.m_program->enableAttributeArray(1);
         pl.m_program->setAttributeBuffer(0, GL_FLOAT, Vertex::positionOffset(), Vertex::PositionTupleSize, Vertex::stride());
         pl.m_program->setAttributeBuffer(1, GL_FLOAT, Vertex::colorOffset(), Vertex::ColorTupleSize, Vertex::stride());

         //Libérer (délier) tout
         pl.m_object.release();
         pl.m_vertex.release();
         pl.m_program->release();


         //Initialisation du cinquième objet
          pangle.m_program = new QOpenGLShaderProgram();
          pangle.m_program->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/simple.vert");
          pangle.m_program->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/simple.frag");
          pangle.m_program->link();
          pangle.m_program->bind();

          // Location du "Cache Uniform"
          pangle.u_modelToWorld = pangle.m_program->uniformLocation("modelToWorld");
          pangle.u_worldToView = pangle.m_program->uniformLocation("worldToView");
          pangle.u_worldToCamera = pangle.m_program->uniformLocation("worldToCamera");
          pangle.u_cameraToView = pangle.m_program->uniformLocation("cameraToView");

          //Créer un tampon (Ne pas relâcher avant la création de VAO)
          pangle.m_vertex.create();
          pangle.m_vertex.bind();
          pangle.m_vertex.setUsagePattern(QOpenGLBuffer::StaticDraw);
          pangle.m_vertex.allocate(ang, sizeof(ang));

          // Créer un objet de tableau Vertex
          pangle.m_object.create();
          pangle.m_object.bind();
          pangle.m_program->enableAttributeArray(0);
          pangle.m_program->enableAttributeArray(1);
          pangle.m_program->setAttributeBuffer(0, GL_FLOAT, Vertex::positionOffset(), Vertex::PositionTupleSize, Vertex::stride());
          pangle.m_program->setAttributeBuffer(1, GL_FLOAT, Vertex::colorOffset(), Vertex::ColorTupleSize, Vertex::stride());

          //Libérer (délier) tout
          pangle.m_object.release();
          pangle.m_vertex.release();
          pangle.m_program->release();




          //Initialisation de l'object py
           py.m_program = new QOpenGLShaderProgram();
           py.m_program->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/simple.vert");
           py.m_program->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/simple.frag");
           py.m_program->link();
           py.m_program->bind();

           // Location du "Cache Uniform"
           py.u_modelToWorld = py.m_program->uniformLocation("modelToWorld");
           py.u_worldToView = py.m_program->uniformLocation("worldToView");
           py.u_worldToCamera = py.m_program->uniformLocation("worldToCamera");
           py.u_cameraToView = py.m_program->uniformLocation("cameraToView");

           //Créer un tampon (Ne pas relâcher avant la création de VAO)
           py.m_vertex.create();
           py.m_vertex.bind();
           py.m_vertex.setUsagePattern(QOpenGLBuffer::StaticDraw);
           py.m_vertex.allocate(ppy, sizeof(ppy));

           // Créer un objet de tableau Vertex
           py.m_object.create();
           py.m_object.bind();
           py.m_program->enableAttributeArray(0);
           py.m_program->enableAttributeArray(1);
           py.m_program->setAttributeBuffer(0, GL_FLOAT, Vertex::positionOffset(), Vertex::PositionTupleSize, Vertex::stride());
           py.m_program->setAttributeBuffer(1, GL_FLOAT, Vertex::colorOffset(), Vertex::ColorTupleSize, Vertex::stride());

           //Libérer (délier) tout
           py.m_object.release();
           py.m_vertex.release();
           py.m_program->release();



           //Initialisation de l'object pg
            pg.m_program = new QOpenGLShaderProgram();
            pg.m_program->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/simple.vert");
            pg.m_program->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/simple.frag");
            pg.m_program->link();
            pg.m_program->bind();

            // Location du "Cache Uniform"
            pg.u_modelToWorld = pg.m_program->uniformLocation("modelToWorld");
            pg.u_worldToView = pg.m_program->uniformLocation("worldToView");
            pg.u_worldToCamera = pg.m_program->uniformLocation("worldToCamera");
            pg.u_cameraToView = pg.m_program->uniformLocation("cameraToView");

            //Créer un tampon (Ne pas relâcher avant la création de VAO)
            pg.m_vertex.create();
            pg.m_vertex.bind();
            pg.m_vertex.setUsagePattern(QOpenGLBuffer::StaticDraw);
            pg.m_vertex.allocate(ppg, sizeof(ppg));

            // Créer un objet de tableau Vertex
            pg.m_object.create();
            pg.m_object.bind();
            pg.m_program->enableAttributeArray(0);
            pg.m_program->enableAttributeArray(1);
            pg.m_program->setAttributeBuffer(0, GL_FLOAT, Vertex::positionOffset(), Vertex::PositionTupleSize, Vertex::stride());
            pg.m_program->setAttributeBuffer(1, GL_FLOAT, Vertex::colorOffset(), Vertex::ColorTupleSize, Vertex::stride());

            //Libérer (délier) tout
            pg.m_object.release();
            pg.m_vertex.release();
            pg.m_program->release();


            //Initialisation de l'object pd
             pg.m_program = new QOpenGLShaderProgram();
             pg.m_program->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/simple.vert");
             pg.m_program->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/simple.frag");
             pg.m_program->link();
             pg.m_program->bind();

             // Location du "Cache Uniform"
             pg.u_modelToWorld = pg.m_program->uniformLocation("modelToWorld");
             pg.u_worldToView = pg.m_program->uniformLocation("worldToView");
             pg.u_worldToCamera = pg.m_program->uniformLocation("worldToCamera");
             pg.u_cameraToView = pg.m_program->uniformLocation("cameraToView");

             //Créer un tampon (Ne pas relâcher avant la création de VAO)
             pg.m_vertex.create();
             pg.m_vertex.bind();
             pg.m_vertex.setUsagePattern(QOpenGLBuffer::StaticDraw);
             pg.m_vertex.allocate(ppg, sizeof(ppg));

             // Créer un objet de tableau Vertex
             pg.m_object.create();
             pg.m_object.bind();
             pg.m_program->enableAttributeArray(0);
             pg.m_program->enableAttributeArray(1);
             pg.m_program->setAttributeBuffer(0, GL_FLOAT, Vertex::positionOffset(), Vertex::PositionTupleSize, Vertex::stride());
             pg.m_program->setAttributeBuffer(1, GL_FLOAT, Vertex::colorOffset(), Vertex::ColorTupleSize, Vertex::stride());

             //Libérer (délier) tout
             pg.m_object.release();
             pg.m_vertex.release();
             pg.m_program->release();

             //Initialisation de l'object pg
              pg.m_program = new QOpenGLShaderProgram();
              pg.m_program->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/simple.vert");
              pg.m_program->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/simple.frag");
              pg.m_program->link();
              pg.m_program->bind();

              // Location du "Cache Uniform"
              pg.u_modelToWorld = pg.m_program->uniformLocation("modelToWorld");
              pg.u_worldToView = pg.m_program->uniformLocation("worldToView");
              pg.u_worldToCamera = pg.m_program->uniformLocation("worldToCamera");
              pg.u_cameraToView = pg.m_program->uniformLocation("cameraToView");

              //Créer un tampon (Ne pas relâcher avant la création de VAO)
              pg.m_vertex.create();
              pg.m_vertex.bind();
              pg.m_vertex.setUsagePattern(QOpenGLBuffer::StaticDraw);
              pg.m_vertex.allocate(ppg, sizeof(ppg));

              // Créer un objet de tableau Vertex
              pg.m_object.create();
              pg.m_object.bind();
              pg.m_program->enableAttributeArray(0);
              pg.m_program->enableAttributeArray(1);
              pg.m_program->setAttributeBuffer(0, GL_FLOAT, Vertex::positionOffset(), Vertex::PositionTupleSize, Vertex::stride());
              pg.m_program->setAttributeBuffer(1, GL_FLOAT, Vertex::colorOffset(), Vertex::ColorTupleSize, Vertex::stride());

              //Libérer (délier) tout
              pg.m_object.release();
              pg.m_vertex.release();
              pg.m_program->release();


              //Initialisation de l'object pd
               pd.m_program = new QOpenGLShaderProgram();
               pd.m_program->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/simple.vert");
               pd.m_program->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/simple.frag");
               pd.m_program->link();
               pd.m_program->bind();

               // Location du "Cache Uniform"
               pd.u_modelToWorld = pd.m_program->uniformLocation("modelToWorld");
               pd.u_worldToView = pd.m_program->uniformLocation("worldToView");
               pd.u_worldToCamera = pd.m_program->uniformLocation("worldToCamera");
               pd.u_cameraToView = pd.m_program->uniformLocation("cameraToView");

               //Créer un tampon (Ne pas relâcher avant la création de VAO)
               pd.m_vertex.create();
               pd.m_vertex.bind();
               pd.m_vertex.setUsagePattern(QOpenGLBuffer::StaticDraw);
               pd.m_vertex.allocate(ppd, sizeof(ppd));

               // Créer un objet de tableau Vertex
               pd.m_object.create();
               pd.m_object.bind();
               pd.m_program->enableAttributeArray(0);
               pd.m_program->enableAttributeArray(1);
               pd.m_program->setAttributeBuffer(0, GL_FLOAT, Vertex::positionOffset(), Vertex::PositionTupleSize, Vertex::stride());
               pd.m_program->setAttributeBuffer(1, GL_FLOAT, Vertex::colorOffset(), Vertex::ColorTupleSize, Vertex::stride());

               //Libérer (délier) tout
               pd.m_object.release();
               pd.m_vertex.release();
               pd.m_program->release();




               //Initialisation de l'object pz
                pz.m_program = new QOpenGLShaderProgram();
                pz.m_program->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/simple.vert");
                pz.m_program->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/simple.frag");
                pz.m_program->link();
                pz.m_program->bind();

                // Location du "Cache Uniform"
                pz.u_modelToWorld = pz.m_program->uniformLocation("modelToWorld");
                pz.u_worldToView = pz.m_program->uniformLocation("worldToView");
                pz.u_worldToCamera = pz.m_program->uniformLocation("worldToCamera");
                pz.u_cameraToView = pz.m_program->uniformLocation("cameraToView");

                //Créer un tampon (Ne pas relâcher avant la création de VAO)
                pz.m_vertex.create();
                pz.m_vertex.bind();
                pz.m_vertex.setUsagePattern(QOpenGLBuffer::StaticDraw);
                pz.m_vertex.allocate(ppz, sizeof(ppz));

                // Créer un objet de tableau Vertex
                pz.m_object.create();
                pz.m_object.bind();
                pz.m_program->enableAttributeArray(0);
                pz.m_program->enableAttributeArray(1);
                pz.m_program->setAttributeBuffer(0, GL_FLOAT, Vertex::positionOffset(), Vertex::PositionTupleSize, Vertex::stride());
                pz.m_program->setAttributeBuffer(1, GL_FLOAT, Vertex::colorOffset(), Vertex::ColorTupleSize, Vertex::stride());

                //Libérer (délier) tout
                pz.m_object.release();
                pz.m_vertex.release();
                pz.m_program->release();


}




void mywindow::resizeGL(int width, int height)
{
    if(height == 0)
        height = 1;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90.0f,(float)500/500,0.1,100);
    glMatrixMode(GL_MODELVIEW);
    pp.m_projection.setToIdentity();
    pp.m_projection.perspective(45.0f, width / float(height), 0.0f, 1000.0f);
    plus.m_projection.setToIdentity();
    plus.m_projection.perspective(45.0f, width / float(height), 0.0f, 1000.0f);
    pt.m_projection.setToIdentity();
    pt.m_projection.perspective(45.0f, width / float(height), 0.0f, 1000.0f);
    pl.m_projection.setToIdentity();
    pl.m_projection.perspective(45.0f, width / float(height), 0.0f, 1000.0f);
    pangle.m_projection.setToIdentity();
    pangle.m_projection.perspective(45.0f, width / float(height), 0.0f, 1000.0f);
    py.m_projection.setToIdentity();
    py.m_projection.perspective(45.0f, width / float(height), 0.0f, 1000.0f);
    pg.m_projection.setToIdentity();
    pg.m_projection.perspective(45.0f, width / float(height), 0.0f, 1000.0f);
    pd.m_projection.setToIdentity();
    pd.m_projection.perspective(45.0f, width / float(height), 0.0f, 1000.0f);
    pz.m_projection.setToIdentity();
    pz.m_projection.perspective(45.0f, width / float(height), 0.0f, 1000.0f);


}


//Dessin des objets sur la scène
void mywindow::paintGL(){
   glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
   glLoadIdentity();
   gluLookAt(x, 1.0f, z, x+lx, 1.0f,  z+lz,0.0f, 1.0f,  0.0f);


   glRotatef(angle,0.0f,1.0f,0.0f);
   //glBindTexture(GL_TEXTURE_2D, textures[0]);
    pp.dessinerP(&m_camera);

    plus.m_transform.setTranslation(-3.0f, 0.0f, -8.0f);
    plus.dessinerPlus(&m_camera);

    pt.m_transform.setTranslation(0.0f, 0.0f, -10.0f);
    pt.dessinerT(&m_camera);


    pl.m_transform.setTranslation(4.0f, 0.0f, -12.0f);
    pl.dessinerL(&m_camera);


    pangle.m_transform.setTranslation(8.0f, 0.0f, -14.0f);
    pangle.dessinerAngle(&m_camera);

    py.m_transform.setTranslation(-3.0f, -2.0f, -8.0f);
    py.dessinerY(&m_camera);


   pg.m_transform.setTranslation(0.0f, -2.0f, -10.0f);
   pg.dessinerG(&m_camera);

   pd.m_transform.setTranslation(4.0f, -2.0f, -12.0f);
   pd.dessinerD(&m_camera);

   pz.m_transform.setTranslation(8.0f, -2.0f, -14.0f);
   pz.dessinerZ(&m_camera);

}


void mywindow::loadTexture(QString textureName)
{
    QImage qim_Texture;
    QImage qim_TempTexture;
    qim_TempTexture.load(textureName);
    qim_Texture = QGLWidget::convertToGLFormat( qim_TempTexture );
    glGenTextures( 1, &textures[8] );
    glBindTexture( GL_TEXTURE_2D, textures[8] );
    glTexImage2D( GL_TEXTURE_2D, 0, 3, qim_Texture.width(), qim_Texture.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, qim_Texture.bits() );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
}

void mywindow::update()
{
  // Update instance information
  py.m_transform.rotate(1.0f, QVector3D(0.4f, 0.3f, 0.3f));

  // Schedule a redraw
  //QOpenGLWindow::update();
}

