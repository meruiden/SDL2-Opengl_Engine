#include "bunnytower.h"

BunnyTower::BunnyTower() : Tower(){
    this->setPng("assets/bunny.png");
    this->scale = Vector2(0.4f, 0.4f);
    this->shootingRange = 250;
}

BunnyTower::~BunnyTower(){
    
}

Bullet* BunnyTower::shoot(){

    BunnyBullet* b;
    b = new BunnyBullet();
    b->position = this->position;
    b->target = this->target;
    b->lastKnownPos = this->target->position;
    b->scale = Vector2(0.2f, 0.2f);
    b->damage = this->damage;

    return b;
}
