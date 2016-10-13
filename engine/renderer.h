#ifndef RENDERER_H
#define RENDERER_H


// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <SDL.h>

#include <SDL_opengl.h>

#include <SDL_mixer.h>

#include <SDL_ttf.h>
// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>

#include <string>
#include <engine/shader.h>

#include <engine/camera.h>
#include <engine/renderer.h>

#include <engine/scene.h>
#include <engine/entity.h>
#include <engine/recoursemanager.h>
#include <engine/input.h>
#include <engine/hudobject.h>
#include <engine/text.h>
#include <engine/shape.h>
#include <time.h>
#include <sstream>
class Renderer{
public:
    Renderer();
    virtual ~Renderer();

    double dt;
    void renderScene(Scene* scene);

    bool mustStop();
    GLuint textureID;
    //The window we'll be rendering to
    SDL_Window* window;

    //OpenGL context
    SDL_GLContext gContext;
    int window_width;
    int window_height;
    glm::mat4 getModelMatrix(Vector2 pos, Vector2 scal, float rot);

    std::string fragment_shader;
    std::string vertex_shader;

    glm::mat4 ProjectionMatrix;
    glm::mat4 ViewMatrix;
    GLuint programID;
    GLuint matrixID;
    GLuint rfloat,gfloat,bfloat;
    GLuint alphafloat;
    GLuint uvoffset;
    GLuint vertexPosition_modelspaceID;
    GLuint vertexUVID;
    Recoursemanager* resman;
    SDL_DisplayMode mode;


    //The sound effects that will be used


    // variable declarations
    static Uint8 *audio_pos; // global pointer to the audio buffer to be played
    static Uint32 audio_len; // remaining length of the sample we have to play
    void renderEntity(glm::mat4& modelMatrix, Entity* entity, bool isHud);

    void updateDeltaTime();
    void displayFPS();
    void renderText(Text* t);
    void renderShape(Shape* s);

    Camera* camera;
private:
    double current_time;
    float fpscounter;
    int frames;
    Input* input;
    Text* fpsText;
    Text* timer;
    void devMode();
    bool devmodeon;
    float counter;

};



#endif
