#include "bullet.h"
#include <iostream>
Bullet::Bullet(int bt) : Entity(){
    //this->scale = Vector2(0.3f, 0.3f);
    this->speed = 500.0f;
    this->disToTarget = 1000.0f;
    this->target = NULL;
    this->hasTarget = false;
    this->destroyMe = false;
    this->damage = 0;
    this->bulletType = bt;
    this->wantsTwinkle = false;
    this->twinkleCounter = 0.0f;
    switch (this->bulletType) {
        case 1:
            this->setPng("assets/Projectiel.png");
        break;

        case 2:
            this->setPng("assets/regenboog_projectiel.png");
        break;
    }
}

Bullet::~Bullet(){

}

void Bullet::update(float deltaTime){
    if(this->hasTarget){
        Vector2 subvec = Vector2(this->position, target->position);
        this->disToTarget = subvec.magnitude();
        float rot = atan2(subvec.y, subvec.x)+3.14f;
        this->vel = Vector2(cos(rot), sin(rot));
        this->vel.normalize();
        this->vel *= this->speed;
        this->position += vel*deltaTime;
        this->lastKnownPos = this->target->position;
    }else{
        Vector2 subvec = Vector2(this->position, lastKnownPos);
        this->disToTarget = subvec.magnitude();
        float rot = atan2(subvec.y, subvec.x)+3.14f;
        this->vel = Vector2(cos(rot), sin(rot));
        this->vel.normalize();
        this->vel *= this->speed;
        this->position += vel*deltaTime;
    }

    if(this->bulletType == 2){
        if(this->twinkleCounter >= 0.01f){
            this->wantsTwinkle = true;
            this->twinkleCounter = 0.0f;


        }
        this->rotation += 1200*deltaTime;
        this->twinkleCounter += deltaTime;
    }
}
