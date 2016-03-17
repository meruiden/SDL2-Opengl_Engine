#include "tower.h"
#include <iostream>
Tower::Tower(int tt) : Entity(){

    this->target = NULL;

    this->shootcounter = 0;
    this->wantsToShoot = false;
    this->ready = false;
    this->color.a = 100;
    this->towerType = tt;
    this->damage = 0;
    switch (this->towerType) {
        case 1:
            this->setPng("assets/hondje_top_down.png");
            this->scale = Vector2(0.5f, 0.5f);
        break;

        case 2:
            this->setPng("assets/bunny.png");
            this->scale = Vector2(0.4f, 0.4f);

        break;
    }
}

Tower::~Tower(){

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
            if( Vector2(target->position, this->position).magnitude() < 360 ){
                rotateTo = atan2(disvec.y, disvec.x)*RAD_TO_DEG;
                rotateTo += 90;
                if(this->shootcounter >= 1.0f && disvec.magnitude() < 360){
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
    b = new Bullet(this->towerType);
    b->position = this->position;
    b->target = this->target;
    b->lastKnownPos = this->target->position;
    b->scale = Vector2(0.2f, 0.2f);
    b->damage = this->damage;

    return b;
}
