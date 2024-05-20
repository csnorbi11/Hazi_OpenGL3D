#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

class Shader {
	unsigned int ID;

public:
	/**
	 * Parameter nelkuli konstruktor, amely az alap shader programot hozza letre
	 * 
	 */
	Shader()
		:
		ID(0)
	{
		try {
			createShader("default.vert", "default.frag");
		}
		catch (const char* s)
		{
			std::cout << "Hiba a shader program keszulese kozben: " << std::endl;
			std::cout << "\n" << s << std::endl;
			throw "Hiba a shader program keszulese kozben";
		}
	}
	/**
	 * Parameteres konstruktor, amely sajat shaderekbol hoz letre shadert.
	 * 
	 * \param vertexShaderPath vertex shader source fajljanak elerese
	 * \param fragmentShaderPath fragment shader source fajljanak elerese
	 */
	Shader(const char* vertexShaderPath, const char* fragmentShaderPath)
		:
		ID(0)
	{
		try {
			createShader(vertexShaderPath, fragmentShaderPath);
		}
		catch (const char* s)
		{
			std::cout << "Hiba a shader program keszulese kozben: " << std::endl;
			std::cout << "\n" << s << std::endl;
			throw "Hiba a shader program keszulese kozben";
		}

	}

	~Shader()
	{
		glDeleteProgram(ID);
	}

	/**
	 * Aktivalja a shader programot
	 */
	void use() const;
	/**
	 * A shader programban a parameterben kapott nevu valtozonak az erteketet beallitja a parameterben kapott ertekre.
	 * 
	 * \param varName az atallitando valtozo neve
	 * \param value a beallitando ertek
	 */
	void setFloat(const char* varName, float value) const;
	/**
	 * A shader programban a parameterben kapott nevu valtozonak az erteketet beallitja a parameterben kapott ertekre.
	 *
	 * \param varName az atallitando valtozo neve
	 * \param value a beallitando ertek
	 */
	void setInt(const char* varName, int value) const;
	/**
	 * A shader programban a parameterben kapott nevu valtozonak az erteketet beallitja a parameterben kapott ertekre.
	 *
	 * \param varName az atallitando valtozo neve
	 * \param value a beallitando ertek
	 */
	void setBool(const char* varName, bool value) const;
	/**
	 * A shader programban a parameterben kapott nevu valtozonak az erteketet beallitja a parameterben kapott ertekre.
	 *
	 * \param varName az atallitando valtozo neve
	 * \param value a beallitando ertek
	 */
	void setMat4(const char* varName, glm::mat4 value) const;
	void setVec3(const char* varName, glm::vec3 value) const;

public:
	/**
	 * Beolvassa, letrehozza a shader programot.
	 * 
	 * \param vertPath vertex shader source fajljanak elerese
	 * \param fragPath fragment shader source fajljanak elerese
	 */
	void createShader(const char* vertPath, const char* fragPath);
};


#endif