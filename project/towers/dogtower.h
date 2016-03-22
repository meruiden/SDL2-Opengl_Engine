#ifndef DOGTOWER_H
#define DOGTOWER_H
#include <project/tower.h>
#include <project/bullets/dogbullet.h>
class DogTower : public Tower
{
public:
	DogTower();
	virtual ~DogTower();
	virtual Bullet* shoot();
private:

};

#endif
