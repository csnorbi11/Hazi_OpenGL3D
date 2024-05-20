#include "MATERIAL.hpp"

const Shader& Material::getShader() const
{
    return shader;
}

void Material::use() const
{
	shader.use();
	texture.useTexture();
	vb.bindVAO();
}
