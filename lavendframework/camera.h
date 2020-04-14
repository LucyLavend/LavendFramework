#ifndef CAMERA_H
#define CAMERA_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp> // glm::lookAt()

void computeMatricesFromInputs(GLFWwindow* window, float deltaTime);
glm::mat4 getViewMatrix();
glm::vec3 getCursor();

#endif
