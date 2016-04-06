#ifndef ICETOWER_H
#define ICETOWER_H
#include <project/tower.h>
#include <project/bullets/icebullet.h>
class IceTower : public Tower
{
public:
	IceTower();
	virtual ~IceTower();
	virtual Bullet* shoot();
	virtual void handleTarget(float deltaTime);
private:

};

#endif
