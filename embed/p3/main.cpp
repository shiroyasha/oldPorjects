#include <QX11EmbedWidget>
#include <QApplication>
#include <QPushButton>

#include <MPlayerProcess.h>

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

    MPlayerProcess proc(&window);

    proc.openStream("/media/files/Movies/OnePiece/One Piece - 344.flv");

    return app.exec();
}
