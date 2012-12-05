#include <GraphicsView.h>
#include <QKeyEvent>
#include <QResizeEvent>
#include <QScrollBar>

GraphicsView::GraphicsView(QWidget *parent) : QGraphicsView(parent)
{
    setInteractive( false );
    setOptimizationFlag( QGraphicsView::DontSavePainterState );
    setOptimizationFlag( QGraphicsView::DontAdjustForAntialiasing );

    setViewportUpdateMode( QGraphicsView::FullViewportUpdate );

    setHorizontalScrollBarPolicy( Qt::ScrollBarAlwaysOn );
    setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOn );
}

GraphicsView::~GraphicsView()
{

}

void GraphicsView::keyReleaseEvent(QKeyEvent *event)
{
    if( event->key() == Qt::Key_Space)
    {
        emit nextPicture();
    }

    if( event->key() == Qt::Key_Backspace )
    {
        emit prevPicture();
    }
    if( event->key() == Qt::Key_Control )
    {
        emit zoomIn();
    }
}

void GraphicsView::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
    emit resized();
}

//void GraphicsView::mouse
