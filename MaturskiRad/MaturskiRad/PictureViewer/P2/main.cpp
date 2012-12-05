#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qDebug() << "a";
    MainWindow w( QString( argv[1] ) , 0 );
    w.show();
    return a.exec();
}
