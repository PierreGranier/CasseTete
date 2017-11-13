#include "cube.h"
#include "vertex.h"


//Constructeur
Cube::Cube()
     {

      }

//Dessin du cube
void Cube::dessinerCube()
     {
    glDrawArrays(GL_TRIANGLES, 0, sizeof(sg_vertexes) / sizeof(sg_vertexes[0]));
      }

//Dessin du rectangle
void Cube::dessinerRec()
     {
    glDrawArrays(GL_TRIANGLES, 0, sizeof(recta) / sizeof(recta[0]));
      }









/*
//@yao
void Cube::dessinerY(Camera3D *c)
     {
    m_program->bind();
    m_program->setUniformValue(u_worldToCamera, m_camera.toMatrix());
    m_program->setUniformValue(u_cameraToView, m_projection);
    m_program->setUniformValue(u_worldToView, m_projection);
         {
           m_object.bind();
           m_program->setUniformValue(u_modelToWorld, m_transform.toMatrix());
           glDrawArrays(GL_TRIANGLES, 0, sizeof(piece1Y) / sizeof(piece1Y[0]));
           m_object.release();
          }
     m_program->release();

      }
*/
