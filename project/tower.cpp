#include "tower.h"
#include <iostream>
Tower::Tower() : Entity(){
    this->setPng("assets/hondje_top_down.png");
    this->target = NULL;
    this->scale = Vector2(0.5f, 0.5f);
    this->shootcounter = 0;
    this->wantsToShoot = false;
    this->ready = false;
    this->color.a = 100;

}

Tower::~Tower(){

}

void Tower::update(float deltaTime){
    if(this->ready && this->target != NULL){
        this->shootcounter += deltaTime;
        float _rotateSpeedMax = 200.0f;
        float _trueRotation = 0.0f;

        Vector2 disvec = Vector2(this->position, target->position);
        float rotateTo = 0.0f;

        if(target != NULL && !target->dead){
            if( Vector2(target->position, this->position).magnitude() < 360 ){
                rotateTo = atan2(disvec.y, disvec.x)*RAD_TO_DEG;
                rotateTo += 90;
                if(this->shootcounter >= 2.0f && disvec.magnitude() < 360){
                    this->wantsToShoot = true;
                }
            }
        }
        if (rotateTo > this->rotation + 180) rotateTo -= 360;
        if (rotateTo < this->rotation  - 180) rotateTo += 360;
        _trueRotation = (rotateTo - this->rotation ) / _rotateSpeedMax;
        this->rotation += _trueRotation;
    }
}

Bullet* Tower::shoot(){
    Bullet* b;
    b = new Bullet();
    b->position = this->position;
    b->target = this->target;
    b->lastKnownPos = this->target->position;
    b->scale = Vector2(0.2f, 0.2f);
    b->setPng("assets/projectiel.png");
    return b;
}
