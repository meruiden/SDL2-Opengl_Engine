#include "text.h"
#include <iostream>

int Text::textIdCounter = 0;

Text::Text(){
    this->layer = 1;
    this->fontsize = 0;
    this->curmessage = "";
    this->lastmessage = "";
    this->textId = textIdCounter;
    Text::textIdCounter ++;
    this->position = Vector2(0,0);
    this->scale = Vector2(1,1);
    this->rotation = 0.0f;
    this->isHud = false;
    this->w = 0;
    this->h = 0;
    this->GLuintData[0] = 0;
    this->f = NULL;
    this->sFont = NULL;
    this->color = Color();

    this->uvbuffer = 0;
    this->vertexbuffer = 0;


}

Text::~Text(){
    glDeleteBuffers(1, &vertexbuffer);
    glDeleteBuffers(1, &uvbuffer);
    if(GLuintData[0] != 0){
        glDeleteTextures(1, &GLuintData[0]);
    }
    if(sFont != NULL){
        SDL_FreeSurface(sFont);
        sFont = NULL;
    }
}

void Text::setFont(const char* fontpath, int size){
    this->fontPath = fontpath;
    this->fontsize = size;
}

void Text::setText(std::string message){
    this->curmessage = message;
}

void Text::makeMesh(){
    //this->curmessage = message;

    if(uvbuffer != 0 && vertexbuffer != 0){
        glDeleteBuffers(1, &uvbuffer);
        glDeleteBuffers(1, &vertexbuffer);
    }

    if(GLuintData[0] != 0){
        glDeleteTextures(1, &GLuintData[0]);
    }
    GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    SDL_Color c = {255, 255, 255, 0};
    sFont = TTF_RenderText_Blended_Wrapped(this->f, this->curmessage.c_str(), c, 1280);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, sFont->w, sFont->h, 0, GL_BGRA, GL_UNSIGNED_BYTE, sFont->pixels);

    this->GLuintData[0] = texture;
    this->w = sFont->w;
    this->h = sFont->h;

    int sprite_width = this->w;
    int sprite_height = this->h;
    GLfloat g_vertex_buffer_data[] = {
    0.5f * sprite_width, -0.5f * sprite_height, 0.0f,
    -0.5f * sprite_width, -0.5f * sprite_height, 0.0f,
    -0.5f * sprite_width,  0.5f * sprite_height, 0.0f,
    -0.5f * sprite_width,  0.5f * sprite_height, 0.0f,
    0.5f * sprite_width,  0.5f * sprite_height, 0.0f,
    0.5f * sprite_width, -0.5f * sprite_height, 0.0f
    };

    // Two UV coordinates for each vertex.
    GLfloat g_uv_buffer_data[] = {
    1.0f, 0.0f,
    0.0f, 0.0f,
    0.0f, 1.0f,
    0.0f, 1.0f,
    1.0f, 1.0f,
    1.0f, 0.0f
    };



    glGenBuffers(1, &vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

    glGenBuffers(1, &uvbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_uv_buffer_data), g_uv_buffer_data, GL_STATIC_DRAW);
    SDL_FreeSurface(sFont);
    sFont = NULL;
}
