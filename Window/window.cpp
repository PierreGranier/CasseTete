#include "window.h"
#include <QFormLayout>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{


   // createActions();
   // createMenus();
    
    

    
    sideBar = new QFrame;
    camera = new QFrame;
    pieceBar = new QFrame;
    //sol = new Solution;
  

    //contentStack = new QStackedWidget;

 QPalette palette;
 palette.setColor(QPalette::Active, QPalette::WindowText, Qt::white);




    

    choix= new QComboBox;
    
    page1label1 = new QLabel("Afficher");
     page1label1->setStyleSheet("background-color: grey;");
    page1radiobutton1 = new QRadioButton("Une solution", this);
    page1radiobutton2 = new QRadioButton("Toutes les solutions", this);
     
    page1label2 = new QLabel("Calculer une piece deja positionee");
     page1label2->setStyleSheet("background-color: grey;");
    page1radiobutton3 = new QRadioButton("oui", this);
    page1radiobutton4 = new QRadioButton("non", this);
    page1pushbutton1 = new QPushButton(tr("Lancer la recherche"), this);
    page1pushbutton1->setPalette(palette);
    page1pushbutton1->setFixedSize(200,30);
    page1pushbutton1->setStyleSheet("background-color: blue;");
    page1label3 = new QLabel("Temps d'excution:");
    page1label3->setStyleSheet("background-color: grey;");
    page1label4 = new QLabel("Nombre de solutions:");
     page1label4->setStyleSheet("background-color: grey;");
    page1label5 = new QLabel("Choix de solutions:");
     page1label5->setStyleSheet("background-color: grey;");
    list = new QListView(this);
    list->setMaximumWidth(200);

 


    QPushButton *page1WidgetA = new QPushButton("Zoom Avant", this);
    QPushButton *page1WidgetB = new QPushButton("rotation gauche", this);
    QPushButton *page1WidgetC = new QPushButton("rotation droite", this);
    QPushButton *page1WidgetD = new QPushButton("zoom arriere", this); 


    QPushButton *piece1 = new QPushButton("piece1", this);
    piece1->setFixedSize(100,100);
    piece1->setEnabled(true);
    piece1->setStyleSheet("background-color: blue;");
    
    QPushButton *piece2 = new QPushButton("piece2", this);
piece2->setFixedSize(100,100);

piece2->setEnabled(true);
piece2->setStyleSheet("background-color: blue;");
    QPushButton *piece3 = new QPushButton("piece3", this);
piece3->setFixedSize(100,100);
piece3->setEnabled(true);
piece3->setStyleSheet("background-color: blue;");
    QPushButton *piece4 = new QPushButton("piece4", this); 
piece4->setFixedSize(100,100);
piece4->setEnabled(true);
piece4->setStyleSheet("background-color: blue;");
    QPushButton *piece5 = new QPushButton("piece5", this);
piece5->setFixedSize(100,100);
piece5->setEnabled(true);
piece5->setStyleSheet("background-color: blue;");
    QPushButton *piece6 = new QPushButton("piece6", this);
piece6->setFixedSize(100,100);
piece6->setEnabled(true);
piece6->setStyleSheet("background-color: blue;");
    QPushButton *piece7 = new QPushButton("piece7", this);
piece7->setFixedSize(100,100);
piece7->setEnabled(true);
piece7->setStyleSheet("background-color: blue;");
    QPushButton *piece8 = new QPushButton("piece8", this); 
piece8->setFixedSize(100,100);
piece8->setEnabled(true);
piece8->setStyleSheet("background-color: blue;");
    QPushButton *piece9 = new QPushButton("piece9", this); 
piece9->setFixedSize(100,100);
piece9->setEnabled(true);
piece9->setStyleSheet("background-color: blue;");





    centralWidget = new QWidget;
   
   
   
 
    
    //Les layouts nécessaires :
   sideBarLayout = new QVBoxLayout;
   page1GridLayout = new QGridLayout;
   layoutPiece = new QHBoxLayout;
   centralLayout = new QGridLayout;
 
    
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


    /* installation des principaux éléments (layout centrale)*/
    
    centralLayout->addWidget(sideBar, 0, 0, 2, 1);//1 0 1 1
    centralLayout->addWidget(camera, 2, 0, 1, 1);
    centralLayout->addWidget(pieceBar, 2, 2, 2, 2);
    
    centralWidget->setLayout(centralLayout);
    setCentralWidget(centralWidget);

    /* couleur et border*/
    setStyleSheet("QWidget {"
                  "border: 1px solid black;"
                  "color: black"
                  "}");

    resize(1024,768);

 QObject::connect(page1pushbutton1, SIGNAL(clicked()),this,SLOT(afficherTest()));

 QObject::connect(page1pushbutton1, SIGNAL(clicked()),list,SLOT(solution()));


}


MainWindow::~MainWindow()
{

}

//void MainWindow::afficherTest(){  std::cout << "Je suis une solution temporaire";}



void MainWindow::solution(){



}




