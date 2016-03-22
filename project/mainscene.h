

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
#include <project/towers/dogTower.h>
#include <project/towers/bunnyTower.h>

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
    Sound* geluidje;
    Sound* bgmusic;
    Vector2 scrollvel;
    Vector2 scrollacc;
    HudObject* chooseframe;
    HudObject* choosedog;
    HudObject* choosebunny;
    bool lockBunny;
    std::vector<Enemy*> enemies;
    std::vector<Bullet*> bullets;
    std::vector<Tower*> towers;
    void spawnEnemies(int number);
    void removeBullet(Bullet* b);
    void removeEnemy(Enemy* e);
    std::vector<Worker*> busyWorkers;
    std::vector<Worker*> readyWorkers;
    std::vector<SimpleEntity*> clouds;
    void removeCloud(SimpleEntity* e);
    bool assignWorker(Tower* tower);
    void clearWorker(Worker* worker);
    Sound* shootSound;
    Sound* explosionSound;
    double counter;
    void fixedUpdate();
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

    std::vector<Particle*> twinkles;

    void removeTwinkle(Particle* p);
    void checkIfCanPlace();

    void setToolBarContent(float range, int damage);
private:

protected:

};

#endif
