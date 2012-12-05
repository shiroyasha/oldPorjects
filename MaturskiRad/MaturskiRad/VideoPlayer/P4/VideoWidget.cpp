#include "VideoWidget.h"
#include <QMouseEvent>

VideoWidget::VideoWidget(QWidget *parent) : QDialog( parent )
{

}

VideoWidget::~VideoWidget()
{

}

void VideoWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
    emit doubleClick();

    Q_UNUSED(event);
}
