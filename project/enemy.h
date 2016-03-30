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
    int currPathPoint;
    bool atTarget;
    Vector2 curtarget;
    float speed;
    float r, g, b;
    float spriteTimer;
    
    int health;
private:

protected:

};

#endif
