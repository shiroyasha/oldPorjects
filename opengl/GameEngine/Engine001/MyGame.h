#ifndef MYGAME_H
#define MYGAME_H

#include <lib/SEngine.h>
#include <SDL/SDL_opengl.h>

class MyGame : public SEngine
{
public:
    MyGame();
    virtual ~MyGame();

    void initData();

    virtual void OnMouseDown(SMouseButtonEvent *e);
    virtual void OnKeyDown(SKeyEvent *e);
    virtual void OnKeyUp(SKeyEvent *e);

    virtual void render();
    virtual void think();

private:
    SDL_Surface *message;
    SDL_Surface *background;

    GLuint texture;
    GLenum texture_format;
    GLint  nOfColors;

    float m_acceleration;
    float m_speed;
    float m_position;
};

#endif // MYGAME_H
