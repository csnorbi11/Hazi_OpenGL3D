#ifndef CAMERA_H
#define CAMERA_H


#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Camera {
	glm::vec3 position;
	glm::vec3 up;
	glm::vec3 front;
	glm::vec3 right;

	glm::vec3 worldUp;
	float pitch;
	float yaw;

	float mouseSensitivy;

public:
	/**
	 * Parameter nelkuli konstruktor.
	 * 
	 */
	Camera()
	:
		position(glm::vec3(0,0,0)),
		up(glm::vec3(0, 1, 0)),
		front(glm::vec3(0, 0, -1)),
		right(glm::vec3(1, 0, 0)),
		worldUp(glm::vec3(0, 1, 0)),
		pitch(0),
		yaw(90),
		mouseSensitivy(1)
	{}
	/**
	 * Parameteres konstruktor.
	 * 
	 * \param pos - pozicio
	 * \param fr - elore vektor
	 * \param u - fel vektor
	 */
	Camera(glm::vec3 pos, glm::vec3 fr = glm::vec3(0, 0, -1), glm::vec3 u = glm::vec3(0, 1, 0))
		:
		position(pos),
		up(u),
		front(fr),
		right(glm::vec3(1, 0, 0)),
		worldUp(u),
		pitch(0),
		yaw(90),
		mouseSensitivy(1)
	{
		calculateView();
	}
	~Camera(){}

	/**
	 * getterek setterek.
	 * 
	 */
	void updatePosition(glm::vec3 pos);
	void updateFront(glm::vec3 fr);
	glm::vec3 getPosition();
	float getYaw();
	float getPitch();
	glm::mat4 getView();

	/**
	 * lekezeli az eger mozgatasat.
	 * 
	 * \param xoffset - x iranyu kiteres
	 * \param yoffset - y iranyu kiteres
	 */
	void processMouse(double& xoffset, double& yoffset);

	

private:
	/**
	 * kiszamitja a view matrixot.
	 * 
	 */
	void calculateView();

};

#endif // !CAMERA_H
