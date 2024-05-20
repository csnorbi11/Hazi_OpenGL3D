#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H


#include "CAMERA.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

class GameObject{
	const char* name;
	float moveSpeed;

protected:
	glm::vec3 position;
	glm::vec3 velocity;

public:
	/**
	 * Parameter nelkul konstruktor alapertekekkel.
	 * 
	 */
	GameObject()
		:
		name("GameObject"),
		moveSpeed(1.0f),
		position(glm::vec3(0.0f)),
		velocity(glm::vec3(0.0f))
	{}
	/**
	 * Parameteres konstruktor.
	 * 
	 * \param n - gameobject nev
	 * \param p - kezdo pozicio
	 * \param v - velocity
	 * \param moveS - sebesseg
	 */
	GameObject(const char* n, glm::vec3 p = glm::vec3(0.0f), float moveS = 1.0f)
		:
		name(n),
		moveSpeed(moveS),
		position(p),
		velocity(glm::vec3(0.0f,0.0f,0.0f))
	{}
	virtual ~GameObject()
	{}
	/**
	 * mozgato fuggveny.
	 */
	virtual void move(float deltaTime) = 0;

	/**
	 * getterek es setterek.
	 */
	virtual void setPosition(glm::vec3 newPos);
	void setVelocity(glm::vec3 newVelo);
	void setMoveSpeed(float mSpeed);
	const char* getName() const;
	glm::vec3 getPosition() const;
	glm::vec3 getVelocity() const;
	float getMoveSpeed() const;

};

#endif // !GAMEOBJECT_H