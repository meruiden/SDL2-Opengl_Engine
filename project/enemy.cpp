#include "enemy.h"
#include <iostream>
Enemy::Enemy() : Entity(){
    this->atTarget = true;
    this->curtarget = Vector2();
    this->currPathPoint = 0;
    this->collisionRadius = 20.0f;
    this->dead = false;
    this->scale = Vector2(0.5f, 0.5f);
    this->setPng("assets/cloud.png");
}

Enemy::~Enemy(){

}

void Enemy::update(float deltaTime){
    Vector2 dir = Vector2(this->curtarget, this->position);
    if(dir.magnitude() < 10){
        atTarget = true;
    }
    dir.normalize();
    this->position += dir*deltaTime;
}
