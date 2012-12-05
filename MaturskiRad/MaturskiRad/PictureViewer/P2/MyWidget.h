#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

class QPixmap;
class QDir;
class QScrollArea;

class MyWidget : public QWidget
{
    Q_OBJECT
public:
    MyWidget( QString file, QScrollArea *parent = 0 );
    ~MyWidget();

    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *);

    QString getImageName() const { return m_name; }
    QSize getImageSize() const { return m_size; }
    int getImageIndex() const { return currentIndex; }
    int getNumberOfImagesInFolder() const;

public slots:
    void rotatePixmap( int angle );
    void nextImage();
    void prevImage();
    void adjustSize();
    void setZoom(int);
    void rotatePixmapLeft();
    void rotatePixmapRight();
    void fitInView(bool);
    void openImage();

protected:
    void setImage(QString);

signals:
    void resized();
    void zoomValueChanged(int);
    void imageChanged();
    void setZoomSlider(bool);

private:
    QPixmap         *previousPixmap;
    QPixmap         *nextPixmap;
    QPixmap         *currentPixmap;

    QDir            *dir;
    int             currentIndex;
    int             m_zoom;
    int             m_angle;
    bool            isThereSomethingToShow;
    bool            fitInScreen;
    QScrollArea*    parent;

    QString         m_name;
    QSize           m_size;
};

#endif // MYWIDGET_H
