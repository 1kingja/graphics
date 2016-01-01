#include "Camera.h"
#include <glm\gtx\transform.hpp>

Camera::Camera() : 
	viewDirection(0.0f, 0.0f, -1.0f), 
	UP(0.0f, 1.0f, 0.0f)
{
}

void Camera::mouseUpdate(const glm::vec2& newMousePosition)
{
	glm::vec2 mouseDelta = newMousePosition - oldMousePosition;
	if (glm::length(mouseDelta) > 50.0f)
	{
		oldMousePosition = newMousePosition;
		return;
	}
	const float ROTATIONAL_SPEED = 0.5f;
	glm::vec3 toRotateAround = glm::cross(viewDirection, UP);
	glm::mat4 rotator =	glm::rotate(-mouseDelta.x * ROTATIONAL_SPEED, UP) *
						glm::rotate(-mouseDelta.y * ROTATIONAL_SPEED, toRotateAround);
	
	viewDirection = glm::mat3(rotator) * viewDirection;

	oldMousePosition = newMousePosition;
}

glm::mat4 Camera::getWorldToViewMatrix() const
{
	return glm::lookAt(position, position + viewDirection, UP);
}