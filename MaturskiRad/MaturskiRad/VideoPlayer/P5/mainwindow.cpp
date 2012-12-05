#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "MySlider.h"
#include "MPlayerProcess.h"
#include "MyWidget.h"

#include <QFileDialog>
#include <QDebug>
#include <QDialog>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->actionOpen->setIcon( QIcon::fromTheme("document-open"));
    ui->actionPlay->setIcon( QIcon::fromTheme("media-playback-start"));
    ui->actionMute->setIcon( QIcon::fromTheme("player-volume"));
    ui->actionVideoOptions->setIcon( QIcon::fromTheme("configure"));

    volumeSlider = new MySlider();
    videoSlider = new MySlider();

    volumeSlider->setMaximumWidth(100);
    volumeSlider->setOrientation( Qt::Horizontal );
    volumeSlider->setMaximum(100);
    volumeSlider->setValue(100);
    videoSlider->setOrientation( Qt::Horizontal );

    ui->mainToolBar->addWidget( videoSlider );
    ui->mainToolBar->addAction( ui->actionMute );
    ui->mainToolBar->addWidget( volumeSlider );

    widget = new MyWidget();
    widget->setMouseTracking(true);

    ui->videoWidget->setMouseTracking(true);

    ui->horizontalLayout->addWidget(widget);
    ui->videoWidget->setParent(widget);

    mainProcess = new MPlayerProcess( ui->videoWidget );
    ui->videoWidget->setFocusPolicy(Qt::NoFocus);


    ui->videoWidget->setAutoFillBackground(false);
    widget->setAutoFillBackground(false);

    ui->dockWidget->hide();

    m_aspectRatio = -1;

    connect( ui->actionOpen        , SIGNAL(triggered())                , this                      , SLOT(openFiles())                       );
    connect( mainProcess           , SIGNAL(mediaPosition(int))         , this                      , SLOT(setVideoSliderValue(int))          );
    connect( videoSlider           , SIGNAL(positionChanged(int))       , mainProcess               , SLOT(setMediaPosition(int))             );
    connect( mainProcess           , SIGNAL(durationChanged(int))       , this                      , SLOT(setDuration(int))                  );
    connect( volumeSlider          , SIGNAL(positionChanged(int))       , this                      , SLOT(setVolume(int))                    );
    connect( mainProcess           , SIGNAL(volumeLevelChanged(int))    , this                      , SLOT(setVolumeSliderValue(int))         );
    connect( mainProcess           , SIGNAL(fileNameChanged(QString))   , this                      , SLOT(setFileName(QString))              );
    connect( ui->actionPlay        , SIGNAL(triggered())                , this                      , SLOT(togglePlayPauseIcon())             );
    connect( mainProcess           , SIGNAL(sizeChanged())              , this                      , SLOT(setVideoWidgetSize())              );
    connect( widget                , SIGNAL(sizeChanged())              , this                      , SLOT(setVideoWidgetSize())              );
    connect( widget                , SIGNAL(doubleClick())              , this                      , SLOT(toggleFullScreen())                );
    connect( widget                , SIGNAL(mouseInArea(bool))          , this                      , SLOT(toggleToolBar(bool))               );
    connect( ui->actionVideoOptions, SIGNAL(toggled(bool))              , ui->dockWidget            , SLOT(setVisible(bool))                  );
    connect( ui->dockWidget        , SIGNAL(visibilityChanged(bool))    , ui->actionVideoOptions    , SLOT(setChecked(bool))                  );
    connect( ui->comboBoxAspect    , SIGNAL(currentIndexChanged(int))   , this                      , SLOT(setAspectRatio(int))               );
    connect( ui->checkBoxLoop      , SIGNAL(toggled(bool))              , mainProcess               , SLOT(setLoop(bool))                     );
    connect( ui->spinBoxSpeed      , SIGNAL(valueChanged(int))          , mainProcess               , SLOT(setSpeed(int))                     );
    connect( ui->spinBoxAVDelay    , SIGNAL(valueChanged(int))          , mainProcess               , SLOT(setAudioDelay(int))                );

}

MainWindow::~MainWindow()
{
    delete ui;

    delete volumeSlider;
    delete videoSlider;
    delete mainProcess;
    delete widget;
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

void MainWindow::openFileFromAnotherProcess(QString value)
{
    mainProcess->openStream(value);
}

void MainWindow::openFiles()
{
    QStringList  fileName = QFileDialog::getOpenFileNames(this, "Select files to add to playlist", "/home" );
    if( !fileName.empty() )
    {
        videoSlider->setValue(0);
        ui->actionPlay->setIcon( QIcon::fromTheme("media-playback-pause"));
        m_isPlaying = true;
        mainProcess->openStream( fileName.at(0) );
    }
}

void MainWindow::setVideoSliderValue(int value)
{
    if( !videoSlider->isMousePressed() && ( (abs(value - videoSlider->value()) < 2) || (abs(value - videoSlider->value()) > (videoSlider->maximum() - 2))) )
    {
        videoSlider->setValue( value );
    }
}

static float aspectRatioArray[10] = { -1, 1, 3.0/2.0, 4.0/3.0, 5.0/4.0, 14.0/9.0, 14.0/10.0, 16.0/9.0, 16.0/10.0, 2.35};

void MainWindow::setAspectRatio(int value)
{
    m_aspectRatio = aspectRatioArray[value];

    setVideoWidgetSize();
}

void MainWindow::setDuration(int value)
{
    //qDebug() << "Duration of the media" << value;
    videoSlider->setMaximum( value );
}

void MainWindow::setVolume(int value)
{
    mainProcess->setVolume(value);
}

void MainWindow::setVolumeSliderValue(int value)
{
    if( !volumeSlider->isMousePressed() )
    {
        volumeSlider->setValue( value );
        m_isPlaying = true;
        togglePlayPauseIcon();
    }
}

void MainWindow::setFileName(QString value)
{
    setWindowTitle(value);
}

void MainWindow::toggleFullScreen()
{
    setWindowState( windowState() ^ Qt::WindowFullScreen);

    ui->mainToolBar->setGeometry(width()/2 - 300, 30, 600, ui->mainToolBar->height());

    if( !isFullScreen() )
    {
        ui->mainToolBar->show();
    }
    else
    {
        ui->mainToolBar->hide();
    }
}

void MainWindow::toggleToolBar(bool value)
{
    if( isFullScreen() )
    {
        if(value)
        {
            ui->mainToolBar->show();
        }
        else
        {
            ui->mainToolBar->hide();
        }
    }
}

void MainWindow::setVideoWidgetSize()
{
    if( mainProcess->getSize().width()*mainProcess->getSize().height() > 0)
    {
        float aspect = 0;
        if(m_aspectRatio < 0)
        {
            aspect = (float)mainProcess->getSize().width()/(float)mainProcess->getSize().height();
        }
        else if( m_aspectRatio > 0)
        {
            aspect = m_aspectRatio;
        }

        float w1 = widget->width();
        float h1 = widget->height();
        float w2 = aspect;
        float h2 = 1;

        //qDebug() << w2 << w1 << w2/w1;
        //qDebug() << h2 << h1 << h2/h1;

        bool chooseHorizontalSide = ( w2 / w1 ) > ( h2 / h1 );

        if( chooseHorizontalSide )
        {
            int size = (int)( (float)(1/aspect) * (float)widget->width() );
            int pos = ( widget->height() - size ) /2;

            ui->videoWidget->setGeometry(0, pos , widget->width() , size );
        }
        else
        {
            int size = (int)( (float)(aspect) * (float)widget->height() );
            int pos = ( widget->width() - size ) /2;

            ui->videoWidget->setGeometry(pos, 0 , size , widget->height() );
        }
    }
}

void MainWindow::togglePlayPauseIcon()
{
    mainProcess->togglePlayPause();

    //qDebug() << m_isPlaying;
    if( !m_isPlaying )
    {
        m_isPlaying = true;
        ui->actionPlay->setIcon( QIcon::fromTheme("media-playback-pause"));

    }
    else
    {
        m_isPlaying = false;
        ui->actionPlay->setIcon( QIcon::fromTheme("media-playback-start"));
    }

    qDebug() << m_isPlaying;
}
