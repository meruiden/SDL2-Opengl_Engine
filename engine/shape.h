#ifndef SHAPE_H
#define SHAPE_H

#include <GL/glew.h>
#include <vector>
#include <engine/vector2.h>
#include <glm/glm.hpp>
#include <engine/color.h>
#include <iostream>
class Shape
{
public:
    Shape();
    virtual ~Shape();
    void circle(float radius);
    GLuint getVtbuffer(){return vertexbuffer;}
    GLuint getUvbuffer(){return uvbuffer;}
    int numverts(){return _numverts;}
    GLuint texId(){return textureid;}
    bool isHud;
    Vector2 position;
    Vector2 scale;
    float rotation;
    Color color;
    int layer;

    int getShapeId(){return shapeId;}
private:
    GLuint vertexbuffer;
    GLuint textureid;
    GLuint uvbuffer;
    int _numverts;
    int shapeId;
    static int idCounter;
};

#endif
