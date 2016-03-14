#include "mainscene.h"

Mainscene::Mainscene() : Scene(){
    pathpoints.push_back(Vector2(300,300));
    pathpoints.push_back(Vector2(500,200));
    pathpoints.push_back(Vector2(700,600));
    pathpoints.push_back(Vector2(1000,100));
    for(unsigned int i = 0; i < 4; i++){
        Worker* worker = new Worker();
        worker->homePos = Vector2(100+ (230*i), 100);
        worker->position = worker->homePos;
        addEntity(worker);
        readyWorkers.push_back(worker);
    }

    scrollvel = Vector2();
    scrollacc = Vector2();
    counter = 0;
    geluidje = new Sound("assets/geluidje.wav");
    shootSound = new Sound("assets/shoot.wav");
    explosionSound = new Sound("assets/explosion.wav");

    chooseframe = new HudObject();
    chooseframe->setTga("assets/chooseframe.tga");
    addHudObject(chooseframe);
    chooseframe->position = Vector2(1280-256/2, 720/2);

    choosedog = new HudObject();
    addHudObject(choosedog);
    choosedog->setPng("assets/hondje_sleeping.png");
    choosedog->position = Vector2(1280-245/2, 180);
    choosedog->scale = Vector2(0.7f, 0.7f);
    spawnEnemies(50);

    lockDog = false;
}

Mainscene::~Mainscene(){
    delete chooseframe;
    delete shootSound;
    delete explosionSound;

    delete geluidje;

    removeHudObject(choosedog);
    delete choosedog;

    for(unsigned int i = 0; i < towers.size(); i++){
        removeEntity(towers[i]);
        delete towers[i];
        towers[i] = NULL;
    }
    towers.clear();
    for(unsigned int i = 0; i < enemies.size(); i ++){
        removeEntity(enemies[i]);
        delete enemies[i];
        enemies[i] = NULL;
    }
    enemies.clear();

    for(unsigned int i = 0; i < bullets.size(); i ++){
        removeEntity(bullets[i]);
        delete bullets[i];
        bullets[i] = NULL;
    }
    pathpoints.clear();
    bullets.clear();
    for(unsigned int i = 0; i < clouds.size(); i++){
        removeCloud(clouds[i]);
    }
    clouds.clear();

    for(unsigned int i = 0; i < busyWorkers.size(); i++){
        removeEntity(busyWorkers[i]);
        delete busyWorkers[i];

        busyWorkers[i] = NULL;
    }

    busyWorkers.clear();

    for(unsigned int i = 0; i < readyWorkers.size(); i++){
        removeEntity(readyWorkers[i]);
        delete readyWorkers[i];
        readyWorkers[i] = NULL;
    }
    readyWorkers.clear();


}

void Mainscene::update(float deltaTime){

    counter += deltaTime;
    if(counter >= 1.0f/60){
        fixedUpdate();
        counter = 0;
    }
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
        }else{
            choosedog->position = Vector2(1280-245/2, chooseframe->position.y - 180);
        }

        if(input->getMouseButtonUp(1) && lockDog){
            lockDog = false;
            Tower* tower = new Tower();

            addEntity(tower);
            tower->position = input->getMouseToWorld(camera);
            if(!assignWorker(tower)){
                removeEntity(tower);
                delete tower;
                tower = NULL;
            }else{
                towers.push_back(tower);
            }
        }
    }



    for(unsigned int i = 0; i < enemies.size(); i ++){
        if(enemies[i]->atTarget){
            if(pathpoints.size()-1 > enemies[i]->currPathPoint){
                enemies[i]->atTarget = false;
                enemies[i]->currPathPoint ++;
                enemies[i]->curtarget = pathpoints[enemies[i]->currPathPoint];
            }
        }
    }

    for(unsigned int i = 0; i < bullets.size(); i++){
        bool done = false;

        if(!bullets[i]->hasTarget && bullets[i]->disToTarget < 10){
            removeBullet(bullets[i]);
            done = true;
        }

        if(!done){
            if(bullets[i]->disToTarget < bullets[i]->target->collisionRadius && bullets[i]->hasTarget){
                bullets[i]->target->dead = true;
                for(unsigned int b = 0; b < bullets.size(); b++){
                    if(bullets[i]->target->getEntityId() == bullets[b]->target->getEntityId()){
                        if(bullets[i]->getEntityId() != bullets[b]->getEntityId()){
                            bullets[b]->lastKnownPos = bullets[i]->target->position;
                            bullets[b]->hasTarget = false;
                        }
                    }
                }

                removeEnemy(bullets[i]->target);
                bullets[i]->destroyMe = true;
                explosionSound->play();
            }


        }

    }

    for(unsigned int i = 0; i < bullets.size(); i++){
        if(bullets[i]->destroyMe){
            removeBullet(bullets[i]);
        }
    }

    if(towers.size() > 0 && enemies.size() > 0){
        Enemy* target = enemies[0];

        for(unsigned int t = 0; t < towers.size(); t++){
            for(unsigned int i = 0; i < enemies.size(); i ++){
                Vector2 curdisvec = Vector2(target->position, towers[t]->position);
                Vector2 disvec = Vector2(enemies[i]->position, towers[t]->position);
                if(disvec.magnitude() < curdisvec.magnitude() && !enemies[i]->dead){
                    target = enemies[i];
                }
            }
            towers[t]->target = target;

            if(towers[t]->wantsToShoot && towers[t]->target != NULL && !towers[t]->target->dead){
                towers[t]->shootcounter = 0;
                towers[t]->wantsToShoot = false;
                Bullet* b;
                b = towers[t]->shoot();
                addEntity(b);
                b->hasTarget = true;
                bullets.push_back(b);
                shootSound->play();
            }
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
    for(unsigned int i = 0; i < busyWorkers.size(); i++){
        if(busyWorkers[i]->wantsCloud){
            SimpleEntity* c;
            c = new SimpleEntity();
            c->position = busyWorkers[i]->cloudpos;
            c->setPng("assets/Bouwwolkje.png");
            c->scale = Vector2(0.5f, 0.5f);
            addEntity(c);
            clouds.push_back(c);
            busyWorkers[i]->wantsCloud = false;
        }
        if(!busyWorkers[i]->working){
            clearWorker(busyWorkers[i]);
        }
    }
    for(unsigned int i = 0; i < clouds.size(); i++){
        clouds[i]->rotation += 15*deltaTime;
        clouds[i]->color.a -= 50*deltaTime;

        if(clouds[i]->color.a < 0){
            removeCloud(clouds[i]);
        }
    }


}

void Mainscene::spawnEnemies(int number){
    for(unsigned int i = 0; i < number; i ++){
        Enemy* e;
        e = new Enemy();
        e->position = Vector2(-100,400);
        e->position.x -= 150*i;
        enemies.push_back(e);
        addEntity(e);
        e->curtarget = pathpoints[0];
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
        }else {
            ++it;
        }
    }
}

void Mainscene::removeCloud(SimpleEntity* e){
    std::vector< SimpleEntity* >::iterator it = clouds.begin();
    while (it != clouds.end()) {
        if ((*it)->getEntityId() == e->getEntityId()) {
            removeEntity((*it));
            delete (*it);
            (*it) = NULL;
            it = clouds.erase(it);
        }else {
            ++it;
        }
    }
}

bool Mainscene::assignWorker(Tower* tower){
    if(readyWorkers.size() > 0){
        std::vector< Worker* >::iterator it = readyWorkers.begin();
        std::vector< Worker* >::iterator curworkerIt = it;
        Worker* curworker = (*it);
        Vector2 disvec = Vector2(curworker->position, tower->position);
        float curdis = disvec.magnitude();
        while (it != readyWorkers.end()) {
            disvec = Vector2((*it)->position, tower->position);
            if (curdis > disvec.magnitude()) {
                curworker = (*it);
                curworkerIt = it;
            }
            ++it;
        }
        busyWorkers.push_back(curworker);
        curworker->giveJob(tower);
        curworkerIt = readyWorkers.erase(curworkerIt);
        return true;
    }
    return false;
}

void Mainscene::clearWorker(Worker* worker){
    std::vector< Worker* >::iterator it = busyWorkers.begin();
    while (it != busyWorkers.end()) {
        if ((*it)->getEntityId() == worker->getEntityId()) {
            it = busyWorkers.erase(it);
            readyWorkers.push_back(worker);
        }else {
            ++it;
        }
    }
}
