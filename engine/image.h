#ifndef IMAGE_H
#define IMAGE_H
#include <stdio.h>
#include <stdlib.h>
#include <string>

#include <GL/glew.h>
#include <SDL.h>
#include <SDL_image.h>



class Image{
public:
    Image();
    virtual ~Image();

    int getHeight();
    int getWidth();
    GLuint getGLuintData();

    void loadTGA(std::string ip);
    void loadPNG(std::string ip);
    std::string getImgPath();

    GLuint getVtbuffer(){return vertexbuffer;}

    GLuint getUvbuffer(){return uvbuffer;}
private:
    GLuint GLuintData[1];
    int w;
    int h;
    std::string imgPath;

    GLuint vertexbuffer;
    GLuint uvbuffer;
};



#endif
