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
    int volume;

    int channel;
    void play(bool loop);
    void setVolume(float value);
    void play();
    void stop();
    
private:
    static int channelCounter;

};



#endif
