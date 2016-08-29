#include "enemy.h"
#include <iostream>
Enemy::Enemy() : Entity(){
    this->atTarget = false;
    this->curtarget = Vector2();
    this->currPathPoint = 0;
    this->collisionRadius = 30.0f;
    this->dead = false;
    this->scale = Vector2(0.3f, 0.3f);
    this->setPng("assets/Devilduck.png");
    speed = 40.0f;
    this->spriteTimer = 0;
    this->health = 100;
    this->slowness = 0;

}

Enemy::~Enemy(){

}

void Enemy::update(float deltaTime){

    handleMovement(deltaTime);

}

void Enemy::handleMovement(float deltaTime){
    Vector2 dir = Vector2(this->curtarget, this->position);


    float _rotateSpeedMax = 100;
    float _trueRotation = 0.0f;
    float rotateTo = 0.0f;
    if(speed > 400){
        speed = 400;
    }
    rotateTo = atan2(dir.y, dir.x)*RAD_TO_DEG;

    if (rotateTo > (this->rotation+90) + 180) rotateTo -= 360;
    if (rotateTo < (this->rotation+90)  - 180) rotateTo += 360;

    _trueRotation = (rotateTo - (this->rotation+90 )) / _rotateSpeedMax;
    _trueRotation*= 600;
    this->rotation += _trueRotation*deltaTime;

    if(dir.magnitude() < 10){
        atTarget = true;
    }
    dir.normalize();
    if(slowness < 0){
        slowness = 0;
    }

    slowness -= deltaTime*5;

    if(slowness > 70){
        slowness = 70;
    }
    float rads = (dir.getAngle()) * DEG_TO_RAD;
    this->position += (Vector2(cos(rads), sin(rads))*((speed/100)*(100-slowness)))*deltaTime;
}
