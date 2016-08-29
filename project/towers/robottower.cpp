#include "robottower.h"

RobotTower::RobotTower() : Tower(){
    this->setPng("assets/towers/robot.png");
    this->scale = Vector2(0.3, 0.3);
    this->shootingRange = 500;
    this->damage = 60;
    this->shootSound = new Sound("assets/sound/shoot.wav");
    this->shootSound->setVolume(30);
    this->shootDelay = 4;
}

RobotTower::~RobotTower(){

}

Bullet* RobotTower::shoot(){
    RobotBullet* b;
    b = new RobotBullet();
    b->position = this->position+Vector2(cos((this->rotation+10)*DEG_TO_RAD), sin((this->rotation+10)*DEG_TO_RAD))*55;
    b->target = this->target;
    b->lastKnownPos = this->target->position;
    b->scale = Vector2(0.2f, 0.2f);
    b->damage = this->damage;
    b->slowingDamage = this->slowingDamage;
    b->explodeSound = this->explosionSound;
    return b;
}
