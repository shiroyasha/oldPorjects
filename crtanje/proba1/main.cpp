#include <QApplication>
#include <widget.h>
#include <QTimer>
#include <QObject>
#include <cinthread.h>

int main( int argc, char** argv)
{
    QApplication a( argc, argv );

    widget w;
    w.show();

    CinThread c(&w);

    return a.exec();
}
