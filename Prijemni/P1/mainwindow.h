#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void init();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;

private slots:
    void on_prijavi_clicked();
    void on_napravi_clicked();

private:

    char m_status[790]; // u-radjen, n-euradjen , 0-nebitan
    int m_trenutni[11];

    int uradjeni;
    int neuradjeni;
    int nebitni;
};

#endif // MAINWINDOW_H
