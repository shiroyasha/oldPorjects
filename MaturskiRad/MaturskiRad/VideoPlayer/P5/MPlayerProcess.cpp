#include "MPlayerProcess.h"

#include <QWidget>
#include <QDebug>
#include <QFileInfo>

MPlayerProcess::MPlayerProcess(QWidget *videoWidget)
{
    connect( this              , SIGNAL(readyReadStandardOutput())        , SLOT(readStandardOutput()) );
    QStringList arguments;
    arguments << "-noaspect"
              << "-nomouseinput"
              << "-wid" << QString::number( videoWidget->winId() )
              << "-slave"
              << "-dr"
              << "-identify"
              << "-nodouble"
              << "-nojoystick"
              << "-nolirc"
              << "-idle"
              << "-idx"
              << "-vo" << "xv";

    start("mplayer", arguments);
}

MPlayerProcess::~MPlayerProcess()
{
    terminate();
}

void MPlayerProcess::togglePlayPause()
{
    QString arg = "pause\n";
    write( arg.toAscii() );
}

void MPlayerProcess::openStream(QString fileName)
{
    QString arg = "loadfile '" + fileName + "' 0 \n";
    write( arg.toAscii() );
}

void MPlayerProcess::setMediaPosition(int value)
{
    QString pomocni;
    pomocni = "pausing_keep_force seek " + QString::number( value ) + " 2 " + "\n";
    write( pomocni.toAscii() );
}

void MPlayerProcess::setVolume(int value)
{
    QString pomocni;
    pomocni = "volume " + QString::number( value ) + " 1" + "\n";
    write( pomocni.toAscii() );
}

void MPlayerProcess::setLoop(bool value)
{
    QString pomocni;
    if(value)
    {
        qDebug() << value;
        pomocni = "loop 1 \n";
    }
    else
    {
        pomocni = "loop -1 \n";
    }
    write( pomocni.toAscii() );
}

void MPlayerProcess::setSpeed(int value)
{
    QString pomocni;

    pomocni = "speed_set " + QString::number( (float) value/100 ) +  "\n";
    write( pomocni.toAscii() );
}

void MPlayerProcess::setAudioDelay(int value)
{
    QString pomocni;

    pomocni = "audio_delay " + QString::number( value ) + " 1 " + "\n";
    write( pomocni.toAscii() );
}

static QRegExp rx_av("^[AV]: *([0-9,:.-]+)");

static QRegExp rx_fileName("^Playing (.*)");
static QRegExp rx_pause(" =====  PAUSE  =====");

static QRegExp rx_duration("^ duration: (.*)");
static QRegExp rx_duration2("^ID_LENGTH=(.*)");

static QRegExp rx_width("^ width: (.*)");
static QRegExp rx_width2("^ID_VIDEO_WIDTH=(.*)");
static QRegExp rx_height("^ height: (.*)");
static QRegExp rx_height2("^ID_VIDEO_HEIGHT=(.*)");

void MPlayerProcess::readStandardOutput()
{
    QByteArray ba;
    ba = readLine();
    QString line = QString::fromLocal8Bit( ba );

    if ( rx_av.indexIn(line) > -1 )
    {
        double sec =  rx_av.cap(1).toDouble();
        //qDebug()<< sec;
        emit mediaPosition( static_cast<int>(sec) );
    }

    if( rx_duration.indexIn( line ) > -1 )
    {
        emit durationChanged( rx_duration.cap(1).toInt() );
    }
    if( rx_duration2.indexIn( line ) > -1 )
    {
        emit durationChanged( (int)rx_duration2.cap(1).toDouble() );
    }

    if( rx_fileName.indexIn(line) > -1)
    {
        //qDebug() << "File Name  " << rx_duration.cap(1);
        QString s = rx_fileName.cap(1);
        s.chop(2);
        QFileInfo info(s);
        emit fileNameChanged( info.fileName() );
    }

    if( rx_width.indexIn(line) > -1)
    {
        //qDebug() << line << "width";
        m_videoSize.setWidth( rx_width.cap(1).toInt() );
        emit sizeChanged();
    }

    if( rx_width2.indexIn(line) > -1)
    {
        //qDebug() << line << "width2";
        m_videoSize.setWidth( rx_width2.cap(1).toInt() );
        emit sizeChanged();
    }

    if( rx_height.indexIn(line) > -1)
    {
        //qDebug() << line << "height";
        m_videoSize.setHeight( rx_height.cap(1).toInt() );
        emit sizeChanged();
    }
    if( rx_height2.indexIn(line) > -1)
    {
        //qDebug() << line << "height2";
        m_videoSize.setHeight( rx_height2.cap(1).toInt() );
        emit sizeChanged();
    }

    if( rx_pause.indexIn(line) > -1)
    {
    }
}
