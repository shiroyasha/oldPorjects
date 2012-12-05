#include <QX11EmbedWidget>
#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    if (app.arguments().count() != 2) {
        qFatal("Error - expected window id as argument");
        return 1;
    }

    QString windowId(app.arguments()[1]);
    QX11EmbedWidget window;
    window.embedInto(windowId.toULong());
    window.show();

    QPushButton b(&window);
    b.show();

    return app.exec();
}
