#include "mainscene.h"

Mainscene::Mainscene() : Scene(){
    house = new SimpleEntity();
    house->setPng("assets/huis.png");
    addEntity(house);
    blackfader = new Shape();
    blackfader->position = Vector2(1000,1000);
    blackfader->layer = 3;
    addShape(blackfader);
    blackfader->square(2000,2000);
    blackfader->color = BLACK;
    blackfader->color.a = 0;
    blackfader->isHud = true;
    house->layer = 5;
    house->scale = Vector2(0.4f ,0.4f);
    house->position = Vector2(780, 1130);
    priceText = new Text();
    priceText->setFont("assets/Inder-Regular.ttf", 30);
    priceText->setText("50 coins");
    priceText->isHud = true;
    priceText->color = BLACK;
    priceText->scale = Vector2(0.9, 0.9);
    addText(priceText);
    SDL_ShowCursor(0);
    waveText = new Text();
    waveText->isHud = true;
    waveText->setFont("assets/Inder-Regular.ttf", 30);
    waveText->setText("Wave: 1");
    addText(waveText);
    waveText->position = Vector2(20, 20);
    wave = 0;
    enemiesToSpawn = 10;
    spawnTimer = 8;
    waveTimerText = new Text();
    waveTimerText->setFont("assets/agoestoesan.ttf", 100);

    waveTimerText->setText("8");
    waveTimerText->color = RED;
    waveTimerText->color.a = 0;
    addText(waveTimerText);
    waveTimerText->isHud = true;
    waveTimerText->position = Vector2(550, 720/2);

    setMenuItems();
    usedInit = false;
    canPlace = true;
    background = new SimpleEntity();
    addEntity(background);
    cursor = new HudObject();
    lockBunny = false;
    toolbarMustPop = false;
    cursor->setPng("assets/pointer.png");
    lockedItem = NULL;
    captureMouseDistance = false;
    dreamHealth = 100.0f;
    hudRangeIndicator = new Shape();
    hudRangeIndicator->isHud = true;
    hudRangeIndicator->color = Color(252, 61, 61, 100);
    damageText = new Text();
    damageText->setFont("assets/Inder-Regular.ttf", 30);
    damageText->setText("Damage: 5");
    damageText->isHud = true;
    addText(damageText);
    damageText->position = Vector2(300,750);
    background->setPng("assets/map_0-1.png");
    background->position = Vector2(1024/2, 1296/2);
    pathpoints.push_back(Vector2(804,- 50));
    pathpoints.push_back(Vector2(804,330));
    pathpoints.push_back(Vector2(474,330));
    pathpoints.push_back(Vector2(474,72));
    pathpoints.push_back(Vector2(210,72));
    pathpoints.push_back(Vector2(210,1063));
    pathpoints.push_back(Vector2(491,1063));
    pathpoints.push_back(Vector2(491,531));
    pathpoints.push_back(Vector2(790,531));
    pathpoints.push_back(Vector2(790,1286));

    for(unsigned int i = 0; i < 3; i++){
        Worker* worker = new Worker();
        worker->homePos = Vector2(490 + (130*i), 420);

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
    notEnoughText->setFont("assets/Inder-Regular.ttf", 40);
    notEnoughText->color = Color(255,0,0, 0);
    notEnoughText->isHud = true;
    coins = 100;
    coinsText = new Text();
    enemiesThisWave = 10;
    coinsText->isHud = true;
    coinsText->setFont("assets/Inder-Regular.ttf", 30);
    coinsText->setText("Coins: ");
    coinsText->position = Vector2(1280-230, 20);
    coinsText->scale = Vector2(0.5f, 0.5f);
    availableWorkersText = new Text();
    availableWorkersText->isHud = true;
    availableWorkersText->position =  Vector2(1280-230, 40);
    availableWorkersText->setFont("assets/Inder-Regular.ttf", 30);
    availableWorkersText->scale = Vector2(0.5f, 0.5f);
    waveTimer = 8;
    availableWorkersText->setText("Available Workers: 0");
    addText(availableWorkersText);
    addText(coinsText);
    rangeText = new Text();
    rangeText->setFont("assets/Inder-Regular.ttf", 30);
    rangeText->setText("Shooting range: 100");
    rangeText->isHud = true;
    addText(rangeText);
    rangeText->position = Vector2(300,750);
    scrollvel = Vector2();
    scrollacc = Vector2();
    counter = 0;
    bgmusic = new Sound("assets/sound/bg-music.wav");

    bgmusic->setVolume(15);

    chooseframe = new HudObject();
    chooseframe->setPng("assets/chooseframe.png");
    addHudObject(chooseframe);
    chooseframe->position = Vector2(1280-256/2, 720/2);

    toolbar = new HudObject();
    toolbar->setPng("assets/toolbar.png");
    toolbar->position = Vector2(520, 720+(64));
    toolbar->scale = Vector2(2,2);
    addHudObject(toolbar);
    lockDog = false;
    notenoughAlpha = 0;
    cursor->scale = Vector2(0.1f, 0.1f);
    cursor->layer = 4;

    addHudObject(cursor);
    statusBarAnger = new HudObject();
    statusBarAnger->setPng("assets/status_bar_anger.png");
    addHudObject(statusBarAnger);
    statusBarAnger->position = Vector2(440,18);
    statusBarAnger->scale = Vector2(0.92f, 1);

    statusBarHappiness = new HudObject();
    statusBarHappiness->setPng("assets/status_bar_happiness.png");
    addHudObject(statusBarHappiness);
    statusBarHappiness->position = Vector2(620,18);
    statusBarHappiness->scale = Vector2(0.92f, 1);
    statusBarFrame = new HudObject();
    statusBarFrame->setPng("assets/status_bar_frame.png");
    addHudObject(statusBarFrame);
    statusBarFrame->position = Vector2(530, 18);

    statusBarAnger->uvOffset = Vector2(-0.5f, 0);
    upgradeBtn = new HudObject();
    upgradeBtn->position.y = 3000;
    addHudObject(upgradeBtn);
    upgradeBtn->scale = Vector2(0.7f, 0.7f);
    upgradeBtn->setPng("assets/upgrade_button.png");
    upgradetxt = new Text();
    upgradetxt->setFont("assets/Inder-Regular.ttf", 30);
    upgradetxt->isHud = true;
    upgradetxt->setText("Upgrade");
    addText(upgradetxt);

    upgradePriceText = new Text();
    upgradePriceText->isHud = true;
    upgradePriceText->setFont("assets/Inder-Regular.ttf", 30);
    upgradePriceText->setText("Upgrade Price: 10");
    addText(upgradePriceText);
    pricetag = new HudObject();
    pricetag->setPng("assets/pricetag.png");
    addHudObject(pricetag);
    pricetag->position = Vector2(-1000, -1000);
    pricetag->scale = Vector2(0.8, 0.8);
    tmpH = 100;
    tmpW = 100;
    waveEnd = true;

}

Mainscene::~Mainscene(){
    delete upgradetxt;
    delete background;
    delete toolbar;
    delete chooseframe;
    delete bgmusic;
    delete availableWorkersText;
    delete coinsText;
    delete notEnoughText;
    delete cursor;
    delete hudRangeIndicator;
    delete rangeText;
    delete damageText;
    delete statusBarFrame;
    delete statusBarAnger;
    delete statusBarHappiness;
    delete upgradeBtn;
    delete upgradePriceText;
    delete pricetag;
    delete priceText;
    delete house;
    delete waveText;
    delete waveTimerText;
    delete blackfader;
    selectedTower = NULL;
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

    for(unsigned int i = 0; i < menuItems.size(); i++){
        removeHudObject(menuItems[i]);
        delete menuItems[i];
        menuItems[i] = NULL;

    }
    menuItems.clear();



}

void Mainscene::update(float deltaTime){

    if(enemiesToSpawn > 0 && !waveEnd){
        spawnTimer += deltaTime;
    }else{

        if(waveEnd){
            spawnTimer = 0;
            waveTimer -= deltaTime;
            waveTimerText->color.a = 255;
            std::ostringstream wts;
            wts << (int)waveTimer;
            waveTimerText->setText(wts.str());
            if(waveTimer <= 0){
                wave ++;
                std::ostringstream ws;
                ws << "Wave: ";
                ws << wave;
                waveText->setText(ws.str());
                waveTimerText->color.a = 0;
                waveTimer = 8;
                if(wave > 1){
                    enemiesToSpawn = 10+(2*wave);
                    enemiesThisWave = enemiesToSpawn;
                }
                waveEnd = false;
                spawnEnemy();
                enemiesToSpawn --;
            }
        }
    }
    if(spawnTimer >= 4.0f){
        spawnEnemy();
        spawnTimer = 0;
        enemiesToSpawn --;

    }
    if(!usedInit){
        usedInit = true;
        init();
    }
    if(enemies.size() == 0 ){
        waveEnd = true;
    }
    handleMenuItems();
    upgradeBtn->position =  Vector2(740,toolbar->position.y);
    upgradetxt->position = upgradeBtn->position+Vector2(-upgradetxt->getWidth()/2,0);
    upgradePriceText->position = Vector2(200,toolbar->position.y+30);

    rangeText->position = Vector2(200,toolbar->position.y-30);
    damageText->position = Vector2(200,toolbar->position.y);

    cursor->position = input->getMouseToScreen()+(Vector2(3,cursor->height()*cursor->scale.y-15));
    if(input->getMouseButton(1)){
        cursor->setPng("assets/pointerClick.png");
    }else{
        cursor->setPng("assets/pointer.png");
    }
    if(input->getMouseToScreen().y > 640 && !toolbar->mouseOver()){
        camera->position.y += (((input->getMouseToScreen().y - 640)/100)*400)*deltaTime;
    }

    if(input->getMouseToScreen().y < 80){
        camera->position.y -= (((80-input->getMouseToScreen().y)/100)*400)*deltaTime;
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
    priceText->position = pricetag->position+Vector2(-80, 10);

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
    pricetag->position = Vector2(-1000, -1000);
    for(unsigned int i = 0; i < menuItems.size(); i++){
        if(menuItems[i]->mouseOver() && lockedItem == NULL){
            std::ostringstream ct;
            ct << menuItems[i]->price;
            ct << " coins";
            priceText->setText(ct.str());
            pricetag->position = Vector2(menuItems[i]->position.x-180, menuItems[i]->position.y);
        }
    }

    if(input->getKeyDown(SDLK_c)){
        coins += 10;
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
                bullets[i]->target->slowness += bullets[i]->slowingDamage;
                coins += 2;

                bullets[i]->destroyMe = true;
                bullets[i]->explodeSound->play();
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
    int enemycounter = 0;
    for(unsigned int i = 0; i < enemies.size(); i ++){
        if(enemies[i]->dead){
            enemycounter ++;
        }
        if(enemies[i]->atTarget){
            if(pathpoints.size()-1 > (unsigned)enemies[i]->currPathPoint){
                enemies[i]->atTarget = false;
                enemies[i]->currPathPoint ++;
                enemies[i]->curtarget = pathpoints[enemies[i]->currPathPoint];
            }
        }
        if(enemies[i]->atTarget ){
            if(enemies[i]->dead){
                dreamHealth += 3;
            }else{
                dreamHealth -= 10;
            }

            removeEnemy(enemies[i]);
        }
    }


    if(enemycounter == enemiesThisWave  && enemies.size() > 0){
        for(unsigned int i = 0; i < enemies.size(); i ++){
            if(enemies[i]->dead){
                enemies[i]->speed = 400;
            }
        }
    }

    for(unsigned int i = 0; i < bullets.size(); i++){
        if(bullets[i]->destroyMe){
            removeBullet(bullets[i]);
        }
    }

    if(towers.size() > 0 && enemies.size() > 0){
        Enemy* target = NULL;
        for(unsigned int i = 0; i < enemies.size(); i++){
            if(!enemies[i]->dead){
                target = enemies[i];
                i = enemies.size();
            }
        }


        for(unsigned int t = 0; t < towers.size(); t++){
            for(unsigned int i = 0;  i  < enemies.size(); i ++){
                if(!enemies[i]->dead ){
                    bool canpass = false;
                    if(towers[t]->slowingDamage > 0 && towers[t]->damage == 0 && enemies[i]->slowness < 60){
                        canpass = true;

                    }
                    if(towers[t]->slowingDamage == 0){
                        canpass = true;
                    }

                    if(canpass){
                        Vector2 curdisvec = Vector2(target->position, towers[t]->position);
                        Vector2 disvec = Vector2(enemies[i]->position, towers[t]->position);
                        if(disvec.magnitude() < curdisvec.magnitude()){
                            target = enemies[i];
                        }

                    }

                }
            }
            if((towers[t]->target == NULL || (towers[t]->target->dead ))&& towers[t]->ready){
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
                towers[t]->shootSound->play();
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
        if(toolbar->position.y > 720-60){
            toolbar->position.y -= 300*deltaTime;
        }
    }else{
        if(toolbar->position.y < 720+64){
            toolbar->position.y += 300*deltaTime;
        }
    }

    if(input->getMouseButtonDown(1)){
        if(!toolbar->mouseOver()){
            for(unsigned int i = 0; i < towers.size(); i++){
                removeShape(towers[i]->shootingRangeShape);

            }
        }
        if(upgradeBtn->mouseOver() && selectedTower->level < 5 && coins-selectedTower->upgradePrice >= 0){
            coins -= selectedTower->upgradePrice;
            selectedTower->upgrade();
            setToolBarContent(selectedTower->shootingRange, selectedTower->damage, selectedTower->upgradePrice);
            if(selectedTower->level < 5){
                upgradeBtn->color = WHITE;
            }else{
                upgradeBtn->color = GREY;
                upgradeBtn->color.a = 100;
            }
        }else{
            if(upgradeBtn->mouseOver() && selectedTower->level < 5 && coins-selectedTower->upgradePrice <= 0){
                notenoughAlpha = 255;
                notenoughAlpha = 255.0f;
                notEnoughText->position.y = 720/2;
            }
        }

    }

    if(dreamHealth == 200){
        for(unsigned int i = 0; i < enemies.size(); i++){
            enemies[i]->speed = 0;
            enemies[i]->health = 0;
        }

        wintimer += deltaTime;

        if(wintimer >= 1){
            blackfader->color.a += deltaTime*100;
            if(blackfader->color.a >= 255){
                reset();
                this->nextScene = true;
                blackfader->color.a = 0;
                wintimer = 0;
                bgmusic->stop();
                usedInit = false;
            }
        }
    }else if(dreamHealth == 0){
        reset();
    }
    upgradetxt->color = upgradeBtn->color;
    for(unsigned int i = 0; i < towers.size(); i++){
        if(input->getMouseButtonDown(1)){
            if(Vector2(input->getMouseToWorld(camera), towers[i]->position).magnitude() < 30 && towers[i]->ready){
                towers[i]->shootingRangeShape->circle(towers[i]->shootingRange);
                addShape(towers[i]->shootingRangeShape);
                toolbarMustPop = true;
                setToolBarContent(towers[i]->shootingRange, towers[i]->damage, towers[i]->upgradePrice);
                selectedTower = towers[i];
                if(selectedTower->level < 5){
                    upgradeBtn->color = WHITE;
                }else{
                    upgradeBtn->color = GREY;
                    upgradeBtn->color.a = 100;
                }
                i = towers.size();
            }else{
                if(!toolbar->mouseOver()){
                    toolbarMustPop = false;
                }

            }
        }
    }

    if(lockedItem != NULL ){
        if(canPlaceMenuItem(lockedItem)){
            lockedItem->color.g = 255;
            lockedItem->color.b = 255;
        }else{
            lockedItem->color.g = 50;
            lockedItem->color.b = 50;
        }
    }
    if(dreamHealth > 200){
        dreamHealth = 200;
    }

    if(dreamHealth < 0){
        dreamHealth = 0;
    }

    if(dreamHealth > 100.0f){
        statusBarHappiness->uvOffset = Vector2(((1.0f/100)*(-(dreamHealth-100))+1), 0);
        statusBarAnger->uvOffset = Vector2(-1, 0);
    }else if(dreamHealth < 100.0f){
        statusBarHappiness->uvOffset = Vector2(1, 0);
        statusBarAnger->uvOffset = Vector2(-(1.0f/100.0f)*dreamHealth, 0);
    }else{
        statusBarHappiness->uvOffset = Vector2(1, 0);
        statusBarAnger->uvOffset = Vector2(-1, 0);
    }

}

void Mainscene::spawnEnemy(){
    Enemy* e;
    float r = rand() % 100;
    if(r > 90 && wave > 2){
        e = new Ufo();
        e->speed = 140;
    }else if(r > 80 && r < 90 && wave > 2){
        e = new Trol();
        e->health = 200;
        e->speed = 30;
    }else{
        e = new Duck();
    }
    if(wave > 1){
        e->speed += 30*wave;
        e->health += 5*wave;
    }
    e->position = Vector2(801,-50);
    enemies.push_back(e);
    addEntity(e);
    e->layer = 2;
    e->dead = false;
    e->curtarget = pathpoints[0];
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

void Mainscene::setToolBarContent(float range, int damage, int price){
    std::ostringstream ss;
    ss << "Shooting range: ";
    ss << range;
    rangeText->setText(ss.str());
    ss.str("");
    ss.clear();
    ss << "Damage: ";
    ss << damage;
    damageText->setText(ss.str());

    ss.str("");
    ss.clear();
    ss << "Upgrade price: ";

    ss << price;
    upgradePriceText->setText(ss.str());

}

void Mainscene::handleMenuItems(){

    for(unsigned int i = 0; i < menuItems.size(); i++){

        if(menuItems[i] != NULL){
            if(input->getMouseToScreen().x < menuItems[i]->position.x + 50 && input->getMouseToScreen().x > menuItems[i]->position.x - 50
                && input->getMouseToScreen().y < menuItems[i]->position.y + 50 && input->getMouseToScreen().y > menuItems[i]->position.y - 50){
                if(input->getMouseButtonDown(1)){
                    addShape(hudRangeIndicator);
                    hudRangeIndicator->circle(menuItems[i]->range);
                    lockedItem = menuItems[i];
                }
                if(menuItems[i]->hoverImgPath != ""){
                    menuItems[i]->setPng(menuItems[i]->hoverImgPath.c_str());
                }
            }else{
                if(menuItems[i]->notHoverImgPath != ""){
                    menuItems[i]->setPng(menuItems[i]->notHoverImgPath.c_str());
                }
            }
        }

        menuItems[i]->scale = menuItems[i]->unselectedScale;
        menuItems[i]->position = Vector2(1280-menuItems[i]->offsetpos.x, chooseframe->position.y - menuItems[i]->offsetpos.y);

    }



    if(lockedItem != NULL){
        lockedItem->scale = lockedItem->selectedScale;
        lockedItem->position = input->getMouseToScreen();
        hudRangeIndicator->position = lockedItem->position;
    }

    if(input->getMouseButtonUp(1) && lockedItem != NULL ){
        removeShape(hudRangeIndicator);
        Tower* tower;
        switch(lockedItem->spawnId){
            case 1:
                tower = new BunnyTower();
            break;

            case 2:
                tower = new DogTower();
            break;

            case 3:
                tower = new IceTower();
            break;

            case 4:
                tower = new TurtleTower();
            break;

            case 5:
                tower = new RobotTower();
            break;
        }
        addEntity(tower);
        tower->layer = 2;
        tower->position = input->getMouseToWorld(camera);
        if(lockedItem->position.x < (chooseframe->position.x-(chooseframe->width()/2)) && canPlaceMenuItem(lockedItem)){
            if((coins-lockedItem->price) >= 0){
                if(!assignWorker(tower)){
                    removeEntity(tower);
                    delete tower;
                    tower = NULL;
                }else{
                    towers.push_back(tower);
                    coins -= lockedItem->price;

                }
            }else{
                notEnoughText->setText("Not enough coins!!");
                notenoughAlpha = 255.0f;
                notEnoughText->position.y = 720/2;
                removeEntity(tower);
                delete tower;
                tower = NULL;

            }
            lockedItem->color.g = 255;
            lockedItem->color.b = 255;
            lockedItem = NULL;
        }else{
            notenoughAlpha = 255.0f;

            notEnoughText->setText("Tower can't be placed here!");
            removeEntity(tower);
            delete tower;
            tower = NULL;
            lockedItem->color.g = 255;
            lockedItem->color.b = 255;
            lockedItem = NULL;
        }
    }
}

void Mainscene::setMenuItems(){
    MenuItem* item = new MenuItem(1);
    menuItems.push_back(item);
    item->offsetpos = Vector2(128, 100);
    item->unselectedScale = Vector2(0.15, 0.15);
    item->selectedScale = Vector2(0.22, 0.22);
    item->range = 250.0f;
    item->price = 100;
    item->notHoverImgPath = "assets/towers/konijn.png";
    item->setPng(item->notHoverImgPath.c_str());
    addHudObject(item);
    item->layer = 2;

    item = NULL;
    item = new MenuItem(2);
    item->offsetpos = Vector2(125, 230);
    menuItems.push_back(item);
    item->range = 200.0f;
    item->price = 80;
    item->notHoverImgPath = "assets/towers/hondje_sleeping.png";
    item->setPng(item->notHoverImgPath.c_str());
    item->hoverImgPath = "assets/towers/hondje_active.png";
    addHudObject(item);
    item->unselectedScale = Vector2(0.35, 0.35);
    item->selectedScale = Vector2(0.5, 0.5);
    item->layer = 2;

    item = NULL;
    item = new MenuItem(3);
    item->offsetpos = Vector2(125, -25);
    menuItems.push_back(item);
    item->range = 130.0f;
    item->price = 110;
    item->notHoverImgPath = "assets/towers/mrcone.png";
    item->setPng(item->notHoverImgPath.c_str());
    addHudObject(item);
    item->unselectedScale = Vector2(0.15, 0.15);
    item->selectedScale = Vector2(0.2, 0.2);
    item->layer = 2;

    item = NULL;
    item = new MenuItem(4);
    item->offsetpos = Vector2(125, -155);
    menuItems.push_back(item);
    item->range = 200.0f;
    item->price = 140;
    item->notHoverImgPath = "assets/towers/turtle_menu.png";
    item->setPng(item->notHoverImgPath.c_str());
    addHudObject(item);
    item->unselectedScale = Vector2(0.33, 0.33);
    item->selectedScale = Vector2(0.5, 0.5);
    item->layer = 2;

    item = NULL;
    item = new MenuItem(5);
    item->offsetpos = Vector2(125, -280);
    menuItems.push_back(item);
    item->range = 500.0f;
    item->price = 140;
    item->notHoverImgPath = "assets/towers/robot.png";
    item->setPng(item->notHoverImgPath.c_str());
    addHudObject(item);
    item->unselectedScale = Vector2(0.22, 0.22);
    item->selectedScale = Vector2(0.3, 0.3);
    item->layer = 2;
}

bool Mainscene::canPlaceMenuItem(MenuItem* m){

    for(unsigned int i = 0; i < towers.size(); i++){
        if(Vector2(m->getPosToWorld(camera), towers[i]->position).magnitude() < 70){
            return false;
        }
    }
    for(unsigned int i = 0; i < pathpoints.size()-1; i++){
            bool canfalse = true;
            Vector2 a = pathpoints[i];
            Vector2 b = pathpoints[i + 1];

            Vector2 normal = Vector2::getNormalPoint(m->getPosToWorld(camera), a, b);
            float distance = Vector2(m->getPosToWorld(camera), normal).magnitude();

            if(a.x < b.x && normal.x < a.x){
                canfalse = false;
            }

            if(a.y < b.y && normal.y < a.y){
                canfalse = false;
            }

            if(a.x < b.x && normal.x > b.x){
                canfalse = false;
            }

            if(a.y < b.y && normal.y > b.y){
                canfalse = false;
            }

            if(b.x < a.x && normal.x < b.x){
                canfalse = false;
            }

            if(b.y < a.y && normal.y < b.y){
                canfalse = false;
            }

            if(b.x < a.x && normal.x > a.x){
                canfalse = false;
            }

            if(b.y < a.y && normal.y > a.y){
                canfalse = false;
            }

            if (distance < 80 && canfalse){
                return false;
            }

    }
    return true;
}

void Mainscene::reset(){
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
    bullets.clear();

    lockedItem = NULL;
    dreamHealth = 100;
    coins = 100;

    wave = 0;
    enemiesToSpawn = 10;
    waveEnd = true;

}

void Mainscene::init(){
    bgmusic->play(true);

}
