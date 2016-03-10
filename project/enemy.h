#ifndef ENEMY_H
#define ENEMY_H

#include <engine/entity.h>
#include <sstream>
class Enemy : public Entity{
public:
    Enemy();
    virtual ~Enemy();
    virtual void update(float deltaTime);
    float collisionRadius;
    bool dead;
    float spritetimer;
    int spritecounter;
private:

protected:

};

#endif
