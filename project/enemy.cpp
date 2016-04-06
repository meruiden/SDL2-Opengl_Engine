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
    spriteTimer += deltaTime;
    if(spriteTimer <= 0.3f && !this->dead){
        this->setPng("assets/devil_duck_walk1.png");

    }else if(spriteTimer > 0.3f&& !this->dead){
        this->setPng("assets/devil_duck_walk2.png");
    }

    if(spriteTimer <= 0.1f && this->dead){
        this->setPng("assets/sheep/Loop0001.png");
    }else if(spriteTimer <= 0.15f&& this->dead){
        this->setPng("assets/sheep/Loop0002.png");
    }else if(spriteTimer <= 0.2f&& this->dead){
        this->setPng("assets/sheep/Loop0003.png");
    }else if(spriteTimer <= 0.25f&& this->dead){
        this->setPng("assets/sheep/Loop0004.png");
    }else if(spriteTimer <= 0.3f&& this->dead){
        this->setPng("assets/sheep/Loop0005.png");
    }
    if(!this->dead){
        if(spriteTimer >= 0.6f){
            spriteTimer = 0;
        }
    }else{
        if(spriteTimer >= 0.35f){
            spriteTimer = 0;
        }
    }

    Vector2 dir = Vector2(this->curtarget, this->position);
    speed += deltaTime;

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
