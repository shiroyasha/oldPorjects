#include <QX11EmbedContainer>
#include <QProcess>
#include <QApplication>
#include <QGraphicsProxyWidget>
#include <QGraphicsView>
#include <QGraphicsScene>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    if (app.arguments().count() < 2) {
        qFatal("Error - expected executable path as argument");
        return 1;
    }

    QX11EmbedContainer container;
    container.setGeometry( container.x(), container.y(), 600, 600);
    container.show();


    QGraphicsScene scene;
    QGraphicsProxyWidget *proxy = scene.addWidget(&container);

    QGraphicsView view(&scene);
    view.setGeometry(50,50, 1000,800);
    view.show();




    QProcess process(&container);
    QString executable(app.arguments()[1]);
    QStringList arguments;
    arguments << QString::number(container.winId());
    process.start(executable, arguments);

    int status = app.exec();
    process.close();
    return status;
}
