#include "mainscene.h"

Mainscene::Mainscene() : Scene(){
    pathpoints.push_back(Vector2(300,300));
    pathpoints.push_back(Vector2(500,600));

    scrollvel = Vector2();
    scrollacc = Vector2();
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
    pathpoints.clear();
    bullets.clear();

}

void Mainscene::update(float deltaTime){

    counter += deltaTime;
    if(counter >= 1.0f/60){
        fixedUpdate();
        counter = 0;
    }



    if(choosedog != NULL){
        choosedog->position.y = chooseframe->position.y - 180;
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




    if(tower != NULL && enemies.size() > 0){
        Enemy* target = enemies[0];
        for(unsigned int i = 0; i < enemies.size(); i ++){
            Vector2 curdisvec = Vector2(target->position, tower->position);
            Vector2 disvec = Vector2(enemies[i]->position, tower->position);
            if(disvec.magnitude() < curdisvec.magnitude()){
                target = enemies[i];
            }

            if(enemies[i]->atTarget){
                enemies[i]->atTarget = false;
                enemies[i]->currPathPoint ++;
                if(pathpoints.size() > enemies[i]->currPathPoint){
                    enemies[i]->curtarget = pathpoints[enemies[i]->currPathPoint];
                }
            }
        }
        tower->target = target;
        for(unsigned int i = 0; i < bullets.size(); i++){
            if(bullets[i]->disToTarget < bullets[i]->target->collisionRadius){
                bullets[i]->target->dead = true;
                removeEnemy(bullets[i]->target);
                removeBullet(bullets[i]);
                explosionSound->play();
            }
        }

        if(tower->wantsToShoot){
            tower->shootcounter = 0;
            tower->wantsToShoot = false;
            Bullet* b;
            b = tower->shoot();
            addEntity(b);
            bullets.push_back(b);
            shootSound->play();

        }
    }

    if(input->scrollDown()){
        chooseframe->position += Vector2(0, 30);
    }

    if(input->scrollUp()){
        chooseframe->position += Vector2(0, -30);
    }
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
        e->position = Vector2(-400,400);
        e->position.x += 150*i;
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

void Mainscene::fixedUpdate(){


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
