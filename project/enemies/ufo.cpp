#include "ufo.h"

Ufo::Ufo() : Enemy(){
    this->setPng("assets/enemies/ufo.png");
    spriteTimer = 0;
    this->health = 20;
}

Ufo::~Ufo(){

}

void Ufo::update(float deltaTime){
    spriteTimer += deltaTime;
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

    if(spriteTimer >= 0.35f){
        spriteTimer = 0;
    }
    handleMovement(deltaTime);
}
