#include "scene.h"

Scene::Scene(){
    this->input = NULL;
    this->camera = NULL;
    this->window_width = 0;
    this->window_height = 0;
    this->nextScene = false;
    this->wantsToQuit = false;
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

void Scene::addShape(Shape* s){
    std::vector< Shape* >::iterator it = shapes.begin();
    while (it != shapes.end()) {
        if ((*it)->getShapeId() == s->getShapeId()) {
            return;
        } else {
            ++it;
        }
    }

    shapes.push_back(s);
}

void Scene::removeShape(Shape* s){
    std::vector< Shape* >::iterator it = shapes.begin();
    while (it != shapes.end()) {
        if ((*it)->getShapeId() == s->getShapeId()) {
            it = shapes.erase(it);
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

void Scene::quit(){
    this->wantsToQuit = true;
}
