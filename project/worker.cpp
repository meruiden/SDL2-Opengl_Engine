#include "worker.h"
#include <iostream>
Worker::Worker() : Entity(){
    this->homePos = Vector2();
    this->wantsCloud = false;
    this->cloudpos = Vector2();
    this->setPng("assets/worker.png");
    this->scale = Vector2(0.5f, 0.5f);
    this->working = false;
    this->target = NULL;
    this->buildProgress = 0;
    this->spriteTimer = 0.0f;
    this->spriteCounter = 1;

}

Worker::~Worker(){

}

void Worker::update(float deltaTime){

    if(this->working && target != NULL){
        Vector2 thisToTarget = Vector2(this->position, target->position);
        this->rotation = thisToTarget.getAngle()+90;
        float rads = (this->rotation+90) * DEG_TO_RAD;
        if(thisToTarget.magnitude() > 100){
            this->position += (Vector2(cos(rads), sin(rads))*100)*deltaTime;
            spriteTimer += deltaTime;

            if(spriteTimer > 1.0f/4){
                spriteTimer = 0;
                spriteCounter ++;

                if(spriteCounter == 3){
                    spriteCounter = 1;
                }
            }
            if(spriteCounter == 1){
                this->setPng("assets/worker_walk_1.png");
            }else if(spriteCounter == 2){
                this->setPng("assets/worker_walk_2.png");
            }
        }else{
            spriteTimer += deltaTime;

            if(spriteTimer > 1.0f/4){
                spriteTimer = 0;
                spriteCounter ++;

                if(spriteCounter == 3){
                    spriteCounter = 1;
                }
            }
            if(spriteCounter == 1){
                this->setPng("assets/worker_building_1.png");
            }else if(spriteCounter == 2){
                this->setPng("assets/worker_building_2.png");
            }
            this->buildProgress += deltaTime;
            cloudCounter += deltaTime;
            if(this->cloudCounter > 1){
                this->wantsCloud = true;
                this->cloudpos = target->position;
                this->cloudpos += Vector2((rand() % 80)-40,  (rand() % 80)-40);
                this->cloudCounter = 0;
            }

            if(this->buildProgress > 4){
                this->working = false;
                this->target->color.a = 255;
                this->target->ready = true;
                this->target = NULL;
                this->buildProgress = 0;
            }


        }
    }else{
        Vector2 thisToTarget = Vector2(this->position, homePos);
        if(thisToTarget.magnitude() > 10){
            this->rotation = thisToTarget.getAngle()+90;
            float rads = (this->rotation+90) * DEG_TO_RAD;
            this->position += (Vector2(cos(rads), sin(rads))*100)*deltaTime;
            spriteTimer += deltaTime;

            if(spriteTimer > 1.0f/4){
                spriteTimer = 0;
                spriteCounter ++;

                if(spriteCounter == 3){
                    spriteCounter = 1;
                }
            }
            if(spriteCounter == 1){
                this->setPng("assets/worker_walk_1.png");
            }else if(spriteCounter == 2){
                this->setPng("assets/worker_walk_2.png");
            }
        }else{
            this->setPng("assets/worker.png");
            this->rotation = 0;
        }
    }

}

void Worker::giveJob(Tower* tower){
    this->target = tower;
    this->working = true;
}
