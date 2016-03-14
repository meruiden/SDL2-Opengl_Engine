#include "enemy.h"
#include <iostream>
Enemy::Enemy() : Entity(){
    this->atTarget = false;
    this->curtarget = Vector2();
    this->currPathPoint = 0;
    this->collisionRadius = 20.0f;
    this->dead = false;
    this->scale = Vector2(0.4f, 0.4f);
    this->setPng("assets/Devilduck.png");
}

Enemy::~Enemy(){

}

void Enemy::update(float deltaTime){
    Vector2 dir = Vector2(this->curtarget, this->position);

    float _rotateSpeedMax = 100;
    float _trueRotation = 0.0f;
    float rotateTo = 0.0f;

    rotateTo = atan2(dir.y, dir.x)*RAD_TO_DEG;

    if (rotateTo > (this->rotation+90) + 180) rotateTo -= 360;
    if (rotateTo < (this->rotation+90)  - 180) rotateTo += 360;

    _trueRotation = (rotateTo - (this->rotation+90 )) / _rotateSpeedMax;

    this->rotation += _trueRotation;

    if(dir.magnitude() < 10){
        atTarget = true;
    }
    dir.normalize();

    float rads = (dir.getAngle()) * DEG_TO_RAD;
    this->position += (Vector2(cos(rads), sin(rads))*150)*deltaTime;
}
