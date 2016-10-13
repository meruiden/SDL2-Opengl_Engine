#ifndef PARTICLE_H
#define PARTICLE_H

#include <engine/entity.h>

class Particle : public Entity{
public:
    Particle(float dirRot);
    virtual ~Particle();
    virtual void update(float deltaTime);
    Vector2 dir;

private:

protected:

};

#endif
