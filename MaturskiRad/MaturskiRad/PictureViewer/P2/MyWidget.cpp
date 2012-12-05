#include "MyWidget.h"

#include <QPixmap>
#include <QDir>
#include <QPainter>
#include <QFileInfo>
#include <QDebug>
#include <QKeyEvent>
#include <QScrollArea>
#include <QFileDialog>


MyWidget::MyWidget(QString file, QScrollArea *par) : m_zoom( 100 ), m_angle(0), isThereSomethingToShow(false),
                                                     fitInScreen(false), parent(par), m_name(""), currentIndex(-1), m_size(0,0)
{
    dir = new QDir("");

    QStringList filter;
    filter << "*.jpg" << "*.jpeg" << "*.bmp" << "*.png" << "*.gif" ; //add more filters !!!

    dir->setNameFilters( filter );
    dir->setSorting( QDir::Name );

    currentPixmap = 0;
    nextPixmap = 0;
    previousPixmap = 0;

    setFocusPolicy( Qt::StrongFocus );

    setImage( file );
}

MyWidget::~MyWidget()
{
    delete dir;
    delete currentPixmap;
    delete nextPixmap;
    delete previousPixmap;
}

void MyWidget::setImage( QString fileName )
{
    //qDebug() << fileName;
    delete nextPixmap;
    delete previousPixmap;
    delete currentPixmap;
    nextPixmap = 0;
    previousPixmap = 0;
    currentPixmap = 0;

    dir->setPath( QFileInfo(fileName).absolutePath() );
    currentIndex = dir->entryInfoList().indexOf( QFileInfo(fileName)  );

    if( currentIndex > -1)
    {
        currentPixmap  = new QPixmap( dir->entryInfoList().at( currentIndex ).absoluteFilePath() );
        m_name = dir->entryInfoList().at( currentIndex ).fileName();
        m_size = currentPixmap->size();
        isThereSomethingToShow = true;

        adjustSize();
        emit imageChanged();
    }

    update();
}

void MyWidget::openImage()
{
    QString filter = "Images ( *.jpg *.jpeg *.bmp *.png *.gif )";
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), QDir::currentPath() , filter);
    if( fileName != "" ) setImage( fileName );
}

int MyWidget::getNumberOfImagesInFolder() const
{
    return dir->entryInfoList().count();
}

void MyWidget::paintEvent(QPaintEvent *e)
{
    if( isThereSomethingToShow )
    {
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);

        painter.rotate( m_angle );

        int width = 0;
        int height = 0;

        width  = ( m_zoom * currentPixmap->width()  ) / 100;
        height = ( m_zoom * currentPixmap->height() ) / 100;
        if( m_angle == 0 )
        {
            painter.drawPixmap( 0, 0, width, height, *currentPixmap );
        }
        else if ( m_angle == 90)
        {
            painter.drawPixmap( 0, -height, width, height, *currentPixmap);
        }
        else if ( m_angle == 180)
        {
            painter.drawPixmap( -width, -height, width, height, *currentPixmap);
        }
        else if ( m_angle == 270)
        {
            painter.drawPixmap( -width, 0, width, height, *currentPixmap);
        }
    }
    Q_UNUSED(e)
}

void MyWidget::keyPressEvent(QKeyEvent *e)
{
    switch(e->key())
    {
        case Qt::Key_Space:
            nextImage();
            break;

        case Qt::Key_Backspace:
            prevImage();
            break;

        case Qt::Key_Plus:
            setZoom( m_zoom + 10);
            break;

        case Qt::Key_Minus:
            setZoom( m_zoom - 10);
            break;

        case Qt::Key_Right:
            rotatePixmap( m_angle + 90);
            break;

        case Qt::Key_Left:
            rotatePixmap( m_angle - 90);
            break;

        default:
            QWidget::keyPressEvent(e);
            break;
    }
}

void MyWidget::setZoom(int value)
{
    m_zoom = value;
    if(m_zoom < 1) m_zoom = 1;
    if(m_zoom > 500) m_zoom = 500;

    emit zoomValueChanged(m_zoom);

    adjustSize();
}

void MyWidget::rotatePixmap(int value)
{
    m_angle = value;
    if(m_angle >= 360) m_angle = 0;
    if(m_angle <= -90) m_angle = 270;

    adjustSize();
}

void MyWidget::adjustSize()
{
    if( isThereSomethingToShow )
    {
        int w,h = 0;

        if( fitInScreen )
        {
            //qDebug() << "haha";
            QScrollArea* p = dynamic_cast<QScrollArea*>(parent);

            float w1 = p->size().width();
            float h1 = p->size().height();
            float w2 = currentPixmap->width();
            float h2 = currentPixmap->height();

            bool chooseHorizontalSide = ( w2 / w1 ) > ( h2 / h1 );

            if( chooseHorizontalSide )
                m_zoom = 100 * ( w1 / w2 )  - 1 ;
            else
                m_zoom = 100 * ( h1 / h2 )  - 1 ;

            emit zoomValueChanged(m_zoom);
        }

        if( (m_angle/90)%2 == 0 )
        {
            w  = ( m_zoom * currentPixmap->width()  ) / 100;
            h = ( m_zoom * currentPixmap->height() ) / 100;
        }
        else
        {
            w  = ( m_zoom * currentPixmap->height() ) / 100;
            h = ( m_zoom * currentPixmap->width()  ) / 100;
        }

        resize( w, h );
    }
}

void MyWidget::nextImage()
{
    if( isThereSomethingToShow)
    {
        currentIndex = (currentIndex + 1) % dir->entryInfoList().count();
        if( nextPixmap == 0) nextPixmap = new QPixmap( dir->entryInfoList().at( currentIndex ).absoluteFilePath());

        delete previousPixmap;
        previousPixmap = currentPixmap;

        currentPixmap = nextPixmap;
        rotatePixmap(0);

        m_name = dir->entryInfoList().at( currentIndex ).fileName();
        m_size = currentPixmap->size();

        emit imageChanged();
        update();

        int picIndex = (currentIndex + 1) % dir->entryInfoList().count();
        nextPixmap = new QPixmap( dir->entryInfoList().at( picIndex ).absoluteFilePath() );


    }
}

void MyWidget::prevImage()
{
    if( isThereSomethingToShow)
    {
        currentIndex = (currentIndex - 1 + dir->entryInfoList().count() ) % dir->entryInfoList().count();
        if( previousPixmap == 0) previousPixmap = new QPixmap( dir->entryInfoList().at( currentIndex ).absoluteFilePath());

        delete nextPixmap;
        nextPixmap = currentPixmap;

        currentPixmap = previousPixmap;

        rotatePixmap(0);

        m_name = dir->entryInfoList().at( currentIndex ).fileName();
        m_size = currentPixmap->size();

        emit imageChanged();
        update();

        int picIndex = ( currentIndex - 1 + dir->entryInfoList().count() ) % dir->entryInfoList().count();
        previousPixmap = new QPixmap( dir->entryInfoList().at( picIndex ).absoluteFilePath() );
    }
}

void MyWidget::rotatePixmapLeft()
{
    rotatePixmap( m_angle - 90 );
}

void MyWidget::rotatePixmapRight()
{
    rotatePixmap( m_angle + 90 );
}

void MyWidget::fitInView(bool value)
{
    fitInScreen = value;
    if(value)
    {
        QScrollArea* p = dynamic_cast<QScrollArea*>(parent);
        p->setHorizontalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
        p->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
        emit setZoomSlider(false);
    }
    else
    {
        QScrollArea* p = dynamic_cast<QScrollArea*>(parent);
        p->setHorizontalScrollBarPolicy( Qt::ScrollBarAlwaysOn );
        p->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOn );
        emit setZoomSlider(true);
    }
    adjustSize();
}





