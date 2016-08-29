#ifndef TOWER_H
#define TOWER_H

#include <engine/entity.h>
#include <project/bullet.h>
#include <project/enemy.h>
#include <engine/shape.h>
#include <engine/sound.h>
class Tower : public Entity{
public:
    Tower();
    virtual ~Tower();
    virtual void update(float deltaTime);

    virtual void handleTarget(float deltaTime);

    float shootDelay;
    float shootcounter;
    int level;
    bool wantsToShoot;
    float slowingDamage;
    Enemy* target;
    virtual Bullet* shoot();
    bool ready;
    int upgradePrice;
    int damage;
    Shape* shootingRangeShape;
    float shootingRange;
    Sound* shootSound;
    Sound* explosionSound;
    bool alreadyDead;
    virtual void upgrade();

private:

protected:

};

#endif
