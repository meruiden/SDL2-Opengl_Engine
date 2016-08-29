#ifndef MENUSCENE_H
#define MENUSCENE_H

#include <engine/scene.h>
#include <engine/Sound.h>
#include <engine/hudobject.h>
class MenuScene : public Scene
{
public:
	MenuScene();
	virtual ~MenuScene();
	virtual void update(float deltaTime);
	HudObject* background;
	Sound* bgMusic;
	HudObject* startBtn;
	HudObject* creditsBtn;
	HudObject* quitBtn;
	HudObject* cursor;

	bool cred;
private:

};

#endif
