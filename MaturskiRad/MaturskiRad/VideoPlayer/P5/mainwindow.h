#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MySlider;
class MyWidget;
class MPlayerProcess;
class QDialog;

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);

protected slots:
    void openFiles();
    void setVideoSliderValue(int);
    void setDuration(int);
    void setVolume(int);
    void setVolumeSliderValue(int);
    void setFileName(QString);
    void togglePlayPauseIcon();
    void setVideoWidgetSize();
    void toggleFullScreen();
    void toggleToolBar(bool);
    void setAspectRatio(int);
    void openFileFromAnotherProcess(QString);

private:
    Ui::MainWindow *ui;

    MySlider        *volumeSlider;
    MySlider        *videoSlider;

    MPlayerProcess  *mainProcess;
    bool            m_isPlaying;
    MyWidget        *widget;
    float           m_aspectRatio;

    //QWidget         *vWidget;

};

#endif // MAINWINDOW_H
