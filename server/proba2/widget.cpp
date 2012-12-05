#include "widget.h"
#include <QPainter>
#include <QDebug>

widget::widget(QWidget *parent) :
    QWidget(parent)
{
    m_x = 1;
    m_y = 1;
}

void widget::paintEvent(QPaintEvent *e)
{
    QPainter p;

    p.begin(this);
    p.drawRect( m_x, m_y, 100, 100);
    p.end();

    qDebug() << m_x << m_y;

}

void widget::crtaj( int x, int y)
{
    m_x = x;
    m_y = y;

    update();
}
