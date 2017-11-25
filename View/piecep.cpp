#include "piecep.h"

PieceP::PieceP()
{

}
void PieceP::dessinerP()
     {

    m_program->bind();m_program->setUniformValue(u_worldToCamera, m_camera.toMatrix());
    m_program->setUniformValue(u_cameraToView, m_projection);
    m_program->setUniformValue(u_worldToView, m_projection);
         {
           m_object.bind();
           m_program->setUniformValue(u_modelToWorld, m_transform.toMatrix());
           //texture[0]->bind();
           glDrawArrays(GL_TRIANGLES, 0, sizeof(p) / sizeof(p[0]));
           m_object.release();
}
     m_program->release();

      }
void PieceP::update()
{
  // Update input
  Input::update();

  // Camera Transformation
  if (Input::buttonPressed(Qt::RightButton))
  {

    static const float rotSpeed   = 0.1f;


    // Handle rotations
    //m_camera.rotate(-rotSpeed * Input::mouseDelta().x(), Camera3D::LocalUp);
    //m_camera.rotate(-rotSpeed * Input::mouseDelta().y(), m_camera.right());
    //m_camera.rotate(1.0f, QVector3D(0.0f, 0.1f, 0.0f));
    //m_camera.rotate(1.0f, QVector3D(0.1f, 0.0f, 0.0f));
}  float fraction = 0.1f;
  static const float transSpeed = 0.5f;
    // Handle translations
    QVector3D translation;
    if (Input::keyPressed(Qt::Key_Up))
    {
      translation +=m_camera.forward();
    }
    if (Input::keyPressed(Qt::Key_Down))
    {
      translation -=m_camera.forward();
    }
    if (Input::keyPressed(Qt::Key_A))
    {
      translation -= m_camera.right();
    }
    if (Input::keyPressed(Qt::Key_D))
    {
        angle += 0.01f;
        lx = sin(angle);
        lz = -cos(angle);
    }
    if (Input::keyPressed(Qt::Key_Escape))
    {
        angle -= 0.01f;
        lx = sin(angle);
        lz = -cos(angle);
    }
   /* if (Input::keyPressed(Qt::Key_E))
    {

    }*/
   m_camera.translate(transSpeed * translation);


  // Update instance information
  m_transform.rotate(1.0f, QVector3D(0.4f, 0.3f, 0.3f));
  // Schedule a redraw
  //QOpenGLWindow::update();
}


void PieceP::keyPressEvent(QKeyEvent *event)
{
  if (event->isAutoRepeat())
  {
    event->ignore();
  }
  else
  {
    Input::registerKeyPress(event->key());
  }
}

void PieceP::keyReleaseEvent(QKeyEvent *event)
{
  if (event->isAutoRepeat())
  {
    event->ignore();
  }
  else
  {
    Input::registerKeyRelease(event->key());
  }
}

void PieceP::mousePressEvent(QMouseEvent *event)
{
  Input::registerMousePress(event->button());
}

void PieceP::mouseReleaseEvent(QMouseEvent *event)
{
  Input::registerMouseRelease(event->button());
}
