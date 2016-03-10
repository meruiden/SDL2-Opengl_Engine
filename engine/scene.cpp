#include "scene.h"

Scene::Scene(){
    this->input = NULL;
    this->camera = NULL;
}

Scene::~Scene(){

}

void Scene::update(float deltaTime){

}

void Scene::addText(Text* t){
    std::vector<Text* >::iterator it = texts.begin();
    while (it != texts.end()) {
        if ((*it)->getTextId() == t->getTextId()) {
            return;
        } else {
            ++it;
        }
    }

    texts.push_back(t);
}

void Scene::removeText(Text* t){
    std::vector< Text* >::iterator it = texts.begin();
    while (it != texts.end()) {
        if ((*it)->getTextId() == t->getTextId()) {
            it = texts.erase(it);
        } else {
            ++it;
        }
    }
}

void Scene::addEntity(Entity* entity){
    std::vector< Entity* >::iterator it = entities.begin();
    while (it != entities.end()) {
        if ((*it)->getEntityId() == entity->getEntityId()) {
            return;
        } else {
            ++it;
        }
    }

    entities.push_back(entity);
}

void Scene::removeEntity(Entity* child){
    std::vector< Entity* >::iterator it = entities.begin();
    while (it != entities.end()) {
        if ((*it)->getEntityId() == child->getEntityId()) {
            it = entities.erase(it);
        } else {
            ++it;
        }
    }
}


void Scene::addHudObject(HudObject* hudobject){
    std::vector< HudObject* >::iterator it = hudObjects.begin();
    while (it != hudObjects.end()) {
        if ((*it)->getEntityId() == hudobject->getEntityId()) {
            return;
        } else {
            ++it;
        }
    }
    hudObjects.push_back(hudobject);
}

void Scene::removeHudObject(HudObject* hudobject){
    GLuint ti = 0;

    std::vector< HudObject* >::iterator it = hudObjects.begin();
    while (it != hudObjects.end()) {
        if ((*it)->getEntityId() == hudobject->getEntityId()) {
            it = hudObjects.erase(it);
        } else {
            ++it;
        }
    }
}

bool Scene::hasEntity(Entity* child){

    std::vector< Entity* >::iterator it = entities.begin();
    while (it != entities.end()) {
        if ((*it)->getEntityId() == child->getEntityId()) {
            return true;
        } else {
            ++it;
        }
    }

    return false;
}

Vector2 Scene::getCursor(){
    int xpos, ypos;
    SDL_GetMouseState(&xpos, &ypos);
    Vector2 cursor = Vector2(xpos, ypos);
    return cursor;
}
