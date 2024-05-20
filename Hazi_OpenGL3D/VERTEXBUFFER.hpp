#ifndef VERTEXBUFFER_H
#define VERTEXBUFFER_H


#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

class VertexBuffer{
	unsigned int VBO;
	unsigned int VAO;
	unsigned int EBO;

public:
	/**
	 * parameter nelkuli konstruktor.
	 * 
	 */
	VertexBuffer()
		:
		VBO(0),
		VAO(0),
		EBO(0)
	{
		createVertexBuffer();
	}
	~VertexBuffer()
	{
		glDeleteBuffers(1, &VBO);
		glDeleteBuffers(1, &EBO);
		glDeleteVertexArrays(1, &VAO);
	}

	/**
	 * aktivalja a VAO-t.
	 * 
	 */
	void bindVAO() const;
	/**
	 * deaktivalja a VAO-t.
	 * 
	 */
	void unbindVAO() const;

private:
	void createVertexBuffer();
};
#endif // !VERTEXBUFFER_H