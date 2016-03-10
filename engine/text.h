#ifndef TEXT_H
#define TEXT_H

#include <GL/glew.h>
#include <SDL.h>
#include <SDL_TTF.h>
#include <string>
#include <engine/vector2.h>
#include <engine/color.h>
class Text{
public:
    Text();
    virtual ~Text();

    int getHeight(){return this->h;}

    int getWidth(){return this->w;}

    int getFontSize(){return this->fontsize;}
    GLuint getGLuintData(){return this->GLuintData[0];}

    std::string getFontPath(){return this->fontPath;}

    std::string getCurMessage(){return this->curmessage;}
    std::string getLastMessage(){return this->lastmessage;}
    void setLastMessage(){lastmessage = getCurMessage();}
    GLuint getVtbuffer(){return vertexbuffer;}

    GLuint getUvbuffer(){return uvbuffer;}

    void setFont(const char* fontpath, int size);
    void setText(std::string message);

    int getTextId(){return this->textId;}
    Color color;
    Vector2 position;
    Vector2 scale;
    float rotation;
    bool isHud;
    void makeMesh();
    TTF_Font* f;

private:
    GLuint GLuintData[1];
    int w;
    int h;
    int fontsize;
    std::string fontPath;

    GLuint vertexbuffer;
    GLuint uvbuffer;
    SDL_Surface* sFont;
    std::string curmessage;
    std::string lastmessage;
    int textId;
    static int textIdCounter;
};



#endif
