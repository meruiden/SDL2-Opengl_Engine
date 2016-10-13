#ifndef DOGBULLET_H
#define DOGBULLET_H
#include <project/bullet.h>
class DogBullet : public Bullet
{
public:
	DogBullet();
	virtual ~DogBullet();
	virtual void update(float deltaTime);
private:

};

#endif
