#include <MyGame.h>

int main(int argc, char *argv[])
{
    MyGame game;

    game.makeScreen(800, 600, false);

    game.setBackgroundColor( 1.0f, 1.0f, 1.0f, 1.0f);

    game.start();

    return 0;
}
