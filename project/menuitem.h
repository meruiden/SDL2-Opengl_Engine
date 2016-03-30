#ifndef MENUITEM_H
#define MENUITEM_H

#include <engine/hudobject.h>

class MenuItem : public HudObject
{
public:
	MenuItem(int id);
	virtual ~MenuItem();
	Vector2 offsetpos;
	float range;
	int spawnId;
	int price;

	std::string hoverImgPath;
	std::string notHoverImgPath;

private:

};

#endif
