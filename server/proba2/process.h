#ifndef PROCESS_H
#define PROCESS_H

#include <QProcess>
#include <widget.h>

class process : public QProcess
{
    Q_OBJECT
public:
    explicit process(widget *parent = 0);
    ~process();

signals:
    void update(int x, int y);
public slots:
    void chitaj();
    void chitaj2();
};

#endif // PROCESS_H
