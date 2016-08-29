#include "menuscene.h"

MenuScene::MenuScene() : Scene(){
    background = new HudObject();
    background->setPng("assets/menu/achtergrond.png");
    addHudObject(background);
    background->position = Vector2(640, 360);
    startBtn = new HudObject();
    startBtn->setPng("assets/menu/play.png");
    addHudObject(startBtn);
    cred = false;
    startBtn->position = Vector2(400, 300);
    startBtn->scale = Vector2(0.35, 0.35);
    bgMusic = new Sound("assets/sound/menumusic.wav");
    bgMusic->play(true);
    creditsBtn = new HudObject();
    creditsBtn->setPng("assets/menu/credits.png");
    creditsBtn->position = Vector2(400, 420);
    creditsBtn->scale = Vector2(0.25, 0.25);
    addHudObject(creditsBtn);

    quitBtn = new HudObject();
    quitBtn->setPng("assets/menu/credits.png");
    quitBtn->position = Vector2(400, 580);
    quitBtn->scale = Vector2(0.3, 0.3);
    cursor = new HudObject();
    cursor->scale = Vector2(0.1f, 0.1f);
    cursor->layer = 4;
    addHudObject(cursor);
    addHudObject(quitBtn);
    cursor->setPng("assets/pointer.png");
}

MenuScene::~MenuScene(){
    delete startBtn;
    delete creditsBtn;
    delete quitBtn;
    delete background;
    delete bgMusic;
    delete cursor;
}

void MenuScene::update(float deltaTime){

    cursor->position = input->getMouseToScreen()+(Vector2(3,cursor->height()*cursor->scale.y-15));
    if(input->getMouseButton(1)){
        cursor->setPng("assets/pointerClick.png");
    }else{
        cursor->setPng("assets/pointer.png");
    }

    if(startBtn->mouseOver()){
        if(input->getMouseButtonDown(1)){
            this->nextScene = true;
            bgMusic->stop();
        }
        startBtn->setPng("assets/menu/playHover.png");
    }else{
        startBtn->setPng("assets/menu/play.png");
    }

    if(creditsBtn->mouseOver()){
        if(input->getMouseButtonDown(1)){
            this->cred = true;

        }
        creditsBtn->setPng("assets/menu/creditsHover.png");
    }else{

        creditsBtn->setPng("assets/menu/credits.png");
    }

    if(quitBtn->mouseOver()){
        if(input->getMouseButtonDown(1)){
            this->quit();
            bgMusic->stop();
        }
        quitBtn->setPng("assets/menu/quitHover.png");
    }else{
        quitBtn->setPng("assets/menu/quit.png");
    }

}
