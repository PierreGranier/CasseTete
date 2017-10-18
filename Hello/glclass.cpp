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


//Gestion des evenements de clavier
void Glclass::keyPressEvent(QKeyEvent *keyEvent)
{
static const float transSpeed = 0.5f;
    static const float rotSpeed   = 0.5f;

    // Gérer les rotations
    m_camera.rotate(-rotSpeed * xinit, Camera3D::LocalUp);
    m_camera.rotate(-rotSpeed * yinit, m_camera.right());

    // Gérer les translations
    QVector3D translation;
        switch(keyEvent->key())
        {
        case Qt::Key_Escape: close();break;
        case Qt::Key_Up:translation += m_camera.forward(); break;
        case Qt::Key_Down:translation -=m_camera.forward(); break;
        case Qt::Key_Left:translation -=m_camera.right(); break;
        case Qt::Key_Right:translation +=m_camera.right(); break;
        /*case Qt::Key_Z: cube2.y+=1; break;
        case Qt::Key_S: cube2.y-=1; break;
        case Qt::Key_D: cube2.x+=1; break;
        case Qt::Key_Q: cube2.x-=1; break;*/
        }
cube1.m_camera.translate(transSpeed * translation);
cube1.m_transform.rotate(1.0f, QVector3D(0.4f, 0.3f, 0.3f));
    paintGL();
}

//Gestion des evenements de souris
void Glclass::mousePressEvent(QMouseEvent *event)
{
      if (event->button()==Qt::RightButton)
           {
             qDebug() << "right button is pressed";
             pressed=true; //<-----
             xinit=event->x();
             yinit=event->y();
             //qDebug() << "x="<<xinit<<"y="<<yinit;
            }
}

//Gestion des evenements de relache de souris
void Glclass::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button()==Qt::RightButton)
        {
           qDebug() << "right button is released";
           pressed=false; //<-----


        }
}

/*QWheelEvent::QWheelEvent(const QPoint & pos, int delta, Qt::MouseButtons buttons, Qt::KeyboardModifiers modifiers, Qt::Orientation orient)
{

        qDebug() << "delta" << delta;
        static const float transSpeed = 0.5f;
        static const float rotSpeed   = 0.5f;

        // Handle rotations
        m_camera.rotate(-rotSpeed * xinit, Camera3D::LocalUp);
        m_camera.rotate(-rotSpeed * yinit, m_camera.right());

        // Handle translations
        QVector3D translation;

    if(delta > 0) {
    cube1.y+=1;
    translation += m_camera.forward();
    }
    else if(delta < 0) {
    cube1.y-=1;
    translation -= m_camera.forward();
    m_camera.translate(transSpeed * translation);
    m_transform.rotate(1.0f, QVector3D(0.4f, 0.3f, 0.3f));
        paintGL();
    }

    }*/

//Gestion des evenements de "move" de la souris
void Glclass::mouseMoveEvent(QMouseEvent *event)

{
    if(pressed)
    {
        xfin=event->x();
        yfin=event->y();
        //qDebug() << "x="<<xinit<<"y="<<yinit;
        //qDebug() << event->pos();
        dx = xfin-xinit;
        dy= yfin-yinit;
        qDebug() << "dx="<<dx<<"dy="<<dy;


    static const float transSpeed = 0.005f;
    static const float rotSpeed   = 0.005f;

   // Gérer les rotations
    m_camera.rotate(-rotSpeed * event->x(), Camera3D::LocalUp);
    m_camera.rotate(-rotSpeed * event->y(), m_camera.right());

   paintGL();
    }

}


void Glclass::timeOutSlot()
{
    updateGL();
}

