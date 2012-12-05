#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QGraphicsView>

class QKeyEvent;
class QResizeEvent;

class GraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    GraphicsView( QWidget *parent = 0 );
    ~GraphicsView();

    void keyReleaseEvent(QKeyEvent *event);

    void resizeEvent(QResizeEvent *event);
public slots:

signals:
    void nextPicture();
    void prevPicture();
    void zoomIn();
    void zoomOut();
    void resized();

private:

};

#endif // GRAPHICSVIEW_H
