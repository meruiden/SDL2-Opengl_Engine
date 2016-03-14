#include <engine/sound.h>

Sound::Sound(const char * filepath){
    this->channel= -10;
    this->sound = Mix_LoadWAV(filepath);
    this->volume = 100;
    if(sound == NULL){
        std::cout << "Failed to load sound!!!" << std::endl;
        return;
    }

}

Sound::~Sound(){
    Mix_FreeChunk(sound);
}

void Sound::play(){
    this->play(false);
}
void Sound::play( bool loop = false){
    int loopornot = 0;

    if(loop){
        loopornot = -1;
    }else{
        loopornot = 0;
    }
    float v = 128.0f/100;
    v *= this->volume;
    this->channel = Mix_PlayChannel(-1, sound, loopornot);
    Mix_Volume(this->channel, (int)v);

}

void Sound::setVolume(float value){
    float v = 128.0f/100;
    v *= value;
    this->volume = value;
    if(this->channel != 10){
        Mix_Volume(this->channel, (int)v);
    }

}
