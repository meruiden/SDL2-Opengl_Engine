#include "mainscene.h"

Mainscene::Mainscene() : Scene(){
    SDL_ShowCursor(0);
    background = new SimpleEntity();
    addEntity(background);
    cursor = new HudObject();
    lockBunny = false;
    choosebunny = new HudObject();
    choosebunny->setPng("assets/bunny.png");
    toolbarMustPop = false;
    choosebunny->scale = Vector2(0.3f, 0.3f);
    choosebunny->position = Vector2(600, 360);
    cursor->setPng("assets/pointer.png");

    captureMouseDistance = false;


    background->setPng("assets/map_0-1.png");
    background->position = Vector2(1024/2, 1296/2);
    pathpoints.push_back(Vector2(801,357));
    pathpoints.push_back(Vector2(478,357));
    pathpoints.push_back(Vector2(477,170));
    pathpoints.push_back(Vector2(631,161));
    pathpoints.push_back(Vector2(639,40));
    pathpoints.push_back(Vector2(141,40));
    pathpoints.push_back(Vector2(135,650));
    pathpoints.push_back(Vector2(802,650));
    pathpoints.push_back(Vector2(802,958));
    pathpoints.push_back(Vector2(137,967));
    pathpoints.push_back(Vector2(131,1426));
    for(unsigned int i = 0; i < 3; i++){
        Worker* worker = new Worker();
        worker->homePos = Vector2(280+ (230*i), 490);
        worker->position = worker->homePos;
        addEntity(worker);
        worker->layer = 3;
        readyWorkers.push_back(worker);
    }
    lastDistance = Vector2();
    mouseDistance = Vector2();
    notEnoughText = new Text();
    addText(notEnoughText);
    notEnoughText->setText("Not enough coins!!");
    notEnoughText->position = Vector2(350, 720/2);
    notEnoughText->setFont("assets/PrintClearly.ttf", 40);
    notEnoughText->color = Color(255,0,0, 0);
    notEnoughText->isHud = true;
    coins = 100;
    coinsText = new Text();

    coinsText->isHud = true;
    coinsText->setFont("assets/ChunkFive-Roman.ttf", 30);
    coinsText->setText("Coins: ");
    coinsText->position = Vector2(1280-230, 20);
    coinsText->scale = Vector2(0.5f, 0.5f);
    availableWorkersText = new Text();
    availableWorkersText->isHud = true;
    availableWorkersText->position =  Vector2(1280-230, 40);
    availableWorkersText->setFont("assets/ChunkFive-Roman.ttf", 30);
    availableWorkersText->scale = Vector2(0.5f, 0.5f);

    //availableWorkersText->scale = Vector2(0.5f, 0.5f);
    availableWorkersText->setText("Available Workers: 0");
    addText(availableWorkersText);
    addText(coinsText);

    scrollvel = Vector2();
    scrollacc = Vector2();
    counter = 0;
    bgmusic = new Sound("assets/bg-music.wav");
    bgmusic->play(true);
    bgmusic->setVolume(40);
    geluidje = new Sound("assets/geluidje.wav");
    shootSound = new Sound("assets/shoot.wav");
    explosionSound = new Sound("assets/explosion.wav");
    shootSound->setVolume(30);
    explosionSound->setVolume(30);
    chooseframe = new HudObject();
    chooseframe->setPng("assets/chooseframe.png");
    addHudObject(chooseframe);
    chooseframe->position = Vector2(1280-256/2, 720/2);

    choosedog = new HudObject();

    choosedog->setPng("assets/hondje_sleeping.png");

    choosedog->position = Vector2((1280/2)-750, 180);
    choosedog->scale = Vector2(0.3f, 0.3f);

    spawnEnemies(50);
    toolbar = new HudObject();
    toolbar->setPng("assets/toolbar.png");
    toolbar->position = Vector2(520, 720+(64));
    toolbar->scale = Vector2(2,2);
    addHudObject(toolbar);
    lockDog = false;
    notenoughAlpha = 0;
    cursor->scale = Vector2(0.1f, 0.1f);
    cursor->layer = 4;
    choosedog->layer = 2;
    choosebunny->layer = 2;
    addHudObject(choosebunny);
    addHudObject(choosedog);
    addHudObject(cursor);
}

Mainscene::~Mainscene(){
    delete background;
    delete toolbar;
    delete chooseframe;
    delete shootSound;
    delete explosionSound;
    delete bgmusic;
    delete geluidje;
    delete availableWorkersText;
    delete coinsText;
    delete notEnoughText;
    delete cursor;
    delete choosebunny;
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


    for(unsigned int i = 0; i < twinkles.size(); i++){
        removeTwinkle(twinkles[i]);
    }
    twinkles.clear();

}

void Mainscene::update(float deltaTime){
    cursor->position = input->getMouseToScreen()+(Vector2(3,cursor->height()*cursor->scale.y-15));
    if(input->getMouseButton(1)){
        cursor->setPng("assets/pointerClick.png");
    }else{
        cursor->setPng("assets/pointer.png");
    }
    if(input->getMouseToScreen().y > 620){
        camera->position.y += (((input->getMouseToScreen().y - 620)/100)*400)*deltaTime;
    }

    if(input->getMouseToScreen().y < 120){
        camera->position.y -= (((120-input->getMouseToScreen().y)/100)*400)*deltaTime;
    }
    if(notenoughAlpha < 0){
        notenoughAlpha = 0;
    }
    notenoughAlpha -= 150*deltaTime;
    if(notEnoughText->color.a > 0){
        notEnoughText->position.y -= 10*deltaTime;
    }
    notEnoughText->color.a = notenoughAlpha;
    std::ostringstream ss;
    ss << "Available Workers: ";
    ss << readyWorkers.size();
    availableWorkersText->setText(ss.str());

    std::ostringstream cc;

    cc << "Coins: ";
    cc << coins;
    coinsText->setText(cc.str());


    counter += deltaTime;
    if(counter >= 1.0f/60){
        fixedUpdate();
        counter = 0;
    }

    for(unsigned int i = 0; i < bullets.size(); i++){
        if(bullets[i]->wantsTwinkle){
            Particle* t;
            t = new Particle(bullets[i]->rotation);
            twinkles.push_back(t);
            addEntity(t);
            t->layer = 3;
            t->position = bullets[i]->position;
            bullets[i]->wantsTwinkle = false;

        }
    }
    for(unsigned int i = 0; i < twinkles.size(); i++){
        if(twinkles[i]->color.a <= 0){
            removeTwinkle(twinkles[i]);
        }
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
            choosedog->scale = Vector2(0.5f, 0.5f);
            choosedog->setPng("assets/hondje_active.png");
            choosedog->position = input->getMouseToScreen();
        }else{
            choosedog->scale = Vector2(0.3f, 0.3f);
            choosedog->position = Vector2(1280-175, chooseframe->position.y - 254);
        }


        if(input->getMouseButtonUp(1) && lockDog){

            lockDog = false;
            Tower* tower = new Tower(1);

            addEntity(tower);
            tower->layer = 1;
            tower->position = input->getMouseToWorld(camera);
            if(choosedog->position.x < (chooseframe->position.x-(chooseframe->width()/2))){
                if((coins-80) >= 0){
                    if(!assignWorker(tower)){
                        removeEntity(tower);
                        delete tower;
                        tower = NULL;
                    }else{
                        towers.push_back(tower);
                        coins -= 80;
                        tower->damage = 25;
                    }
                }else{
                    notenoughAlpha = 255;
                    notenoughAlpha = 255.0f;
                    notEnoughText->position.y = 720/2;
                    removeEntity(tower);
                    delete tower;
                    tower = NULL;
                }
            }else{
                removeEntity(tower);
                delete tower;
                tower = NULL;
            }
        }
    }

    if(choosebunny != NULL){
        if(input->getMouseToScreen().x < choosebunny->position.x + 50 && input->getMouseToScreen().x > choosebunny->position.x - 50
            && input->getMouseToScreen().y < choosebunny->position.y + 50 && input->getMouseToScreen().y > choosebunny->position.y - 50){
                if(input->getMouseButtonDown(1)){
                    lockBunny = true;
                }

            }else{

        }
        if(lockBunny){
            choosebunny->scale = Vector2(0.5f, 0.5f);
            choosebunny->position = input->getMouseToScreen();
        }else{
            choosebunny->scale = Vector2(0.3f, 0.3f);
            choosebunny->position = Vector2(1280-80, chooseframe->position.y - 254);
        }
        if(input->getMouseButtonDown(3)){
            toolbarMustPop = true;
        }

        if(input->getMouseButtonUp(1) && lockBunny){

            lockBunny = false;
            Tower* tower = new Tower(2);

            addEntity(tower);
            tower->layer = 1;
            tower->position = input->getMouseToWorld(camera);
            if(choosebunny->position.x < (chooseframe->position.x-(chooseframe->width()/2))){
                if((coins-100) >= 0){
                    if(!assignWorker(tower)){
                        removeEntity(tower);
                        delete tower;
                        tower = NULL;
                    }else{
                        towers.push_back(tower);
                        coins -= 100;
                        tower->damage = 40;
                    }
                }else{
                    notenoughAlpha = 255;
                    notenoughAlpha = 255.0f;
                    notEnoughText->position.y = 720/2;
                    removeEntity(tower);
                    delete tower;
                    tower = NULL;
                }
            }else{
                removeEntity(tower);
                delete tower;
                tower = NULL;
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
                bullets[i]->target->health -= bullets[i]->damage;
                coins += 2;

                bullets[i]->destroyMe = true;
                explosionSound->play();
                if(bullets[i]->target->health <= 0){
                    bullets[i]->target->dead = true;
                }
                if(bullets[i]->target->dead){
                    for(unsigned int b = 0; b < bullets.size(); b++){
                        if(bullets[i]->target->getEntityId() == bullets[b]->target->getEntityId()){
                            if(bullets[i]->getEntityId() != bullets[b]->getEntityId()){
                                bullets[b]->lastKnownPos = bullets[i]->lastKnownPos;
                                bullets[b]->hasTarget = false;
                            }
                        }
                    }
                }
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
        if(enemies[i]->dead){
            removeEnemy(enemies[i]);
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
            if((towers[t]->target == NULL || towers[t]->target->dead )&& towers[t]->ready){
                towers[t]->target = target;
            }

            if(towers[t]->wantsToShoot && towers[t]->target != NULL && !towers[t]->target->dead){
                towers[t]->shootcounter = 0;
                towers[t]->wantsToShoot = false;
                Bullet* b;

                b = towers[t]->shoot();

                addEntity(b);
                b->layer = 4;
                b->hasTarget = true;
                bullets.push_back(b);
                shootSound->play();
            }
        }

    }

    for(unsigned int i = 0; i < busyWorkers.size(); i++){
        if(busyWorkers[i]->wantsCloud){
            SimpleEntity* c;
            c = new SimpleEntity();
            c->position = busyWorkers[i]->cloudpos;
            c->setPng("assets/Bouwwolkje.png");
            c->scale = Vector2(0.5f, 0.5f);
            addEntity(c);
            c->layer = 4;
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
    if(camera->position.y < 0){
        camera->position.y = 0;
    }

    if(camera->position.y > 1296-720){
        camera->position.y = 1296-720;
    }

    if(toolbarMustPop){
        if(toolbar->position.y > 720-62){
            toolbar->position.y -= 300*deltaTime;
        }
    }else{
        if(toolbar->position.y < 720+64){
            toolbar->position.y += 300*deltaTime;
        }
    }

}

void Mainscene::spawnEnemies(int number){
    for(unsigned int i = 0; i < number; i ++){
        Enemy* e;
        e = new Enemy();
        e->position = Vector2(801,-500);
        e->position.y -= 200*i;
        enemies.push_back(e);
        addEntity(e);
        e->layer = 2;
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

void Mainscene::removeTwinkle(Particle* p){
    std::vector< Particle* >::iterator it = twinkles.begin();
    while (it != twinkles.end()) {
        if ((*it)->getEntityId() == p->getEntityId()) {
            removeEntity((*it));
            delete (*it);
            (*it) = NULL;
            it = twinkles.erase(it);

        }else {
            ++it;
        }
    }
}
