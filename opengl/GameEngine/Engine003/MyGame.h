#ifndef MYGAME_H
#define MYGAME_H

#include <Engine.h>
#include <SDL/SDL_opengl.h>

#include <Animation.h>
#include <Texture.h>

class MyGame : public Engine
{
public:
    MyGame();
    virtual ~MyGame();

    virtual void init();

    virtual void onMouseDown(MouseButtonEvent *e);
    virtual void onKeyDown(KeyEvent *e);
    virtual void onKeyUp(KeyEvent *e);

    virtual void render();
    virtual void think();

private:

    Animation anim1;
    Animation anim2;
    Texture*  texture1;
    Texture*  texture2;

    float m_acceleration;
    float m_speed;
    float m_position;

    bool m_direction;

    int speed;
    int pos;
};

#endif // MYGAME_H
