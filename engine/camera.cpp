// Include SDL
#include <SDL.h>
#include <SDL_opengl.h>

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "camera.h"

#include <iostream>



glm::mat4 Camera::getViewMatrix(){
	return ViewMatrix;
}

void Camera::computeMatricesFromInputs(float deltaTime)
{
	glm::vec3 pos = glm::vec3( position.x, position.y, 5 );

	// View matrix
	ViewMatrix = glm::lookAt(
			pos, // Camera is at (xpos,ypos,5), in World Space
			pos + glm::vec3(0, 0, -5), // and looks towards Z
			glm::vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
			);
}
