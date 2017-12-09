#pragma once

#ifndef WINDOW_H
#define WINDOW_H

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
#include "../Model/Solution.h"




class QAction;
class QLabel;
class QFrame;
class QMenu;



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
   
private slots:

// void afficherTest();
void solution();


    

private:
 
   // Solution *sol;
    
  

    
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
    QGridLayout *page1GridLayout;
    QGridLayout *centralLayout;
    

  

   
};

#endif
