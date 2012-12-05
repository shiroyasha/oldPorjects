#ifndef CINTHREAD_H
#define CINTHREAD_H

#include <QThread>
#include <string>
#include <widget.h>
#include <widget.h>

class CinThread : public QThread
{
    Q_OBJECT
public:
    explicit CinThread(widget *parent = 0);
    virtual ~CinThread();

    void run();
    QString getLine();
    function getNextFunction();

signals:
    void newInput(QList<function>);

public slots:

private:
    bool quit;

};

#endif // CINTHREAD_H
