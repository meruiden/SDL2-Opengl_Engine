#include "icetower.h"

IceTower::IceTower() : Tower(){
    this->setPng("assets/mrcone.png");
    this->scale = Vector2(0.2f, 0.2f);
    this->shootingRange = 130;
    this->slowingDamage = 40;
}

IceTower::~IceTower(){

}

Bullet* IceTower::shoot(){
    IceBullet* b;
    b = new IceBullet();
    b->position = this->position;
    b->target = this->target;
    b->lastKnownPos = this->target->position;
    b->scale = Vector2(0.2f, 0.2f);
    b->damage = this->damage;
    b->slowingDamage = this->slowingDamage;

    return b;
}


void IceTower::handleTarget(float deltaTime){
    this->shootingRangeShape->position = this->position;
    if(this->ready && this->target != NULL){
        if(target->dead || target->slowness >= 60){
            this->target = NULL;
        }
    }
    float rotateTo = 0.0f;
    float _rotateSpeedMax = 200.0f;
    float _trueRotation = 0.0f;
    if(this->ready && this->target != NULL){

        this->shootcounter += deltaTime;


        Vector2 disvec = Vector2(this->position, target->position);



        if(target != NULL && (!target->dead || target->slowness >= 60)){
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
