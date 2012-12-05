#ifndef MYSLIDER_H
#define MYSLIDER_H

#include <QSlider>

class QMouseEvent;
class QWheelEvent;
class QKeyEvent;

class MySlider : public QSlider
{
    Q_OBJECT
public:
    MySlider();
    ~MySlider();

    void mousePressEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);
    void wheelEvent(QWheelEvent *e);
    void keyPressEvent(QKeyEvent *ev);
    void keyReleaseEvent(QKeyEvent *);

    bool isMousePressed();

signals:
    void positionChanged(int);

private:
    bool m_mousePressed;
};

#endif // MYSLIDER_H
