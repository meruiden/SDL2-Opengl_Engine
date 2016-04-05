#include "renderer.h"

Renderer::Renderer(){
    srand (time(NULL));

    counter = 0.0f;
    devmodeon = false;
    if( SDL_Init( SDL_INIT_EVERYTHING ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        return;
    }

    window_width = 1280;
    window_height = 720;
    frames = 0;
    fpscounter = 0.0f;
    fragment_shader	= "shaders/sprite.frag";
    vertex_shader	= "shaders/sprite.vert";

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

    // Open a window and create its OpenGL context
    window = SDL_CreateWindow(
     "Dream Defenders",
     SDL_WINDOWPOS_UNDEFINED,
     SDL_WINDOWPOS_UNDEFINED,
     window_width,
     window_height,
     SDL_WINDOW_OPENGL
    );


    if( window == NULL )
    {
       printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
       return;
   }
   //Create context
    gContext = SDL_GL_CreateContext( window );
    if( gContext == NULL )
    {
        printf( "OpenGL context could not be created! SDL Error: %s\n", SDL_GetError() );
        return;
    }


    //Intialize OpenGL
    GLenum error = GL_NO_ERROR;

     //Initialize Projection Matrix
     glMatrixMode( GL_PROJECTION );
     glLoadIdentity();

     //Check for error
     error = glGetError();
     if( error != GL_NO_ERROR )
     {
         std::cout << "Error initializing OpenGL! \n";
         return;
     }

     //Initialize Modelview Matrix
     glMatrixMode( GL_MODELVIEW );
     glLoadIdentity();

     //Check for error
     error = glGetError();
     if( error != GL_NO_ERROR )
     {
         std::cout << "Error initializing OpenGL! \n";
         return;
     }
    // Initialize GLEW
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
        return;
    }

    // Dark blue background
    glClearColor(101/255.0f, 121/255.0f, 98/255.0f, 0.0f);

    // Cull triangles which normal is not towards the camera
    glEnable(GL_CULL_FACE);

    // Create and compile our GLSL program from the shaders
    // see: shader.h/cpp
    programID = loadShaders(vertex_shader.c_str(), fragment_shader.c_str());

    // Get a handle for our buffers
    vertexPosition_modelspaceID = glGetAttribLocation(programID, "vertexPosition_modelspace");
    vertexUVID = glGetAttribLocation(programID, "vertexUV");

    alphafloat =  glGetUniformLocation(programID, "alpha");
    rfloat = glGetUniformLocation(programID, "r");
    gfloat = glGetUniformLocation(programID, "g");
    bfloat = glGetUniformLocation(programID, "b");
    uvoffset = glGetUniformLocation(programID, "uvOffset");
    // Get a handle for our "MVP" uniform
    matrixID = glGetUniformLocation(programID, "MVP");
    // Get a handle for our "myTextureSampler" uniform
    textureID  = glGetUniformLocation(programID, "myTextureSampler");

    // Load the texture (see: texture.h/cpp)

    ProjectionMatrix = glm::ortho(0.0f, (float)window_width, (float)window_height, 0.0f, 0.1f, 100.0f);



    // start SDL with audio support
    if(SDL_Init(SDL_INIT_AUDIO)==-1) {
        printf("SDL_Init: %s\n", SDL_GetError());
    }

    int imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) )
    {
        printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
        return;
    }
    // open 44.1KHz, signed 16bit, system byte order,
    //      stereo audio, using 1024 byte chunks
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024)==-1) {
        printf("Mix_OpenAudio: %s\n", Mix_GetError());
    }
    Mix_AllocateChannels(70);

    SDL_GL_SetSwapInterval(0);
    TTF_Init();

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable( GL_BLEND );

    resman = new Recoursemanager();
    input = new Input();
    camera = new Camera();

    timer = new Text();
    fpsText = new Text();

    timer->setFont("assets/PrintClearly.ttf", 70);
    timer->setText("Time: 0");
    timer->position = Vector2(20,40);

    fpsText->setFont("assets/PrintClearly.ttf", 70);
    fpsText->setText("FPS: 0");
    fpsText->position = Vector2(20,100);

    timer->isHud = true;
    fpsText->isHud = true;

    std::cout << "Press F10 to view fps and time" << std::endl;

}

void Renderer::renderScene(Scene* scene){
        // Clear the screen
        int xx;
        int yy;
        SDL_GetWindowSize(window, &xx, &yy);
        window_width = xx;
        window_height = yy;

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        scene->window_width = this->window_width;
        scene->window_height = this->window_height;
        this->input->window_width = this->window_width;
        this->input->window_height= this->window_height;

        displayFPS();
        updateDeltaTime();
        counter += dt;

        scene->input = input;
        scene->camera = camera;

        for(unsigned int i = 0; i < scene->entities.size(); i ++){
            scene->entities[i]->input = input;
            for(unsigned int a = 0; a < scene->entities[i]->getChildren().size(); a++){
                if(!scene->hasEntity(scene->entities[i]->getChildren()[a])){
                    scene->entities[i]->getChildren()[a]->input = input;
                    scene->entities[i]->getChildren()[a]->update(dt);
                }
            }
            scene->entities[i]->update(dt);
        }


        for(unsigned int i = 0; i < scene->hudObjects.size(); i ++){
            scene->hudObjects[i]->input = input;
            for(unsigned int a = 0; a < scene->hudObjects[i]->getChildren().size(); a++){
                if(!scene->hasEntity(scene->hudObjects[i]->getChildren()[a])){
                    scene->hudObjects[i]->getChildren()[a]->input = input;
                    scene->hudObjects[i]->getChildren()[a]->update(dt);
                }
            }
            scene->hudObjects[i]->update(dt);
        }

        input->update();
        scene->update(dt);


        camera->computeMatricesFromInputs(dt);

        ViewMatrix = camera->getViewMatrix();

        //render all entities, hudObjects, shapes and texts
        int curlayer = 1;
        bool needHigherLayer = true;
        do{
            needHigherLayer = false;
            for(unsigned int i = 0; i < scene->entities.size(); i ++){
                glm::mat4 mm = glm::mat4(1.0f);
                if(scene->entities[i]->parent == NULL && scene->entities[i]->layer == curlayer){
                    renderEntity(mm, scene->entities[i], false);
                }

                if(scene->entities[i]->parent == NULL && scene->entities[i]->layer > curlayer){
                    needHigherLayer = true;
                }
            }

            for(unsigned int i = 0; i < scene->texts.size(); i ++){
                if(scene->texts[i] != NULL && !scene->texts[i]->isHud && scene->texts[i]->layer == curlayer){
                    renderText(scene->texts[i]);
                }

                if(scene->texts[i] != NULL && !scene->texts[i]->isHud && scene->texts[i]->layer > curlayer){
                    needHigherLayer = true;
                }
            }

            for(unsigned int i = 0; i < scene->shapes.size(); i ++){
                if(scene->shapes[i] != NULL && !scene->shapes[i]->isHud && scene->shapes[i]->layer == curlayer){
                    renderShape(scene->shapes[i]);
                }

                if(scene->shapes[i] != NULL && !scene->shapes[i]->isHud && scene->shapes[i]->layer > curlayer){
                    needHigherLayer = true;
                }
            }
            curlayer++;
        }while(needHigherLayer);

        curlayer = 1;
        needHigherLayer = true;

        do{

            needHigherLayer = false;
            for(unsigned int i = 0; i < scene->hudObjects.size(); i ++){
                glm::mat4 mm = glm::mat4(1.0f);
                if(scene->hudObjects[i]->parent == NULL && scene->hudObjects[i]->layer == curlayer){
                    renderEntity(mm, scene->hudObjects[i], true);

                }

                if(scene->hudObjects[i]->parent == NULL && scene->hudObjects[i]->layer > curlayer){
                    needHigherLayer = true;

                }
            }

            for(unsigned int i = 0; i < scene->texts.size(); i ++){
                if(scene->texts[i] != NULL && scene->texts[i]->isHud && scene->texts[i]->layer == curlayer){
                    renderText(scene->texts[i]);

                }

                if(scene->texts[i] != NULL && scene->texts[i]->isHud && scene->texts[i]->layer > curlayer){
                    needHigherLayer = true;

                }
            }

            for(unsigned int i = 0; i < scene->shapes.size(); i ++){
                if(scene->shapes[i] != NULL && scene->shapes[i]->isHud && scene->shapes[i]->layer == curlayer){
                    renderShape(scene->shapes[i]);
                }

                if(scene->shapes[i] != NULL && scene->shapes[i]->isHud && scene->shapes[i]->layer > curlayer){
                    needHigherLayer = true;
                }
            }
            curlayer ++;

        }while(needHigherLayer);

        std::ostringstream ss;
        ss << "Time: ";
        float roundedtime = counter;
        roundedtime = roundf(roundedtime * 100) / 100;
        ss <<  roundedtime;
        timer->setText(ss.str());

        devMode();

        SDL_GL_SwapWindow(window);
}



void Renderer::renderEntity(glm::mat4& modelMatrix, Entity* entity, bool isHud){

    if(entity->getImgPath() != "NULL" && entity->getImgPath() != "" && entity->getImgPath() != " " ){

        Image* img;
        img = NULL;
        modelMatrix *= getModelMatrix(entity->position, entity->scale, entity->rotation);
        if(entity->getExtention() == "tga"){
            img = resman->getImage(entity->getImgPath(), true);
        }
        if(entity->getExtention() == "png"){
            img = resman->getImage(entity->getImgPath(), false);
        }
        if(img == NULL){
            return;
        }

        entity->width(img->getWidth());
        entity->height(img->getHeight());

        if(img->getImgPath() != "NULL" && img->getImgPath() != "" && img->getImgPath() != " "){
            // Use our shader
            glm::mat4 MVP;
            glUseProgram(programID);
            if(isHud){
                glm::mat4 vm = glm::lookAt(
                        glm::vec3(0, 0, 5), // Camera is at (xpos,ypos,5), in World Space
                        glm::vec3(0, 0, 0), // and looks towards Z
                        glm::vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
                        );
                MVP = ProjectionMatrix * vm * modelMatrix;
            }else{
                MVP = ProjectionMatrix * ViewMatrix * modelMatrix;
            }



            // Send our transformation to the currently bound shader,
            // in the "MVP" uniform
            glUniformMatrix4fv(matrixID, 1, GL_FALSE, &MVP[0][0]);
            glUniform2f(uvoffset, entity->uvOffset.x, entity->uvOffset.y);
            glUniform1f(alphafloat, (float)entity->color.a/255.0f);
            glUniform1f(rfloat, (float)entity->color.r/255.0f);
            glUniform1f(gfloat, (float)entity->color.g/255.0f);
            glUniform1f(bfloat, (float)entity->color.b/255.0f);
            // Bind our texture in Texture Unit 0
            glActiveTexture(GL_TEXTURE0);

            glBindTexture(GL_TEXTURE_2D, img->getGLuintData());
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            // Set our "myTextureSampler" sampler to user Texture Unit 0
            glUniform1i(textureID, 0);

            // 1st attribute buffer : vertices
            glEnableVertexAttribArray(vertexPosition_modelspaceID);
            glBindBuffer(GL_ARRAY_BUFFER, img->getVtbuffer());
            glVertexAttribPointer(
                                  vertexPosition_modelspaceID,  // The attribute we want to configure
                                  3,                            // size : x+y+z => 3
                                  GL_FLOAT,                     // type
                                  GL_FALSE,                     // normalized?
                                  0,                            // stride
                                  (void*)0                      // array buffer offset
                                  );

            // 2nd attribute buffer : UVs
            glEnableVertexAttribArray(vertexUVID);
            glBindBuffer(GL_ARRAY_BUFFER, img->getUvbuffer());
            glVertexAttribPointer(
                                  vertexUVID,                   // The attribute we want to configure
                                  2,                            // size : U+V => 2
                                  GL_FLOAT,                     // type
                                  GL_FALSE,                     // normalized?
                                  0,                            // stride
                                  (void*)0                      // array buffer offset
                                  );

            // Draw the triangles !

            glDrawArrays(GL_TRIANGLES, 0, 2*3); // 2*3 indices starting at 0 -> 2 triangles

            glDisableVertexAttribArray(vertexPosition_modelspaceID);
            glDisableVertexAttribArray(vertexUVID);
        }
    }

    // Render all Children (recursively)
    std::vector<Entity*> children = entity->getChildren();
    std::vector<Entity*>::iterator child;
    for (child = children.begin(); child != children.end(); child++) {
        
        if((*child)->parent != NULL){
              modelMatrix = this->getModelMatrix( (*child)->parent->position,  (*child)->parent->scale, (*child)->parent->rotation);
        }else{
              modelMatrix = this->getModelMatrix(entity->position, entity->scale, entity->rotation);
        }
        
        this->renderEntity(modelMatrix, *child, isHud);
    }
}

glm::mat4 Renderer::getModelMatrix(Vector2 pos, Vector2 scal, float rot){
	// OpenGL doesn't understand our Vector2. Make it glm::vec3 compatible.
	glm::vec3 position = glm::vec3(pos.x, pos.y, 0.0f);
	glm::vec3 rotation = glm::vec3(0.0f, 0.0f, rot);
	glm::vec3 scale = glm::vec3(scal.x, scal.y, 1.0f);

	// Build the Model matrix
	glm::mat4 translationMatrix	= glm::translate(glm::mat4(1.0f), position);
	glm::mat4 rotationMatrix	= glm::eulerAngleYXZ(0.0f, 0.0f, rotation.z * 0.0174532925f);
	glm::mat4 scalingMatrix		= glm::scale(glm::mat4(1.0f), scale);

	glm::mat4 mm = translationMatrix * rotationMatrix * scalingMatrix;

	return mm;
}

Renderer::~Renderer(){
    delete timer;
    delete fpsText;

    delete input;
    delete camera;
    delete resman;
    Mix_CloseAudio();

    glDeleteProgram(programID);
    glDeleteTextures(1, &textureID);
    std::cout << "DELETED SHADER" << std::endl;
    SDL_GL_DeleteContext(gContext);
    std::cout << "DELETED CONTEXT" << std::endl;
    // Close and destroy the window
    SDL_DestroyWindow(window);
    std::cout << "DELETED WINDOW" << std::endl;
    // Clean up

    SDL_Quit();
    std::cout << "DELETED RENDERER" << std::endl;
}

bool Renderer::mustStop(){
    if(input->getKeyDown(SDLK_ESCAPE) || input->mustQuit()){
        return true;
    }
    return false;
}


void Renderer::updateDeltaTime(){
    double old_time = current_time;
    current_time = SDL_GetTicks();
    dt = (current_time - old_time) / 1000.0f;
}

void Renderer::displayFPS(){
    if(fpscounter >= 1){
        std::cout << "FPS: ";
        std::cout << frames << std::endl;
        std::ostringstream ss;
        ss << "FPS: ";
        ss << frames;
        fpsText->setText(ss.str());

        frames = 0;
        fpscounter = 0.0f;
    }

    fpscounter += dt;
    frames += 1;
}

void Renderer::renderText(Text* t){

    glUniform2f(uvoffset, 0, 0);
    t->f = resman->getFont(t->getFontPath(), t->getFontSize());

    if(t->getCurMessage() != t->getLastMessage()){
        t->makeMesh();
        t->setLastMessage();
    }

    glm::mat4 MVP;
    glm::mat4 modelMatrix = getModelMatrix(t->position+Vector2((t->getWidth()/2)*t->scale.x, 0), t->scale, t->rotation);


    if(t->isHud){
        glm::mat4 vm = glm::lookAt(
                glm::vec3(0, 0, 5), // Camera is at (xpos,ypos,5), in World Space
                glm::vec3(0, 0, 0), // and looks towards Z
                glm::vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
                );
        MVP = ProjectionMatrix * vm * modelMatrix;
    }else{
        MVP = ProjectionMatrix * ViewMatrix * modelMatrix;
    }

    glUseProgram(programID);


    // Send our transformation to the currently bound shader,
    // in the "MVP" uniform
    glUniformMatrix4fv(matrixID, 1, GL_FALSE, &MVP[0][0]);
    glUniform1f(alphafloat, (float)t->color.a/255.0f);
    glUniform1f(rfloat, (float)t->color.r/255.0f);
    glUniform1f(gfloat, (float)t->color.g/255.0f);
    glUniform1f(bfloat, (float)t->color.b/255.0f);
    // Bind our texture in Texture Unit 0
    glActiveTexture(GL_TEXTURE0);

    glBindTexture(GL_TEXTURE_2D, t->getGLuintData());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // Set our "myTextureSampler" sampler to user Texture Unit 0
    glUniform1i(textureID, 0);

    // 1st attribute buffer : vertices
    glEnableVertexAttribArray(vertexPosition_modelspaceID);
    glBindBuffer(GL_ARRAY_BUFFER, t->getVtbuffer());
    glVertexAttribPointer(
                          vertexPosition_modelspaceID,  // The attribute we want to configure
                          3,                            // size : x+y+z => 3
                          GL_FLOAT,                     // type
                          GL_FALSE,                     // normalized?
                          0,                            // stride
                          (void*)0                      // array buffer offset
                          );

    // 2nd attribute buffer : UVs
    glEnableVertexAttribArray(vertexUVID);
    glBindBuffer(GL_ARRAY_BUFFER, t->getUvbuffer());
    glVertexAttribPointer(
                          vertexUVID,                   // The attribute we want to configure
                          2,                            // size : U+V => 2
                          GL_FLOAT,                     // type
                          GL_FALSE,                     // normalized?
                          0,                            // stride
                          (void*)0                      // array buffer offset
                          );

    // Draw the triangles !
    glDrawArrays(GL_TRIANGLES, 0, 2*3); // 2*3 indices starting at 0 -> 2 triangles

    glDisableVertexAttribArray(vertexPosition_modelspaceID);
    glDisableVertexAttribArray(vertexUVID);
}

void Renderer::renderShape(Shape* t){
    glUniform2f(uvoffset, 0, 0);

    glm::mat4 MVP;
    glm::mat4 modelMatrix = getModelMatrix(t->position, t->scale, t->rotation);


    if(t->isHud){
        glm::mat4 vm = glm::lookAt(
                glm::vec3(0, 0, 5), // Camera is at (xpos,ypos,5), in World Space
                glm::vec3(0, 0, 0), // and looks towards Z
                glm::vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
                );
        MVP = ProjectionMatrix * vm * modelMatrix;
    }else{
        MVP = ProjectionMatrix * ViewMatrix * modelMatrix;
    }

    glUseProgram(programID);


    // Send our transformation to the currently bound shader,
    // in the "MVP" uniform
    glUniformMatrix4fv(matrixID, 1, GL_FALSE, &MVP[0][0]);
    glUniform1f(alphafloat, (float)t->color.a/255.0f);
    glUniform1f(rfloat, (float)t->color.r/255.0f);
    glUniform1f(gfloat, (float)t->color.g/255.0f);
    glUniform1f(bfloat, (float)t->color.b/255.0f);
    // Bind our texture in Texture Unit 0

    glActiveTexture(GL_TEXTURE0);

    glBindTexture(GL_TEXTURE_2D, t->texId());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // Set our "myTextureSampler" sampler to user Texture Unit 0
    glUniform1i(textureID, 0);

    // 1st attribute buffer : vertices
    glEnableVertexAttribArray(vertexPosition_modelspaceID);
    glBindBuffer(GL_ARRAY_BUFFER, t->getVtbuffer());
    glVertexAttribPointer(
                          vertexPosition_modelspaceID,  // The attribute we want to configure
                          3,                            // size : x+y+z => 3
                          GL_FLOAT,                     // type
                          GL_FALSE,                     // normalized?
                          0,                            // stride
                          (void*)0                      // array buffer offset
                          );

    // 2nd attribute buffer : UVs
    glEnableVertexAttribArray(vertexUVID);
    glBindBuffer(GL_ARRAY_BUFFER, t->getUvbuffer());
    glVertexAttribPointer(
                          vertexUVID,                   // The attribute we want to configure
                          2,                            // size : U+V => 2
                          GL_FLOAT,                     // type
                          GL_FALSE,                     // normalized?
                          0,                            // stride
                          (void*)0                      // array buffer offset
                          );

    // Draw the triangles !
    glDrawArrays(GL_TRIANGLES, 0, t->numverts()); // 2*3 indices starting at 0 -> 2 triangles

    glDisableVertexAttribArray(vertexPosition_modelspaceID);
    glDisableVertexAttribArray(vertexUVID);
}

void Renderer::devMode(){
    if( input->getKeyDown(SDLK_F10)){
        if(devmodeon){
            devmodeon = false;
        }else if(!devmodeon){
            devmodeon = true;
        }
    }
    if(devmodeon){
        renderText(timer);
        renderText(fpsText);
    }
}
