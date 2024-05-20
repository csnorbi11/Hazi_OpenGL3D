#include "DRAWABLEGAMEOBJECT.hpp"

void DrawableGameObject::draw(glm::mat4 view, glm::mat4 proj) const
{
	material.use();
	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, glm::vec3(this->getPosition()));
	material.getShader().setMat4("model", model);
	material.getShader().setMat4("view", view);
	material.getShader().setMat4("projection", proj);


	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
}

void DrawableGameObject::move(float deltaTime)
{
	position += velocity * getMoveSpeed();
}