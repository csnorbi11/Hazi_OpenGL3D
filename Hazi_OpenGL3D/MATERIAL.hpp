#ifndef MATERIAL_H
#define MATERIAL_H
#include "SHADER.hpp"
#include "TEXTURE.hpp"
#include "VERTEXBUFFER.hpp"


class Material {
	VertexBuffer vb;
	Texture texture;
	Shader shader;

public:
	/**
	 * Parameter nelkuli konstruktor, ami olyan materialt hoz letre, ami egy szinu, textura nelkuli.
	 * 
	 */
	Material()
		:
		vb(),
		texture(),
		shader()
	{}
	/**
	 * Parameteres konstruktor, ami egy specifikus shader programot hoz letre es texturat is tartalmaz.
	 * 
	 * \param shaderVertexShaderPath
	 * \param shaderFragmentShaderPath
	 * \param texturepath
	 */
	Material(const char* shaderVertexShaderPath, const char* shaderFragmentShaderPath, const char* texturepath)
		:
		vb(),
		texture(texturepath),
		shader(shaderVertexShaderPath,shaderFragmentShaderPath)
	{}
	~Material(){}

	/**
	 * Visszaadja a texturat.
	 * 
	 * \return 
	 */
	const Shader& getShader() const;
	/**
	 * Hasznalja a texturat.
	 * 
	 */
	void use() const;
};
#endif