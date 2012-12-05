#ifndef VIDEOWIDGET_H
#define VIDEOWIDGET_H

#include <QDialog>

class QMouseEvent;

class VideoWidget : public QDialog
{
    Q_OBJECT
public:
    VideoWidget(QWidget *parent);
    ~VideoWidget();

    void mouseDoubleClickEvent ( QMouseEvent * event  );
signals:
    void doubleClick();
};

#endif // VIDEOWIDGET_H
