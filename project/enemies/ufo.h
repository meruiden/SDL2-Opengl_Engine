#ifndef UFO_H
#define UFO_H

#include <project/enemy.h>
class Ufo : public Enemy
{
public:
	Ufo();
	virtual ~Ufo();
	virtual void update(float deltaTime);
	float spriteTimer;
private:

};

#endif
