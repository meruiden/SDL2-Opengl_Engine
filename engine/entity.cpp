#include "entity.h"

int Entity::idCounter = 0;
Entity::Entity(){
    this->color = Color();
    this->input = NULL;
    this->parent = NULL;
    this->entityId = idCounter;
    Entity::idCounter ++;
    this->imagePath = "NULL";
    this->extention = "NULL";
    this->position = Vector2(0,0);
    this->scale = Vector2(1,1);
    this->rotation = 0;
    this->uvOffset = Vector2();
}

Entity::~Entity(){
}

void Entity::update(float deltaTime){

}

void Entity::setTga(std::string imagepath){
    this->imagePath = imagepath;
    this->extention = "tga";
}


void Entity::setPng(std::string imagepath){
    this->imagePath = imagepath;
    this->extention = "png";
}
std::string Entity::getImgPath(){
  return this->imagePath;
}

void Entity::addChild(Entity* child){
    if(child->parent != NULL) {
        child->parent->removeChild(child);
    }
    child->parent = this;
    this->children.push_back(child);
}

bool Entity::collideTestObject(Entity* entity){
    if (this->position.x < entity->position.x + (entity->width()*entity->scale.x) &&
        this->position.x + (this->width()*this->scale.x) > entity->position.x &&
        this->position.y < entity->position.y + (entity->height()*entity->scale.y) &&
        (this->height()*this->scale.y) + this->position.y > entity->position.y) {

        return true;
    }
    return false;
}

void Entity::removeChild(Entity* child){
    std::vector< Entity* >::iterator it = children.begin();
	while (it != children.end()) {
		if ((*it)->getEntityId() == child->getEntityId()) {
			it = children.erase(it);
            child->parent = NULL;
		} else {
			++it;
		}
	}
}
