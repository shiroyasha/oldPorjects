#include <QApplication>
#include <QDeclarativeView>
#include <QDeclarativeEngine>

int main(int argc, char *argv[])
{
    QApplication::setGraphicsSystem("raster");
    QApplication app(argc, argv);

    QDeclarativeView view;
    view.setSource(QUrl("/media/files/Codes/qml/proba/p1/p1.qml"));
    view.setResizeMode(QDeclarativeView::SizeRootObjectToView);

    view.setAttribute(Qt::WA_OpaquePaintEvent);

    view.setAttribute(Qt::WA_NoSystemBackground);


    //view.setCacheMode(QGraphicsView::CacheBackground);
    view.setOptimizationFlag(QGraphicsView::DontSavePainterState, true);
    view.setOptimizationFlag(QGraphicsView::DontAdjustForAntialiasing, true);
    view.setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);

    view.setRenderHint(QPainter::Antialiasing , true);
    view.setRenderHint(QPainter::SmoothPixmapTransform , true);



    view.setFocus();

    //QObject::connect((QObject*)view.engine(), SIGNAL(quit()), &app, SLOT(quit()));

    view.show();


    return app.exec();
}
