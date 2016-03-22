#include "tower.h"
#include <iostream>
Tower::Tower() : Entity(){
    this->shootingRange = 100;
    this->target = NULL;

    this->shootcounter = 0;
    this->wantsToShoot = false;
    this->ready = false;
    this->color.a = 100;
    this->damage = 0;

    this->shootingRangeShape = new Shape();
    this->shootingRangeShape->circle(shootingRange);
    this->shootingRangeShape->color = Color(252, 61, 61, 100);
}

Tower::~Tower(){
    delete this->shootingRangeShape;
}

void Tower::update(float deltaTime){

    if(this->ready && this->target != NULL){
        if(target->dead){
            this->target = NULL;
        }
    }

    if(this->ready && this->target != NULL){
        this->shootcounter += deltaTime;
        float _rotateSpeedMax = 200.0f;
        float _trueRotation = 0.0f;

        Vector2 disvec = Vector2(this->position, target->position);
        float rotateTo = 0.0f;

        if(target != NULL && !target->dead){
            if( disvec.magnitude() < (this->shootingRange + target->collisionRadius) ){
                rotateTo = atan2(disvec.y, disvec.x)*RAD_TO_DEG;
                rotateTo += 90;
                if(this->shootcounter >= 1.0f && disvec.magnitude() < (this->shootingRange + target->collisionRadius)){
                    this->wantsToShoot = true;
                }
            }else{
                this->target = NULL;
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
    b->damage = this->damage;

    return b;
}
