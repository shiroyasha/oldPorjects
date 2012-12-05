#include <MyGame.h>
#include <iostream>

MyGame::MyGame()
{
    m_acceleration = 0;
    m_speed        = 0;
    m_position     = 0;
}

MyGame::~MyGame()
{
    delete texture1;
    delete texture2;
}

void MyGame::init()
{
    texture1 = new Texture("/media/files/Codes/GameDev/stickman/sasuke002.png");

    anim1.pushTextureSection( texture1->createSection( 0.00/6.00, 0.00, 1.00/6.00, 1.00) );
    anim1.pushTextureSection( texture1->createSection( 1.00/6.00, 0.00, 2.00/6.00, 1.00) );
    anim1.pushTextureSection( texture1->createSection( 2.00/6.00, 0.00, 3.00/6.00, 1.00) );
    anim1.pushTextureSection( texture1->createSection( 3.00/6.00, 0.00, 4.00/6.00, 1.00) );
    anim1.pushTextureSection( texture1->createSection( 4.00/6.00, 0.00, 5.00/6.00, 1.00) );
    anim1.pushTextureSection( texture1->createSection( 5.00/6.00, 0.00, 6.00/6.00, 1.00) );

    //anim1.resume();
    //anim1.setLoop(true);
    anim1.setDelays( 30 );

    texture2 = new Texture("/media/files/Codes/GameDev/stickman/sasuke_run001.png");

    anim2.pushTextureSection( texture2->createSection( 0.00/6.00, 0.00, 1.00/6.00, 1.00) );
    anim2.pushTextureSection( texture2->createSection( 1.00/6.00, 0.00, 2.00/6.00, 1.00) );
    anim2.pushTextureSection( texture2->createSection( 2.00/6.00, 0.00, 3.00/6.00, 1.00) );
    anim2.pushTextureSection( texture2->createSection( 3.00/6.00, 0.00, 4.00/6.00, 1.00) );
    anim2.pushTextureSection( texture2->createSection( 4.00/6.00, 0.00, 5.00/6.00, 1.00) );
    anim2.pushTextureSection( texture2->createSection( 5.00/6.00, 0.00, 6.00/6.00, 1.00) );

    anim2.resume();
    anim2.setLoop(true);
    anim2.setDelays( 75 );
}

void MyGame::onMouseDown(MouseButtonEvent *e)
{

}

void MyGame::onKeyDown(KeyEvent *e)
{
    if( e->button == SDLK_KP1 )
    {
        anim1.resume();
        anim1.jumpToFrame(0);
        anim1.setLoop(0);


        std::cout << "udarac" << std::endl;
    }
    else if( e->button == SDLK_LEFT )
    {
        m_direction = true;

        m_speed = -2;
    }
    else if( e->button == SDLK_RIGHT )
    {
        m_direction = false;

        m_speed = 2;
    }
}

void MyGame::onKeyUp(KeyEvent *e)
{
    if( e->button == SDLK_ESCAPE )
    {
        shutdownEngine();
    }
}

void MyGame::think()
{
    anim2.update();

    m_position += m_speed;
}

void MyGame::render()
{
    if( !m_direction )
    {
        anim2.draw(m_position , 552, m_position + 256.0/6.0, 600);
    }
    else
    {
        anim2.draw(m_position + 256.0/6.0, 552, m_position , 600 );
    }
    //anim1.draw(100, 100, 400, 100 + 1969 / 6 );
}
