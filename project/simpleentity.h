#ifndef SIMPLEENTITY_H
#define SIMPLEENTITY_H

#include <engine/entity.h>
class SimpleEntity : public Entity{
public:
    SimpleEntity();
    virtual ~SimpleEntity();
    virtual void update(float deltaTime);

private:

protected:

};

#endif
