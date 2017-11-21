#include "piecep.h"

PieceP::PieceP()
{

}
void PieceP::dessinerP(Camera3D *c)
     {

    m_program->bind();m_program->setUniformValue(u_worldToCamera, m_camera.toMatrix());
    m_program->setUniformValue(u_cameraToView, m_projection);
    m_program->setUniformValue(u_worldToView, m_projection);
         {
           m_object.bind();
           m_program->setUniformValue(u_modelToWorld, m_transform.toMatrix());
           glDrawArrays(GL_TRIANGLES, 0, sizeof(p) / sizeof(p[0]));
           m_object.release();
}
     m_program->release();

      }
