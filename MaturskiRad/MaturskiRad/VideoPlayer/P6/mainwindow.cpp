#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->actionOpen->setIcon(QIcon::fromTheme("document-open"));
    ui->actionPause->setIcon( QIcon::fromTheme("media-playback-pause") );
    ui->actionSettings->setIcon( QIcon::fromTheme("media-playback-pause") );

    ui->mainToolBar->addAction(ui->actionOpen);
    ui->mainToolBar->addAction(ui->actionPause);
    ui->mainToolBar->addAction(ui->actionSettings);
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
