#ifndef FENETRE_H
#define FENETRE_H


#include <QMainWindow>
#include <QWidget>
#include <QToolBar>
#include <QComboBox>
#include <QBoxLayout>
#include <QLabel>
#include <QRadioButton>
#include <QPushButton>
#include <QListView>
#include <QStackedWidget>
#include <QMenuBar>
#include <QFile>
#include <QDebug>
#include <QString>
#include <QTextStream>
#include <QMenu>
#include <QFileDialog>
#include <QMessageBox>
#include <QtDebug>
#include <QIcon>
#include <QApplication>
#include "mywindow.h"
#include "glclass.h"


class QAction;
class QLabel;
class QFrame;
class QMenu;


class Fenetre : public QMainWindow
{
    Q_OBJECT

public:
    explicit Fenetre(QWidget *parent = 0);
    ~Fenetre();



private slots:
   void afficher1();
   void afficher2();
   void afficher3();
   void afficher4();
   void afficher5();
   void afficher6();
   void afficher7();
   void afficher8();
   void afficher9();
private:
    void createActions();
    void createMenus();
   mywindow *affichage;




    QFrame *sideBar;
    QFrame *camera;
    QFrame *pieceBar;

    //QStackedWidget *contentStack;




    QComboBox *choix;
    QLabel *page1label1;
    QRadioButton *page1radiobutton1;
    QRadioButton *page1radiobutton2;
    QLabel *page1label2;
    QRadioButton *page1radiobutton3;
    QRadioButton *page1radiobutton4;
    QPushButton *page1pushbutton1;
    QLabel *page1label3;
    QLabel *page1label4;
    QLabel *page1label5;
    QListView *list;


    QWidget *centralWidget;

    //Les layouts nécessaires :
    QVBoxLayout *sideBarLayout;
    QHBoxLayout *layoutPiece;
    QGridLayout *milieuLayout;
    QGridLayout *page1GridLayout;
    QGridLayout *centralLayout;





};

#endif // FENETRE_H
