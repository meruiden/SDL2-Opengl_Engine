#include "particle.h"
#include <iostream>
Particle::Particle(float dirRot) : Entity(){
    float rads = dirRot*DEG_TO_RAD;
    this->dir = Vector2(cos(rads), sin(rads));
    this->dir.normalize();
    this->dir *= 250;
    this->setPng("assets/twinkle.png");
}

Particle::~Particle(){

}

void Particle::update(float deltaTime){
    this->position += dir*deltaTime;
    this->color.a -= 1300*deltaTime;
}
