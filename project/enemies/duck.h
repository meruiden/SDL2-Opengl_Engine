#ifndef DUCK_H
#define DUCK_H

#include <project/enemy.h>
class Duck : public Enemy
{
public:
	Duck();
	virtual ~Duck();
	virtual void update(float deltaTime);

	float spriteTimer;
private:

};

#endif
