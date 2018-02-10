#include "interface.h"
#include "ui_interface.h"

Interface::Interface(QWidget* parent) : QMainWindow(parent), ui(new Ui::Interface) {
    ui->setupUi(this);

    /** Liste des problèmes **/
    problems.push_back("Exemple 1");
    problems.push_back("Exemple 2");
    problems.push_back("5*4*2");
    problems.push_back("5*3*3");

    /** Création des layouts **/
    main_layout = new QGridLayout();
    left_layout = new QVBoxLayout();
    bottom_layout = new QHBoxLayout();
    bottom_left_layout = new QGridLayout();

    /** Left Layout **/
    list_of_problems = new QListWidget();
    list_of_problems->setMaximumWidth(400);
    for (unsigned int i = 0; i < problems.size(); ++i) {
        list_of_problems->addItem(problems[i].c_str());
    }
    list_of_problems->setCurrentRow(0);
    get_solutions = new QLabel("Rechercher :");
    number_of_solutions = new QButtonGroup();
    one_solution = new QRadioButton("Une seule solution");
    one_solution->setChecked(true);
    all_solutions = new QRadioButton("Toutes les solutions");
    number_of_solutions->addButton(one_solution);
    number_of_solutions->addButton(all_solutions);
    search = new QPushButton("Lancer la recherche");
    time = new QLabel("Temps de recherche : ");
    solutions_found = new QLabel("Nombre de solutions : ");
    list_of_solutions = new QListWidget();
    list_of_solutions->setMaximumWidth(400);
    left_layout->addWidget(list_of_problems);
    left_layout->addWidget(get_solutions);
    left_layout->addWidget(one_solution);
    left_layout->addWidget(all_solutions);
    left_layout->addWidget(search);
    left_layout->addWidget(time);
    left_layout->addWidget(solutions_found);
    left_layout->addWidget(list_of_solutions);

    /** Bottom Left Layout **/
    turn_left = new QPushButton("<-");
    turn_right = new QPushButton("->");
    turn_up = new QPushButton("^");
    turn_down = new QPushButton("v");
    zoom_in = new QPushButton("+");
    zoom_out = new QPushButton("-");
    bottom_left_layout->addWidget(turn_left, 0, 0, 2, 1);
    bottom_left_layout->addWidget(turn_up, 0, 1);
    bottom_left_layout->addWidget(turn_right, 0, 2, 2, 1);
    bottom_left_layout->addWidget(turn_down, 1, 1);
    bottom_left_layout->addWidget(zoom_in, 0, 3);
    bottom_left_layout->addWidget(zoom_out, 1, 3);

    /** Bottom Layout **/
    piece_1 = new QPushButton("Piece 1");
    piece_2 = new QPushButton("Piece 2");
    piece_3 = new QPushButton("Piece 3");
    piece_4 = new QPushButton("Piece 4");
    piece_5 = new QPushButton("Piece 5");
    piece_6 = new QPushButton("Piece 6");
    piece_7 = new QPushButton("Piece 7");
    piece_8 = new QPushButton("Piece 8");
    piece_9 = new QPushButton("Piece 9");
    bottom_layout->addLayout(bottom_left_layout);
    bottom_layout->addWidget(piece_1);
    bottom_layout->addWidget(piece_2);
    bottom_layout->addWidget(piece_3);
    bottom_layout->addWidget(piece_4);
    bottom_layout->addWidget(piece_5);
    bottom_layout->addWidget(piece_6);
    bottom_layout->addWidget(piece_7);
    bottom_layout->addWidget(piece_8);
    bottom_layout->addWidget(piece_9);

    /** Main Layout **/
    modelisation = new Modelisation();
    central_widget = new QWidget();
    central_widget->setLayout(main_layout);
    main_layout->addLayout(left_layout, 0, 0);
    main_layout->addWidget(modelisation, 0, 1, 1, 3);
    main_layout->addLayout(bottom_layout, 1, 0, 1, 4);

    resize(QDesktopWidget().availableGeometry(this).size());
    this->setCentralWidget(central_widget);

    /** Connexion des slots **/
    QObject::connect(search, SIGNAL(clicked()), this, SLOT(solve()));
    QObject::connect(list_of_solutions, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(itemSelected(QListWidgetItem*)));
    QObject::connect(zoom_in, SIGNAL(clicked()), this, SLOT(zoomIn()));
    QObject::connect(zoom_out, SIGNAL(clicked()), this, SLOT(zoomOut()));
    QObject::connect(turn_right, SIGNAL(clicked()), this, SLOT(turnRight()));
    QObject::connect(turn_left, SIGNAL(clicked()), this, SLOT(turnLeft()));
    QObject::connect(turn_up, SIGNAL(clicked()), this, SLOT(turnUp()));
    QObject::connect(turn_down, SIGNAL(clicked()), this, SLOT(turnDown()));
    QObject::connect(piece_1, SIGNAL(clicked()), this, SLOT(switchPieceT()));
    QObject::connect(piece_2, SIGNAL(clicked()), this, SLOT(switchPieceAngle()));
    QObject::connect(piece_3, SIGNAL(clicked()), this, SLOT(switchPiecePlus()));
    QObject::connect(piece_4, SIGNAL(clicked()), this, SLOT(switchPieceL()));
    QObject::connect(piece_5, SIGNAL(clicked()), this, SLOT(switchPieceZ()));
    QObject::connect(piece_6, SIGNAL(clicked()), this, SLOT(switchPieceP()));
    QObject::connect(piece_7, SIGNAL(clicked()), this, SLOT(switchPieceY()));
    QObject::connect(piece_8, SIGNAL(clicked()), this, SLOT(switchPieceD()));
    QObject::connect(piece_9, SIGNAL(clicked()), this, SLOT(switchPieceG()));
}

Interface::~Interface() {
    delete ui;
}

void Interface::setInterfaceCommunication(InterfaceCommunication* c) {
    comm = c;
}

void Interface::keyPressEvent(QKeyEvent* event) {
    modelisation->keyPressEvent(event);
}

bool Interface::getAllSolutions() {
    return all_solutions->isChecked();
}

void Interface::calculFinished(int n_sol, int t, std::vector<Solution*>* sol) {
    std::string s1 = "Nombre de solutions : " + std::to_string(n_sol);
    solutions_found->setText(s1.c_str());

    int hours = t / 3600;
    int minutes = (t % 3600) / 60;
    int seconds = (t % 3600) % 60;
    std::string s = "Temps de recherche : " + ((hours > 0) ? std::to_string(hours) + " h" : "") + " " + ((hours > 0 || minutes > 0) ? std::to_string(minutes) + " min" : "") + " " + std::to_string(seconds) + " s";
    time->setText(s.c_str());

    solutions.clear();
    list_of_solutions->clear();
    for (unsigned int i = 0; i < sol->size(); ++i) {
        std::string sol_name = "solution " + std::to_string(i + 1);
        solutions[sol_name] = sol->at(i);
        list_of_solutions->addItem(sol_name.c_str());
    }

    search->setEnabled(true);
}

int Interface::getProblem() {
    std::string ss = list_of_problems->currentItem()->text().toStdString();
    for (unsigned int i = 0; i < problems.size(); ++i) {
        if (problems[i] == ss) {
            return i;
        }
    }
    return -1;
}

void Interface::solve() {
    comm->startSolving();
    search->setEnabled(false);
}

void Interface::itemSelected(QListWidgetItem* item) {
    Solution* current_sol = solutions[item->text().toStdString()];
    for (int i = 0; i < 9; ++i) {
        PieceModel* pm = current_sol->getPiece((PieceType) i);
        modelisation->setPieceInfo((PieceType) i, pm->isUsed(), pm->getPosition(), pm->getRotation());
    }
}

/**
 * Zoom avant de la camera
 */
void Interface::zoomIn() {
    modelisation->zoomIn();
}

/**
 * Zoom arriere de la camera
 */
void Interface::zoomOut() {
    modelisation->zoomOut();
}

/**
 * Rotation vers la droite de la camera
 */
void Interface::turnRight() {
    modelisation->turnRight();
}

/**
 * Rotation vers la gauche de la camera
 */
void Interface::turnLeft() {
    modelisation->turnLeft();
}

/**
 * Rotation vers le haut de la camera
 */
void Interface::turnUp() {
    modelisation->turnUp();
}

/**
 * Rotation vers le bas de la camera
 */
void Interface::turnDown() {
    modelisation->turnDown();
}

/**
 * Affiche la piece T si elle est affichee, sinon la cache
 */
void Interface::switchPieceT() {
    modelisation->switchPieceT();
}

/**
 * Affiche la piece Angle si elle est affichee, sinon la cache
 */
void Interface::switchPieceAngle() {
    modelisation->switchPieceAngle();
}

/**
 * Affiche la piece Plus si elle est affichee, sinon la cache
 */
void Interface::switchPiecePlus() {
    modelisation->switchPiecePlus();
}

/**
 * Affiche la piece L si elle est affichee, sinon la cache
 */
void Interface::switchPieceL() {
    modelisation->switchPieceL();
}

/**
 * Affiche la piece Z si elle est affichee, sinon la cache
 */
void Interface::switchPieceZ() {
    modelisation->switchPieceZ();
}

/**
 * Affiche la piece P si elle est affichee, sinon la cache
 */
void Interface::switchPieceP() {
    modelisation->switchPieceP();
}

/**
 * Affiche la piece Y si elle est affichee, sinon la cache
 */
void Interface::switchPieceY() {
    modelisation->switchPieceY();
}

/**
 * Affiche la piece D si elle est affichee, sinon la cache
 */
void Interface::switchPieceD() {
    modelisation->switchPieceD();
}

/**
 * Affiche la piece G si elle est affichee, sinon la cache
 */
void Interface::switchPieceG() {
    modelisation->switchPieceG();
}
