#include "pieced.h"

PieceD::PieceD() : PieceView() {
}

void PieceD::show() {
    if (is_used && display) {
        glTranslatef(position->getX(), -position->getY(), -position->getZ());
        glRotatef(90 * rotation->getX(), 1.0f, 0.0f, 0.0f);
        glRotatef(90 * rotation->getY(), 0.0f, 1.0f, 0.0f);
        glRotatef(90 * rotation->getZ(), 0.0f, 0.0f, 1.0f);

        glColor3f(0.25f, 0.64f, 0.59f);
        /** Avant **/
        glBegin(GL_QUADS);
            glVertex3f(-0.5f, -0.5f, 0.5f);
            glVertex3f(1.5f, -0.5f, 0.5f);
            glVertex3f(1.5f, 0.5f, 0.5f);
            glVertex3f(-0.5f, 0.5f, 0.5f);
        glEnd();

        glBegin(GL_QUADS);
            glVertex3f(0.5f, -2.5f, -0.5f);
            glVertex3f(1.5f, -2.5f, -0.5f);
            glVertex3f(1.5f, -0.5f, -0.5f);
            glVertex3f(0.5f, -0.5f, -0.5f);
        glEnd();

        /** Arriere **/
        glBegin(GL_QUADS);
            glVertex3f(0.5f, -0.5f, -0.5f);
            glVertex3f(-0.5f, -0.5f, -0.5f);
            glVertex3f(-0.5f, 0.5f, -0.5f);
            glVertex3f(0.5f, 0.5f, -0.5f);
        glEnd();

        glBegin(GL_QUADS);
            glVertex3f(1.5f, -2.5f, -1.5f);
            glVertex3f(0.5f, -2.5f, -1.5f);
            glVertex3f(0.5f, 0.5f, -1.5f);
            glVertex3f(1.5f, 0.5f, -1.5f);
        glEnd();

        /** Droite **/
        glBegin(GL_QUADS);
            glVertex3f(1.5f, -2.5f, -0.5f);
            glVertex3f(1.5f, -2.5f, -1.5f);
            glVertex3f(1.5f, 0.5f, -1.5f);
            glVertex3f(1.5f, 0.5f, -0.5f);
        glEnd();

        glBegin(GL_QUADS);
            glVertex3f(1.5f, -0.5f, 0.5f);
            glVertex3f(1.5f, -0.5f, -0.5f);
            glVertex3f(1.5f, 0.5f, -0.5f);
            glVertex3f(1.5f, 0.5f, 0.5f);
        glEnd();

        /** Gauche **/
        glBegin(GL_QUADS);
            glVertex3f(-0.5f, -0.5f, -0.5f);
            glVertex3f(-0.5f, -0.5f, 0.5f);
            glVertex3f(-0.5f, 0.5f, 0.5f);
            glVertex3f(-0.5f, 0.5f, -0.5f);
        glEnd();

        glBegin(GL_QUADS);
            glVertex3f(0.5f, -2.5f, -1.5f);
            glVertex3f(0.5f, -2.5f, -0.5f);
            glVertex3f(0.5f, 0.5f, -0.5f);
            glVertex3f(0.5f, 0.5f, -1.5f);
        glEnd();

        /** Dessus **/
        glBegin(GL_QUADS);
            glVertex3f(-0.5f, 0.5f, 0.5f);
            glVertex3f(0.5f, 0.5f, 0.5f);
            glVertex3f(0.5f, 0.5f, -0.5f);
            glVertex3f(-0.5f, 0.5f, -0.5f);
        glEnd();

        glBegin(GL_QUADS);
            glVertex3f(0.5f, 0.5f, 0.5f);
            glVertex3f(1.5f, 0.5f, 0.5f);
            glVertex3f(1.5f, 0.5f, -1.5f);
            glVertex3f(0.5f, 0.5f, -1.5f);
        glEnd();

        /** Dessous **/
        glBegin(GL_QUADS);
            glVertex3f(-0.5f, -0.5f, -0.5f);
            glVertex3f(1.5f, -0.5f, -0.5f);
            glVertex3f(1.5f, -0.5f, 0.5f);
            glVertex3f(-0.5f, -0.5f, 0.5f);
        glEnd();

        glBegin(GL_QUADS);
            glVertex3f(0.5f, -2.5f, -1.5f);
            glVertex3f(1.5f, -2.5f, -1.5f);
            glVertex3f(1.5f, -2.5f, -0.5f);
            glVertex3f(0.5f, -2.5f, -0.5f);
        glEnd();

        glRotatef(-90 * rotation->getZ(), 0.0f, 0.0f, 1.0f);
        glRotatef(-90 * rotation->getY(), 0.0f, 1.0f, 0.0f);
        glRotatef(-90 * rotation->getX(), 1.0f, 0.0f, 0.0f);
        glTranslatef(-position->getX(), position->getY(), position->getZ());
    }
}
