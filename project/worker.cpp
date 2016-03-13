#include "worker.h"
#include <iostream>
Worker::Worker() : Entity(){
    this->setPng("assets/worker.png");
    this->scale = Vector2(0.5f, 0.5f);
    this->position = Vector2(100,100);
    this->working = false;
    this->target = NULL;
    this->buildProgress = 0;
    this->spriteTimer = 0.0f;
    this->spriteCounter = 1;
}

Worker::~Worker(){
    deleteClouds();
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
            this->setPng("assets/worker.png");
            this->buildProgress += deltaTime;
            cloudCounter += deltaTime;
            if(this->cloudCounter > 1){

                SimpleEntity* c;
                c = new SimpleEntity();
                c->position = Vector2(100,200);
                c->setPng("assets/cloud.png");
                this->addChild(c);
                clouds.push_back(c);

                this->cloudCounter = 0;
            }

            if(this->buildProgress > 4){
                deleteClouds();
                this->working = false;
                this->target->color.a = 255;
                this->target->ready = true;
                this->target = NULL;
                this->buildProgress = 0;

            }
        }
    }else{
        Vector2 thisToTarget = Vector2(this->position, Vector2(100,100));
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
        }

    }

    for(unsigned int i = 0; i < clouds.size(); i++){
        clouds[i]->rotation += 15*deltaTime;
        //clouds[i]->color.a -= 1*deltaTime;
    }
}

void Worker::giveJob(Tower* tower){
    this->target = tower;
    this->working = true;
}

void Worker::deleteClouds(){
    for(unsigned int i = 0; i < clouds.size(); i++){
        this->removeChild(clouds[i]);
        delete clouds[i];
        std::cout << 1 << std::endl;
        clouds[i] = NULL;
    }
    clouds.clear();
}
