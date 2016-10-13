#include "turtletower.h"

TurtleTower::TurtleTower() : Tower(){
    this->setPng("assets/towers/turtle.png");
    this->scale = Vector2(0.2, 0.2);
    this->shootingRange = 200;
    this->damage = 5;
    this->shootDelay = 0.2f;
    this->spriteTimer = 0;
    this->shot = false;
    this->shootSound = new Sound("assets/sound/turtle_shoot_sound.wav");
    this->shootSound->setVolume(30);
}

void TurtleTower::update(float deltaTime){
    if(this->shot){
        this->spriteTimer += deltaTime;
    }else{
        this->spriteTimer = 0;
    }
    if(this->spriteTimer >= 0.05){
            this->setPng("assets/towers/turtle.png");
            this->spriteTimer = 0;
            this->shot = false;
    }

    handleTarget(deltaTime);
}

void TurtleTower::handleTarget(float deltaTime){
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
                        this->setPng("assets/towers/turtle_shooting.png");
                        this->shot = true;
                }
            }else{
                this->target = NULL;
            }

        }

    }

    if (rotateTo > this->rotation + 180) rotateTo -= 360;
    if (rotateTo < this->rotation  - 180) rotateTo += 360;
    _trueRotation = (rotateTo - this->rotation ) / _rotateSpeedMax;
    _trueRotation *= 400;
    this->rotation += _trueRotation*deltaTime;
}

TurtleTower::~TurtleTower(){

}

Bullet* TurtleTower::shoot(){
    TurtleBullet* b;
    b = new TurtleBullet();
    b->position = this->position+Vector2(cos((this->rotation+70)*DEG_TO_RAD), sin((this->rotation+70)*DEG_TO_RAD))*45;
    b->target = this->target;
    b->lastKnownPos = this->target->position;
    b->scale = Vector2(0.2f, 0.2f);
    b->damage = this->damage;
    b->slowingDamage = this->slowingDamage;
    b->explodeSound = this->explosionSound;
    return b;
}
