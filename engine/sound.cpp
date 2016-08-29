#include <engine/sound.h>
int Sound::channelCounter = 1;
Sound::Sound(const char * filepath){
    this->channel= channelCounter;
    Sound::channelCounter ++;
    if(this->channel > 70){
        Mix_AllocateChannels(this->channel);
    }
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
    Mix_PlayChannel(this->channel, sound, loopornot);
    Mix_Volume(this->channel, (int)v);

}

void Sound::setVolume(float value){
    float v = 128.0f/100;
    v *= value;
    this->volume = value;
    Mix_Volume(this->channel, (int)v);

}

void Sound::stop(){
    Mix_HaltChannel(this->channel);
}
