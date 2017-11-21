#ifndef PIECEZ_H
#define PIECEZ_H

#include <QtOpenGL>
#include <QGLWidget>
#include <vertex.h>
#include <transform3d.h>
#include <camera3d.h>

//DESSIN DU Z


//Vertex de face
//FTR(L)= Front Top Right( Left)/ FBL(R) = Front Bottom Left (Right)/ BTR(L) = Back Top Right(Left)/ BBL(R) = Back Bottom Left(Right)
#define VERTEX_FTR  Vertex(QVector3D( 0.25f,  0.25f, -1.00f), QVector3D( 0.0f, 0.0f, 1.0f ))
#define VERTEX_FTL  Vertex(QVector3D(-0.25f,  0.25f, -1.00f), QVector3D( 0.0f, 0.0f, 1.0f ))
#define VERTEX_FBL  Vertex(QVector3D(-0.25f, -0.25f, -1.00f), QVector3D( 0.0f, 0.0f, 1.0f ))
#define VERTEX_FBR  Vertex(QVector3D( 0.25f, -0.25f, -1.00f), QVector3D( 0.0f, 0.0f, 1.0f ))
#define VERTEX_FTR1 Vertex(QVector3D( 0.75f,  0.25f,  1.00f), QVector3D( 0.0f, 0.0f, 1.0f ))
#define VERTEX_FTL1 Vertex(QVector3D( 0.25f,  0.25f,  1.00f), QVector3D( 0.0f, 0.0f, 1.0f ))
#define VERTEX_FBL1 Vertex(QVector3D( 0.25f, -0.25f,  1.00f), QVector3D( 0.0f, 0.0f, 1.0f ))
#define VERTEX_FBR1 Vertex(QVector3D( 0.75f, -0.25f,  1.00f), QVector3D( 0.0f, 0.0f, 1.0f ))


//Vertex arriere
#define VERTEX_BTR  Vertex(QVector3D( 0.25f,  0.25f,  0.25f), QVector3D( 0.0f, 0.0f, 1.0f ))
#define VERTEX_BTL  Vertex(QVector3D(-0.25f,  0.25f,  0.25f), QVector3D( 0.0f, 0.0f, 1.0f ))
#define VERTEX_BBL  Vertex(QVector3D(-0.25f, -0.25f,  0.25f), QVector3D( 0.0f, 0.0f, 1.0f ))
#define VERTEX_BBR  Vertex(QVector3D( 0.25f, -0.25f,  0.25f), QVector3D( 0.0f, 0.0f, 1.0f ))
#define VERTEX_BTR1 Vertex(QVector3D( 0.75f,  0.25f, -0.50f), QVector3D( 0.0f, 0.0f, 1.0f ))
#define VERTEX_BTL1 Vertex(QVector3D( 0.25f,  0.25f, -0.50f), QVector3D( 0.0f, 0.0f, 1.0f ))
#define VERTEX_BBL1 Vertex(QVector3D( 0.25f, -0.25f, -0.50f), QVector3D( 0.0f, 0.0f, 1.0f ))
#define VERTEX_BBR1 Vertex(QVector3D( 0.75f, -0.25f, -0.50f), QVector3D( 0.0f, 0.0f, 1.0f ))



// Creation d'un Z coloré
static const Vertex ppz[] = {
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



#undef VERTEX_BBR1
#undef VERTEX_BBL1
#undef VERTEX_BTL1
#undef VERTEX_BTR1

#undef VERTEX_FBR1
#undef VERTEX_FBL1
#undef VERTEX_FTL1
#undef VERTEX_FTR1



class PieceZ
{
public:
    //Variable pour définir l'angle
    GLfloat angle;

    //Informations d'état d'OpenGL
    QOpenGLVertexArrayObject m_object;
    QOpenGLShaderProgram *m_program;
    QOpenGLBuffer m_vertex;


    //Informations du Shader
    int u_modelToWorld;
    int u_worldToView;
    int u_worldToCamera;
    int u_cameraToView;
    QMatrix4x4 m_projection;

    //Variable de transformation
    Transform3D m_transform;

    //Variable de type camera
    Camera3D m_camera;

    //Constructeur
    PieceZ();

    //Requetes
    void dessinerZ(Camera3D *c);


};

#endif // PIECEZ_H
