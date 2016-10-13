#ifndef TROL_H
#define TROL_H
#include <project/enemy.h>
class Trol : public Enemy
{
public:
	Trol();
	virtual ~Trol();
	virtual void update(float deltaTime);
	float spriteTimer;
	int curSprite;
private:

};

#endif
