#include <engine/sound.h>

Sound::Sound(const char * filepath){
    this->sound = Mix_LoadWAV(filepath);
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

    Mix_PlayChannel(-1, sound, loopornot);
}
