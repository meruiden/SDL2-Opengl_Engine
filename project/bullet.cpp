#include "bullet.h"
#include <iostream>
Bullet::Bullet() : Entity(){
    //this->scale = Vector2(0.3f, 0.3f);
    this->speed = 400.0f;
    this->disToTarget = 1000.0f;
}

Bullet::~Bullet(){
    
}

void Bullet::update(float deltaTime){
    Vector2 subvec = Vector2(this->position, target->position);
    this->disToTarget = subvec.magnitude();
    this->rotation = atan2(subvec.y, subvec.x)+3.14f;
    this->vel = Vector2(cos(this->rotation), sin(this->rotation));
    this->vel.normalize();
    this->vel *= this->speed;
    this->position += vel*deltaTime;
}
