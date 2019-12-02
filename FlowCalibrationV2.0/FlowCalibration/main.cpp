#include "FCMainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FCMainWindow w;
    w.show();

    return a.exec();
}
