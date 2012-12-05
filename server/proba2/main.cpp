#include <QApplication>
#include <widget.h>
#include <process.h>

int main( int argc, char** argv)
{
    QApplication a(argc, argv);

    widget w;
    w.show();

    process p(&w);

    return a.exec();
}
