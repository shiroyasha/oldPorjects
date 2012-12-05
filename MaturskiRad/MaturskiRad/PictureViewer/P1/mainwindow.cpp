#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileInfo>
#include <QDebug>
#include <QDir>
#include <QGraphicsPixmapItem>

#include <GraphicsView.h>

MainWindow::MainWindow( QString name, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    view = new GraphicsView( ui->centralWidget );
    ui->verticalLayout->insertWidget(0, view );

    connect(view, SIGNAL(nextPicture()), SLOT(next()));
    connect(view, SIGNAL(prevPicture()), SLOT(prev()));
    connect(view, SIGNAL(zoomIn()), SLOT(zoomIn()));
    connect(view, SIGNAL(zoomOut()), SLOT(zoomOut()));
    connect(view, SIGNAL(resized()), SLOT(adjustPosition()));

    scene = new QGraphicsScene();
    item = new QGraphicsPixmapItem();
    file = new QFileInfo( name );
    dir = new QDir( file->absoluteDir() );

    scene->addItem( item );
    view->setScene( scene );

    QStringList filter;
    filter << "*.jpg" << "*.jpeg" << "*.bmp" << "*.png" << "*.gif" ;
    dir->setNameFilters( filter );
    dir->setSorting( QDir::Name );

    currentPicture = dir->entryInfoList().indexOf( *file );

    if( currentPicture > -1 ) item->setPixmap( QPixmap(name) );


}

MainWindow::~MainWindow()
{
    delete item;
    delete scene;
    delete file;


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

void MainWindow::next()
{
    int picIndex = ++currentPicture;
    if( picIndex == dir->entryInfoList().count() ) picIndex = 0;

    //qDebug() << picIndex << dir->entryInfoList().count() << dir->entryInfoList().at( picIndex ).absoluteFilePath();
    item->setPixmap( QPixmap( dir->entryInfoList().at( picIndex ).absoluteFilePath() ));
    currentPicture = picIndex;
}

void MainWindow::prev()
{
    int picIndex = --currentPicture;
    if( picIndex == -1 ) picIndex = dir->entryInfoList().count() -1;

    //qDebug() << picIndex << dir->entryInfoList().count() << dir->entryInfoList().at( picIndex ).absoluteFilePath();
    item->setPixmap( QPixmap( dir->entryInfoList().at( picIndex ).absoluteFilePath() ));
    currentPicture = picIndex;
}

void MainWindow::zoomIn()
{
    item->rotate( 90 );
    adjustPosition();
    qDebug() << "bla";
}

void MainWindow::zoomOut()
{

}

void MainWindow::adjustPosition()
{
    view->fitInView( item, Qt::KeepAspectRatio );

}
