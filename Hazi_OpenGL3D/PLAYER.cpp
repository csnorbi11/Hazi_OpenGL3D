#include "PLAYER.hpp"
//a go tombben az utolso elem az a cel elem, ezert ha azzal utkozik, akkor atallitja annak poziciojat ezzel jelezve hogy a jatekos elerte azt
void Player::applyPhysics(float deltaTime, std::vector<GameObject*>& go)
{
	velocity.y += -9.81 * deltaTime * 2;
	for (size_t i = 1; i < go.size(); i++)
	{
		if (position.x + 0.5 > go.at(i)->getPosition().x && position.x < go.at(i)->getPosition().x + 0.5 &&
			position.z + 0.5 > go.at(i)->getPosition().z && position.z < go.at(i)->getPosition().z + 0.5)
		{

			if (position.y - 2 <= go.at(i)->getPosition().y && position.y >= go.at(i)->getPosition().y + 1)
			{
				readyToJump = true;
				velocity.y = 0;
				if (i == go.size() - 1)
					go.at(go.size() - 1)->setPosition(glm::vec3(99.0f, 99.0f, 99.0f));
			}
		}
		else if (position.y - 1.9 <= go.at(i)->getPosition().y && position.y > go.at(i)->getPosition().y - 1)
		{

			if (position.z + 1 >= go.at(i)->getPosition().z && position.z < go.at(i)->getPosition().z &&
				position.x + 0.5>go.at(i)->getPosition().x && position.x < go.at(i)->getPosition().x + 0.5)
			{
				position.z = go.at(i)->getPosition().z - 1;
				if (i == go.size() - 1)
					go.at(go.size() - 1)->setPosition(glm::vec3(99.0f, 99.0f, 99.0f));
			}
			else if (position.z <= go.at(i)->getPosition().z + 1 && position.z + 1 > go.at(i)->getPosition().z + 1 &&
				position.x + 0.5 > go.at(i)->getPosition().x && position.x < go.at(i)->getPosition().x + 0.5)
			{
				position.z = go.at(i)->getPosition().z + 1;
				if (i == go.size() - 1)
					go.at(go.size() - 1)->setPosition(glm::vec3(99.0f, 99.0f, 99.0f));
			}
			else if (position.x <= go.at(i)->getPosition().x + 1 && position.x + 1 > go.at(i)->getPosition().x + 1 &&
				position.z + 0.5 > go.at(i)->getPosition().z && position.z < go.at(i)->getPosition().z + 0.5)
			{
				position.x = go.at(i)->getPosition().x + 1;
				if (i == go.size() - 1)
					go.at(go.size() - 1)->setPosition(glm::vec3(99.0f, 99.0f, 99.0f));
			}
			else if (position.x + 1 >= go.at(i)->getPosition().x && position.x < go.at(i)->getPosition().x &&
				position.z + 0.5 > go.at(i)->getPosition().z && position.z < go.at(i)->getPosition().z + 0.5)
			{
				position.x = go.at(i)->getPosition().x - 1;
				if (i == go.size() - 1)
					go.at(go.size() - 1)->setPosition(glm::vec3(99.0f, 99.0f, 99.0f));
			}
		}
	}
}

void Player::move(float deltaTime)
{
	frontVelocity.x = cos(glm::radians(camera.getYaw()));
	frontVelocity.z = sin(glm::radians(camera.getYaw()));
	frontVelocity = glm::normalize(frontVelocity);
	rightVelocity = glm::normalize(glm::cross(frontVelocity, glm::vec3(0, 1, 0)));
	if (glm::sqrt(velocity.x * velocity.x + velocity.z * velocity.z)>1)
	{
		float norm = glm::sqrt(0.5f);
		velocity.x *= norm;
		velocity.z *= norm;
	}
	position += (velocity.z * frontVelocity + velocity.x * rightVelocity) * this->getMoveSpeed() * deltaTime;
	position.y += velocity.y * deltaTime;
	camera.updatePosition(position);
}

void Player::setPosition(glm::vec3 newPos)
{
	GameObject::setPosition(newPos);
	camera.updatePosition(getPosition());
}

void Player::setJumpBool(bool ready)
{
	readyToJump = ready;
}

bool Player::getJumpBool()
{
	return readyToJump;
}

Camera Player::getCamera() const
{
	return camera;
}

void Player::setCameraPos(glm::vec3 pos)
{
	camera.updatePosition(pos);
}

void Player::mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
{
	double xpos = xposIn;
	double ypos = yposIn;
	
	double xoffset = xpos - lastX;
	double yoffset = lastY - ypos;

	lastX = xpos;
	lastY = ypos;

	camera.processMouse(xoffset, yoffset);
}
