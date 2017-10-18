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

void Cube::dessinerPlus()
     {
    m_program->bind();
    m_program->setUniformValue(u_worldToCamera, m_camera.toMatrix());
    m_program->setUniformValue(u_cameraToView, m_projection);
    m_program->setUniformValue(u_worldToView, m_projection);
          {
     m_object.bind();
     m_program->setUniformValue(u_modelToWorld, m_transform.toMatrix());
    glDrawArrays(GL_TRIANGLES, 0, sizeof(plus) / sizeof(plus[0]));
    m_object.release();
    }
    m_program->release();

      }


void Cube::dessinerT()
     {
    m_program->bind();
    m_program->setUniformValue(u_worldToCamera, m_camera.toMatrix());
    m_program->setUniformValue(u_cameraToView, m_projection);
    m_program->setUniformValue(u_worldToView, m_projection);
          {
     m_object.bind();
     m_program->setUniformValue(u_modelToWorld, m_transform.toMatrix());
    glDrawArrays(GL_TRIANGLES, 0, sizeof(t) / sizeof(t[0]));
    m_object.release();
    }
    m_program->release();
      }

void Cube::dessinerAngle()
     {
    m_program->bind();
    m_program->setUniformValue(u_worldToCamera, m_camera.toMatrix());
    m_program->setUniformValue(u_cameraToView, m_projection);
    m_program->setUniformValue(u_worldToView, m_projection);
          {
     m_object.bind();
     m_program->setUniformValue(u_modelToWorld, m_transform.toMatrix());
    glDrawArrays(GL_TRIANGLES, 0, sizeof(ang) / sizeof(ang[0]));
    m_object.release();
    }
    m_program->release();
      }

void Cube::dessinerP()
     {
    m_program->bind();
    m_program->setUniformValue(u_worldToCamera, m_camera.toMatrix());
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

void Cube::dessinerL()
     {
    m_program->bind();
    m_program->setUniformValue(u_worldToCamera, m_camera.toMatrix());
    m_program->setUniformValue(u_cameraToView, m_projection);
    m_program->setUniformValue(u_worldToView, m_projection);
         {
           m_object.bind();
           m_program->setUniformValue(u_modelToWorld, m_transform.toMatrix());
           glDrawArrays(GL_TRIANGLES, 0, sizeof(l) / sizeof(l[0]));
           m_object.release();
          }
     m_program->release();

      }
