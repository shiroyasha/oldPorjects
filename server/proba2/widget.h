#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class widget : public QWidget
{
    Q_OBJECT
public:
    explicit widget(QWidget *parent = 0);

    virtual void paintEvent(QPaintEvent *);

signals:

public slots:
    void crtaj(int x, int y);

private:
    int m_x;
    int m_y;
};

#endif // WIDGET_H
