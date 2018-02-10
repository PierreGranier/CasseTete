#ifndef MODELISATION_H
#define MODELISATION_H

#include <iostream>
#include <QtOpenGL>
#include <QGLWidget>
#include <GL/glu.h>
#include "piecet.h"
#include "pieceangle.h"
#include "pieceplus.h"
#include "piecel.h"
#include "piecez.h"
#include "piecep.h"
#include "piecey.h"
#include "pieced.h"
#include "pieceg.h"
#include "../Model/piecemodel.h"

/**
 * @brief Classe Modelisation
 * Represente la modelisation 3D de la solution courante
 */
class Modelisation : public QGLWidget {
    Q_OBJECT

private:
    QTimer* t_Timer;
    int zoom;
    int horizontal_rotation;
    int vertical_rotation;
    PieceT* piece_t;
    PieceAngle* piece_angle;
    PiecePlus* piece_plus;
    PieceL* piece_l;
    PieceZ* piece_z;
    PieceP* piece_p;
    PieceY* piece_y;
    PieceD* piece_d;
    PieceG* piece_g;

public:
    explicit Modelisation(int framesPerSecond = 0, QWidget* parent = 0, char* name = 0);
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();
    void keyPressEvent(QKeyEvent* keyEvent);
    void setPieceInfo(PieceType t, bool used, Position* pos, Position* rot);
    void zoomIn();
    void zoomOut();
    void turnRight();
    void turnLeft();
    void turnUp();
    void turnDown();
    void switchPieceT();
    void switchPieceAngle();
    void switchPiecePlus();
    void switchPieceL();
    void switchPieceZ();
    void switchPieceP();
    void switchPieceY();
    void switchPieceD();
    void switchPieceG();

public slots:
    virtual void timeOutSlot();
};

#endif // MODELISATION_H
