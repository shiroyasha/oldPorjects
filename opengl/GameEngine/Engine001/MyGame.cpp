#include <MyGame.h>
#include <iostream>

#include <lib/SFPSControler.h>
#include <lib/SEntity.h>

MyGame::MyGame()
{
    message = NULL;
    background = NULL;

    m_acceleration = 0;
    m_speed        = 0;
    m_position     = 0;
}

MyGame::~MyGame()
{
    SDL_FreeSurface(message);
    SDL_FreeSurface(background);
}

void MyGame::initData()
{
    SEntity* player = new SEntity;
    player->init();
    SEntity::entityList.push_back(player);
}

void MyGame::OnMouseDown(SMouseButtonEvent *e)
{
}

void MyGame::OnKeyDown(SKeyEvent *e)
{
    if( e->sym == SDLK_LEFT )
    {
        m_acceleration = -0.1;
    }
    if( e->sym == SDLK_RIGHT)
    {
        m_acceleration = 0.1;
    }
}

void MyGame::OnKeyUp(SKeyEvent *e)
{
    if( e->sym == SDLK_LEFT )
    {
        m_speed = 0;
        m_acceleration = 0;
    }
    if( e->sym == SDLK_RIGHT)
    {
        m_speed = 0;
        m_acceleration = 0;
    }
    if( e->sym == SDLK_ESCAPE )
    {
        ShutdownEngine();
    }
}

void MyGame::think()
{
    m_speed += m_acceleration * SFPS::SFPSControler.getSpeedFactor();

    //std::cout << "m_speed " << m_speed << std::endl;

    if( m_speed > 15.0 ) m_speed = 15.0;
    if( m_speed < -15.0 ) m_speed = -15.0;

    m_position += m_speed;

    if( m_position < 0.0) m_position = 0.0;
    if( m_position > 1000.0) m_position = 1000.0;
}

void MyGame::render()
{
    int size = SEntity::entityList.size();
    for( int i = 0; i < size ; ++i)
    {
        SEntity::entityList[i]->draw();
    }
}
