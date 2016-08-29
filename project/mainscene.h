

#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <engine/scene.h>
#include <project/tower.h>
#include <project/enemy.h>
#include <engine/hudobject.h>
#include <engine/sound.h>
#include <project/worker.h>
#include <project/simpleentity.h>
#include <project/particle.h>
#include <sstream>
#include <engine/shape.h>
#include <project/towers/dogtower.h>
#include <project/towers/bunnytower.h>
#include <project/towers/turtletower.h>
#include <project/towers/robottower.h>
#include <project/menuitem.h>
#include <project/towers/icetower.h>
#include <project/enemies/duck.h>
#include <project/enemies/ufo.h>
#include <project/enemies/trol.h>
class Mainscene : public Scene{
public:
    Mainscene();
    virtual ~Mainscene();
    virtual void update(float deltaTime);

    Text* rangeText;
    Text* damageText;
    bool canPlace;
    bool toolbarMustPop;
    Shape* hudRangeIndicator;
    Text* coinsText;
    int coins;
    std::vector<Vector2> pathpoints;

    Sound* bgmusic;
    Vector2 scrollvel;
    Vector2 scrollacc;
    HudObject* chooseframe;

    void setMenuItems();
    bool lockBunny;
    std::vector<Enemy*> enemies;
    std::vector<Bullet*> bullets;
    std::vector<Tower*> towers;
    void spawnEnemy();
    void removeBullet(Bullet* b);
    void removeEnemy(Enemy* e);
    std::vector<Worker*> busyWorkers;
    std::vector<Worker*> readyWorkers;
    std::vector<SimpleEntity*> clouds;
    void removeCloud(SimpleEntity* e);
    bool assignWorker(Tower* tower);
    void clearWorker(Worker* worker);
    void reset();
    float wintimer;
    int enemiesToSpawn;
    bool waveEnd;
    int enemiesThisWave;
    int wave;
    HudObject* pricetag;
    Text* priceText;
    float spawnTimer;
    float waveTimer;
    Text* waveTimerText;
    double counter;
    void fixedUpdate();
    SimpleEntity* house;
    Text* waveText;
    HudObject* toolbar;
    Text* availableWorkersText;
    bool lockDog;
    bool captureMouseDistance;
    Vector2 mouseDistance;
    Vector2 lastDistance;
    Text* notEnoughText;
    float notenoughAlpha;
    HudObject* cursor;
    SimpleEntity* background;
    Shape* blackfader;
    std::vector<Particle*> twinkles;

    void removeTwinkle(Particle* p);
    void checkIfCanPlace();
    Tower* selectedTower;
    Text* upgradePriceText;
    void setToolBarContent(float range, int damage, int price);
    Text* upgradetxt;
    HudObject* upgradeBtn;
    HudObject* statusBarFrame;
    HudObject* statusBarAnger;
    HudObject* statusBarHappiness;
    bool canPlaceMenuItem(MenuItem* m);
    float dreamHealth;
    std::vector<MenuItem*> menuItems;
    void handleMenuItems();
    MenuItem* lockedItem;
    void init();
    bool usedInit;

    float tmpH;
    float tmpW;
private:

protected:

};

#endif
