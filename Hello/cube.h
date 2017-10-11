/*
 * Classe où sont définies les formes de notre jeu
*/

#ifndef CUBE_H
#define CUBE_H
#include <QtOpenGL>
#include <QGLWidget>
#include <vertex.h>

//DESSIN DU CUBE

//Vertex de face
#define VERTEX_FTR Vertex( QVector3D( 0.5f,  0.5f,  0.5f), QVector3D( 1.0f, 0.0f, 0.0f ) )
#define VERTEX_FTL Vertex( QVector3D(-0.5f,  0.5f,  0.5f), QVector3D( 0.0f, 1.0f, 0.0f ) )
#define VERTEX_FBL Vertex( QVector3D(-0.5f, -0.5f,  0.5f), QVector3D( 0.0f, 0.0f, 1.0f ) )
#define VERTEX_FBR Vertex( QVector3D( 0.5f, -0.5f,  0.5f), QVector3D( 0.0f, 0.0f, 0.0f ) )

//Vertex arrières
#define VERTEX_BTR Vertex( QVector3D( 0.5f,  0.5f, -0.5f), QVector3D( 1.0f, 1.0f, 0.0f ) )
#define VERTEX_BTL Vertex( QVector3D(-0.5f,  0.5f, -0.5f), QVector3D( 0.0f, 1.0f, 1.0f ) )
#define VERTEX_BBL Vertex( QVector3D(-0.5f, -0.5f, -0.5f), QVector3D( 1.0f, 0.0f, 1.0f ) )
#define VERTEX_BBR Vertex( QVector3D( 0.5f, -0.5f, -0.5f), QVector3D( 1.0f, 1.0f, 1.0f ) )

//Creation d'un cube coloré
static const Vertex sg_vertexes[] = {
  // Face 1 (Face)
    VERTEX_FTR, VERTEX_FTL, VERTEX_FBL,
    VERTEX_FBL, VERTEX_FBR, VERTEX_FTR,
  // Face 2 (Arriere)
    VERTEX_BBR, VERTEX_BTL, VERTEX_BTR,
    VERTEX_BTL, VERTEX_BBR, VERTEX_BBL,
  // Face 3 (Haut)
    VERTEX_FTR, VERTEX_BTR, VERTEX_BTL,
    VERTEX_BTL, VERTEX_FTL, VERTEX_FTR,
  // Face 4 (Bas)
    VERTEX_FBR, VERTEX_FBL, VERTEX_BBL,
    VERTEX_BBL, VERTEX_BBR, VERTEX_FBR,
  // Face 5 (Gauche)
    VERTEX_FBL, VERTEX_FTL, VERTEX_BTL,
    VERTEX_FBL, VERTEX_BTL, VERTEX_BBL,
  // Face 6 (Droite)
    VERTEX_FTR, VERTEX_FBR, VERTEX_BBR,
    VERTEX_BBR, VERTEX_BTR, VERTEX_FTR
};

#undef VERTEX_BBR
#undef VERTEX_BBL
#undef VERTEX_BTL
#undef VERTEX_BTR

#undef VERTEX_FBR
#undef VERTEX_FBL
#undef VERTEX_FTL
#undef VERTEX_FTR





//DESSIN DU RECTANGLE


//Vertex de face
#define VERTEX_FTR Vertex( QVector3D( 0.25f,  0.25f,  1.25f), QVector3D( 0.5f, 0.0f, 1.0f ) )
#define VERTEX_FTL Vertex( QVector3D(-0.25f,  0.25f,  1.25f), QVector3D( 0.0f, 0.5f, 1.0f ) )
#define VERTEX_FBL Vertex( QVector3D(-0.25f, -0.25f,  1.25f), QVector3D( 0.0f, 0.0f, 1.5f ) )
#define VERTEX_FBR Vertex( QVector3D( 0.25f, -0.25f,  1.25f), QVector3D( 0.0f, 0.0f, 1.0f ) )

//Vertex arriere
#define VERTEX_BTR Vertex( QVector3D( 0.25f,  0.25f, -1.25f), QVector3D( 0.5f, 0.5f, 1.0f ) )
#define VERTEX_BTL Vertex( QVector3D(-0.25f,  0.25f, -1.25f), QVector3D( 0.0f, 0.5f, 1.5f ) )
#define VERTEX_BBL Vertex( QVector3D(-0.25f, -0.25f, -1.25f), QVector3D( 0.5f, 0.0f, 1.5f ) )
#define VERTEX_BBR Vertex( QVector3D( 0.25f, -0.25f, -1.25f), QVector3D( 0.5f, 0.5f, 1.5f ) )


// Creation d'un rectangle coloré
static const Vertex recta[] = {
  // Face 1 (Face)
    VERTEX_FTR, VERTEX_FTL, VERTEX_FBL,
    VERTEX_FBL, VERTEX_FBR, VERTEX_FTR,
  // Face 2 (Arriere)
    VERTEX_BBR, VERTEX_BTL, VERTEX_BTR,
    VERTEX_BTL, VERTEX_BBR, VERTEX_BBL,
  // Face 3 (Haut)
    VERTEX_FTR, VERTEX_BTR, VERTEX_BTL,
    VERTEX_BTL, VERTEX_FTL, VERTEX_FTR,
  // Face 4 (Bas)
    VERTEX_FBR, VERTEX_FBL, VERTEX_BBL,
    VERTEX_BBL, VERTEX_BBR, VERTEX_FBR,
  // Face 5 (Gauche)
    VERTEX_FBL, VERTEX_FTL, VERTEX_BTL,
    VERTEX_FBL, VERTEX_BTL, VERTEX_BBL,
  // Face 6 (Droite)
    VERTEX_FTR, VERTEX_FBR, VERTEX_BBR,
    VERTEX_BBR, VERTEX_BTR, VERTEX_FTR
};

#undef VERTEX_BBR
#undef VERTEX_BBL
#undef VERTEX_BTL
#undef VERTEX_BTR

#undef VERTEX_FBR
#undef VERTEX_FBL
#undef VERTEX_FTL
#undef VERTEX_FTR





//Dessin du +

//Vertex de facer
//FTR(L)= Front Top Right( Left)/ FBL(R) = Front Bottom Left (Right)/ BTR(L) = Back Top Right(Left)/ BBL(R) = Back Bottom Left(Right)
#define VERTEX_FTR Vertex( QVector3D( 0.25f,  0.25f,  0.75f), QVector3D( 0.0f, 0.0f, 1.0f ) )
#define VERTEX_FTL Vertex( QVector3D(-0.25f,  0.25f,  0.75f), QVector3D( 0.0f, 0.0f, 1.0f ) )
#define VERTEX_FBL Vertex( QVector3D(-0.25f, -0.25f,  0.75f), QVector3D( 0.0f, 0.0f, 1.0f ) )
#define VERTEX_FBR Vertex( QVector3D( 0.25f, -0.25f,  0.75f), QVector3D( 0.0f, 0.0f, 1.0f ) )
#define VERTEX_FTR1 Vertex( QVector3D( 0.75f,  0.25f,  0.25f), QVector3D( 0.0f, 0.0f, 1.0f ) )
#define VERTEX_FTL1 Vertex( QVector3D(0.75f,  0.25f,  -0.25f), QVector3D( 0.0f, 0.0f, 1.0f ) )
#define VERTEX_FBL1 Vertex( QVector3D(0.75f, -0.25f,  -0.25f), QVector3D( 0.0f, 0.0f, 1.0f ) )
#define VERTEX_FBR1 Vertex( QVector3D( 0.75f, -0.25f,  0.25f), QVector3D( 0.0f, 0.0f, 1.0f ) )

//Vertex arriere
#define VERTEX_BTR Vertex( QVector3D( 0.25f,  0.25f, -0.75f), QVector3D( 0.0f, 0.0f, 1.0f ) )
#define VERTEX_BTL Vertex( QVector3D(-0.25f,  0.25f, -0.75f), QVector3D( 0.0f, 0.0f, 1.0f ))
#define VERTEX_BBL Vertex( QVector3D(-0.25f, -0.25f, -0.75f), QVector3D( 0.0f, 0.0f, 1.0f ) )
#define VERTEX_BBR Vertex( QVector3D( 0.25f, -0.25f, -0.75f), QVector3D( 0.0f, 0.0f, 1.0f )  )
#define VERTEX_BTR1 Vertex( QVector3D( -0.75f,  0.25f, 0.25f), QVector3D( 0.0f, 0.0f, 1.0f ) )
#define VERTEX_BTL1 Vertex( QVector3D(-0.75f,  0.25f, -0.25f), QVector3D( 0.0f, 0.0f, 1.0f ) )
#define VERTEX_BBL1 Vertex( QVector3D(-0.75f, -0.25f, -0.25f), QVector3D( 0.0f, 0.0f, 1.0f ) )
#define VERTEX_BBR1 Vertex( QVector3D( -0.75f, -0.25f, 0.25f), QVector3D( 0.0f, 0.0f, 1.0f )  )

// Creation d'un + coloré
static const Vertex plus[] = {
  // Face 1 (Face)
    VERTEX_FTR1, VERTEX_FTL1, VERTEX_FBL1,
    VERTEX_FBL1, VERTEX_FBR1, VERTEX_FTR1,
    VERTEX_FTR, VERTEX_FTL, VERTEX_FBL,
    VERTEX_FBL, VERTEX_FBR, VERTEX_FTR,

  // Face 2 (Arriere)

    VERTEX_BBR1, VERTEX_BTL1, VERTEX_BTR1,
    VERTEX_BTL1, VERTEX_BBR1, VERTEX_BBL1,
    VERTEX_BBR, VERTEX_BTL, VERTEX_BTR,
    VERTEX_BTL, VERTEX_BBR, VERTEX_BBL,
  // Face 3 (Haut)

    VERTEX_FTR1, VERTEX_BTR1, VERTEX_BTL1,
    VERTEX_BTL1, VERTEX_FTL1, VERTEX_FTR1,
    VERTEX_FTR, VERTEX_BTR, VERTEX_BTL,
    VERTEX_BTL, VERTEX_FTL, VERTEX_FTR,
  // Face 4 (Bas)

    VERTEX_FBR1, VERTEX_FBL1, VERTEX_BBL1,
    VERTEX_BBL1, VERTEX_BBR1, VERTEX_FBR1,
    VERTEX_FBR, VERTEX_FBL, VERTEX_BBL,
    VERTEX_BBL, VERTEX_BBR, VERTEX_FBR,

  // Face 5 (Gauche)

    VERTEX_FBL1, VERTEX_FTL1, VERTEX_BTL1,
    VERTEX_FBL1, VERTEX_BTL1, VERTEX_BBL1,
    VERTEX_FBL, VERTEX_FTL, VERTEX_BTL,
    VERTEX_FBL, VERTEX_BTL, VERTEX_BBL,
  // Face 6 (Droite)

    VERTEX_FTR1, VERTEX_FBR1, VERTEX_BBR1,
    VERTEX_BBR1, VERTEX_BTR1, VERTEX_FTR1,
    VERTEX_FTR, VERTEX_FBR, VERTEX_BBR,
    VERTEX_BBR, VERTEX_BTR, VERTEX_FTR
};

#undef VERTEX_BBR
#undef VERTEX_BBL
#undef VERTEX_BTL
#undef VERTEX_BTR

#undef VERTEX_FBR
#undef VERTEX_FBL
#undef VERTEX_FTL
#undef VERTEX_FTR


class Cube
{
	public:

        //Variable pour définir l'angle
	    GLfloat angle;

        //Informations d'état d'OpenGL
	    QOpenGLVertexArrayObject m_object;
	    

        //Constructeur
	    Cube();

        //Requetes
        void dessinerCube();
        void dessinerRec();
};

#endif // CUBE_H
