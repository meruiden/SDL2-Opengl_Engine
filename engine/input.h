#ifndef INPUT_H
#define INPUT_H

#include <SDL.h>

#include <engine/vector2.h>
#include <engine/camera.h>
class Input{
public:
    Input();
    virtual ~Input();

    void update();
    bool getKey(int keyCode);
    bool getKeyUp(int keyCode);
    bool getKeyDown(int keyCode);

    bool getMouseButton(int number);
    bool getMouseButtonDown(int number);
    bool getMouseButtonUp(int number);

    Vector2 getMouseToScreen();

    Vector2 getMouseToWorld(Camera* camera);

    bool mustQuit(){return mustq;};

    bool scrollUp(){return scrollup;}
    bool scrollDown(){return scrolldown;}

    int window_width;
    int window_height;

private:
    bool keys[282];
    bool keysdown[282];
    bool keysup[282];

    bool keyalrdyup[282];
    bool keyalrdydown[282];
    bool mustq;

    bool mousebutton[20];
    bool mousebuttondown[20];
    bool mousebuttonup[20];

    bool mousebuttonalrdydown[20];
    bool mousebuttonalrdyup[20];

    bool scrollup;
    bool scrolldown;
    Vector2 mousepos;
};



#endif
