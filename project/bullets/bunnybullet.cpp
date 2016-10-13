#include "bunnybullet.h"

BunnyBullet::BunnyBullet() : Bullet(){
    this->setPng("assets/bullets/regenboog_projectiel.png");
    this->bulletRotate = false;
}

BunnyBullet::~BunnyBullet(){

}

void BunnyBullet::update(float deltaTime){
    handleTarget(deltaTime);
    if(this->twinkleCounter >= 0.01f){
        this->wantsTwinkle = true;
        this->twinkleCounter = 0.0f;
    }
    this->rotation += 1200*deltaTime;
    this->twinkleCounter += deltaTime;
}
