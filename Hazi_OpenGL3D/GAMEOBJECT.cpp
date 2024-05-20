#include "GAMEOBJECT.hpp"

void GameObject::setPosition(glm::vec3 newPos)
{
	position = newPos;
	
}

const char* GameObject::getName() const
{
	return name;
}

glm::vec3 GameObject::getPosition() const
{
	return position;
}

void GameObject::setVelocity(glm::vec3 newVelo)
{
	velocity = newVelo;
}

glm::vec3 GameObject::getVelocity() const
{
	return velocity;
}

void GameObject::setMoveSpeed(float mSpeed)
{
	moveSpeed = mSpeed;
}

float GameObject::getMoveSpeed() const
{
	return moveSpeed;
}
