#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QProcess>

#include "VideoWidget.h"
#include "MySlider.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    video= new VideoWidget(this);
    video->show();
    connect( video, SIGNAL(doubleClick()), SLOT(toggleFullscreen()));

    timeSlider = new MySlider();
    timeSlider->setOrientation(Qt::Horizontal);
    ui->horizontalLayout_2->addWidget( timeSlider );
    connect(timeSlider, SIGNAL(positionChanged(int)), SLOT( timeSliderPositionChanged(int) ) );

    QStringList arguments;
    arguments << "-nomouseinput" << "-wid" << QString::number( video->winId() )
              << "-slave" << "-dr" << "-nodouble" << "-nojoystick" << "-nolirc"
              << "-idx" << "-vo" << "xv" << "/tmp/Flashxb2Ixg";


    mp = new QProcess(this);

    connect( mp , SIGNAL( readyReadStandardOutput() ), this, SLOT( readStandardOutputMplayer() ) );

    mp->start("mplayer", arguments);


    mp->waitForStarted(100000000);

    mp->write("get_file_name \n");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::on_pushButton_4_toggled(bool checked)
{
    mp->write("pause\n");
}

void MainWindow::toggleFullscreen()
{
    if( video->isFullScreen() )
    {
        video->setWindowState( video->windowState() ^ Qt::WindowFullScreen);
        mp->write("pausing_keep_force vo_fullscreen 0\n");
    }
    else
    {
        video->setWindowState( video->windowState() ^ Qt::WindowFullScreen);
        mp->write("pausing_keep_force vo_fullscreen 1\n");
    }
}

void MainWindow::timeSliderPositionChanged(int value)
{
    QString pomocni;
    pomocni = "seek " + QString::number( value ) + " 2 " + "\n";
    mp->write( pomocni.toAscii() );
}

void MainWindow::setMediaPosition(int sec)
{
    if( !timeSlider->isMousePressed() )
    {
        timeSlider->setValue( sec );
    }
}

static QRegExp rx("^(.*)=(.*)");
static QRegExp rx_av("^[AV]: *([0-9,:.-]+)");

//video
static QRegExp rx_video("^ID_VID_(\\d+)_(LANG|NAME)=(.*)");

void MainWindow::readStandardOutputMplayer()
{
    QByteArray ba;
    ba = mp->readLine();
    QString line = QString::fromLocal8Bit( ba );

    if (rx_av.indexIn(line) > -1)
    {
        double sec =  rx_av.cap(1).toDouble();
        setMediaPosition( static_cast<int>(sec) );
    }
    if (rx.indexIn(line) > -1)
    {
        QString tag = rx.cap(1);
        QString value = rx.cap(2);

        if( tag == "ID_LENGTH")
        {
            qDebug( "lenght is %d", value.toInt() );
        }
    }
    static QRegExp rx2("^ duration: (.*)");
    if( rx2.indexIn( line ) > -1 )
    {
        qDebug() << rx2.cap(1);
        timeSlider->setMaximum( rx2.cap(1).toInt() );


    }



    static QRegExp rx3("^ANS_FILENAME=(.*)");
    if( rx3.indexIn(line) > -1)
    {
        QString pomocni = rx3.cap(1);
        ui->label->setText( pomocni );
    }

}


void MainWindow::on_verticalSlider_valueChanged(int value)
{
    qDebug() << value;
    QString pomocni;
    pomocni = "volume " + QString::number( value ) + " 1" + "\n";
    mp->write( pomocni.toAscii() );
}
