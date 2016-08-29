#include "duck.h"

Duck::Duck() : Enemy(){
    this->setPng("assets/enemies/Devilduck.png");
}

Duck::~Duck(){

}

void Duck::update(float deltaTime){
    spriteTimer += deltaTime;

    if(spriteTimer <= 0.3f && !this->dead){
        this->setPng("assets/enemies/devil_duck_walk1.png");

    }else if(spriteTimer > 0.3f&& !this->dead){
        this->setPng("assets/enemies/devil_duck_walk2.png");
    }

    if(spriteTimer <= 0.1f && this->dead){
        this->setPng("assets/sheep/Loop0001.png");
    }else if(spriteTimer <= 0.15f&& this->dead){
        this->setPng("assets/sheep/Loop0002.png");
    }else if(spriteTimer <= 0.2f&& this->dead){
        this->setPng("assets/sheep/Loop0003.png");
    }else if(spriteTimer <= 0.25f&& this->dead){
        this->setPng("assets/sheep/Loop0004.png");
    }else if(spriteTimer <= 0.3f&& this->dead){
        this->setPng("assets/sheep/Loop0005.png");
    }
    if(!this->dead){
        if(spriteTimer >= 0.6f){
            spriteTimer = 0;
        }
    }else{
        if(spriteTimer >= 0.35f){
            spriteTimer = 0;
        }
    }
    handleMovement(deltaTime);
}
