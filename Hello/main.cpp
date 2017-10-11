#include <QApplication>
#include "mywindow.h"



int main(int argc, char *argv[])
{

           QApplication app(argc, argv);
           mywindow mywin;
           mywin.show();
           return app.exec();
}
