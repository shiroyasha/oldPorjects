#include "MySlider.h"

#include <QMouseEvent>
#include <QWheelEvent>
#include <QKeyEvent>

MySlider::MySlider() : m_mousePressed( false )
{

}

MySlider::~MySlider() 
{

}

void MySlider::mousePressEvent(QMouseEvent *e)
{
    m_mousePressed = true;
    if (e->button() == Qt::LeftButton)
    {
        QMouseEvent ev2(QEvent::MouseButtonRelease, e->pos(), e->globalPos(), Qt::MidButton, Qt::MidButton, e->modifiers());
        QSlider::mousePressEvent(&ev2);
        return;
    }
    else if (e->button() == Qt::MidButton)
    {
        //QMouseEvent ev2(QEvent::MouseButtonRelease, e->pos(), e->globalPos(), Qt::LeftButton, Qt::LeftButton, e->modifiers());
        //QSlider::mousePressEvent(&ev2);
    }
    else
    {
        QSlider::mousePressEvent(e);
    }
}

void MySlider::mouseReleaseEvent(QMouseEvent *ev)
{
    emit positionChanged( value() );
    m_mousePressed = false;
}

void MySlider::wheelEvent(QWheelEvent *e)
{
    e->ignore();
}
void MySlider::keyPressEvent(QKeyEvent *e)
{
    e->ignore();
}
void MySlider::keyReleaseEvent(QKeyEvent *e)
{
    e->ignore();
}

bool MySlider::isMousePressed()
{
    return m_mousePressed;
}
