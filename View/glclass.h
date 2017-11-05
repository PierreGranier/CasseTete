/*
 * classe qui définit opengl dans notre interface
*/
#ifndef GLCLASS_H
#define GLCLASS_H

#include <QtOpenGL>
#include <QGLWidget>
#include "cube.h"
#include "pieceplus.h"
#include "piecep.h"
#include "piecel.h"
#include "piecet.h"
#include "piecey.h"
#include "pieceangle.h"
#include "pieceg.h"
#include "pieced.h"
#include "piecez.h"
#include "camera3d.h"
#include<QWheelEvent>
class Glclass : public QGLWidget
{
    Q_OBJECT
public:

    //Constructeur
    explicit Glclass(int framesPerSecond = 0, QWidget *parent = 0, char *name = 0);

    //Requêtes OpenGl
    virtual void initializeGL() = 0;
    virtual void resizeGL(int width, int height) = 0;
    virtual void paintGL() = 0;

    //Evenements
    virtual void keyPressEvent( QKeyEvent *keyEvent );
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
    //virtual void QWheelEvent(const QPoint & pos, int delta, Qt::MouseButtons buttons, Qt::KeyboardModifiers modifiers, Qt::Orientation orient = Qt::Vertical);

    //Variables de traitement
    bool pressed=false;
    float xinit,xfin;
    float yinit,yfin;
    float dx,dy;
    // angle of rotation for the camera direction
    float angle=45.0;
    // actual vector representing the camera's direction
    float lx=0.0f,lz=-1.0f;
    // XZ position of the camera
    float x=0.0f,z=5.0f;

    //Variables de type cube
    PieceP pp;
    PiecePlus plus;
    PieceAngle pangle;
    PieceL pl;
    PieceT pt;
    PieceY py;
    PieceG pg;
    PieceD pd;
    PieceZ pz;

    //Cube pieceY;
    GLuint text; //identifiant de la texture

    //Variable de type camera
    Camera3D m_camera;

    //Variable de type camera
    Transform3D m_transform;
    Transform3D m_transform2;

public slots:
    virtual void timeOutSlot();

private:
    QTimer *t_Timer;



};

#endif // GLCLASS_H
