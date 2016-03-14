#ifndef WORKER_H
#define WORKER_H

#include <engine/entity.h>
#include <project/tower.h>
#include <project/simpleentity.h>
class Worker : public Entity{
public:
    Worker();
    virtual ~Worker();
    virtual void update(float deltaTime);

    bool working;
    void giveJob(Tower* tower);
    float buildProgress;
    float cloudCounter;


    bool wantsCloud;
    Vector2 cloudpos;
    Vector2 homePos;
    int spriteCounter;
    float spriteTimer;

private:
    Tower* target;
protected:

};

#endif
