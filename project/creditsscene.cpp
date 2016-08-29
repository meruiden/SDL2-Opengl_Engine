#include "creditsscene.h"

CreditsScene::CreditsScene() : Scene(){
    bg = new HudObject();
    addHudObject(bg);
    bg->setPng("assets/creditsbg.png");
    bg->position = Vector2(1280/2, 720/2);
    cursor = new HudObject();
    cursor->scale = Vector2(0.1f, 0.1f);
    cursor->layer = 4;
    addHudObject(cursor);
    cursor->setPng("assets/pointer.png");
    clickfix = false;
}

CreditsScene::~CreditsScene(){
    delete bg;
    delete cursor;
}

void CreditsScene::update(float deltaTime){
    cursor->position = input->getMouseToScreen()+(Vector2(3,cursor->height()*cursor->scale.y-15));
    if(input->getMouseButton(1)){
        cursor->setPng("assets/pointerClick.png");

    }else{
        cursor->setPng("assets/pointer.png");
    }

    if(input->getMouseButtonUp(1)){
        if(clickfix){
            this->nextScene = true;
        }
        clickfix = true;

    }
}
