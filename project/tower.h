#ifndef TOWER_H
#define TOWER_H

#include <engine/entity.h>
#include <project/bullet.h>
#include <project/enemy.h>
#include <engine/shape.h>
class Tower : public Entity{
public:
    Tower();
    virtual ~Tower();
    virtual void update(float deltaTime);

    float shootcounter;

    bool wantsToShoot;
    Enemy* target;
    virtual Bullet* shoot();
    bool ready;

    int damage;
    Shape* shootingRangeShape;
    float shootingRange;

private:

protected:

};

#endif
