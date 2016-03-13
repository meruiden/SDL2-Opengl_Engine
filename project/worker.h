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
    std::vector<SimpleEntity*> clouds;

    void deleteClouds();

    int spriteCounter;
    float spriteTimer;

private:
    Tower* target;
protected:

};

#endif
