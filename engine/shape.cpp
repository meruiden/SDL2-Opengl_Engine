#include "shape.h"
int Shape::idCounter = 0;
Shape::Shape(){
    this->shapeId = idCounter;
    Shape::idCounter ++;
    this->layer = 1;
    this->color = Color();
    this->rotation = 0.0f;
    this->scale = Vector2(1.0f, 1.0f);
    this->position = Vector2();
    this->isHud = false;
    this->uvbuffer = 0;
    this->vertexbuffer = 0;
    this->textureid = 0;
    this->w = 0;
    this->h = 0;
    this->_radius = 0;
}

Shape::~Shape(){
    if(uvbuffer != 0 && vertexbuffer != 0){
        glDeleteBuffers(1, &uvbuffer);
        glDeleteBuffers(1, &vertexbuffer);
    }
    if(textureid != 0){
        glDeleteTextures(1, &textureid);
    }
}

void Shape::circle(float radius){
    if(radius == this->radius()){
        return;
    }
    this->w = 0;
    this->h = 0;
    this->_radius = radius;
    long size = (radius*2) * (radius*2) * 3;
    unsigned char* data;
	data = new unsigned char[size];
	//create white opaque pixels
	for (long i=0; i<size; i++) {
		data[i] = 255;
	}
    if(textureid != 0){
        glDeleteTextures(1, &textureid);
    }
    glGenTextures(1, &textureid);
    glBindTexture(GL_TEXTURE_2D, textureid);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, radius, radius, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

    delete data;

    if(uvbuffer != 0 && vertexbuffer != 0){
        glDeleteBuffers(1, &uvbuffer);
        glDeleteBuffers(1, &vertexbuffer);
    }

	unsigned int step = 40;
	_numverts = step*3; // n triangles with 3 vertices each

	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> uvs;
    float uvheight = 1.0f;
    float uvwidth = 1.0f;
	float x = 0.0f;
	float y = 0.0f;
	float u = 0.5f;
	float v = 0.5f;
	int deg = 360;
	// for each triangle, do ...
	for (unsigned int i = 0; i < step; i++) {
		// ####################################################
		// start at, and always go back to (0,0), UV (0.5,0.5)
		vertices.push_back(glm::vec3(0.0f, 0.0f, 0.0f));
		uvs.push_back(glm::vec2(0.5f, 0.5f));

		// #############################
		// create second vertex
		x = cos(deg*DEG_TO_RAD)*radius;
		y = sin(deg*DEG_TO_RAD)*radius;
		u = (x/radius) * uvwidth;
		v = (-y/radius) *  uvheight;
		vertices.push_back(glm::vec3(x, y, 0.0f));
		uvs.push_back(glm::vec2(u/2+0.5f, v/2+0.5f)); // translate UV's from (-1, +1) to (0, +1)

		// #############################
		// rotate n degrees for the final vertex
		deg -= 360/step;
		// create third vertex
		x = cos(deg*DEG_TO_RAD)*radius;
		y = sin(deg*DEG_TO_RAD)*radius;
		u = (x/radius) * uvwidth;
		v = (-y/radius) * uvheight;
		vertices.push_back(glm::vec3(x, y, 0.0f));
		uvs.push_back(glm::vec2(u/2+0.5f, v/2+0.5f)); // translate UV's from (-1, +1) to (0, +1)
		// ####################################################
	}


    glGenBuffers(1, &vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);


    glGenBuffers(1, &uvbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
    glBufferData(GL_ARRAY_BUFFER, uvs.size() * sizeof(glm::vec2), &uvs[0], GL_STATIC_DRAW);
}

void Shape::square(float ww, float hh){
    if(ww == this->width() && hh == this->height()){
        return;
    }
    this->_radius = 0;
    this->w = ww;
    this->h = hh;
    long size = ww*hh*4;
    unsigned char* data;
	data = new unsigned char[size];
	//create white opaque pixels
	for (long i=0; i<size; i++) {
		data[i] = 255;
	}
    if(textureid != 0){
        glDeleteTextures(1, &textureid);
    }
    glGenTextures(1, &textureid);
    glBindTexture(GL_TEXTURE_2D, textureid);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, ww, hh, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

    delete data;

    if(uvbuffer != 0 && vertexbuffer != 0){
        glDeleteBuffers(1, &uvbuffer);
        glDeleteBuffers(1, &vertexbuffer);
    }

    int sprite_width = ww;
    int sprite_height = hh;
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
    this->_numverts = 2*3;


    glGenBuffers(1, &vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

    glGenBuffers(1, &uvbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_uv_buffer_data), g_uv_buffer_data, GL_STATIC_DRAW);
}
