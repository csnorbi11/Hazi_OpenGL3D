#ifndef DRAWABLEGAMEOBJECT_H
#define DRAWABLEGAMEOBJECT_H

#include "GAMEOBJECT.hpp"
#include "MATERIAL.hpp"

class DrawableGameObject : public GameObject {
	Material material;
	glm::vec3 color;

public:
	/**
	 * Parameter nelkuli konstruktor.
	 * 
	 */
	DrawableGameObject() 
		:
		GameObject("DrawableGameObject"),
		material(),
		color(glm::vec3(0.1f, 0, 0.9f))
	{
		material.getShader().setVec3("vertColor", color);
	}
	/**
	 * Paramteres konstruktor.
	 * 
	 * \param shaderVertexShaderPath - vertex shader eleresi utja
	 * \param shaderFragmentShaderPath - fragment shader eleresi utja
	 * \param texturepath - textura eleresi utja
	 * \param n - nev
	 * \param p - pozicio
	 * \param moveS - sebesseg
	 */
	DrawableGameObject(const char* shaderVertexShaderPath, const char* shaderFragmentShaderPath, const char* texturepath, const char* n, glm::vec3 p = glm::vec3(0.0), glm::vec3 v = glm::vec3(0.0), float moveS = 0.0)
		:
		GameObject(n,p,moveS),
		material(shaderVertexShaderPath,shaderFragmentShaderPath,texturepath),
		color(glm::vec3(0.2f, 0.0f, 1.0f))
	{
		material.getShader().setVec3("vertColor", color);
	}
	virtual ~DrawableGameObject()
	{}

	/**
	 * kirajzolja a drawablegameobjectet.
	 * 
	 * \param view - view matrix
	 * \param proj - projection matrix
	 */
	void draw(glm::mat4 view, glm::mat4 proj) const;
	/**
	 * mozgato fuggveny.
	 * 
	 * \param deltaTime - kepkocka idotartama
	 */
	void move(float deltaTime);
};

#endif // !DRAWABLEGAMEOBJECT_H