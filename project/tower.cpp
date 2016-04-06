#include "tower.h"
#include <iostream>
Tower::Tower() : Entity(){
    this->shootingRange = 100;
    this->target = NULL;
    this->slowingDamage = 0;
    this->shootcounter = 0;
    this->wantsToShoot = false;
    this->ready = false;
    this->color.a = 100;
    this->damage = 0;
    this->level = 0;
    this->shootingRangeShape = new Shape();
    this->shootingRangeShape->circle(shootingRange);
    this->shootingRangeShape->color = Color(252, 61, 61, 100);
    this->shootDelay = 1.0f;
    this->upgradePrice = 10;
}

Tower::~Tower(){
    delete this->shootingRangeShape;
}

void Tower::update(float deltaTime){
    handleTarget(deltaTime);
}

void Tower::handleTarget(float deltaTime){
    this->shootingRangeShape->position = this->position;
    if(this->ready && this->target != NULL){
        if(target->dead){
            this->target = NULL;
        }
    }
    float rotateTo = 0.0f;
    float _rotateSpeedMax = 200.0f;
    float _trueRotation = 0.0f;
    if(this->ready && this->target != NULL){

        this->shootcounter += deltaTime;


        Vector2 disvec = Vector2(this->position, target->position);



        if(target != NULL && !target->dead){
            if( disvec.magnitude() < (this->shootingRange + target->collisionRadius) ){
                rotateTo = atan2(disvec.y, disvec.x)*RAD_TO_DEG;
                rotateTo += 90;
                if(this->shootcounter >= this->shootDelay){
                    this->wantsToShoot = true;
                }
            }else{
                this->target = NULL;
            }

        }

    }

    if (rotateTo > this->rotation + 180) rotateTo -= 360;
    if (rotateTo < this->rotation  - 180) rotateTo += 360;
    _trueRotation = (rotateTo - this->rotation ) / _rotateSpeedMax;
    _trueRotation *= 300;
    this->rotation += _trueRotation*deltaTime;
}

void Tower::upgrade(){
    this->level ++;
    this->shootingRange += 5*this->level;
    this->shootingRangeShape->circle(shootingRange);

    this->upgradePrice += 15*this->level;
    if(this->level == 5){
        this->upgradePrice = 0;
    }
    if(this->damage > 0)
    this->damage += 3*this->level;
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
