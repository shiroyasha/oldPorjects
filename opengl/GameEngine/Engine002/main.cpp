#include <MyGame.h>

int main(int argc, char *argv[])
{
    MyGame game;

    game.init(1680, 1050, false);

    game.initData();

    game.start();

    return 0;
}



