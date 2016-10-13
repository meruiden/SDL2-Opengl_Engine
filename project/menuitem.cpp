#include "menuitem.h"

MenuItem::MenuItem(int id) : HudObject(){
    this->spawnId = id;
    this->range = 100.0f;

    this->offsetpos = Vector2();
    this->price = 0;

    this->hoverImgPath = "";
    this->notHoverImgPath = "";
    this->selectedScale = Vector2();
    this->unselectedScale = Vector2();
}

MenuItem::~MenuItem(){

}
