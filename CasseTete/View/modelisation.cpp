#include "modelisation.h"

Modelisation::Modelisation(int framesPerSecond, QWidget* parent, char* name) : QGLWidget(parent) {
    setWindowTitle(QString::fromUtf8(name));
    if(framesPerSecond == 0) {
        t_Timer = NULL;
    }
    else {
        int seconde = 1000;
        int timerInterval = seconde / framesPerSecond;
        t_Timer = new QTimer(this);
        connect(t_Timer, SIGNAL(timeout()), this, SLOT(timeOutSlot()));
        t_Timer->start(timerInterval);
    }

    /** Camera **/
    zoom = -20;
    horizontal_rotation = 0;
    vertical_rotation = 0;

    /** Pieces **/
    piece_t = new PieceT();
    piece_t->setPosition(-4, 5, 0);
    piece_angle = new PieceAngle();
    piece_angle->setPosition(0, 5, 0);
    piece_plus = new PiecePlus();
    piece_plus->setPosition(4, 5, 0);
    piece_l = new PieceL();
    piece_l->setPosition(-4, 0, 0);
    piece_z = new PieceZ();
    piece_z->setPosition(0, 0, 0);
    piece_p = new PieceP();
    piece_p->setPosition(4, 0, 0);
    piece_y = new PieceY();
    piece_y->setPosition(-4, -5, 0);
    piece_d = new PieceD();
    piece_d->setPosition(0, -5, 0);
    piece_g = new PieceG();
    piece_g->setPosition(4, -5, 0);
}

void Modelisation::initializeGL() {
    glShadeModel(GL_SMOOTH);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void Modelisation::resizeGL(int width, int height) {
    if(height == 0) {
        height = 1;
    }
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (GLfloat)width/(GLfloat)height, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Modelisation::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, zoom);
    glRotatef(horizontal_rotation, 0.0f, 1.0f, 0.0f);
    glRotatef(vertical_rotation, 1.0f, 0.0f, 0.0f);

    glTranslatef(-2.5f, 2.0f, 0.0f);

    /** Draw pieces **/
    glColor3f(0.8f, 0.8f, 0.8f);
    piece_t->show();
    piece_angle->show();
    piece_plus->show();
    piece_l->show();
    piece_z->show();
    piece_p->show();
    piece_y->show();
    piece_d->show();
    piece_g->show();
}

void Modelisation::setPieceInfo(PieceType t, bool used, Position* pos, Position* rot) {
    PieceView* p;
    switch (t) {
        case 0:
            p = piece_t;
            break;
        case 1:
            p = piece_angle;
            break;
        case 2:
            p = piece_plus;
            break;
        case 3:
            p = piece_l;
            break;
        case 4:
            p = piece_z;
            break;
        case 5:
            p = piece_p;
            break;
        case 6:
            p = piece_y;
            break;
        case 7:
            p = piece_d;
            break;
        case 8:
            p = piece_g;
            break;
        default:
            break;
    }
    p->setIsUsed(used);
    p->setPosition(pos->getX(), pos->getY(), pos->getZ());
    int y_rot = rot->getY();
    if (y_rot == 3) {
        y_rot = 1;
    }
    else if (y_rot == 1) {
        y_rot = 3;
    }
    int z_rot = rot->getZ();
    if (z_rot == 3) {
        z_rot = 1;
    }
    else if (z_rot == 1) {
        z_rot = 3;
    }
    p->setRotation(rot->getX(), y_rot, z_rot);
    update();
}

/**
 * Zoom avant de la caméra
 */
void Modelisation::zoomIn() {
    if (zoom < -15) {
        ++zoom;
        update();
    }
}

/**
 * Zoom arriere de la camera
 */
void Modelisation::zoomOut() {
    if (zoom > -50) {
        --zoom;
        update();
    }
}

/**
 * Rotation vers la droite de la camera
 */
void Modelisation::turnRight() {
    horizontal_rotation -= 10;
    update();
}

/**
 * Rotation vers la gauche de la camera
 */
void Modelisation::turnLeft() {
    horizontal_rotation += 10;
    update();
}

/**
 * Rotation vers le haut de la camera
 */
void Modelisation::turnUp() {
    vertical_rotation += 10;
    update();
}

/**
 * Rotation vers le bas de la camera
 */
void Modelisation::turnDown() {
    vertical_rotation -= 10;
    update();
}

/**
 * Affiche la piece T si elle est affichee, sinon la cache
 */
void Modelisation::switchPieceT() {
    piece_t->reverseDisplay();
    update();
}

/**
 * Affiche la piece Angle si elle est affichee, sinon la cache
 */
void Modelisation::switchPieceAngle() {
    piece_angle->reverseDisplay();
    update();
}

/**
 * Affiche la piece Plus si elle est affichee, sinon la cache
 */
void Modelisation::switchPiecePlus() {
    piece_plus->reverseDisplay();
    update();
}

/**
 * Affiche la piece L si elle est affichee, sinon la cache
 */
void Modelisation::switchPieceL() {
    piece_l->reverseDisplay();
    update();
}

/**
 * Affiche la piece Z si elle est affichee, sinon la cache
 */
void Modelisation::switchPieceZ() {
    piece_z->reverseDisplay();
    update();
}

/**
 * Affiche la piece P si elle est affichee, sinon la cache
 */
void Modelisation::switchPieceP() {
    piece_p->reverseDisplay();
    update();
}

/**
 * Affiche la piece Y si elle est affichee, sinon la cache
 */
void Modelisation::switchPieceY() {
    piece_y->reverseDisplay();
    update();
}

/**
 * Affiche la piece D si elle est affichee, sinon la cache
 */
void Modelisation::switchPieceD() {
    piece_d->reverseDisplay();
    update();
}

/**
 * Affiche la piece G si elle est affichee, sinon la cache
 */
void Modelisation::switchPieceG() {
    piece_g->reverseDisplay();
    update();
}

/**
 * Methode gerant les evenements de touches pressees
 */
void Modelisation::keyPressEvent(QKeyEvent* keyEvent) {
    switch (keyEvent->key()) {
        case Qt::Key_F1:
            switchPieceT();
            break;
        case Qt::Key_F2:
            switchPieceAngle();
            break;
        case Qt::Key_F3:
            switchPiecePlus();
            break;
        case Qt::Key_F4:
            switchPieceL();
            break;
        case Qt::Key_F5:
            switchPieceZ();
            break;
        case Qt::Key_F6:
            switchPieceP();
            break;
        case Qt::Key_F7:
            switchPieceY();
            break;
        case Qt::Key_F8:
            switchPieceD();
            break;
        case Qt::Key_F9:
            switchPieceG();
            break;
        case Qt::Key_Up:
            turnUp();
            break;
        case Qt::Key_Down:
            turnDown();
            break;
        case Qt::Key_Right:
            turnRight();
            break;
        case Qt::Key_Left:
            turnLeft();
            break;
        case Qt::Key_Plus:
            zoomIn();
            break;
        case Qt::Key_Minus:
            zoomOut();
            break;
        default:
            break;
    }
}

void Modelisation::timeOutSlot() {

}
