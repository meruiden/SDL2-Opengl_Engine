#ifndef BULLET_H
#define BULLET_H

#include <engine/entity.h>
#include <project/enemy.h>


class Bullet : public Entity{
public:
    Bullet(int bt);
    virtual ~Bullet();
    virtual void update(float deltaTime);
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

private:

protected:

};

#endif
