#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <MyWidget.h>

namespace Ui {
    class MainWindow;
}

class QScrollArea;
class QResizeEvent;

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QString fileName, QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);
    void resizeEvent(QResizeEvent *);

protected slots:
    void setZoomValue(int);
    void updateImageInfo();
    void setFullScreen();
    void toggleEnableZoomSlider(bool);

private:
    Ui::MainWindow *ui;
    MyWidget *picWidget;
    QScrollArea *area;
};

#endif // MAINWINDOW_H
