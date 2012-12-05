#include "cinthread.h"
#include <iostream>
#include <QRect>
#include <QList>
#include <QMetaType>
#include <QDebug>
#include <sstream>
#include <QString>
#include <QStringList>


CinThread::CinThread(widget *parent) :
    QThread(parent)
{
    connect( this,  SIGNAL(newInput(QList<function>)) , parent , SLOT(crtaj(QList<function>)));
    quit = false;

    qRegisterMetaType< QList<function> >("QList<function>");

    start();
}

CinThread::~CinThread()
{
    quit = false;
    if( isRunning() )
    {
        wait();
    }
}

QString CinThread::getLine()
{
    std::string pomocni;
    std::getline( std::cin, pomocni );

    return QString::fromStdString( pomocni );
}

function CinThread::getNextFunction()
{
    function ret;
    QString str = getLine();

    QRegExp rx("\\b[0-9]+\\b");
    if( rx.indexIn( str ) > -1 )
    {
            qDebug() << rx.cap(1);
    }

    QStringList slist = str.split(" ", QString::SkipEmptyParts);

    ret.id = slist[0].toInt();
    slist.removeAt(0);

    foreach(QString s, slist)
    {
        ret.args.append( s );
    }

    return ret;
}

void CinThread::run()
{
    QList<function> list;
    while( !quit )
    {
        function f = getNextFunction();

        if( widget::numOfArgs[ f.id ] == f.args.length()  && f.id > 0 && f.id < NUMBER_OF_FUNCTIONS )
        {
            list.push_back( f );
        }
        else
        {
            qDebug() << "function" << f.id << "takes" << widget::numOfArgs[ f.id ] << "arguments" << "not" << f.args.length();
        }

        if( f.id == 0 )
        {
            emit newInput(list);
            quit = true;
        }
    }
}
