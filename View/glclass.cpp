#include "glclass.h"


//Constructeur
Glclass::Glclass(int framesPerSecond, QWidget *parent, char *name)  : QGLWidget(parent)
{
    setWindowTitle(QString::fromUtf8(name));
    setMouseTracking(true);

    if(framesPerSecond == 0)
        t_Timer = NULL;
    else
    {
        int seconde = 1000; // 1 seconde = 1000 ms
        int timerInterval = seconde / framesPerSecond;
        t_Timer = new QTimer(this);
        connect(t_Timer, SIGNAL(timeout()), this, SLOT(timeOutSlot()));
        t_Timer->start( timerInterval );
    }
}


/*Gestion des evenements de clavier
void Glclass::keyPressEvent(QKeyEvent *keyEvent)
{
   float fraction=0.1f;
        switch(keyEvent->key())
        {
        case Qt::Key_Escape: close();break;
        case Qt::Key_Up: x += 1; z += 1;break;
        case Qt::Key_Down:x -= lx * fraction;z -= lz * fraction;break;
        case Qt::Key_Left:angle -= 0.01f;lx = sin(angle);lz = -cos(angle);break;
        case Qt::Key_Right:angle += 0.01f;lx = sin(angle);lz = -cos(angle);break;
        /*
        case Qt::Key_Z: cube2.y+=1; break;
        case Qt::Key_S: cube2.y-=1; break;
        case Qt::Key_D: cube2.x+=1; break;
        case Qt::Key_Q: cube2.x-=1; break;

        }
/*
cube1.m_camera.translate(transSpeed * translation);
cube1.m_transform.rotate(1.0f, QVector3D(0.4f, 0.3f, 0.3f));
cube2.m_camera.translate(transSpeed * translation);
cube2.m_transform.rotate(1.0f, QVector3D(0.4f, 0.3f, 0.3f));
cube3.m_camera.translate(transSpeed * translation);
cube3.m_transform.rotate(1.0f, QVector3D(0.4f, 0.3f, 0.3f));
cube4.m_camera.translate(transSpeed * translation);
cube4.m_transform.rotate(1.0f, QVector3D(0.4f, 0.3f, 0.3f));
pd.m_camera.translate(transSpeed * translation);
pd.m_transform.rotate(angle, QVector3D(0.4f, 0.3f, 0.3f));

    paintGL();
}
*/


void Glclass::timeOutSlot()
{
    updateGL();
}

