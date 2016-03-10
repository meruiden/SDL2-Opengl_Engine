 #ifndef CAMERA_H
#define CAMERA_H

#include <engine/vector2.h>

#include <glm/gtc/matrix_transform.hpp>
class Camera{
    public:
        void computeMatricesFromInputs(float deltaTime);
        glm::mat4 getViewMatrix();
        Vector2 position;
    private:
        glm::mat4 ViewMatrix;

};

#endif
