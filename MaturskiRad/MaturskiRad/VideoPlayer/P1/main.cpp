#include <phonon>
#include <QApplication>
#include <QObject>

using namespace Phonon;
int main( int argc, char**argv)
{
    QApplication a( argc, argv);

    Phonon::VideoWidget *w = new Phonon::VideoWidget();
    w->setGeometry( 0,0, 1000, 1000);
    VideoPlayer *player = new VideoPlayer(Phonon::VideoCategory, w);
    QObject::connect(player, SIGNAL(finished()), player, SLOT(deleteLater()));


    player->play( Phonon::MediaSource("/tmp/Flash1iOif9") );
    player->setGeometry( 0,0,1000,1000);
    w->show();

    return a.exec();
}
