#include "dogbullet.h"

DogBullet::DogBullet() : Bullet(){
    this->setPng("assets/projectiel.png");
}

DogBullet::~DogBullet(){

}

void DogBullet::update(float deltaTime){
    handleTarget(deltaTime);
}
