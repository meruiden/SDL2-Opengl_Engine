#ifndef BULLET_H
#define BULLET_H

#include <engine/entity.h>
#include <project/enemy.h>
#include <engine/sound.h>
#include <iostream>
class Bullet : public Entity{
public:
    Bullet();
    virtual ~Bullet();
    virtual void update(float deltaTime);
    void handleTarget(float deltaTime);
    Vector2 vel;
    Enemy* target;
    float speed;
    float disToTarget;
    Vector2 lastKnownPos;
    bool hasTarget;
    bool destroyMe;
    int damage;
    int bulletType;
    bool wantsTwinkle;
    float twinkleCounter;
    float slowingDamage;
    Sound* explodeSound;
    bool bulletRotate;
private:

protected:

};

#endif
