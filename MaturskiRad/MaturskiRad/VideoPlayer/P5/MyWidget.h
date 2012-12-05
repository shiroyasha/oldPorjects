#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QResizeEvent>
#include <QPaintEvent>
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>


class MyWidget : public QWidget
{
    Q_OBJECT
public:
    MyWidget()
    {
        m_inArea = false;

        //setAttribute(Qt::WA_NoSystemBackground);
        //setAttribute(Qt::WA_PaintOnScreen);
        //setAttribute(Qt::WA_PaintUnclipped);

    }
    ~MyWidget(){}

    void resizeEvent(QResizeEvent *)
    {
        emit sizeChanged();
    }
    void paintEvent(QPaintEvent *e)
    {

        QPainter p(this);
        p.fillRect(0,0, width(), height(), Qt::black );
        p.end();

    }

    void mouseDoubleClickEvent(QMouseEvent *e)
    {
        emit doubleClick();
    }

    void mouseMoveEvent(QMouseEvent *e)
    {
        //qDebug() << e->y() << m_inArea;
        if(e->y() <= 50 && !m_inArea)
        {
            m_inArea = true;
            emit mouseInArea(m_inArea);
        }
        else if( e->y() > 50 && m_inArea )
        {
            m_inArea = false;
            emit mouseInArea(m_inArea);
        }
    }

    void keyPressEvent(QKeyEvent *e)
    {
        qDebug() << e->key();
    }

    void keyReleaseEvent(QKeyEvent *e)
    {
        qDebug() << e->key();
    }

signals:
    void sizeChanged();
    void doubleClick();
    void mouseInArea(bool);

private:
    bool m_inArea;
};

#endif // MYWIDGET_H
