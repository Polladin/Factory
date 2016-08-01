#include "factorygamemainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FactoryGameMainWindow w;
    w.show();

    return a.exec();
}
