#include <QtGui/QApplication>
#include "mainwindow.h"

#include <QFileInfo>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w( QString( argv[1] ) , 0);
    w.show();


    return a.exec();
}
