#ifndef MYVIDEOWIDGET_H
#define MYVIDEOWIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QDebug>


class MyVideoWidget : public QWidget
{
    Q_OBJECT
public:
    MyVideoWidget()
    {
        setMouseTracking(true);
        m_inArea = false;
    }
    ~MyVideoWidget(){}

    void mouseDoubleClickEvent(QMouseEvent *e)
    {
        emit doubleClick();
    }

    void mouseMoveEvent(QMouseEvent *e)
    {
        qDebug() << "a";
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

signals:
    void sizeChanged();
    void doubleClick();
    void mouseInArea(bool);

private:
    bool m_inArea;
};

#endif // MYVIDEOWIDGET_H
