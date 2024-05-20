#include "CAMERA.hpp"

void Camera::updatePosition(glm::vec3 pos)
{
	position = pos;
}

void Camera::updateFront(glm::vec3 fr)
{
	front = fr;
}

glm::mat4 Camera::getView()
{
	glm::mat4 lookat = glm::lookAt(position, position + front, up);
	return lookat;
}

glm::vec3 Camera::getPosition()
{
	return position;
}

void Camera::processMouse(double& xoffset, double& yoffset)
{
	xoffset *= mouseSensitivy;
	yoffset *= mouseSensitivy;

	yaw += xoffset;
	pitch += yoffset;


	if (pitch > 89.0f)
		pitch = 89.0f;
	if (pitch < -89.0f)
		pitch = -89.0f;


	calculateView();
}

float Camera::getYaw()
{
	return yaw;
}

float Camera::getPitch()
{
	return pitch;
}

void Camera::calculateView()
{
	glm::vec3 dir;
	dir.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	dir.y = sin(glm::radians(pitch));
	dir.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	front = glm::normalize(dir);

	right = glm::normalize(glm::cross(front, worldUp));
	up = glm::normalize(glm::cross(right, front));
}
