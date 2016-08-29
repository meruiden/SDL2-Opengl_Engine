#include "trol.h"

Trol::Trol() : Enemy(){
    this->setPng("assets/enemies/troll/trol1.png");
    this->spriteTimer = 0;
    this->curSprite = 1;

}

Trol::~Trol(){

}

void Trol::update(float deltaTime){
    spriteTimer += deltaTime;

    if(!this->dead){
        if(spriteTimer >= 1.0f/30){
            if(curSprite > 16){
                curSprite = 1;
            }
            std::ostringstream p;
            p << "assets/enemies/troll/trol";
            p << curSprite;
            p << ".png";
            this->setPng(p.str());
            curSprite ++;
            spriteTimer = 0;
        }
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

    if(spriteTimer >= 0.35f && this->dead){
        spriteTimer = 0;
    }

    handleMovement(deltaTime);
}
