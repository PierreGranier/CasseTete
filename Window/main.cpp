#include <QApplication>
#include "window.h"

int main(int argc, char *argv[]) {
    
  QApplication app(argc, argv);  

 MainWindow window;

  window.setWindowTitle("solution de casse-tetes");

  window.show();

  return app.exec();
}
