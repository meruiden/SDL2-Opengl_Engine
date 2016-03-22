#ifndef BUNNYBULLET_H
#define BUNNYBULLET_H

#include <project/bullet.h>
class BunnyBullet : public Bullet
{
public:
	BunnyBullet();
	virtual ~BunnyBullet();
	virtual void update(float deltaTime);
private:

};

#endif
