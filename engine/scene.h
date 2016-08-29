#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <engine/entity.h>
#include <engine/hudobject.h>
#include <engine/input.h>
#include <iostream>
#include <engine/camera.h>
#include <engine/text.h>
#include <engine/shape.h>

class Scene{
public:
    Scene();
    virtual ~Scene();
    virtual void update(float deltaTime);

    bool nextScene;
    std::vector<Shape*> shapes;
    std::vector<Entity*> entities;
    std::vector<HudObject*> hudObjects;
    std::vector<Text*> texts;

    void addEntity(Entity* entity);
    void removeEntity(Entity* entity);

    void addText(Text* t);
    void removeText(Text* t);

    void addShape(Shape* s);
    void removeShape(Shape* s);

    void addHudObject(HudObject* hudobject);
    void removeHudObject(HudObject* hudobject);
    bool hasEntity(Entity* entity);

    Vector2 getCursor();
    Input* input;

    Camera* camera;
    bool wantsToQuit;
    int window_width;
    int window_height;

    void quit();
private:

};


#endif
