#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QCoreApplication::setOrganizationName("SquirrelProject");
    //QCoreApplication::setOrganizationDomain("mysoft.com");
    QCoreApplication::setApplicationName("Squirrel Editor");


    QStringList lista;
    if( argc > 1)
    {
        for(int i= 1; i < argc; ++i)
        {
            QString pomocni = argv[i];
            lista.append(pomocni);
        }
    }
    //qDebug() << "tu";
    MainWindow w(lista);
    w.show();
    return a.exec();
}
