#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QHBoxLayout>
#include <QStringList>
#include <QFont>
#include <QColor>

namespace Ui {
    class MainWindow;
}

class TextEdit;
class QCloseEvent;

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QStringList files, QWidget *parent = 0 );
    ~MainWindow();

    void closeEvent(QCloseEvent *);

protected:
    void changeEvent(QEvent *e);
    void writeToFile(QString fileName);
    void createTab(QString fileName);

protected slots:
    void undo();
    void redo();
    void open();
    void save();
    void saveAs();
    void configureGui();
    void configureGui(int);
    void configureGui(bool);
    void newTab();
    void closeTabFromMenu();
    int  closeTab(int);
    void quitFromMenu();
    void toggleFindWidget();
    void toggleGotoLine();
    void requestedClosing(TextEdit*);

    //find
    void findFirst(QString);
    void findNext();
    void findPrev();
    void replaceNext();
    void replacePrevious();
    void replaceAll();

    //gotoLine
    void gotoLine(int);
    void setGotoMaximum();

    //select
    void selectAll();
    void deselect();

    //copy-paste
    void toggleCopyAction(bool);
    void copy();
    void cut();
    void paste();

    //tools
    void indent();
    void unindent();
    void uppercase();
    void lowercase();
    void capitalize();

    //settings
    void selectFont();
    void selectFontColor();
    void zoomIn();
    void zoomOut();

private:
    Ui::MainWindow          *ui;
    QList<TextEdit*>        widgets;

    QColor                  m_textColor;
    QFont                   m_textFont;
    QString                 m_lastPath;

};

#endif // MAINWINDOW_H
