#include "SHADER.hpp"
#include <sstream>
#include <fstream>
#include <iostream>


void Shader::use() const
{
	glUseProgram(ID);
}

void Shader::setFloat(const char* varName, float value) const
{
	glUniform1f(glGetUniformLocation(ID, varName), value);
}

void Shader::setInt(const char* varName, int value) const
{
	glUniform1i(glGetUniformLocation(ID, varName), value);
}

void Shader::setBool(const char* varName, bool value) const
{
	glUniform1i(glGetUniformLocation(ID, varName), value);
}

void Shader::setMat4(const char* varName, glm::mat4 value) const
{
	glUniformMatrix4fv(glGetUniformLocation(ID, varName), 1, GL_FALSE, &value[0][0]);
}

void Shader::setVec3(const char* varName, glm::vec3 value) const
{
	glUniform3fv(glGetUniformLocation(ID, varName), 1, &value[0]);
}

void Shader::createShader(const char* vertPath, const char* fragPath)
{
	//Fajlbol betolti a vertex shader es fragment shader source fajljait
	std::ifstream vertexFile, fragmentFile;
	std::stringstream vertexFileBuffer, fragmentFileBuffer;
	std::string vertexCode, fragmentCode;

	vertexFile.open(vertPath);
	if (!vertexFile.is_open())
	{
		throw "Nem tudta beolvasni a vertex shader source fájlját";
	}
	fragmentFile.open(fragPath);
	if (!fragmentFile.is_open())
	{
		throw "Nem tudta beolvasni a fragment shader source fájlját";
	}

	vertexFileBuffer << vertexFile.rdbuf();
	fragmentFileBuffer << fragmentFile.rdbuf();

	vertexFile.close();
	fragmentFile.close();

	vertexCode = vertexFileBuffer.str();
	fragmentCode = fragmentFileBuffer.str();

	const char* vertexShaderSource = vertexCode.c_str();
	const char* fragmentShaderSource = fragmentCode.c_str();


	int success;
	char infoLog[512];


	unsigned int vertexShader, fragmentShader;
	//letrehozza a shadereket
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	//csatolja a shaderekhez a source fajlokat
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	//leforditja a shadereket
	glCompileShader(vertexShader);
	glCompileShader(fragmentShader);
	//vertex shader hibakezeles
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "Nem sikerult a vertex shadert leforditani: ";
		throw infoLog;
	}
	//fragment shader hibakezeles
	glad_glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "Nem sikerult a fragment shadert leforditani: ";
		throw infoLog;
	}
	//shader program letrehozasa
	ID = glCreateProgram();
	//shaderek hozzacsatolasa a programhoz
	glAttachShader(ID, vertexShader);
	glAttachShader(ID, fragmentShader);
	glLinkProgram(ID);
	//shader program hibakezelese
	glad_glGetShaderiv(ID, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(ID, 512, NULL, infoLog);
		std::cout << "Nem sikerult a shader programot linkelni: ";
		throw infoLog;
	}
	//a mar felesleges shadereket torli
	glad_glDeleteShader(vertexShader);
	glad_glDeleteShader(fragmentShader);

	glUseProgram(ID);


}


