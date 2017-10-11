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
    glDrawArrays(GL_TRIANGLES, 0, sizeof(plus) / sizeof(plus[0]));
      }

