#include "bunnytower.h"

BunnyTower::BunnyTower() : Tower(){
    this->setPng("assets/towers/konijn.png");
    this->scale = Vector2(0.22f, 0.22f);
    this->shootingRange = 250;
    this->damage = 40;
    this->shootSound = new Sound("assets/sound/shoot.wav");
    this->shootSound->setVolume(30);
    
}

BunnyTower::~BunnyTower(){

}

Bullet* BunnyTower::shoot(){

    BunnyBullet* b;
    b = new BunnyBullet();
    b->position = this->position;
    b->target = this->target;
    b->lastKnownPos = this->target->position;
    b->scale = Vector2(0.13f, 0.13f);
    b->damage = this->damage;
    b->explodeSound = this->explosionSound;
    return b;
}
