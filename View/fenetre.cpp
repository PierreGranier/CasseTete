#include "fenetre.h"
#include "glclass.h"
#include <QFormLayout>
#include <QGuiApplication>
#include <QApplication>
#include<qstackedlayout.h>
#include<QStackedLayout>
Fenetre::Fenetre(QWidget *parent)
    : QMainWindow(parent)
{


    createActions();
    createMenus();




    sideBar = new QFrame;
    camera = new QFrame;
    pieceBar = new QFrame;
    affichage = new mywindow;

    //contentStack = new QStackedWidget;





    choix= new QComboBox;
    //setCurrentText("Choix casse tete");
    page1label1 = new QLabel("Afficher");
    page1radiobutton1 = new QRadioButton("Une solution", this);
    page1radiobutton2 = new QRadioButton("Toutes les solutions", this);

    page1label2 = new QLabel("Calculer une piece deja positionee");
    page1radiobutton3 = new QRadioButton("oui", this);
    page1radiobutton4 = new QRadioButton("non", this);
    page1pushbutton1 = new QPushButton("Lancer la recherche", this);
    page1pushbutton1->setStyleSheet("background-color: cyan;");
    page1label3 = new QLabel("Temps d'excution:");
    page1label4 = new QLabel("Nombre de solutions:");
    page1label5 = new QLabel("Choix de solutions:");
    list = new QListView(this);


    QPushButton *page1WidgetA = new QPushButton("Zoom Avant", this);
    QPushButton *page1WidgetB = new QPushButton("rotation gauche", this);
    QPushButton *page1WidgetC = new QPushButton("rotation droite", this);
    QPushButton *page1WidgetD = new QPushButton("zoom arriere", this);


    QPushButton *piece1 = new QPushButton("piece1", this);
piece1->setGeometry(10, 10, 10, 10);
piece1->setEnabled(true);
piece1->setStyleSheet("background-color: cyan;");

    QPushButton *piece2 = new QPushButton("piece2", this);
piece2->setGeometry(10, 10, 10, 10);
piece2->setEnabled(true);
piece2->setStyleSheet("background-color: cyan;");
    QPushButton *piece3 = new QPushButton("piece3", this);
piece3->setGeometry(10, 10, 10, 10);
piece3->setEnabled(true);
piece3->setStyleSheet("background-color: cyan;");
    QPushButton *piece4 = new QPushButton("piece4", this);
piece4->setGeometry(10, 10, 10, 10);
piece4->setEnabled(true);
piece4->setStyleSheet("background-color: cyan;");
    QPushButton *piece5 = new QPushButton("piece5", this);
piece5->setGeometry(10, 10, 10, 10);
piece5->setEnabled(true);
piece5->setStyleSheet("background-color: cyan;");
    QPushButton *piece6 = new QPushButton("piece6", this);
piece6->setGeometry(10, 10, 10, 10);
piece6->setEnabled(true);
piece6->setStyleSheet("background-color: cyan;");
    QPushButton *piece7 = new QPushButton("piece7", this);
piece7->setGeometry(10, 10, 10, 10);
piece7->setEnabled(true);
piece7->setStyleSheet("background-color: cyan;");
    QPushButton *piece8 = new QPushButton("piece8", this);
piece8->setGeometry(10, 10, 10, 10);
piece8->setEnabled(true);
piece8->setStyleSheet("background-color: cyan;");
    QPushButton *piece9 = new QPushButton("piece9", this);
piece9->setGeometry(10, 10, 10, 10);
piece9->setEnabled(true);
piece9->setStyleSheet("background-color: cyan;");





    centralWidget = new QWidget;




    //Les layouts nécessaires :
   sideBarLayout = new QVBoxLayout;
   page1GridLayout = new QGridLayout;
   layoutPiece = new QHBoxLayout;
    centralLayout = new QGridLayout;
     milieuLayout = new QGridLayout;

    //Connectons des pièces

    /* Installation de la barre latérale */
    sideBarLayout->addWidget(choix);
    sideBarLayout->addWidget(page1label1);
    sideBarLayout->addWidget(page1radiobutton1);
    sideBarLayout->addWidget(page1radiobutton2);
    sideBarLayout->addWidget(page1label2);
    sideBarLayout->addWidget(page1radiobutton3);
    sideBarLayout->addWidget(page1radiobutton4);
    sideBarLayout->addWidget(page1pushbutton1);
    sideBarLayout->addWidget(page1label3);
    sideBarLayout->addWidget(page1label4);
    sideBarLayout->addWidget(page1label5);
     sideBarLayout->addWidget(list);




    sideBarLayout->addStretch();
    sideBar->setLayout(sideBarLayout);
    sideBar->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);

    //contentStack->addWidget(camera);
    //contentStack->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);


    page1GridLayout->addWidget(page1WidgetA, 2, 0, 3, 1);//0 0 3 1
    page1GridLayout->addWidget(page1WidgetB, 2, 1, 1, 1);//0 1 1 1
    page1GridLayout->addWidget(page1WidgetC, 3, 1, 2, 1);//1 1 2 1
    page1GridLayout->addWidget(page1WidgetD, 3, 0, 1, 2);//3 0 1 2

    camera->setLayout(page1GridLayout);
    camera->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);

   //contentStack->addWidget(camera);
   // contentStack->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);


     layoutPiece->addWidget(piece1);
     layoutPiece->addWidget(piece2);
     layoutPiece->addWidget(piece3);
     layoutPiece->addWidget(piece4);
     layoutPiece->addWidget(piece5);
     layoutPiece->addWidget(piece6);
     layoutPiece->addWidget(piece7);
     layoutPiece->addWidget(piece8);
     layoutPiece->addWidget(piece9);



    layoutPiece->addStretch();
    pieceBar->setLayout(layoutPiece);
    pieceBar->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);

    // contentStack->addWidget(upperBar);

    //contentStack->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    affichage->setLayout(milieuLayout);
    affichage->setPalette(QPalette(QColor(0, 255, 127)));
    affichage->setAutoFillBackground(true);

    /* installation des principaux éléments (layout centrale)*/

    centralLayout->addWidget(sideBar, 0, 0, 2, 1);//1 0 1 1
    centralLayout->addWidget(camera, 2, 0, 1, 1);
    centralLayout->addWidget(pieceBar, 2, 2, 2, 2);
    centralLayout->addWidget(affichage,0,1,2,4);
    centralWidget->setLayout(centralLayout);
    setCentralWidget(centralWidget);

    /* couleur et border
    setStyleSheet("QWidget {"
                  "border: 1px solid black;"
                  "color: black"
                  "}");*/

    resize(1024,768);

    QObject::connect(piece1, SIGNAL(clicked()),this,SLOT(afficher1()));
    QObject::connect(piece2, SIGNAL(clicked()),this,SLOT(afficher2()));
    QObject::connect(piece3, SIGNAL(clicked()),this,SLOT(afficher3()));
    QObject::connect(piece4, SIGNAL(clicked()),this,SLOT(afficher4()));
    QObject::connect(piece5, SIGNAL(clicked()),this,SLOT(afficher5()));
    QObject::connect(piece6, SIGNAL(clicked()),this,SLOT(afficher6()));
    QObject::connect(piece7, SIGNAL(clicked()),this,SLOT(afficher7()));
    QObject::connect(piece8, SIGNAL(clicked()),this,SLOT(afficher8()));
    QObject::connect(piece9, SIGNAL(clicked()),this,SLOT(afficher9()));







}

Fenetre::~Fenetre()
{

}




//Création des Actions
void Fenetre::createActions()
{


}


// Création des menus
void Fenetre::createMenus()
{


}

void Fenetre::afficher1()
{

affichage->plus.visible=false;
affichage->pangle.visible=false;
affichage->pd.visible=false;
affichage->pg.visible=false;
affichage->pl.visible=false;
affichage->pt.visible=false;
affichage->py.visible=false;
affichage->pz.visible=false;
affichage->pp.m_transform.setTranslation(0.0f, 0.0f, -10.0f);
affichage->paintGL();
}


void Fenetre::afficher2()
{
affichage->plus.visible=true;
affichage->pp.visible=false;
affichage->pangle.visible=false;
affichage->pd.visible=false;
affichage->pg.visible=false;
affichage->pl.visible=false;
affichage->pt.visible=false;
affichage->py.visible=false;
affichage->pz.visible=false;
affichage->plus.m_transform.setTranslation(0.0f, 0.0f, -10.0f);
affichage->paintGL();
}


void Fenetre::afficher3()
{
affichage->pt.visible=true;
affichage->plus.visible=false;
affichage->pp.visible=false;
affichage->pd.visible=false;
affichage->pg.visible=false;
affichage->pl.visible=false;
affichage->pangle.visible=false;
affichage->py.visible=false;
affichage->pz.visible=false;
affichage->pt.m_transform.setTranslation(0.0f, 0.0f, -10.0f);
affichage->paintGL();
}


void Fenetre::afficher4()
{
affichage->pl.visible=true;
affichage->plus.visible=false;
affichage->pangle.visible=false;
affichage->pd.visible=false;
affichage->pg.visible=false;
affichage->pp.visible=false;
affichage->pt.visible=false;
affichage->py.visible=false;
affichage->pz.visible=false;
affichage->pl.m_transform.setTranslation(0.0f, 0.0f, -10.0f);
affichage->paintGL();
}

void Fenetre::afficher5()
{
affichage->pangle.visible=true;
affichage->plus.visible=false;
affichage->pp.visible=false;
affichage->pd.visible=false;
affichage->pg.visible=false;
affichage->pl.visible=false;
affichage->pt.visible=false;
affichage->py.visible=false;
affichage->pz.visible=false;
affichage->pangle.m_transform.setTranslation(0.0f, 0.0f, -10.0f);
affichage->paintGL();
}


void Fenetre::afficher6()
{
affichage->py.visible=true;
affichage->plus.visible=false;
affichage->pangle.visible=false;
affichage->pd.visible=false;
affichage->pg.visible=false;
affichage->pl.visible=false;
affichage->pt.visible=false;
affichage->pp.visible=false;
affichage->pz.visible=false;
affichage->py.m_transform.setTranslation(0.0f, 0.0f, -10.0f);
affichage->paintGL();
}


void Fenetre::afficher7()
{
affichage->pg.visible=true;
affichage->plus.visible=false;
affichage->pangle.visible=false;
affichage->pd.visible=false;
affichage->pp.visible=false;
affichage->pl.visible=false;
affichage->pt.visible=false;
affichage->py.visible=false;
affichage->pz.visible=false;
affichage->pg.m_transform.setTranslation(0.0f, 0.0f, -10.0f);
affichage->paintGL();
}


void Fenetre::afficher8()
{
affichage->pd.visible=true;
affichage->plus.visible=false;
affichage->pangle.visible=false;
affichage->pp.visible=false;
affichage->pg.visible=false;
affichage->pl.visible=false;
affichage->pt.visible=false;
affichage->py.visible=false;
affichage->pz.visible=false;
affichage->pd.m_transform.setTranslation(0.0f, 0.0f, -10.0f);
affichage->paintGL();
}

void Fenetre::afficher9()
{
affichage->pz.visible=true;
affichage->plus.visible=false;
affichage->pangle.visible=false;
affichage->pd.visible=false;
affichage->pg.visible=false;
affichage->pl.visible=false;
affichage->pt.visible=false;
affichage->py.visible=false;
affichage->pp.visible=false;
affichage->pz.m_transform.setTranslation(0.0f, 0.0f, -10.0f);
affichage->paintGL();
}
