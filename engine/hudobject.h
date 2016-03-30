#ifndef HUDOBJECT_H
#define HUDOBJECT_H

#include <engine/entity.h>

class HudObject : public Entity{
public:
    HudObject();
    virtual ~HudObject();

    bool mouseOver();
private:

};

#endif
