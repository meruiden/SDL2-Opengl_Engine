#ifndef ROBOTTOWER_H
#define ROBOTTOWER_H
#include <project/tower.h>
#include <project/bullets/robotbullet.h>
class RobotTower : public Tower
{
public:
	RobotTower();
	virtual ~RobotTower();
	virtual Bullet* shoot();
private:

};

#endif
