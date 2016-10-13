#include "dogtower.h"
#include <iostream>
DogTower::DogTower() : Tower(){
    this->setPng("assets/towers/hondje_top_down.png");
    this->scale = Vector2(0.5f, 0.5f);
    this->shootingRange = 200;
    this->damage = 25;
    this->shootSound = new Sound("assets/sound/shoot.wav");
    this->shootSound->setVolume(30);
}

DogTower::~DogTower(){

}

Bullet* DogTower::shoot(){
    DogBullet* b;
    b = new DogBullet();
    b->position = this->position;
    b->target = this->target;
    b->lastKnownPos = this->target->position;
    b->scale = Vector2(0.2f, 0.2f);
    b->damage = this->damage;
    b->explodeSound = this->explosionSound;
    return b;
}
