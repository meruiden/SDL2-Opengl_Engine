#include "dogbullet.h"

DogBullet::DogBullet() : Bullet(){
    this->setPng("assets/bullets/projectiel.png");
}

DogBullet::~DogBullet(){

}

void DogBullet::update(float deltaTime){
    handleTarget(deltaTime);
}
