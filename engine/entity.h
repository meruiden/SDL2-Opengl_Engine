#ifndef ENTITY_H
#define ENTITY_H


#include <engine/vector2.h>
#include <engine/input.h>
#include <engine/text.h>
#include <engine/color.h>
#include <vector>
class Entity{
public:
    Entity();
    virtual ~Entity();
    virtual void update(float deltaTime);
    void setTga(std::string imagepath);
    void setPng(std::string imagepath);
    Vector2 position;
    Vector2 scale;
    float rotation;
    int getEntityId(){return entityId;}
    std::vector<Entity*>getChildren(){return this->children;}
    Entity* parent;
    std::string getImgPath();
    void addChild(Entity* entity);
    void removeChild(Entity* entity);
    Input* input;
    void addText(Text* t);
    void removeText(Text* t);

    std::string getExtention(){return extention;}

    Color color;
private:
    std::string imagePath;
    std::string extention;
    std::vector<Entity*> children;
    int entityId;
    static int idCounter;

};



#endif
