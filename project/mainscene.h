#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <engine/scene.h>
#include <project/tower.h>
#include <project/enemy.h>
#include <engine/hudobject.h>
#include <engine/sound.h>

#include <sstream>
class Mainscene : public Scene{
public:
    Mainscene();
    virtual ~Mainscene();
    virtual void update(float deltaTime);

    std::vector<Vector2> pathpoints;
    Sound* geluidje;
    Vector2 scrollvel;
    Vector2 scrollacc;
    HudObject* chooseframe;
    HudObject* choosedog;
    std::vector<Enemy*> enemies;
    std::vector<Bullet*> bullets;
    Tower* tower;
    void spawnEnemies(int number);
    void removeBullet(Bullet* b);
    void removeEnemy(Enemy* e);

    Sound* shootSound;
    Sound* explosionSound;
    double counter;
    void fixedUpdate();


    bool lockDog;
private:

protected:

};

#endif
