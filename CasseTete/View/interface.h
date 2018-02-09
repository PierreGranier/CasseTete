#ifndef INTERFACE_H
#define INTERFACE_H

#include <QMainWindow>
#include <vector>
#include "modelisation.h"
#include "../Model/solution.h"

namespace Ui {
    class Interface;
}

class InterfaceCommunication {
public:
    virtual void startSolving() =0;
};

class Interface : public QMainWindow {
    Q_OBJECT

private:
    std::vector<Solution*> solutions;
    InterfaceCommunication* comm;

    Ui::Interface* ui;

    QGridLayout *main_layout;
    QVBoxLayout *left_layout;
    QHBoxLayout *bottom_layout;
    QGridLayout *bottom_left_layout;

    QLabel* get_solutions;
    QButtonGroup* number_of_solutions;
    QRadioButton* one_solution;
    QRadioButton* all_solutions;
    QPushButton* search;
    QLabel* time;
    QLabel* solutions_found;
    QListWidget* list_of_solutions;
    QPushButton* turn_left;
    QPushButton* turn_right;
    QPushButton* turn_up;
    QPushButton* turn_down;
    QPushButton* zoom_in;
    QPushButton* zoom_out;
    QPushButton* piece_1;
    QPushButton* piece_2;
    QPushButton* piece_3;
    QPushButton* piece_4;
    QPushButton* piece_5;
    QPushButton* piece_6;
    QPushButton* piece_7;
    QPushButton* piece_8;
    QPushButton* piece_9;

    QWidget* central_widget;
    Modelisation* modelisation;

public:
    explicit Interface(QWidget* parent = 0);
    ~Interface();
    void setInterfaceCommunication(InterfaceCommunication* c);
    void keyPressEvent(QKeyEvent* event);
    bool getAllSolutions();
    void calculFinished(int n_sol, int t, std::vector<Solution*>* sol);

private slots:
    void solve();
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
};

#endif // INTERFACE_H
