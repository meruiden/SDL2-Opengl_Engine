#include "enemy.h"
#include <iostream>
Enemy::Enemy() : Entity(){
    this->collisionRadius = 20.0f;
    this->dead = false;
    this->spritetimer = 0.0f;
    this->spritecounter = 0;
}

Enemy::~Enemy(){

}

void Enemy::update(float deltaTime){
    this->position.x += 70*deltaTime;

    if(spritetimer >= 0.08f){
        std::stringstream ss;
        ss << "assets/skeleton/skeleton-";
        ss << spritecounter;
        ss << ".png";
        this->setPng(ss.str());
        spritecounter ++;
        if(spritecounter == 24){
            spritecounter = 0;
        }

        spritetimer = 0.0f;
    }
    spritetimer += deltaTime;
}
