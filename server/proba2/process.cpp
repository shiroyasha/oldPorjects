#include "process.h"
#include <QDebug>
#include <sstream>
#include <string>
#include <QTimer>

process::process(widget *parent) :
    QProcess(parent)
{
    connect( this              , SIGNAL(update(int,int))                  , parent                 , SLOT(crtaj(int,int))       );
    connect( this              , SIGNAL(readyReadStandardOutput())        , SLOT(chitaj()) );
    start("./proba1");
}

process::~process()
{
    terminate();
}


void process::chitaj()
{
    while( canReadLine() )
    {
        QTimer::singleShot(200, this, SLOT(chitaj2()));
    }
}

void process::chitaj2()
{
    QByteArray ba;
    ba = readLine();
    QString line = QString::fromLocal8Bit( ba );

    int x,y;

    std::stringstream ss(std::stringstream::in | std::stringstream::out);

    std::string s(line.toAscii());

    ss << s;

    qDebug() << line;

    ss >> x >> y;

    qDebug() << "ok?" << x << y;

    update(x, y);
}


