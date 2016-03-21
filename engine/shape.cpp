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
