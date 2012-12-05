#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QScrollBar>
#include <QDebug>
#include <QScrollArea>
#include <QResizeEvent>
#include <QIcon>

MainWindow::MainWindow(QString fileName, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    area = new QScrollArea();
    ui->horizontalLayout->addWidget(area);

    picWidget = new MyWidget( fileName , area);
    picWidget->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    area->setWidget(picWidget);
    area->setFocusPolicy(Qt::NoFocus);

    area->setAlignment( Qt::AlignCenter );

    ui->statusBar->addWidget( ui->label);
    ui->toolBar->addWidget( ui->widget );
    ui->toolBar->addAction( ui->actionFullScreen );
    ui->toolBar->addAction( ui->actionFitInView );
    ui->toolBar->addWidget( ui->horizontalSlider );
    ui->toolBar->addWidget( ui->spinBox );

    ui->action1->setIcon( QIcon::fromTheme("document-open"));
    ui->actionPrev->setIcon( QIcon::fromTheme("go-previous") );
    ui->actionNext->setIcon( QIcon::fromTheme("go-next") );
    ui->actionRotate_Left->setIcon( QIcon::fromTheme("object-rotate-left") );
    ui->actionRotate_Right->setIcon( QIcon::fromTheme("object-rotate-right"));
    ui->actionFitInView->setIcon( QIcon::fromTheme("zoom-fit-best"));
    ui->actionFullScreen->setIcon( QIcon::fromTheme("view-fullscreen"));

    connect( ui->horizontalSlider     , SIGNAL(valueChanged(int))    , picWidget    , SLOT( setZoom(int))                );
    connect( ui->spinBox              , SIGNAL(valueChanged(int))    , picWidget    , SLOT( setZoom(int))                );
    connect( picWidget                , SIGNAL(zoomValueChanged(int))               , SLOT( setZoomValue(int))           );
    connect( picWidget                , SIGNAL(imageChanged())                      , SLOT( updateImageInfo())           );
    connect( ui->actionNext           , SIGNAL(triggered())          , picWidget    , SLOT( nextImage())                 );
    connect( ui->actionPrev           , SIGNAL(triggered())          , picWidget    , SLOT( prevImage())                 );
    connect( ui->actionRotate_Left    , SIGNAL(triggered())          , picWidget    , SLOT( rotatePixmapLeft())          );
    connect( ui->actionRotate_Right   , SIGNAL(triggered())          , picWidget    , SLOT( rotatePixmapRight())         );
    connect( ui->actionFitInView      , SIGNAL(toggled(bool))        , picWidget    , SLOT( fitInView(bool))             );
    connect( ui->actionFullScreen     , SIGNAL(toggled(bool))        ,                SLOT( setFullScreen())             );
    connect( ui->action1              , SIGNAL(triggered())          , picWidget    , SLOT( openImage())                 );
    connect( picWidget                , SIGNAL(setZoomSlider(bool))  ,                SLOT(toggleEnableZoomSlider(bool)) );

    updateImageInfo();

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

void MainWindow::resizeEvent(QResizeEvent *e)
{
    picWidget->adjustSize();
    Q_UNUSED(e)
}

void MainWindow::setZoomValue(int value)
{
    //qDebug() << value;
    ui->horizontalSlider->setValue( value );
    ui->spinBox->setValue( value );
}

void MainWindow::updateImageInfo()
{
    setWindowTitle( "Squirell Viewer - " + picWidget->getImageName() );
    ui->label->setText( "  index: " + QString::number(picWidget->getImageIndex() + 1) + " / " + QString::number(picWidget->getNumberOfImagesInFolder())
                        + "     size: " + QString::number( picWidget->getImageSize().width() ) + " x " + QString::number( picWidget->getImageSize().height() ));
}

void MainWindow::setFullScreen()
{
    setWindowState( windowState() ^ Qt::WindowFullScreen);
}

void MainWindow::toggleEnableZoomSlider(bool value)
{
    ui->horizontalSlider->setEnabled(value);
    ui->spinBox->setEnabled(value);
}

