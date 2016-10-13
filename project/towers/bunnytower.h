#ifndef BUNNYTOWER_H
#define BUNNYTOWER_H
#include <project/tower.h>
#include <project/bullets/bunnybullet.h>
class BunnyTower : public Tower
{
public:
	BunnyTower();
	virtual ~BunnyTower();
	virtual Bullet* shoot();
private:

};

#endif
