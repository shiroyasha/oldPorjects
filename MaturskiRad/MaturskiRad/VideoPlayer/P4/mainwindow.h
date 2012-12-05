#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}
class QProcess;
class VideoWidget;
class MySlider;

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);

    void setMediaPosition( int sec );

private:
    Ui::MainWindow *ui;
    QProcess *mp;
    VideoWidget *video;
    MySlider *timeSlider;

private slots:
    void on_verticalSlider_valueChanged(int value);
    void on_pushButton_4_toggled(bool checked);
    void toggleFullscreen();
    void timeSliderPositionChanged(int value);
    void readStandardOutputMplayer();
};

#endif // MAINWINDOW_H
