#include <engine/input.h>
#include <iostream>
Input::Input(){
    this->scrollup = false;
    this->scrolldown = false;
    this->mustq = false;
    for(unsigned int i = 0; i < 282; i++){
        keys[i] =  false;
        keysdown[i] = false;
        keysup[i] = false;

        keyalrdyup[i] = true;
        keyalrdydown[i] = false;

        if(i < 20){
                mousebutton[i] = false;
                mousebuttondown[i] = false;
                mousebuttonup[i] = false;

                mousebuttonalrdyup[i] = true;
                mousebuttonalrdydown[i] = false;
        }
    }
}

Vector2 Input::getMouseToScreen(){
    Vector2 mpos = Vector2((mousepos.x/window_width)*1280, (mousepos.y/window_height)*720);
    return mpos;
}

Vector2 Input::getMouseToWorld(Camera* camera){

    Vector2 mousepostocam = Vector2(getMouseToScreen().x + camera->position.x, getMouseToScreen().y + camera->position.y);
    return mousepostocam;
}

Input::~Input(){

}

void Input::update(){
    /* Our SDL event placeholder. */
    this->scrollup = false;
    this->scrolldown = false;
    int x,y;
    SDL_GetMouseState(&x, &y);
    mousepos = Vector2(x,y);

    SDL_Event event;
    for(unsigned int i = 0; i < 282; i++){
        if(keysup[i]){
            keysup[i] =  false;
        }
        if(keysdown[i]){
            keysdown[i] = false;
        }

        if(i < 20){
            if(mousebuttonup[i]){
                mousebuttonup[i] = false;
            }
            if(mousebuttondown[i]){
                mousebuttondown[i] = false;
            }
        }
    }
    /* Grab all the events off the queue. */
    while( SDL_PollEvent( &event ) ) {
        switch( event.type ) {
        case SDL_KEYDOWN:
            keyalrdyup[event.key.keysym.scancode] = false;

            if(keyalrdydown[event.key.keysym.scancode] == false){
                keysdown[event.key.keysym.scancode] = true;
                keyalrdydown[event.key.keysym.scancode] = true;
            }
            keys[event.key.keysym.scancode] = true;
        break;

        case SDL_KEYUP:
            keyalrdydown[event.key.keysym.scancode] = false;

            if(keyalrdyup[event.key.keysym.scancode] == false){
                keysup[event.key.keysym.scancode] = true;
                keyalrdyup[event.key.keysym.scancode] = true;
            }
            keys[event.key.keysym.scancode] = false;
        break;
        case SDL_QUIT:
                mustq = true;
        break;

        case SDL_MOUSEBUTTONDOWN:
            mousebuttonalrdyup[(int)event.button.button] = false;

            if(mousebuttonalrdydown[(int)event.button.button] == false){
                mousebuttondown[(int)event.button.button] = true;
                mousebuttonalrdydown[(int)event.button.button] = true;
            }
            mousebutton[(int)event.button.button] = true;
        break;

        case SDL_MOUSEBUTTONUP:
            mousebuttonalrdydown[(int)event.button.button] = false;

            if(mousebuttonalrdyup[(int)event.button.button] == false){
                mousebuttonup[(int)event.button.button] = true;
                mousebuttonalrdyup[(int)event.button.button] = true;
            }
            mousebutton[(int)event.button.button] = false;
        break;
        case SDL_MOUSEWHEEL:
            if (event.wheel.y < 0){
                this->scrolldown = true;
            }else{
                this->scrollup = true;
            }
        }
    }
}

bool Input::getKey(int keyCode){
    if(keys[SDL_GetScancodeFromKey(keyCode)]){
        return true;
    }
    return false;
}

bool Input::getKeyDown(int keyCode){
    if(keysdown[SDL_GetScancodeFromKey(keyCode)]){
        return true;
    }
    return false;
}

bool Input::getKeyUp(int keyCode){
    if(keysup[SDL_GetScancodeFromKey(keyCode)]){
        return true;
    }
    return false;
}

bool Input::getMouseButton(int number){
    if(mousebutton[number]){
        return true;
    }
    return false;
}

bool Input::getMouseButtonDown(int number){
    if(mousebuttondown[number]){
        return true;
    }
    return false;
}

bool Input::getMouseButtonUp(int number){
    if(mousebuttonup[number]){
        return true;
    }
    return false;
}
