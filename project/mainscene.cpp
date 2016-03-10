#include "mainscene.h"

Mainscene::Mainscene() : Scene(){

    counter = 0;
    geluidje = new Sound("assets/geluidje.wav");
    shootSound = new Sound("assets/shoot.wav");
    explosionSound = new Sound("assets/explosion.wav");
    tower = NULL;

    chooseframe = new HudObject();
    chooseframe->setTga("assets/chooseframe.tga");
    addHudObject(chooseframe);
    chooseframe->position = Vector2(1280-256/2, 720/2);

    choosedog = new HudObject();
    addHudObject(choosedog);
    choosedog->setPng("assets/hondje_sleeping.png");
    choosedog->position = Vector2(1280-245/2, 180);
    choosedog->scale = Vector2(0.7f, 0.7f);
    spawnEnemies(5);
    textje = new Text();
    textje->setFont("assets/PrintClearly.ttf", 70);
    textje->setText("Time: 0");
    textje->position = Vector2(20,70);
    textje->isHud = true;
    addText(textje);

    lockDog = false;
}

Mainscene::~Mainscene(){
    delete chooseframe;
    delete choosedog;
    delete shootSound;
    delete explosionSound;
    delete tower;
    delete geluidje;
    for(unsigned int i = 0; i < enemies.size(); i ++){
        delete enemies[i];
        enemies[i] = NULL;
    }
    enemies.clear();

    for(unsigned int i = 0; i < bullets.size(); i ++){
        delete bullets[i];
        bullets[i] = NULL;
    }
    bullets.clear();
    delete textje;
}

void Mainscene::update(float deltaTime){

    if(choosedog != NULL){
        if(input->getMouseToScreen().x < choosedog->position.x + 50 && input->getMouseToScreen().x > choosedog->position.x - 50
            && input->getMouseToScreen().y < choosedog->position.y + 50 && input->getMouseToScreen().y > choosedog->position.y - 50){
                if(input->getMouseButtonDown(1)){
                    lockDog = true;
                }
                choosedog->setPng("assets/hondje_active.png");
            }else{
            choosedog->setPng("assets/hondje_sleeping.png");
        }
        if(lockDog){
            choosedog->setPng("assets/hondje_active.png");
            choosedog->position = input->getMouseToScreen();
        }

        if(input->getMouseButtonUp(1) && lockDog){
            lockDog = false;
            removeHudObject(choosedog);
            delete choosedog;
            choosedog = NULL;

            tower = new Tower();
            addEntity(tower);
            tower->position = input->getMouseToWorld(camera);
        }

    }

    if(tower != NULL){
        Enemy* target = enemies[0];
        for(unsigned int i = 0; i < enemies.size(); i ++){
            Vector2 curdisvec = Vector2(target->position, tower->position);
            Vector2 disvec = Vector2(enemies[i]->position, tower->position);
            if(disvec.magnitude() < curdisvec.magnitude()){
                target = enemies[i];
            }
        }
        tower->target = target;
        for(unsigned int i = 0; i < bullets.size(); i++){
            if(bullets[i]->disToTarget < bullets[i]->target->collisionRadius){
                bullets[i]->target->dead = true;
                removeEnemy(bullets[i]->target);
                removeBullet(bullets[i]);
                //explosionSound->play();
                i--;
            }
        }

        if(tower->wantsToShoot){
            tower->shootcounter = 0;
            tower->wantsToShoot = false;
            Bullet* b;
            b = tower->shoot();
            addEntity(b);
            bullets.push_back(b);
            //shootSound->play();

        }
    }
    counter += deltaTime;
    std::ostringstream ss;
    std::string s = "Time: ";
    ss << s;
    ss << (int)counter;
    textje->setText(ss.str());

    if(input->getKey(SDLK_w)){
        camera->position += Vector2(0,-150*deltaTime);
    }

    if(input->getKeyDown(SDLK_g)){
        //geluidje->play();
    }
    if(input->getKey(SDLK_a)){
        camera->position += Vector2(-150*deltaTime,0);
    }
    if(input->getKey(SDLK_s)){
        camera->position += Vector2(0,150*deltaTime);
    }
    if(input->getKey(SDLK_d)){
        camera->position += Vector2(150*deltaTime,0);
    }



}

void Mainscene::spawnEnemies(int number){
    for(unsigned int i = 0; i < number; i ++){
        Enemy* e;
        e = new Enemy();
        e->position = Vector2(-100,70);
        e->position.y += 150*i;
        enemies.push_back(e);
        addEntity(e);
    }
}

void Mainscene::removeBullet(Bullet* b){
    std::vector< Bullet* >::iterator it = bullets.begin();
    while (it != bullets.end()) {
        if ((*it)->getEntityId() == b->getEntityId()) {
            removeEntity((*it));
            delete (*it);
            (*it) = NULL;
            it = bullets.erase(it);
        } else {
            ++it;
        }
    }
}


void Mainscene::removeEnemy(Enemy* e){
    std::vector< Enemy* >::iterator it = enemies.begin();
    while (it != enemies.end()) {
        if ((*it)->getEntityId() == e->getEntityId()) {
            removeEntity((*it));
            delete (*it);
            (*it) = NULL;
            it = enemies.erase(it);
        } else {
            ++it;
        }
    }
}
