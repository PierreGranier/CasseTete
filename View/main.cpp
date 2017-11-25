#include <QApplication>
#include "fenetre.h"



int main(int argc, char *argv[])
{

           QApplication app(argc, argv);
           Fenetre window;
         //  window.setFormat(format);
           window.resize(QSize(800, 600));
           window.show();

           return app.exec();
}
