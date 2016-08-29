#include "bullet.h"
#include <iostream>
Bullet::Bullet() : Entity(){
    //this->scale = Vector2(0.3f, 0.3f);
    this->speed = 500.0f;
    this->disToTarget = 1000.0f;
    this->target = NULL;
    this->hasTarget = false;
    this->destroyMe = false;
    this->damage = 0;
    this->wantsTwinkle = false;
    this->twinkleCounter = 0.0f;
    this->slowingDamage = 0;
    this->explodeSound = NULL;
    this->bulletRotate = true;
}

Bullet::~Bullet(){
    this->explodeSound = NULL;
}

void Bullet::update(float deltaTime){
    handleTarget(deltaTime);
}

void Bullet::handleTarget(float deltaTime){
    if(this->hasTarget){
        Vector2 subvec = Vector2(this->position, target->position);
        this->disToTarget = subvec.magnitude();
        float rot = atan2(subvec.y, subvec.x)+3.14f;
        if(bulletRotate){
            this->rotation = (rot*RAD_TO_DEG)+90;
        }
        this->vel = Vector2(cos(rot), sin(rot));
        this->vel.normalize();
        this->vel *= this->speed;
        this->position += vel*deltaTime;
        this->lastKnownPos = this->target->position;
    }else{
        Vector2 subvec = Vector2(this->position, lastKnownPos);
        this->disToTarget = subvec.magnitude();
        float rot = atan2(subvec.y, subvec.x)+3.14f;
        if(bulletRotate){
            this->rotation = (rot*RAD_TO_DEG)+90;
        }
        this->vel = Vector2(cos(rot), sin(rot));
        this->vel.normalize();
        this->vel *= this->speed;
        this->position += vel*deltaTime;
    }
}
