#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

class QFileInfo;
class QGraphicsPixmapItem;
class QGraphicsScene;
class QDir;
class GraphicsView;

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QString name, QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);

public slots:
    void next();
    void prev();
    void zoomIn();
    void zoomOut();
    void adjustPosition();

private:
    Ui::MainWindow *ui;
    QFileInfo *file;

    QGraphicsPixmapItem *item;
    QGraphicsScene *scene;
    QDir *dir;
    GraphicsView *view;
    int currentPicture;
};

#endif // MAINWINDOW_H
