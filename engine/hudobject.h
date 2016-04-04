#ifndef HUDOBJECT_H
#define HUDOBJECT_H

#include <engine/entity.h>
#include <engine/shape.h>
#include <engine/camera.h>
class HudObject : public Entity{
public:
    HudObject();
    virtual ~HudObject();

    bool mouseOver();

    Vector2 getPosToWorld(Camera* c);

private:

};

#endif
