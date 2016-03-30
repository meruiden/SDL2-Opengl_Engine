#include "image.h"
#include <iostream>
Image::Image(){
    this->w = 0;
    this->h = 0;
    this->GLuintData[0] = 0;
    this->imgPath = "NULL";
}

Image::~Image(){
    glDeleteBuffers(1, &vertexbuffer);
    glDeleteBuffers(1, &uvbuffer);
    if(GLuintData[0] != 0){
        glDeleteTextures(1, &GLuintData[0]);
    }
}

int Image::getHeight(){
    return this->h;
}

int Image::getWidth(){
    return this->w;
}

std::string Image::getImgPath(){
  return this->imgPath;
}

GLuint Image::getGLuintData(){
    return this->GLuintData[0];
}

void Image::loadTGA(std::string ip){
    this->imgPath = "NULL";
    FILE *file;
    const char* imagepath = ip.c_str();
    unsigned char type[4];
    unsigned char info[6];
    file = fopen(imagepath, "rb");
    if (!file){
        printf("Can't open %s.\n", imagepath);
        return;
    }
    printf("Reading image %s\n", imagepath);

    fread (&type, sizeof (char), 3, file);
    fseek (file, 12, SEEK_SET);
    fread (&info, sizeof (char), 6, file);
    //image type either 2 (color) or 3 (greyscale)
    if (type[1] != 0 || (type[2] != 2 && type[2] != 3))
    {
        fclose(file);
        printf("Can't open %s.\n", imagepath);
        return;
    }
    int width = info[0] + info[1] * 256;
    int height = info[2] + info[3] * 256;
    unsigned char byteCount = info[4] / 8;
    if (byteCount != 1 && byteCount != 3 && byteCount != 4) {
        fclose(file);
        printf("Can't open %s.\n", imagepath);
        return;
    }


    long imageSize = width * height * width * byteCount;
    //allocate memory for image data
    unsigned char* data = new unsigned char[imageSize];
    //read in image data
    fread(data, sizeof(unsigned char), imageSize, file);

       //close file
    fclose(file);

    if (byteCount == 3 || byteCount == 4) {
        long counter = 0;
        long s = width * height;
        for (long i=0; i<s; i++) {
            //swap every 1st byte with every 3rd byte
            unsigned char temp = data[counter];
            data[counter] = data[counter+2];
            data[counter+2] = temp;

            counter += byteCount;
        }
    }

    // Create one OpenGL texture
    GLuint textureid[1];

    glGenTextures(1, &textureid[0]);

    // "Bind" the newly created texture : all future texture functions will modify this texture
    glBindTexture(GL_TEXTURE_2D, textureid[0]);

    // Give the image to OpenGL
    if(byteCount ==4){
        glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_BLEND);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    }

    if(byteCount ==3){
        glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);
    }

    if(byteCount ==1){
        glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_BLEND);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    }
    // OpenGL has now copied the data. Free our own version
    delete [] data;

    // Poor filtering, or ...
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    // ... nice trilinear filtering.
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

    glGenerateMipmap(GL_TEXTURE_2D);

    // Return the ID of the texture we just created
    this->imgPath = ip;
    this->w = width;
    this->h = height;
    this->GLuintData[0] = textureid[0];

    int sprite_width = width;
    int sprite_height = height;

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
        1.0f, 1.0f,
        0.0f, 1.0f,
        0.0f, 0.0f,
        0.0f, 0.0f,
        1.0f, 0.0f,
        1.0f, 1.0f
    };

    glGenBuffers(1, &this->uvbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_uv_buffer_data), g_uv_buffer_data, GL_STATIC_DRAW);

    glGenBuffers(1, &this->vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);


}

void Image::loadPNG(std::string ip){

    printf("Reading image %s\n", ip.c_str());
    this->imgPath = "NULL";

    SDL_Surface * plaatje = NULL;
    plaatje = IMG_Load(ip.c_str());
    if(plaatje == NULL){
        printf("Can't open %s.\n", ip.c_str());
        return;
    }
    int mode = GL_BGRA;
    switch (plaatje->format->BytesPerPixel)
        {
        case 4:
            if (plaatje->format->Rmask == 0x000000ff)
                mode = GL_RGBA;
            else
                mode = GL_BGRA;
            break;
        case 3:
            if (plaatje->format->Rmask == 0x000000ff)
                mode = GL_RGB;
            else
                mode = GL_BGR;
            break;
        default:
            std::cout << "Error, image is not truecolor." << std::endl;
            return;
        }
    GLuint textureid[1];
    glGenTextures(1, &textureid[0]);

    // "Bind" the newly created texture : all future texture functions will modify this texture
    glBindTexture(GL_TEXTURE_2D, textureid[0]);

    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);

    glTexImage2D(GL_TEXTURE_2D, 0, plaatje->format->BytesPerPixel, plaatje->w, plaatje->h, 0, mode, GL_UNSIGNED_BYTE, plaatje->pixels);
    // Poor filtering, or ...
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    // ... nice trilinear filtering.
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

    glGenerateMipmap(GL_TEXTURE_2D);

    this->imgPath = ip;
    this->w = plaatje->w;
    this->h = plaatje->h;
    this->GLuintData[0] = textureid[0];

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

    glGenBuffers(1, &this->vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

    glGenBuffers(1, &this->uvbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_uv_buffer_data), g_uv_buffer_data, GL_STATIC_DRAW);

    SDL_FreeSurface(plaatje);
    plaatje = NULL;
}
