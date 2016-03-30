#include <engine/hudobject.h>

HudObject::HudObject() : Entity(){
    this->layer = 1;
}

HudObject::~HudObject(){

}

bool HudObject::mouseOver(){

    Vector2 v = input->getMouseToScreen();

    if(v.x < this->position.x+((this->width()/2)*this->scale.x)
    && v.x > this->position.x-((this->width()/2)*this->scale.x)
    && v.y < this->position.y+((this->height()/2)*this->scale.y)
    && v.y > this->position.y-((this->height()/2)*this->scale.y)){
        return true;
    }

    return false;
}
