#ifndef SOUND_H
#define SOUND_H


#include <SDL_mixer.h>
#include <string>
#include <iostream>
class Sound{
public:
    Sound(const char * filepath);
    virtual ~Sound();

    Mix_Chunk *sound;

    void play(bool loop);
    void play();
private:

};



#endif
