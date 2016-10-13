#ifndef CREDITSSCENE_H
#define CREDITSSCENE_H
#include <engine/scene.h>
#include <engine/hudobject.h>
class CreditsScene : public Scene
{
public:
	CreditsScene();
	virtual ~CreditsScene();
	virtual void update(float deltaTime);
	HudObject* bg;
	HudObject* cursor;
	bool clickfix;
private:

};

#endif
