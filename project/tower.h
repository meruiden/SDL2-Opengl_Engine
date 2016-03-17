#ifndef TOWER_H
#define TOWER_H

#include <engine/entity.h>
#include <project/bullet.h>
#include <project/enemy.h>
class Tower : public Entity{
public:
    Tower(int tt);
    virtual ~Tower();
    virtual void update(float deltaTime);

    float shootcounter;

    bool wantsToShoot;
    Enemy* target;
    Bullet* shoot();
    bool ready;
    int towerType;
    int damage;

private:

protected:

};

#endif
