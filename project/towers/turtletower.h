#ifndef TURTLETOWER_H
#define TURTLETOWER_H
#include <project/tower.h>
#include <project/bullets/turtlebullet.h>
class TurtleTower : public Tower
{
public:
	TurtleTower();
	virtual ~TurtleTower();
	virtual Bullet* shoot();
	virtual void  update(float deltaTime);
	virtual void handleTarget(float deltaTime);
	bool shot;
	float spriteTimer;
private:

};

#endif
